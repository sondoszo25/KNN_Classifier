#include <list>
#include <string>
#include <iterator>
using namespace std;
class Filevector{
private:
list<string> vectorlist;
list<string> Vectortest;
list<string> classified;
public:
Filevector();
void addvlist();
void addvtest();
void addc();
list<string> getlistvector();
list<string> getlistclass();
~Filevector();
};