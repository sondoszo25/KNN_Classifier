#include <vector>
#include <string>
using namespace std;

class Vectors
{
    vector<double> v1;
    vector<double> v2;
    double distance;
    string kind;
    string typedis;
    int Knum;

public:
    double funcaOkled();
    double funcMnhaten();
    double funcCheb();
    double funCanbra();
    double funcMenevoske();
    Vectors(vector<double> v1, vector<double> v2);
    Vectors();
    Vectors(vector<double> v1, vector<double> v2, string s, string ss, int k);
    string getKind();
    double getDistance();
    void setDistance(string s);
    void setDistance();
};

class Types
{
    int quantity;
    string type;

public:
    Types();
    Types(string t);
    int getQuantity();
    string getType();
    void incQuantity();
};