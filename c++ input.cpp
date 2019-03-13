#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "person.h"

using namespace std;

int numLines();
void getRecords(int numRecords, Person record[]);
void printRecords(int numRecords, Person record[]);

int main()
{
  int numRecords;

  numRecords = numLines();

  Person record[numRecords];

  getRecords(numRecords, record);

  printRecords(numRecords, record);

  return 0;
}

int numLines()
{
  string line;
  int numRecords;
  ifstream inData;
  inData.open("data.txt");

  while(!inData.eof())
  {
    getline(inData, line);
    //cout << line << " " << endl;
    numRecords++;

  }
  numRecords--;
  //cout << numRecords << endl;
  inData.close();

  return numRecords;
}

void getRecords(int numRecords, Person record[])
{
  ifstream inData;
  string first;
  string last;
  string full;

  inData.open("data.txt");
  for (int i=0; i < numRecords; i++)
  {
    inData >> first;
    inData >> last;
    full = first + " " + last;
    strcpy(record[i].Name, full.c_str());
    inData >> record[i].Balance;
  }
  inData.close();
}

void printRecords(int numRecords, Person record[])
{
  cout << "Name  |  Balance" << endl;
  for (int i=0; i < numRecords; i++)
    {
      cout << record[i].Name << " " << record[i].Balance << endl;
    }
}
