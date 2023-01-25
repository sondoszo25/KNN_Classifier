#include "Command.h"
#include "Myvector.h"
#include "Data.h"
#include <iostream>
#include "Filesave.h"
/******************
* Function Name: default ctor
* Input: none
* Output: none
* Function Operation: ctor for command
******************/
Command::Command()
{
}
/******************
* Function Name: command2.setK()
* Input: int k
* Output: void
* Function Operation: set k = num of neighbours.
******************/
void Command2::setK(int k1)
{
  this->k = k1;
}
/******************
* Function Name: command2.setTypdis
* Input: string
* Output: void
* Function Operation: set string
******************/
void Command2::setTypdis(string s)
{
  this->typdis = s;
}
/******************
* Function Name: getTypdis()
* Input: none
* Output: string
* Function Operation:  return string type
******************/
string Command2::getTypdis()
{
  return this->typdis;
}
/******************
* Function Name: getK
* Input: none
* Output: int 
* Function Operation: returns k
******************/
int Command2::getK()
{
  return this->k;
}
/******************
* Function Name: command2 ctor
* Input: DefaultIO
* Output: command2
* Function Operation: ctor
******************/
Command2::Command2(DefaultIO *t)
{
  this->dio = t;
  this->descrpiton = "2. algorithm settings";
}
/******************
* Function Name: execute
* Input: none
* Output: void
* Function Operation: executing command2
******************/
void Command2::Execute()
{
  string output = "The current KNN parameters are: K = ";
  output.append(to_string(k));
  output.append(", distance metric = ");
  output.append(typdis);
  dio->write(output);
  string input;
  input = dio->read();
  if (!input.empty())
  {
    string s;
    vector<double> v1;
    char delim[1];
    int flag89 = 0;
    delim[0] = ' ';
    MakeData data1(input, delim, v1, 36, s);
    string output2;
    int flag = 0;
    int flag1 = 0;
    if (data1.makeInput())
    {
      if (data1.getVector().at(0) > 0)
      {
        flag = 1;
      }
    }
    if (data1.getString() == "MAN" || data1.getString() == "CAN" || data1.getString() == "CHB" || data1.getString() == "MIN" || data1.getString() == "AUC")
    {
      flag1 = 1;
    }
    if (flag1 == 1 && flag == 1)
    {
      k = data1.getVector().at(0);
      typdis = data1.getString();
      dio->write("valid");
      return;
    }
    else if (flag == 0 && flag1 == 0)
    {
      output2 = "invaild value for metric and invaild value for K";
    }
    else if (flag == 0)
    {
      output2 = "invaild value for K";
    }
    else
    {
      output2 = "invaild value for metric";
    }
    dio->write(output2);
  }
  return;
}
/******************
* Function Name: command1 ctor
* Input: DefaultIO
* Output: command1
* Function Operation: ctor for command1
******************/
Command1::Command1(DefaultIO *t)
{
  this->filevector = new Filevector();
  dio = t;
  this->descrpiton = "upload an unclassified csv data file";
}
/******************
* Function Name: command1 dtor
* Input: none
* Output: 
* Function Operation: deleting command1
******************/
Command1::~Command1()
{
  delete (filevector);
}
/******************
* Function Name: execute
* Input: none
* Output: void
* Function Operation: command1 execute
******************/
void Command1::Execute()
{
  flag3 = 0;
  filevector->getlistvector()->clear();
  filevector->getlisttest()->clear();
  filevector->getlistclass()->clear();
  dio->write("Please upload your local train CSV file.");
  string read;
  while (1)
  {
    read = dio->read();
    if (read == "finish")
    {
      dio->write("upload complete.");
      break;
    }
    else if (read == "finish1")
    {
      break;
    }
    else
    {
      filevector->addvlist(read);
    }
  }
  dio->write("Please upload your local test CSV file.");
  while (1)
  {
    read = dio->read();
    if (read == "finish")
    {
      dio->write("upload complete.");
      break;
    }
    else if (read == "finish1")
    {
      break;
    }
    else
    {
      filevector->addvtest(read);
    }
  }
}
/******************
* Function Name: 
* Input:
* Output:
* Function Operation:
******************/
Filevector *Command1::getf()
{
  return this->filevector;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
Filevector *Command3::getf()
{
  return this->filevector;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
Command3::Command3(DefaultIO *t)
{
  dio = t;
  this->descrpiton = "classify data";
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command3::setK(int k1)
{
  this->k = k1;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command3::setTypdis(string s)
{
  this->typdis = s;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
string Command3::getTypdis()
{
  return this->typdis;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
int Command3::getK()
{
  return this->k;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command3::setf(Filevector *s)
{
  this->filevector = s;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command3::Execute()
{

  if (filevector == nullptr)
  {
    dio->write("please upload data");
    return;
  }
  if (filevector->getlisttest()->size() == 0 || filevector->getlistvector()->size() == 0)
  {
    dio->write("please upload data");
    return;
  }
  if (k > filevector->getlistvector()->size())
  {
    k = filevector->getlistvector()->size();
  }
  filevector->getlistclass()->clear();
  this->flag3 = 1;
  for (std::list<string>::iterator i = filevector->getlisttest()->begin(); i != filevector->getlisttest()->end(); ++i)
  {
    string s;
    vector<double> v1;
    char delim[1];
    int flag89 = 0;
    delim[0] = ',';
    MakeData data1(*i, delim, v1, 16, s);
    if (data1.makeInput() == 0)
    {
      continue;
    }
    int sizeVec = 0;
    int indexMax = 0;
    int indexFile = 0;
    string line;
    Vectors *vecArray = new Vectors[k];
    int ctest = 0;
    for (std::list<string>::iterator j = filevector->getlistvector()->begin(); j != filevector->getlistvector()->end(); ++j)
    {

      if ((*j).length() == 0)
      {
        continue;
      }
      string kind;
      vector<double> v2;
      char delim2[1];
      delim2[0] = ',';
      MakeData data2(*j, delim2, v2, 1, kind);
      if (data2.makeInput())
      {
        Vectors f(data1.getVector(), data2.getVector(), data2.getString(), typdis, k);
        if (sizeVec < k)
        {
          vecArray[sizeVec] = f;
          sizeVec++;
        }
        if (indexFile >= k)
        {
          indexMax = 0;
          for (int i = 0; i < sizeVec; i++)
          {
            if (vecArray[i].getDistance() > vecArray[indexMax].getDistance())
            {
              indexMax = i;
            }
          }
          if (f.getDistance() < vecArray[indexMax].getDistance())
          {
            vecArray[indexMax] = f;
          }
        }
        indexFile++;
      }
      else
      {
        continue;
      }
    }
    Types *typesArray = new Types[sizeVec];
    int sizeTypes = 0;

    for (int ii = 0; ii < sizeVec; ii++)
    {
      if (ii == 0)
      {
        Types t(vecArray->getKind());
        typesArray[0] = t;
        sizeTypes++;
        continue;
      }
      int flag12 = 0;
      for (int jj = 0; jj < sizeTypes; jj++)
      {
        if (vecArray[ii].getKind() == typesArray[jj].getType())
        {
          typesArray[jj].incQuantity();
          flag12 = 1;
          break;
        }
      }
      if (flag12 == 0)
      {
        Types t(vecArray[ii].getKind());
        typesArray[sizeTypes] = t;
        sizeTypes++;
      }
    }
    int maxIndexT = 0;
    for (int jjj = 0; jjj < sizeTypes; jjj++)
    {
      if (typesArray[jjj].getQuantity() > typesArray[maxIndexT].getQuantity())
      {
        maxIndexT = jjj;
      }
    }
    filevector->addc(typesArray[maxIndexT].getType());
    dio->write(typesArray[maxIndexT].getType());
    delete[] typesArray;
    delete[] vecArray;
  }
  dio->write("classifying data complete");
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command4::setf(Filevector *s)
{
  this->filevector = s;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
Command4::Command4(DefaultIO *t)
{
  dio = t;
  this->descrpiton = "display results";
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command4::Execute()
{
  if (this->filevector != NULL)
  {
    if (filevector->getlisttest()->size() == 0 || filevector->getlistvector()->size() == 0)
    {
      dio->write("please upload data");
      return;
    }
    if (filevector->getlistclass()->size() == 0)
    {
      dio->write("please classify the data");

      return;
    }
    for (std::list<string>::iterator j = filevector->getlistclass()->begin(); j != filevector->getlistclass()->end(); ++j)
    {
      dio->write(*j);
    }
    dio->write("Done.");
  }
  else
  {
    dio->write("please upload data");
  }
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
Command5::Command5(DefaultIO *t)
{
  dio = t;
  this->descrpiton = "download results";
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command5::setf(Filevector *s)
{
  this->filevector = s;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command5::Execute()
{
  if (this->filevector != NULL)
  {
    if (filevector->getlisttest()->size() == 0 || filevector->getlistvector()->size() == 0)
    {
      dio->write("please upload data");
      return;
    }
    if (filevector->getlistclass()->size() == 0)
    {

      dio->write("please classify the data");
      return;
    }
    dio->write("Done.");
  }
  else
  {
    dio->write("please upload data");
  }
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
int Command3::getflag()
{
  return this->flag3;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command4::setflag(int f)
{
  this->flag3 = f;
}
/******************
* Function Name:
* Input:
* Output:
* Function Operation:
******************/
void Command5::setflag(int f)
{
  this->flag3 = f;
}