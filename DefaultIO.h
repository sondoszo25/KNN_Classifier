#ifndef  DefaultIO.h 
#define  DefaultIO.h 
#include <string>
#include <stdbool.h>





class SocketIO{
protected:
bool stat=true;
int sock;
public:
SocketIO(int sockk);
virtual std::string read() ;
virtual void write(std::string s);
bool getflag();
};


#endif