
#include <string>
#include "DefaultIO.h"
using namespace std;

class Command
{
protected:
    string descrpiton;
    SocketIO* dio;
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
    Command2(SocketIO* t);
    string getTypdis();
     int    getK();
     void setTypdis(string s);
     void setK(int k1);
};
