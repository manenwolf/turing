#include "transitionfunction.h"

Transitionfunction::Transitionfunction()
{

}

void Transitionfunction::addtransition(std::string ss,std::string es, std::string r, std::string w, std::string d){
    std::cout << "start making new transition" << std::endl;
    Transition temp;
    temp.startstate = ss;
    temp.endstate = es;
    for(int i = 0; i < r.size();i++){
        std::string tempstr = "";
        tempstr+= r[i];
        temp.r.push_back(tempstr);
        tempstr = "";
        tempstr+= w[i];
        temp.w.push_back(tempstr);
        tempstr = "";
        tempstr+= d[i];
        temp.D.push_back(tempstr);
    }

    transtions.push_back(temp);
    std::cout << "added transition " << temp.r.size() << " " << temp.w.size() << " " << temp.D.size() << std::endl;
    //std::cout << ss.c_str() << " " << es.c_str() << " " << r.c_str() << " " << w.c_str() << " " << d.c_str() << std::endl;
}

std::string Transitionfunction::gettransition(int i){
    std::string t =  transtions[i].startstate + " |" + transtions[i].endstate + " |";
    for(int j = 0; j < transtions[i].r.size();j++){
        t+=transtions[i].r[j] +" ";
    }
    t+=" |";
    for(int j = 0; j < transtions[j].w.size();j++){
        t+=transtions[i].w[j]+" ";
    }


    if(transtions[i].D[0] == "L"){
        t += "<-";
    }else if (transtions[i].D[0] == "R"){
        t+= "->";
    }
    return t;
}

std::vector<std::vector<std::string>> Transitionfunction::getdotlabels(){
   std::vector<std::vector<std::string>> r;
   for(int i = 0;i < transtions.size();i++){
       std::vector<std::string> t;
       t.push_back(transtions[i].startstate);
       t.push_back(transtions[i].endstate);
       std::string label = "";
       for(int j = 0; j < transtions[i].r.size();j++){
           label+=transtions[i].r[j] +"";
       }
        label += "/";
       for(int j = 0; j < transtions[j].w.size();j++){
           label+=transtions[i].w   [j]+"";
       }
       label+= ", ";
       for(int j = 0; j < transtions[j].D.size();j++){
           label+=transtions[i].D[j]+"";
       }
       t.push_back(label);
       r.push_back(t);
   }
   return r;

}
std::vector<std::vector<std::string>> Transitionfunction::transform(std::string ss , std::vector<std::string> r){
    //testoutput
    std::cout << "starttest" << std::endl;
    std::cout << ss << std::endl;
    for(int i = 0 ;i< r.size();i++){
        std::cout << r[i] << std::endl;
    }
    std::cout << "--endtest" << std::endl;



    //std::cout << "transform of state, read:" << ss.c_str() << ", " << r.c_str() << std::endl;
    bool found = true;
    for(int i = 0; i< transtions.size();i++){
        //std::cout << "test" << std::endl;
        found = true;
        if(transtions[i].startstate == ss){

            for(int j = 0;j < transtions[i].r.size();j++){
               //std::cout << "dd" << std::endl;
               if((transtions[i].r[j] != r[j]) ){
                    found = false;

               }
            }
            if(found){
                std::vector<std::string> temps;
                std::vector<std::string> tempw;
                std::vector<std::string> tempD;
                std::vector<std::vector<std::string>> temp;
                temps.push_back(transtions[i].endstate);
                temp.push_back(temps);
                std::cout << "aaa" << std::endl;
                for(int k = 0;k < transtions[i].w.size();k++){
                    tempw.push_back(transtions[i].w[k]);
                    std::cout << "w: " << transtions[i].w[k] << std::endl;
                }
                std::cout << "aaa" << std::endl;
                temp.push_back(tempw);
                for(int k = 0;k < transtions[k].D.size();k++){
                    tempD.push_back(transtions[i].D[k]);
                    std::cout  << "D: " << transtions[i].D[k] << std::endl;
                }
                temp.push_back(tempD);
                std::cout << "aaa" << std::endl;
                return temp;
            }
        }
    }


    std::cout << "no transition on " << ss.c_str() <<" |" << r[0].c_str() << std::endl;// << ", " << r.c_str() << std::endl;
    throw 1;
}
