#ifndef __ObjectStoredInStack
#define __ObjectStoredInStack

class ObjectStoredInStack
{
private:
                    ObjectStoredInStack( bool );

protected:
                    ObjectStoredInStack();

public:
    virtual        ~ObjectStoredInStack();

public:
    virtual bool    storedInHeap()      const;
    virtual bool    storedInStack()     const;

private:
            bool    setStoredOnStack()  const;

private:
    const bool      m_bStoredOnStack;
};

#endif
