#ifndef __DateTFS
#define __DateTFS

class SocketPackage;

struct Date
{
                    Date();
    virtual        ~Date();

    virtual void    serialize( SocketPackage&, bool );

    int year, month, day;
};

#endif