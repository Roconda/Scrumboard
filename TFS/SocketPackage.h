#ifndef __SocketPackage
#define __SocketPackage

#include <string>
#include <vector>

class TCPSocket;

class SocketPackage
{
public:
                                SocketPackage();
    virtual                    ~SocketPackage();

public:
    virtual const char         *getData()           const;
    virtual unsigned            getCount()          const;
    virtual unsigned            getStoredCount()    const;

public:
    virtual bool                read( TCPSocket& );

public:
    virtual void                add( const std::string& );
    virtual void                add( int );
    virtual void                add( double );
    virtual void                add( unsigned char );

    virtual void                done();
    virtual bool                isEmpty()           const;

public:
    virtual const std::string  &getString( std::string& );
    virtual int                 getInt();
    virtual double              getDouble();
    virtual unsigned char       getByte();

public:
    virtual void                add( const char*, size_t );
    virtual char*               get( size_t );
    virtual void                resetCounter();

private:
    static  bool                validHeader( const char*, int );

private:
    static  void                read( void* );

private:
    class ReadClass
    {
    public:
                        ReadClass( SocketPackage*, TCPSocket& );

    public:
        SocketPackage*  pPackage;
        TCPSocket&      cSocket;
        std::string     sID;
        bool            bValidRead;
    };

private:
    class CharVector : public std::vector<char> {};

private:
    CharVector                  m_caData;
    unsigned                    m_nCounter;
};

#endif
