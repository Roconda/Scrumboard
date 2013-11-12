#ifndef ___User___
#define ___User___

#include "TFSBasis.h"
#include "UniqueKeyItem.h"
#include "ItemStorage.h"

#include <string>

#define NoName  withName("")

class User : public TFSBasis
{
public:
    typedef ItemStorageWithKey<User,std::string> ItemStorage;

private:
                                    User();
                                    User( const std::string& );

public:
    virtual                        ~User();

public:
    virtual const char*             getName()       const;

public:
    virtual TFSBasis*               serialize( SocketPackage&, bool );

public:
    static  User*                   withName( const char* );
    static  bool                    isPresent( const char* );

public:
    static  size_t                  size();
    static  ItemStorage::iterator   begin();
    static  ItemStorage::iterator   end();

public:
    virtual bool                    operator < ( const User& )  const;

public:
    static  ItemStorage&            getStorage();

    TFSBASIS_DECLARE( User )

private:
    std::string                     m_sName;

private:
    friend class ItemStorage;
};

#endif
