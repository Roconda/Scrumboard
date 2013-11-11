#ifndef ___STATUS__
#define ___STATUS__

#include "TFSBasis.h"
#include "NonUniqueKeyItem.h"
#include "UniqueKeyItem.h"
#include "Date.h"

#include <string>

class StatusType;
class User;

class Status : public TFSBasis
{
public:
                                    Status();
    virtual                        ~Status();

public:
    virtual void                    setDay( int );
    virtual void                    setMonth( int );
    virtual void                    setYear( int );
    virtual void                    setAnnotation( const char* );
    virtual void                    setUser( const User* );
    virtual void                    setStatusType( const StatusType& ); 

public:
    virtual int                     getDay()        const;
    virtual int                     getMonth()      const;
    virtual int                     getYear()       const;
    virtual const char*             getAnnotation() const;
    virtual User*                   getUser()       const;
    virtual StatusType*             getStatusType() const;

public:
    virtual TFSBasis*               serialize( SocketPackage&, bool );

public:
    TFSBASIS_DECLARE( Status )

private:
    Date                            m_cDate;
    std::string                     m_sAnnotation;
    std::string                     m_sUser;
    StatusType*                     m_pStatusType;
};

#endif
