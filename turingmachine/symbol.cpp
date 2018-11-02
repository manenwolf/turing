#include "symbol.h"
Symbol::Symbol(){

}
Symbol::Symbol(char v)
{
    value = v;
}
Symbol::Symbol(std::string v){
    value = v;
}
std::string Symbol::getvalue(){
    return value;
}
