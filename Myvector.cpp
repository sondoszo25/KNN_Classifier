#include "Myvector.h"
#include <cmath>
#include <string>
#include <iostream>
/******************
 * Function Name: Vectors ctor.
 * Input: 2 vectors
 * Output: object type Vectors
 * Function Operation: initallizing Vectors.
 ******************/
Vectors::Vectors(vector<double> v3, vector<double> v4) : v1(v3), v2(v4)
{
}
/******************
 * Function Name: Vectors ctor
 * Input: 2 vectors and their types as string
 * Output: Vectors object which contain the input data.
 * Function Operation: makes Vectors object.
 ******************/
Vectors::Vectors(vector<double> v3, vector<double> v4, string s, string ss, int k) : v1(v3), v2(v4), kind(s), typedis(ss), Knum(k)
{
    setDistance();
}
/******************
 * Function Name: Vectors default ctor
 * Input: none
 * Output: Vectors object
 * Function Operation: initialize Vectors object.
 *****************/
Vectors::Vectors()
{
}
/******************
 * Function Name: getDistance()
 * Input: none
 * Output: distance between both vectors in the class
 * Function Operation: returns the distance depends on user's input
 ******************/
double Vectors::getDistance()
{
    return this->distance;
}
/******************
 * Function Name: getKind()
 * Input: none
 * Output: string type of the vector/flower
 * Function Operation: returns kind
 ******************/
string Vectors::getKind()
{
    return this->kind;
}
/******************
 * Function Name: setDistance()
 * Input: string represent type of distance
 * Output: void
 * Function Operation: sets the type of distance
 ******************/
void Vectors::setDistance(string s)
{
    if (!(s.compare("MAN")))
    {
        this->distance = funcMnhaten();
    }
    else if (!(s.compare("AUC")))
    {
        this->distance = funcaOkled();
    }
    else if (!(s.compare("CHB")))
    {
        this->distance = funcCheb();
    }
    else if (!(s.compare("CAN")))
    {
        this->distance = funCanbra();
    }
    else if (!(s.compare("MIN")))
    {
        this->distance = funcMenevoske();
    }
    else
    {
        this->distance = funcMnhaten();
    }
}
/******************
 * Function Name: setDistance()
 * Input: void
 * Output: void
 * Function Operation: set the distance type while initializing
 ******************/
void Vectors::setDistance()
{
    if (!(typedis.compare("MAN")))
    {
        this->distance = funcMnhaten();
    }
    else if (!(typedis.compare("AUC")))
    {
        this->distance = funcaOkled();
    }
    else if (!(typedis.compare("CHB")))
    {
        this->distance = funcCheb();
    }
    else if (!(typedis.compare("CAN")))
    {
        this->distance = funCanbra();
    }
    else if (!(typedis.compare("MIN")))
    {
        this->distance = funcMenevoske();
    }
    else
    {
        this->distance = funcMnhaten();
    }
}
/******************
 * Function Name: funcaOkled
 * Input: no input
 * Output: the distance between the 2 vectors in the Vectors.
 * Function Operation: calculate the distance between the 2 vectors according to Euclidean distance.
 ******************/
double Vectors::funcaOkled()
{
    double sum = 0;
    for (vector<double>::iterator i = v1.begin(), j = v2.begin(); i != v1.end() && j != v2.end(); i++, j++)
    {
        sum = sum + pow((*j) - (*i), 2);
    }
    return sqrt(sum);
}

/******************
 * Function Name: funCanbra
 * Input: no input
 * Output: the distance between the 2 vectors in the Vectors.
 * Function Operation: calculate the distance between the 2 vectors according to Canberra distance.
 ******************/
double Vectors::funCanbra()
{
    double sum = 0;
    for (vector<double>::iterator i = v1.begin(), j = v2.begin(); i != v1.end() && j != v2.end(); i++, j++)
    {
        if (!(*i == 0 && *j == 0))
        {
            sum = sum + (abs(((*i) - (*j)))) / (((abs(*i) + abs(*j))));
        }
    }
    return sum;
}
/******************
 * Function Name: funcCheb
 * Input: no input
 * Output: the distance between the 2 vectors in the Vectors.
 * Function Operation: calculate the distance between the 2 vectors according to Chebyshev distance
 ******************/
double Vectors::funcCheb()
{
    double max = 0;
    for (vector<double>::iterator i = v1.begin(), j = v2.begin(); i != v1.end() && j != v2.end(); i++, j++)
    {
        if (*i > *j)
        {
            if (*i - *j >= max)
            {
                max = *i - *j;
            }
        }
        else if (*j - *i >= max)
        {
            max = *j - *i;
        }
    }
    return max;
}
/******************
 * Function Name: funcMenevoske
 * Input: no input
 * Output: the distance between the 2 vectors in the Vectors.
 * Function Operation: calculate the distance between the 2 vectors according to  Minkowski distance.
 ******************/
double Vectors::funcMenevoske()
{
    double sum = 0;
    for (vector<double>::iterator i = v1.begin(), j = v2.begin(); i != v1.end() && j != v2.end(); i++, j++)
    {
        sum = sum + pow((*i) - (*j), 2);
    }
    return sqrt(sum);
}

/******************
 * Function Name: funcMnhaten
 * Input: no input
 * Output: the distance between the 2 vectors in the Vectors.
 * Function Operation: calculate the distance between the 2 vectors according to Taxicab geometry (manhaten).
 ******************/
double Vectors::funcMnhaten()
{
    double sum = 0;
    for (vector<double>::iterator i = v1.begin(), j = v2.begin(); i != v1.end() && j != v2.end(); i++, j++)
    {
        if ((*i) > (*j))
        {
            sum = sum + (*i) - (*j);
        }
        else
        {
            sum = sum + ((*j) - (*i));
        }
    }
    return sum;
}
/******************
 * Function Name: Types() ctor
 * Input: string & int
 * Output: types object
 * Function Operation: return type object
 ******************/
Types ::Types(string t) : quantity(1), type(t) {}
/******************
 * Function Name: getQuantity()
 * Input: none
 * Output: int
 * Function Operation: returns how much quantity of that type.
 ******************/
int Types ::getQuantity()
{
    return this->quantity;
}
/******************
 * Function Name: Types() default ctor
 * Input: none
 * Output: Types object
 * Function Operation: default ctor
 ******************/
Types ::Types()
{
}
/******************
 * Function Name: getTyoe()
 * Input: none
 * Output: string
 * Function Operation: returns type of the flower
 ******************/
string Types ::getType()
{
    return this->type;
}
/******************
 * Function Name: incQuantity()
 * Input: none
 * Output: void
 * Function Operation: increase the quantity by 1.
 ******************/
void Types ::incQuantity()
{
    this->quantity = this->quantity + 1;
}