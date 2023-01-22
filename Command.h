
#include <string>
#include "DefaultIOo.h"
using namespace std;

class Command
{
protected:
    string descrpiton;
    DefaultIO* dio;
public:
    Command();
    virtual void Execute()=0;
    string getdescrption();
};

class Command2 : public Command
{
    private:
    int k=5;
    string typdis="AUC";
    public:
    void Execute();
    Command2(DefaultIO* t);
    string getTypdis();
     int    getK();
     void setTypdis(string s);
     void setK(int k1);
};
