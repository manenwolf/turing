#ifndef STATE_H
#define STATE_H

#include <iostream>


class State
{
public:
    State();
    State(char v);
    State(std::string v);
    std::string getvalue();
private:
    std::string value;

};

#endif // STATE_H
