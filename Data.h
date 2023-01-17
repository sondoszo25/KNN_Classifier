#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex.h>
using namespace std;

class MakeData
{
    string input;
    char *delim;
    vector<double> v;
    int flag9;
    string kind;
    string typdis;
    int knum;

public:
    MakeData(string input1, char *delim1, vector<double> v1, int flag99, string kind1);
    vector<double> &getVector();
    string getString();
    int makeInput();
    int match(const char *string, char *pattern);
    int getk();
    string getTypDis();
};