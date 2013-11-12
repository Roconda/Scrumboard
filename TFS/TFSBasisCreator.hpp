template <class Class>
TFSBasisCreator<Class>::TFSBasisCreator()
{
    TFSBasisFactory::add( *this );
}

template <class Class>
TFSBasisCreator<Class>::~TFSBasisCreator()
{
}

template <class Class>
TFSBasis*
TFSBasisCreator<Class>::create() const
{
    return new Class;
}

template <class Class>
const char*
TFSBasisCreator<Class>::getID() const
{
    return Class::ClassID();
}
