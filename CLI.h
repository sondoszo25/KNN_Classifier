#include "Command.h"
#include "DefaultIOo.h"

class Cli
{
private:
    Command1 *c1;
    Command2 *c2;
    Command3 *c3;
    Command4 *c44;
    Command5 *c5;
    int i;
    Command *c[5];
    DefaultIO *t;

public:
    Cli(DefaultIO *s);
    void start(int i);
    ~Cli();
};