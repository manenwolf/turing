#ifndef MACHINE_H
#define MACHINE_H
#include "state.h"
#include "symbol.h"
#include "transitionfunction.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include "tinyxml/tinyxml.h"
#include "tape.h"
#include <string>
#include <fstream>

class singletape{};

class Machine
{
public:
    Machine();
    bool end();
    void loadxml(std::string filename);
    std::vector<std::string> getinputsymbols();
    std::vector<std::string> gettapesymbols();
    std::string getblank();
    std::vector<std::string> getstates();
    std::vector<std::string> getacceptingstates();
    std::string getstartstate();
    std::vector<std::string> gettransitions();
    void setinput(std::string s);
    std::string run();
    void step();
    void onestep();
    std::vector<int> finitecontrol;
    Machine tosingletape();
    void todot();
    std::string gettape();
    void addsubroutine(std::string fromstate, std::string tostate, std::string file);

private:
    std::vector<State> states;
    std::vector<std::string> inputsymbols;
    std::vector<std::string> tapesymbols;
    Transitionfunction transitionfunction;
    State startstate;
    Symbol blank;
    std::vector<State> acceptingstates;
    std::vector<tape> tapes;
    State s;
    State* mystate =nullptr;
    void printsimple();
};

#endif // MACHINE_H
