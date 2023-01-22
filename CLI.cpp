#include "CLI.h"
#include <iostream>
void Cli::start(int i){
    c[i-1]->Execute();
}

Cli::Cli(DefaultIO* s)
{
 t=s;
 c[1]=new Command2(s);
 c[0]=new Command1(s);
}

Cli::~Cli(){
    free(c[1]);
    free(c[0]);
}