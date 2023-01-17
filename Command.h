#include <string>
#include "DefaultIO.h"
using namespace std;

class Command
{
protected:
    string descrpiton;
    DeafultIO dio();

public:
    virtual void Execute() const = 0;
    string getdescrption();
};

class Command1 : public Command
{
};

class Command2 : public Command
{
};

class Command3 : public Command
{
};

class Command4 : public Command
{
};

class Command5 : public Command
{
};