#include "Command.h"
#include "Myvector.h"
#include "Data.h"
#include <iostream>

Command::Command()
{
}
void Command2::setK(int k1)
{
  this->k = k1;
}

void Command2::setTypdis(string s)
{
  this->typdis = s;
}

string Command2::getTypdis()
{
  return this->typdis;
}

int Command2::getK()
{
  return this->k;
}

Command2::Command2(DefaultIO *t)
{
  this->dio = t;
  this->descrpiton = "2. algorithm settings";
}

void Command2::Execute()
{
  string output = "The current KNN parameters are: K = ";
  output.append(to_string(k));
  output.append(", distance metric = ");
  output.append(typdis);
  dio->write(output);
  string input;
  input = dio->read();
  if(!input.empty()){
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
    flag = 1;
  }
  if (data1.getString() == "MAN" || data1.getString() == "CAN" || data1.getString() == "CHB" || data1.getString() == "MIN" || data1.getString() == "AUC")
  {
    flag1 = 1;
  }
  if (flag1==1 && flag==1)
  {
    k = data1.getVector().at(0);
    typdis = data1.getString();
    dio->write("valid");
    return;
  }
  else if (flag == 0 && flag1 == 0)
  {
    output2 = "invaild value for metric and invaild valur for k";
  }
  else if (flag == 0)
  {
    output2 = "invaild value for k";
  }
  else
  {
    output2 = "invaild value for metric";
  }
  dio->write(output2);
  }
  return;
}

Command1::Command1(DefaultIO*t)
{
  //this->filevector=new Filevector();
  dio=t;
  this->descrpiton="upload an unclassified csv data file";
}

Command1::~Command1()
{
  //delete(filevector);
}

void Command1::Execute()
{
    dio->write("please upload your local train csv file.");
}