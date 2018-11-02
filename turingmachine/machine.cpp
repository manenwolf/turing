#include "machine.h"

Machine::Machine()
{
    tapes.push_back(tape());
    finitecontrol.push_back(0);
}

bool Machine::end()
{
    if(mystate != nullptr){
    for(int i = 0; i < acceptingstates.size(); i++){
        if(acceptingstates[i].getvalue()== mystate->getvalue()){
            return true;
        }
    }
    }
    return false;
}

void Machine::loadxml(std::string filename){
    //clear old machine
    tapes.clear();
    tapes.push_back(tape());
    finitecontrol.clear();
    finitecontrol.push_back(0);
    states.clear();
    inputsymbols.clear();
    tapesymbols.clear();
    transitionfunction = Transitionfunction();
    acceptingstates.clear();
    s = State();


    TiXmlDocument doc( filename.c_str() );
    if(!doc.LoadFile()){
        return;
        //throw "incorect filename";
    }


    TiXmlElement* root = doc.FirstChildElement();
    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        std::string value = elem->Value();

        if(value == "InputAlphabet"){
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
                std::string name = e->GetText();
                //Symbol temp = Symbol(name);
                inputsymbols.push_back(name);
            }
        }else if(value == "numtapes"){
            for(int i = 1;i<atoi(elem->GetText());i++){
                tapes.push_back(tape());
                finitecontrol.push_back(0);
            }
        }else if(value == "TapeAlphabet"){
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
                std::string name = e->GetText();
                //Symbol temp = Symbol(name);
                tapesymbols.push_back(name);
            }
        }else if(value == "Blank"){
            std::cout << "new blank symbol" << tapes.size()<< std::endl;
            std::string name = elem->GetText();
            blank = Symbol(name);
            for(int i= 0;i<tapes.size();i++){
                tapes[i].blank = Symbol(name);
            }
            std::cout << "ddtest" << std::endl;


        }else if(value == "States"){
            std::cout << "newstate" << std::endl;
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
                std::string name = e->GetText();
                State temp = State(name);
                states.push_back(temp);
            }
        }else if(value == "Transitions"){
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
                TiXmlElement* v = e->FirstChildElement();
                std::string from = v->GetText();
                 v = v->NextSiblingElement();
                std::string to = v->GetText();
                 v = v->NextSiblingElement();
                std::string read = v->GetText();
                 v = v->NextSiblingElement();
                std::string write = v->GetText();
                 v = v->NextSiblingElement();
                std::string dir = v->GetText();
                transitionfunction.addtransition(from,to,read,write,dir);
            }
        }else if(value == "StartState"){
            std::string name = elem->FirstChildElement()->GetText();
            startstate = State(name);
        }else if(value == "AcceptingStates"){
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){

                std::string name = e->FirstChildElement()->GetText();
                State temp = State(name);
                acceptingstates.push_back(temp);
            }

        }else{
            std::cout << "wrong xml value" << value.c_str() << std::endl;
            throw "wrong filetype";
        }
    }
}

 std::vector<std::string> Machine::getinputsymbols(){
      std::vector<std::string> temp;
      for(int i = 0; i< inputsymbols.size();i++){
          temp.push_back(inputsymbols[i]);
      }
    return temp;
 }

std::vector<std::string> Machine::gettapesymbols(){
    std::vector<std::string> temp;
    for(int i = 0; i< tapesymbols.size();i++){
        temp.push_back(tapesymbols[i]);
    }
  return temp;
}
std::string Machine::getblank(){
    return blank.getvalue();
}
std::vector<std::string> Machine::getstates(){
    std::vector<std::string> temp;
    for(int i = 0; i< states.size();i++){
        temp.push_back(states[i].getvalue());
    }
  return temp;
}
std::vector<std::string> Machine::getacceptingstates(){
    std::vector<std::string> temp;
    for(int i = 0; i< acceptingstates.size();i++){
        temp.push_back(acceptingstates[i].getvalue());
    }
  return temp;
}
std::string Machine::getstartstate(){
    return startstate.getvalue();
}

std::vector<std::string> Machine::gettransitions(){
    std::vector<std::string> temp;
    for(int i = 0;i < transitionfunction.transtions.size();i++){
        temp.push_back(transitionfunction.gettransition(i));
    }
    return temp;
}
void Machine::setinput(std::string s){
    tapes[0].setinput(s);
}

std::string Machine::run(){
    for(int i = 0;i< finitecontrol.size();i++){
    finitecontrol[i] = 0;
    }
    s = startstate;
   // std::cout <<"aab" << startstate.getvalue().c_str() << std::endl;

    while(true){
        std::cout << "checking endstate" << std::endl;
        bool end = false;
        for(int i = 0; i < acceptingstates.size(); i++){
            if(acceptingstates[i].getvalue()== s.getvalue()){
                end = true;
            }
        }
        if(end == true){
            break;
        }
        try{
        step();
        }catch(std::string aap){
            std::cout << aap.c_str() << std::endl;
            return "fail";
        }
        std::string returnstring;
        for(int i = 0;i<tapes.size();i++){
            returnstring += tapes[i].to_string();
            returnstring += "|";
        }
        std::cout << returnstring<< std::endl;
    }

    std::string returnstring;
    for(int i = 0;i<tapes.size();i++){
        if(i !=0 ){
         returnstring += "|";
        }
        returnstring += tapes[i].to_string();

    }
    return returnstring;
}
void Machine::step(){

    std::cout << "making a step" << finitecontrol[0]<< std::endl;
    std::vector<std::string> tapesymbol;


    for(int i = 0;i< tapes.size();i++){
        std::cout << i<< " " << tapes.size() << std::endl ;
        tapesymbol.push_back(tapes[i].get(finitecontrol[i]));
    }

    std::cout << "calling transform" << std::endl;
    std::vector<std::vector<std::string>> t;
    try{
        t = transitionfunction.transform(s.getvalue(),tapesymbol);
    }catch(int i){
        std::cout << "wrong transition" << std::endl;
        throw std::string("lolz");
    }
   // std::cout<< "end of transform" << t[0].c_str()<<" " << t[1].c_str()<<" " << t[2].c_str() << std::endl;
    std::cout << "ddw" <<std::endl;
    s = State(t[0][0]);
    for(int i = 0;i<tapes.size();i++){
       std::string a ="";
       a+= t[1][i];
       tapes[i].set(a, finitecontrol[i]);
    }

    for(int i = 0;i<tapes.size();i++){
        std::string dir ="";
        dir+=t[2][i];
        if(dir=="L"){
            finitecontrol[i]--;
        }else if (dir == "R"){
            finitecontrol[i]++;
        }else if(dir == "N"){

        }else{
            throw("wrong direction");
        }
    }
    std::cout << "kdm" << std::endl;


}

void Machine::onestep()
{
    if(mystate == nullptr){
     mystate =new State(startstate.getvalue());
    }

    std::cout << "checking endstate onestep" << std::endl;
    bool end = false;
    for(int i = 0; i < acceptingstates.size(); i++){
        if(acceptingstates[i].getvalue()== mystate->getvalue()){
            end = true;
        }
    }
    if(end == true){
        std::cout << "end" << std::endl;
        return;
    }


    std::cout << "making a step" << finitecontrol[0]<< std::endl;
    std::vector<std::string> tapesymbol;


    for(int i = 0;i< tapes.size();i++){
        std::cout << i<< " " << tapes.size() << std::endl ;
        tapesymbol.push_back(tapes[i].get(finitecontrol[i]));
    }

    std::cout << "calling transform" << std::endl;
    std::vector<std::vector<std::string>> t;
    try{
        t = transitionfunction.transform(mystate->getvalue(),tapesymbol);
    }catch(int i){
        std::cout << "wrong transition" << std::endl;
        throw std::string("lolz");
    }
   // std::cout<< "end of transform" << t[0].c_str()<<" " << t[1].c_str()<<" " << t[2].c_str() << std::endl;
    std::cout << "ddw" <<std::endl;
    delete mystate;
    mystate = new State(t[0][0]);
    for(int i = 0;i<tapes.size();i++){
       std::string a ="";
       a+= t[1][i];
       std::cout << "new tape on pos" << finitecontrol[i] << "|" << a << std::endl;
       tapes[i].set(a, finitecontrol[i]);
    }

    for(int i = 0;i<tapes.size();i++){
        std::string dir ="";
        dir+=t[2][i];
        if(dir=="L"){
            finitecontrol[i]--;
        }else if (dir == "R"){
            finitecontrol[i]++;
        }else if(dir == "N"){

        }else{
            throw("wrong direction");
        }
    }
    std::cout << "kdm" << std::endl;





}

void Machine::printsimple(){
    /*
    std::cout << "start" << std::endl;
    std::string r= "";

    for(int i = negtape.size()-1; i>0 ; i--){
        r += negtape[i];
    }

    bool flag = false;
    for(int i = 0;i < postape.size();i++){
        if(i==finitecontrol && flag == false){
            r+=" ";
            r+=s.getvalue();
            r+= " ";
            flag = true;

        }

        r += postape[i];

    }
    std::cout << "simpleprint:                  " << r.c_str() << std::endl;
    */
}

Machine Machine::tosingletape(){
    if(tapes.size()==1){
        throw singletape();
    }

    Machine m;

    //making the new inputsymbols
    for(int i = 0;i<inputsymbols.size();i++){
        m.inputsymbols.push_back(inputsymbols[i]);
        m.inputsymbols.push_back(inputsymbols[i]+"*");
    }
    m.inputsymbols.push_back("#");

    //new tape

    m.tapes[0].setinput("#"+tapes[0].getall());
    for(int i = 0; i < tapes.size();i++){
        m.tapes[0].append("#");
    }


    return m;
}

void Machine::todot(){
    std::cout << "--------starting making dot file" << std::endl;
    std::ofstream myfile;
    myfile.open("out.dot");

    myfile<< "digraph G{\n";
    for(int i = 0;i < states.size();i++){

        myfile << states[i].getvalue();

        if(mystate != nullptr){
            std::cout << mystate->getvalue() << "|" << states[i].getvalue();
            if(mystate->getvalue() == states[i].getvalue()){
                myfile << "[color=red]";
            }
        }

        myfile << " \n";
    }


    std::vector<std::vector<std::string>>  t = transitionfunction.getdotlabels();
    std::cout << "got the labels" << std::endl;
    for(int i = 0;i< t.size();i++){
      //  std::cout << "ttt" << std::endl;
        myfile << t[i][0] + " -> " + t[i][1] +"[label=\"" + t[i][2] + "\"] \n";
    }

    myfile << "}\n";
    myfile.close();
}

std::string Machine::gettape()
{
    std::string returnstring;
    for(int i = 0;i<tapes.size();i++){
        if(i !=0 ){
         returnstring += "|";
        }
        returnstring += tapes[i].to_string();

    }
    std::cout << "testerdetest" << returnstring << std::endl;
    return returnstring;
}

void Machine::addsubroutine(std::string fromstate, std::string tostate, std::string file){


    TiXmlDocument doc( file.c_str() );
    if(!doc.LoadFile()){
        return;
        //throw "incorect filename";
    }


    TiXmlElement* root = doc.FirstChildElement();
    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        std::string value = elem->Value();

        if(value == "InputAlphabet"){

        }else if(value == "numtapes"){

        }else if(value == "TapeAlphabet"){

        }else if(value == "Blank"){



        }else if(value == "States"){
            std::cout << "newstate" << std::endl;
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
                std::string name = e->GetText();
                State temp = State(fromstate + "s" + name);
                states.push_back(temp);
            }
        }else if(value == "Transitions"){
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
                TiXmlElement* v = e->FirstChildElement();
                std::string from = fromstate+"s"+v->GetText();
                 v = v->NextSiblingElement();
                std::string to = fromstate+"s"+ v->GetText();
                 v = v->NextSiblingElement();
                std::string read = v->GetText();
                 v = v->NextSiblingElement();
                std::string write = v->GetText();
                 v = v->NextSiblingElement();
                std::string dir = v->GetText();
                transitionfunction.addtransition(from,to,read,write,dir);
            }
        }else if(value == "StartState"){
            std::string name = elem->FirstChildElement()->GetText();

            for(int k = 0;k< tapesymbols.size();k++){
            transitionfunction.addtransition(fromstate,fromstate+"s"+name,tapesymbols[k],tapesymbols[k],"N");
            }
        }else if(value == "AcceptingStates"){
            for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){

                std::string name = e->FirstChildElement()->GetText();

                for(int k = 0;k< tapesymbols.size();k++){
                transitionfunction.addtransition(fromstate+"s"+name,tostate,tapesymbols[k],tapesymbols[k],"N");
                }
            }

        }else{
            std::cout << "wrong xml value" << value.c_str() << std::endl;
            throw "wrong filetype";
        }
    }

}
