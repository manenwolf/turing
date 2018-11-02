#ifndef TRANSITIONFUNCTION_H
#define TRANSITIONFUNCTION_H
#include "transition.h"
#include <vector>
#include <iostream>
#include <string>

class Transitionfunction
{
public:
    Transitionfunction();
    void addtransition(std::string ss,std::string es, std::string r, std::string w, std::string d);
    std::vector<Transition> transtions;
    std::string gettransition(int i);
    std::vector<std::vector<std::string> > transform(std::string ss , std::vector<std::string> r);
    std::vector<std::vector<std::string>> getdotlabels();
};

#endif // TRANSITIONFUNCTION_H
