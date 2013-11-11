//#include "stdafx.h"

#include "Attachment.h"

#include "general.h"
#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_INT( Attachment )

Attachment::Attachment()
{
}

Attachment::~Attachment()
{
}

void
Attachment::setContent( char* caContent, size_t nSize )
{
    m_caContent.resize( nSize );

    ::memcpy( &m_caContent[0], caContent, nSize*sizeof(char) );
}

void
Attachment::setExtension( const char* szExtension )
{
    assign( szExtension, m_sExtension );
}

void
Attachment::setFileName( const char* szFileName )
{
    assign( szFileName, m_sFileName );
}

void
Attachment::setFileType( const char* szFileType )
{
    assign( szFileType, m_sFileType );
}

char*
Attachment::getContent() const
{
    return (char*) &m_caContent[0];
}

size_t
Attachment::getContentSize() const
{
    return m_caContent.size();
}

const char*
Attachment::getExtension() const
{
    return m_sExtension.c_str();
}

const char*
Attachment::getFilename() const
{
    return m_sFileName.c_str();
}

const char*
Attachment::getFileType() const
{
    return m_sFileType.c_str();
}

TFSBasis*
Attachment::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    if ( bWriteToStorage )
    {
        cPackage.add( m_sExtension );
        cPackage.add( m_sFileName );
        cPackage.add( m_sFileType );

        cPackage.add( int(m_caContent.size()) );
        cPackage.add( &m_caContent[0], m_caContent.size() );
    }
    else
    {
        std::string sBuffer;
        size_t      nSize;

        setExtension( cPackage.getString(sBuffer).c_str() );
        setFileName ( cPackage.getString(sBuffer).c_str() );
        setFileType ( cPackage.getString(sBuffer).c_str() );

        m_caContent.resize( (nSize=cPackage.getInt()) );
        if ( nSize > 0 )
            ::memcpy( &m_caContent[0], cPackage.get(nSize), nSize*sizeof(char) );
    }

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
Attachment::ClassID()
{
    return "class Attachment";
}
