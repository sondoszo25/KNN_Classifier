
#include "Filesave.h"


Filevector::~Filevector(){
delete(vectorlist);
delete(Vectortest);
delete(classified);
}
Filevector::Filevector(){}
void Filevector::addvlist(string s){
this->vectorlist->push_back(s);
}

void Filevector::addvtest(string s){
this->Vectortest->push_back(s);
}

void Filevector::addc(string s){
this->classified->push_back(s);
}

list<string>* Filevector::getlistvector(){
return this->vectorlist;
}
list<string>* Filevector::getlistclass(){
return this->classified;
}
list<string>* Filevector::getlisttest(){
return this->Vectortest;
}
