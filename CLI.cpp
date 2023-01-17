#include "CLI.h"

void Cli::start(){
    c->Execute();
}

Cli::Cli(Command*d)
{
    c=d;
}