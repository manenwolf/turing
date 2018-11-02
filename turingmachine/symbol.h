#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

class Symbol
{
public:
    Symbol();
    Symbol(char v);
    Symbol(std::string v);
    std::string getvalue();
private:
    std::string value;

};

#endif // SYMBOL_H
