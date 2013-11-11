//#include "stdafx.h"

#include "SocketPackage.h"

#include "PracticalSocket.h"

#include <memory.h>
#include <process.h>

#define SIZEOF_UNSIGNED     4

#define szFirstCheck        "BHJvWSV"
#define nFirstCheckSize      8
#define nOffset             12

#define FIRST_POSITION      nOffset
#define STEP_SIZE           1024
#define POWER_2_STEP_SIZE   10

#define READ_MAX_TIME       30000

//  comment the next line in case you use Qt:
#define RUN_READ_IN_THREAD

SocketPackage::SocketPackage()
{
    m_caData.resize( STEP_SIZE );

    ::memcpy( &m_caData[0], szFirstCheck, nFirstCheckSize );

    resetCounter();
}

SocketPackage::~SocketPackage()
{
}

const char*
SocketPackage::getData() const
{
    return &m_caData[0];
}

unsigned
SocketPackage::getCount() const
{
    return m_nCounter;
}

unsigned
SocketPackage::getStoredCount() const
{
    return *(unsigned*) &m_caData[nFirstCheckSize];
}

bool
SocketPackage::read( TCPSocket& cSocket )
{
#ifdef _RUN_READ_IN_THREAD
    bool        bValidRead  = false;
    ReadClass   cReadClass( this, cSocket );
    HANDLE      nRead       = HANDLE( ::_beginthread(read,0,&cReadClass) );

    if ( ::WaitForSingleObject(nRead,READ_MAX_TIME) == WAIT_TIMEOUT )
    {
        resetCounter();

        return false;
    }
    else
        return cReadClass.bValidRead;
#else
    ReadClass   cReadClass( this, cSocket );

    read( &cReadClass );

    return cReadClass.bValidRead;
#endif
}

void
SocketPackage::add( const std::string& sText )
{
    add( int(sText.size()) );
    add( sText.c_str(), sText.size()+1 );
}

void
SocketPackage::add( int nValue )
{
    add( (const char*) &nValue, SIZEOF_UNSIGNED );
}

void
SocketPackage::add( double dValue )
{
    add( (const char*) &dValue, sizeof(double) );
}

void
SocketPackage::add( unsigned char cValue )
{
    add( (const char*) &cValue, sizeof(unsigned char) );
}

void
SocketPackage::done()
{
    ::memcpy( &m_caData[nFirstCheckSize], &m_nCounter, SIZEOF_UNSIGNED );
}

bool
SocketPackage::isEmpty() const
{
    return m_nCounter == FIRST_POSITION;
}

const std::string&
SocketPackage::getString( std::string& sBuffer )
{
    int nSize   = getInt();
    sBuffer.resize( nSize );

    sBuffer     = get( nSize + 1 );

    return sBuffer;
}

int
SocketPackage::getInt()
{
    long    nResult = *(long*) get( SIZEOF_UNSIGNED );

    return int( nResult );
}

double
SocketPackage::getDouble()
{
    double  dResult = *(double*) get( sizeof(double) );

    return dResult;
}

unsigned char
SocketPackage::getByte()
{
    return unsigned char( m_caData[m_nCounter++] );
}

void
SocketPackage::add( const char* caArray, size_t nSize )
{
    if ( nSize == 0 )
        return;

    unsigned    currentSize = unsigned( nSize + m_nCounter );

    if ( currentSize > m_caData.size() )
    {
        div_t   nDiv    = div( currentSize, STEP_SIZE );

        m_caData.resize( (nDiv.rem==0?nDiv.quot:nDiv.quot+1)<<POWER_2_STEP_SIZE );
    }

    ::memcpy( &m_caData[m_nCounter], caArray, nSize );

    m_nCounter += unsigned( nSize );
}

char*
SocketPackage::get( size_t nSize )
{
    char   *caValue = &m_caData[m_nCounter];

    m_nCounter += unsigned( nSize );

    return caValue;
}

void
SocketPackage::resetCounter()
{
    m_nCounter  = FIRST_POSITION;
}

bool
SocketPackage::validHeader( const char* szInput, int nSize )
{
    bool    bIsValid    = nSize >= FIRST_POSITION;

    if ( bIsValid )
        bIsValid    = ::strcmp( szInput, szFirstCheck ) == 0;

    return bIsValid;
}

void
SocketPackage::read( void* pVoid )
{
    ReadClass      *pReadClass  = (ReadClass*) pVoid;
    SocketPackage  &cPackage    = *pReadClass->pPackage;
    TCPSocket      &cSocket     =  pReadClass->cSocket;
    bool           &bValidRead  =  pReadClass->bValidRead;

    int             nBytesReceived,
                    nTotalReceived;
    unsigned        nTotalSize  = 0;
    char            caEchoBuffer[STEP_SIZE];

    cPackage.resetCounter();

    try
    {
        nTotalReceived  = cSocket.recv( caEchoBuffer, STEP_SIZE );
        bValidRead      = cPackage.validHeader( caEchoBuffer, nTotalReceived );
    }
    catch( ... )
    {
        bValidRead      = false;
    }

    if ( bValidRead )
    {
        //  write everything except the first bytes that describe the header and the size...
        cPackage.add( caEchoBuffer+FIRST_POSITION, nTotalReceived-FIRST_POSITION );

        //  first position holds the length of the sent data in bytes...
        ::memcpy( &nTotalSize, caEchoBuffer+nFirstCheckSize, SIZEOF_UNSIGNED );
        if ( unsigned(nTotalReceived) < nTotalSize )
        {
            do
            {
                nBytesReceived  = cSocket.recv( caEchoBuffer, STEP_SIZE );
                cPackage.add( caEchoBuffer, nBytesReceived );

                nTotalReceived += nBytesReceived;
            }
            while ( unsigned(nTotalReceived) < nTotalSize );
        }

        cPackage.done();
    }
}

SocketPackage::ReadClass::ReadClass( SocketPackage* _pPackage, TCPSocket& _cSocket )
    : pPackage( _pPackage )
    , cSocket ( _cSocket )
{
    bValidRead  = false;
}
