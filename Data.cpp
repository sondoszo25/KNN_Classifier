#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <regex.h>
#include <cstring>
#include <string>
using namespace std;

/******
* Function Name: match
* Input: const char *string, char *pattern
* Output: if there is a match return 1 else 0
* Function Operation: checks if the string matches the pattern if there is
match return 1 else 0.
******/
int MakeData::match(const char *string, char *pattern)
{
    int status;
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0)
    {
        return 0;
    }
    status = regexec(&re, string, (size_t)0, NULL, 0);
    regfree(&re);
    if (status != 0)
    {
        return 0;
    }
    return 1;
}
/******************
 * Function Name: makeInput()
 * Input: none
 * Output: 0 or 1
 * Function Operation: if the input is legal return 1 else 0.
 ******************/
int MakeData::makeInput()
{
    string sreg = "^(^[+-]?(\\.)([0-9]+)((E|e)[+-]?([0-9]+))?$)|(^[+-]?([0-9]+)((\\.)([0-9]+))?((E|e)[+-]?([0-9]+))?$)$";
    string filename;
    string typedis;
    char myreg[sreg.length() + 1];
    strcpy(myreg, sreg.c_str());
    int flag1 = 0;
    char charArray[input.length() + 1];
    strcpy(charArray, input.c_str());
    for (int i = 0; i < input.length(); i++)
    {
        if (charArray[input.length() - 1] == ' ')
        {
            flag1 = 1;
        }
        if (charArray[0] == ' ')
        {
            flag1 = 1;
        }
        if (i < input.length())
        {
            if (charArray[i] == ' ' && charArray[i + 1] == ' ')
            {
                flag1 = 1;
            }
        }
    }
    if (flag9 == 566)
    {
        char *token = strtok(charArray, ",");
        while (token != NULL)
        {
            if (match(token, myreg))
            {
                v.push_back(stod(token));
            }
            else
            {
                flag1 = 1;
                break;
            }
            token = strtok(NULL, ",");
        }
    }
     if (flag9 == 0)
    {
        char *token = strtok(charArray, " ");
        while (token != NULL)
        {
            if (match(token, myreg))
            {
                v.push_back(stod(token));
            }
            else
            {
                flag1 = 1;
                break;
            }
            token = strtok(NULL, " ");
        }
    }
    else if (flag9 == 1)
    {
        int count = 0;
        char charArray2[input.length() + 1];
        strcpy(charArray2, charArray);
        char *token = strtok(charArray, ",");
        while (token != NULL)
        {
            count++;
            token = strtok(NULL, ",");
        }
        char *token2 = strtok(charArray2, ",");
        if (count == 1)
        {
            flag1 = 1;
            return 0;
        }
        while (count > 1 && token2 != NULL)
        {
            count--;
            if (match(token2, myreg))
            {
                v.push_back(stod(token2));
            }
            else
            {
                flag1 = 1;
                return 0;
                break;
            }
            token2 = strtok(NULL, ",");
        }
        kind = token2;
    }
    else if (flag9 == 2)
    {
        int count = 0;
        char charArray2[input.length() + 1];
        strcpy(charArray2, charArray);
        char *token = strtok(charArray, " ");
        while (token != NULL)
        {
            count++;
            token = strtok(NULL, " ");
        }
        char *token2 = strtok(charArray2, " ");
        if (count <= 2)
        {
            flag1 = 1;
            return 0;
        }
        while (count > 2 && token2 != NULL)
        {
            count--;
            if (match(token2, myreg))
            {
                v.push_back(stod(token2));
            }
            else
            {
                flag1 = 1;
                return 0;
                break;
            }
            token2 = strtok(NULL, " ");
        }
        typdis = token2;
        token2 = strtok(NULL, " ");
        try
        {
            if (match(token2, myreg))
            {
                knum = stod(token2);
            }
            else
            {
                flag1 = 1;
                return 0;
            }
        }
        catch (exception e)
        {
            flag1 = 1;
        }
    }
    else if (flag9 == 5)
    {
        int count = 0;
        char charArray2[input.length() + 1];
        strcpy(charArray2, charArray);
        char *token = strtok(charArray, ".");
        while (token != NULL)
        {
            count++;
            token = strtok(NULL, ".");
        }
        char *token2 = strtok(charArray2, ".");
        if (count != 4)
        {
            flag1 = 1;
            return 0;
        }
        while (count > 0 && token2 != NULL)
        {
            count--;
            if (match(token2, myreg))
            {
                v.push_back(stod(token2));
            }
            else
            {
                flag1 = 1;
                return 0;
                break;
            }
            token2 = strtok(NULL, ".");
        }
    }

       else if (flag9 == 36)
    {
        int count = 0;
        char charArray2[input.length() + 1];
        strcpy(charArray2, charArray);
        char *token = strtok(charArray, " ");
        while (token != NULL)
        {
            count++;
            token = strtok(NULL, " ");
        }
        char *token2 = strtok(charArray2, " ");
        if (count == 1)
        {
            flag1 = 1;
            return 0;
        }
        while (count > 1 && token2 != NULL)
        {
            count--;
            if (match(token2, myreg))
            {
                v.push_back(stod(token2));
            }
            else
            {
                flag1 = 1;
                return 0;
                break;
            }
            token2 = strtok(NULL, " ");
        }
        kind = token2;
    }
    
    if (flag1 == 1)
    {
        if (flag9 != 1)
        {
            // cout << "v have invaild input" << endl;
        }
        return 0;
    }
    if (flag1 == 1)
    {
        if (flag9 != 1)
        {
            // cout << "v have invaild input" << endl;
        }
        return 0;
    }
    if (v.size() == 0)
    {
        if (flag9 != 1)
        {
            // cout << " v is lenght 0 sorry!" << endl;
        }
        return 0;
    }
    return 1;
}
/******************
 * Function Name: MakeData ctor
 * Input: strings and vector to scan the vector.
 * Output: MakeDAta object
 * Function Operation: initialize the MakeData object.
 ******************/
MakeData::MakeData(string input1, char *delim1, vector<double> v1, int flag99, string kind1) : input(input1), v(v1)
{
    this->delim = delim1;
    this->flag9 = flag99;
    this->kind = kind1;
}
/******************
 * Function Name: getVector()
 * Input: none
 * Output: vector object
 * Function Operation: returns the vector in the right format
 ******************/
vector<double> &MakeData::getVector()
{
    return this->v;
}
/******************
 * Function Name: getString()
 * Input: none
 * Output: string
 * Function Operation: returns type of vector/flower.
 ******************/
string MakeData::getString()
{
    return kind;
}
int MakeData::getk()
{
    return knum;
}
string MakeData::getTypDis()
{
    return typdis;
}