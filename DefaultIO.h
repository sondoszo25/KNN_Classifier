#include <string>

class DeafultIO{
public:
virtual string read();
virtual void write(string s);
};

class SocketIO :public DeafultIO{
};


class StandardIO:public DeafultIO{
};