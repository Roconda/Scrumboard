#ifndef ___Attachment
#define ___Attachment

#include "TFSBasis.h"
#include "UniqueKeyItem.h"

#include <string>
#include <vector>

class Attachment : public TFSBasis
{
public:
                                    Attachment();
    virtual                        ~Attachment();

public:
    virtual void                    setContent( char*, size_t );
    virtual void                    setExtension( const char* );
    virtual void                    setFileName( const char* );
    virtual void                    setFileType( const char* );

public:
    virtual char*                   getContent()        const;
    virtual size_t                  getContentSize()    const;
    virtual const char*             getExtension()      const;
    virtual const char*             getFilename()       const;
    virtual const char*             getFileType()       const;

public:
    virtual TFSBasis*               serialize( SocketPackage&, bool );

public:
    TFSBASIS_DECLARE( Attachment )

private:
    std::vector<char>               m_caContent;
    std::string                     m_sExtension,
                                    m_sFileName,
                                    m_sFileType;
};

#endif
