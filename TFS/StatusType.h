#ifndef ___StatusType____
#define ___StatusType____

#include "TFSBasis.h"
#include "ItemStorage.h"
#include "UniqueKeyItem.h"

#include <string>
#include <vector>

class StatusType : public TFSBasis
{
public:
    typedef ItemStorageWithKey<StatusType,std::string> ItemStorage;

private:
                                    StatusType();
                                    StatusType( const std::string& );

public:
    virtual                        ~StatusType();

private:
    virtual void                    setName( const std::string& );

public:
    virtual void                    setAllowedOn( int );

    virtual void                    addPrevStatusType( const StatusType& );
    virtual void                    addNextStatusType( const StatusType& );

public:
    virtual int                     getAllowedOn()                          const;
    virtual const char*             getName()                               const;

    virtual size_t                  sizePrevStatusType()                    const;
    virtual const StatusType*       getPrevStatusType( size_t )             const;

    virtual size_t                  sizeNextStatusType()                    const;
    virtual const StatusType*       getNextStatusType( size_t )             const;

public:
    virtual TFSBasis*               serialize( SocketPackage&, bool );

public:
    static  StatusType*             withName( const char* );
    static  bool                    isPresent( const char* );

public:
    virtual bool                    operator < ( const StatusType& )        const;

public:
    static  ItemStorage&            getStorage();

private:
    virtual void                    add( const StatusType&
                                       , std::vector<std::string>&
                                       , size_t& );
    virtual const StatusType*       get( size_t
                                       , const std::vector<std::string>&
                                       , size_t )                           const;
    virtual void                    serialize( std::vector<std::string>&
                                             , size_t&
                                             , SocketPackage&
                                             , bool );

private:
    virtual void                    initialize();

    TFSBASIS_DECLARE( StatusType )

private:
    int                             m_nAllowedOn;   // waarvoor bedoeld ?????
    std::string                     m_sName;
    std::vector<std::string>        m_saPrevStatus,
                                    m_saNextStatus;
    size_t                          m_nPrevCount,
                                    m_nNextCount;

private:
    friend class ItemStorage;
};

#endif
