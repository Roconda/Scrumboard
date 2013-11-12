#ifndef __TFSBASIS__
#define __TFSBASIS__

#define INI_SIZE    10

#include "ObjectStoredInStack.h"

#include "ItemStorage.h"

#include "TFSBasisCreator.h"

#include "TFSVisitor.h"
#include "TFSConstVisitor.h"

#include <vector>

class SocketPackage;

class TFSBasis : public ObjectStoredInStack
{
public:
                                    TFSBasis();
    virtual                        ~TFSBasis();

public:
    virtual TFSBasis*               get( const std::string& )   const   = 0;

public:
    virtual TFSBasis*               serialize( SocketPackage&, bool )   = 0;
    virtual const char*             getClassID()                const   = 0;

public:
    virtual void                    accept( TFSVisitor& )               = 0;
    virtual void                    accept( TFSConstVisitor& )  const   = 0;

public:
    static  void                    serialize( TFSBasis*&, SocketPackage&, bool );
    static  const char*             getClassID( TFSBasis* );

public:
    static  bool                    exists( TFSBasis* );
    static  bool                    canBeDeleted( TFSBasis* );

public:
    static  bool                    accept( TFSBasis*, TFSVisitor& );
    static  bool                    accept( TFSBasis*, TFSConstVisitor& );

public:
    static  void                    removeAll();

public:
    template <class Class>
    static  void                    serialize( std::vector<Class*>&
                                             , size_t&
                                             , SocketPackage&, bool );

protected:
    template <class Class>
    void                            addElement( std::vector<Class*>&, size_t&
                                              , const Class& );

    template <class Class>
    Class*                          getElementAt( const std::vector<Class*>&
                                                , size_t
                                                , size_t )      const;

    template <class Class>
    void                            removeElementAt( std::vector<Class*>&, size_t&, size_t );

    template <class Class>
    void                            removeAll( std::vector<Class*>&, size_t& );

private:
    static  ItemStorage<TFSBasis>&  getStorage();
};

#include "TFSBasis.hpp"

#endif
