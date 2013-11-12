template <class Class>
void
TFSBasis::serialize( std::vector<Class*>& paArray
                   , size_t&              nSize
                   , SocketPackage&       cPackage
                   , bool                 bWriteToStorage )
{
    size_t      n;
    TFSBasis   *pAction;

    if ( bWriteToStorage )
    {
        cPackage.add( int(nSize) );

        for ( n=0; n<nSize; n++ )
        {
            pAction = paArray[n];

            if ( !getStorage().isPresent(pAction) )
                pAction = NULL;

            serialize( pAction, cPackage, true );
        }
    }
    else
    {
        nSize   = cPackage.getInt();

        paArray.resize( std::max<size_t>(INI_SIZE,nSize) );

        for ( n=0; n<nSize; n++ )
        {
            serialize( pAction, cPackage, false );

            if ( pAction == NULL )
                paArray[n]  = NULL;
            else
                paArray[n]  = dynamic_cast<Class*>( pAction );
        }
    }
}

template <class Class>
void
TFSBasis::addElement( std::vector<Class*>& paVector, size_t& nSize, const Class& cClass )
{
    if ( nSize >= paVector.size() )
        paVector.resize( (paVector.size()+1) << 1 );

    paVector[nSize++]    = (Class*) &cClass;
}

template <class Class>
Class*
TFSBasis::getElementAt( const std::vector<Class*>& paVector, size_t nSize, size_t nIndex ) const
{
    if ( nIndex < 0 || nIndex >= nSize )
        return NULL;
    else
    {
        if ( getStorage().isPresent(paVector[nIndex]) )
            return paVector[nIndex];
        else
            return NULL;
    }
}

template <class Class>
void
TFSBasis::removeElementAt( std::vector<Class*>& paVector, size_t& nSize, size_t nIndex )
{
    if ( nIndex >= 0 && nIndex < nSize )
    {
        paVector.erase( paVector.begin()+nIndex );

        nSize  -= 1;
        if ( paVector.size() < INI_SIZE )
            paVector.resize( INI_SIZE );
    }
}

template <class Class>
void
TFSBasis::removeAll( std::vector<Class*>& paVector, size_t& nSize )
{
    size_t  n;

    for ( n=0; n<nSize; n++ )
        if ( canBeDeleted(paVector[n]) )
            delete paVector[n];

    paVector.clear();
    nSize   = 0;
}

#define TFSBASIS_DECLARE( Class ) \
public: \
    TFSBasis* get( const std::string& ) const; \
    static const char* ClassID(); \
    const char* getClassID() const { \
        return ClassID(); } \
    void accept( TFSVisitor& visitor ) {\
        visitor.visit( *this ); }\
    void accept( TFSConstVisitor& visitor ) const {\
        visitor.visit( *this ); }\
    class Creator : TFSBasisCreator< Class > {}; \
private: \
    static Creator m_cCreator; \
private: \
    friend class TFSBasisCreator< Class >;

#define TFSBASIS_IMPLEMENT_STRING( Class ) \
Class ::Creator Class ::m_cCreator; \
TFSBasis* Class :: get( const std::string& sID ) const { \
    if ( getStorage().isPresent(sID) ) \
      return getStorage().get( sID ); \
    else \
      return NULL; }

#define TFSBASIS_IMPLEMENT_INT( Class ) \
Class ::Creator Class ::m_cCreator; \
TFSBasis* Class :: get( const std::string& sID ) const { \
    return NULL; }
