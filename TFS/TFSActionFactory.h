#ifndef ___TFSActionFactory
#define ___TFSActionFactory

#include <list>
#include <map>
#include <string>

class TFSAction;
class TFSActionDecorator;
class SocketPackage;

class TFSActionFactory
{
private:
                            TFSActionFactory();

public:
    static  TFSAction*      create( const char* );

    static  void            process( const char*
                                   , SocketPackage&
                                   , SocketPackage& );

private:
    static  void            assignStrategy( const char*, TFSAction* );
    static  void            assignDecorator( const char*, TFSActionDecorator* );

private:
    static  TFSAction*      createStrategy( const char* );
    static  TFSAction*      createDecorator( const char*, TFSAction* );

private:
    class StrategyMap  : public std::map<std::string,TFSAction*> {};
    class DecoratorMap : public std::map<std::string,TFSActionDecorator*> {};

private:
    static  StrategyMap&    getStrategyMap();
    static  DecoratorMap&   getDecoratorMap();

private:
    static  void            decompose( const char*, std::list<std::string>& );

private:
    friend class TFSAction;
    friend class TFSActionDecorator;
};

#endif
