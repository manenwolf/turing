#include "state.h"
State::State(){

}
State::State(char v){
    value = v;
}
State::State(std::string v){
    value = v;
}

std::string State::getvalue(){
    return value;
}
