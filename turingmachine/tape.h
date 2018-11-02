#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include"symbol.h"

class tape
{
public:
    tape();
    void setinput(std::string s);
    std::string to_string();
    Symbol blank;
    std::string get(int i);
    void set(std::string, int i);
    void append(std::string s);
    std::string getall();
private:
    std::vector<std::string> postape;
    std::vector<std::string> negtape;

};

#endif // TAPE_H
