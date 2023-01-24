#ifndef  filesave 
#define  filesave


#include <list>
#include <string>
#include <iterator>
using namespace std;
class Filevector{
private:
list<string>* vectorlist=new list<string>;
list<string>* Vectortest=new list <string>;
list<string>* classified=new list<string>;
public:
Filevector();
void addvlist(string s);
void addvtest(string s);
void addc(std::string s);
list<string>* getlistvector();
list<string>* getlistclass();
list<string>* getlisttest();
~Filevector();
};
#endif