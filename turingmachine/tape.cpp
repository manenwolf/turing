#include "tape.h"

tape::tape()
{
    negtape.push_back(blank.getvalue());
}

void tape::setinput(std::string s){
    postape.clear();
    negtape.clear();
    for(int i = 0;i < s.size(); i++){
        postape.push_back(std::string(1,s[i]));
    }
}
std::string tape::to_string(){
    std::string r= "";
    for(int i = negtape.size()-1; i>0 ; i--){
        if(negtape[i] != blank.getvalue()){
        r += negtape[i];
        r+="";
        }
    }
    for(int i = 0;i < postape.size();i++){
        if(postape[i]!= blank.getvalue()){
        r += postape[i];
        r += "";
        }
    }
    return r;
}

std::string tape::get(int finitecontrol){
    std::cout << "geting" << finitecontrol << " " <<  std::endl;

    if(finitecontrol>=0){
        if(finitecontrol >= (static_cast<int>(postape.size())) -1){
            std::cout << "a" << std::endl;
            postape.push_back(blank.getvalue());
            std::cout << "b" << std::endl;
        }
        return postape[finitecontrol];
    }else{
        if(-finitecontrol >= negtape.size()){
            negtape.push_back(blank.getvalue());

            std::cout << "new blank on negtape"  <<  -finitecontrol << " ," << negtape.size() << std::endl;
            return blank.getvalue();
        }
        return negtape[-finitecontrol];
    }
    std::cout << "end of get" << std::endl;
}

void tape::set(std::string s, int i){
    if(i>=0){
        postape[i] = s;
    }else{
        negtape[-i] = s;
    }

}

void tape::append(std::string s){
    postape.push_back(s);
}

std::string tape::getall()
{
    std::string temp = "";
    for(int i = negtape.size()-1;i>=0;i--){
        temp+= negtape[i];
    }
    for(int i = 0; i< postape.size();i++){
        temp+= postape[i];
    }
    return temp;
}
