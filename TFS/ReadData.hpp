template <class Class>
void
ReadData::readEveryObject( SocketPackage& cPackage )
{
    //ItemStorageWithKey<Class,std::string>&  cStorage    = Class::getStorage();
    int                                     n, max;
    //std::string                             sID         = Class::ClassID();
    TFSBasis*                               pObject;

    max     = cPackage.getInt();

    for ( n=0; n<max; n++ )
        TFSBasis::serialize( pObject, cPackage, false );
}
