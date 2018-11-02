#ifndef TRANSITION_H
#define TRANSITION_H
#include "state.h"
#include "symbol.h"
#include <vector>

enum Direction{
    Left,
    Right
};

class Transition
{
public:
    Transition();

    std::string startstate;
    std::string endstate;
    std::vector<std::string> r;
    std::vector<std::string> w;
    std::vector<std::string> D;

};

#endif // TRANSITION_H
