#ifndef __TFSBasisFactory
#define __TFSBasisFactory

#include <map>
#include <string>

class TFSBasis;
class TFSBasisCreatorInterface;

class TFSBasisFactory
{
private:
                                            TFSBasisFactory();
    virtual                                ~TFSBasisFactory();

public:
    static  void                            add( const TFSBasisCreatorInterface& );
    static  TFSBasis*                       create( const char* );

public:
    static  const TFSBasisCreatorInterface* get( const char* );

private:
    typedef std::map<std::string,const TFSBasisCreatorInterface*> Map;

private:
    static  Map                            &getMap();
};

#endif
