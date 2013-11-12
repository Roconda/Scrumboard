#ifndef ___WorkItem
#define ___WorkItem

#include <string>
#include <vector>

#include "TFSBasis.h"
#include "UniqueKeyItem.h"
#include "NonUniqueKeyItem.h"

class Attachment;
class User;

class WorkItem : public TFSBasis
{
public:
                                            WorkItem();
    virtual                                ~WorkItem();

public:
    virtual void                            setAdditionalInfo( const char* );
    virtual void                            setDescription( const char* );
    virtual void                            setIterationPath( const char* );
    virtual void                            setTitle( const char* );
    virtual void                            setWorkItemNumber( int );

    virtual void                            setUser( const User* );

    virtual void                            addAttachment( const Attachment& );

public:
    virtual const char*                     getAdditionalInfo()         const;
    virtual const char*                     getDescription()            const;
    virtual const char*                     getIterationPath()          const;
    virtual const char*                     getTitle()                  const;
    virtual int                             getWorkItemNumber()         const;

    virtual User*                           getUser();

    virtual size_t                          getNumberOfAttachements()   const;
    virtual Attachment*                     getAttachment( size_t )     const;

    virtual const std::vector<Attachment*>& getAttachmentArray()        const;

public:
    virtual void                            removeAttachmentAt( size_t );

public:
    virtual TFSBasis*                       serialize( SocketPackage&, bool );

public:
    TFSBASIS_DECLARE( WorkItem )

private:
    std::string                             m_sAdditionalInfo,
                                            m_sDescription,
                                            m_sIterationPath,
                                            m_sTitle;
    int                                     m_nWorkItemNumber;

    std::string                             m_sUser;

    std::vector<Attachment*>                m_paAttachment;
    size_t                                  m_nCount;
};

#endif
