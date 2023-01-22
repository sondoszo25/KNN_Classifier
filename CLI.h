#include "Command.h"
#include "DefaultIOo.h"

class Cli{
private:
int i;
Command* c[5];
DefaultIO* t;

public:
Cli(DefaultIO* s);
void start(int i);
~Cli();
};