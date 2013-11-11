#ifndef NULL
    #define NULL 0
#endif

template <class Class>
void
WriteData::writeEveryObject( SocketPackage& cPackage )
{
    ItemStorageWithKey<Class,std::string>&          cStorage = Class::getStorage();
    ItemStorageWithKey<Class,std::string>::iterator iStorage;
    TFSBasis*                                       pObject;

    cPackage.add( int(cStorage.size()) );

    for ( iStorage=cStorage.begin(); iStorage!=cStorage.end(); ++iStorage )
    {
        pObject = iStorage->second;
        if ( !TFSBasis::exists(pObject) )
            pObject = NULL;

        TFSBasis::serialize( pObject, cPackage, true );
    }
}
