#ifndef ___TFSBASISCREATOR__
#define ___TFSBASISCREATOR__

#include "TFSBasisFactory.h"

class TFSBasisCreatorInterface
{
protected:
                        TFSBasisCreatorInterface()      {}
    virtual            ~TFSBasisCreatorInterface()      {}

public:
    virtual TFSBasis*   create()                    const   = 0;
    virtual const char* getID()                     const   = 0;
};

template <class Class>
class TFSBasisCreator : public TFSBasisCreatorInterface
{
public:
                                    TFSBasisCreator();
    virtual                        ~TFSBasisCreator();

public:
    virtual TFSBasis*               create()                    const;
    virtual const char*             getID()                     const;
};

#include "TFSBasisCreator.hpp"

#endif
