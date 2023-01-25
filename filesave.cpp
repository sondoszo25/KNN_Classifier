#include "Filesave.h"
/******************
 * Function Name: Filevector dtor
 * Input: none
 * Output:
 * Function Operation: deleting Filevector
 ******************/
Filevector::~Filevector()
{
    delete (vectorlist);
    delete (Vectortest);
    delete (classified);
}
/******************
 * Function Name: default ctor
 * Input: none
 * Output: Filevector
 * Function Operation: ctor
 ******************/
Filevector::Filevector() {}
/******************
 * Function Name: addvlist
 * Input: s
 * Output: void
 * Function Operation: add vector to list
 ******************/
void Filevector::addvlist(string s)
{
    this->vectorlist->push_back(s);
}
/******************
 * Function Name: addvtest
 * Input: string
 * Output: void
 * Function Operation: add vector to list of test
 ******************/
void Filevector::addvtest(string s)
{
    this->Vectortest->push_back(s);
}
/******************
 * Function Name: addc
 * Input: string
 * Output: void
 * Function Operation: add string to list
 ******************/
void Filevector::addc(string s)
{
    this->classified->push_back(s);
}
/******************
 * Function Name: getlistvector
 * Input: none
 * Output: list of strings
 * Function Operation: return list of vectors
 ******************/
list<string> *Filevector::getlistvector()
{
    return this->vectorlist;
}
/******************
 * Function Name: getlistclass
 * Input: none
 * Output: void
 * Function Operation: returns list of strings
 ******************/
list<string> *Filevector::getlistclass()
{
    return this->classified;
}
/******************
 * Function Name: getlisttest
 * Input: none
 * Output: void
 * Function Operation: returns list of strings
 ******************/
list<string> *Filevector::getlisttest()
{
    return this->Vectortest;
}
