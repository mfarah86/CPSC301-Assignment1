#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include "person.h"
using namespace std;

int numLines();
PERSON * readData(const int N);
void customerEntry(string &name, float &amount);
void validEntry(const string &name);
void Deposit(PERSON *arr, const int N, const string custName, const float amount);
void FindRichest(const PERSON *arr, const int N);
void Display(PERSON *arr, const int N);
void NewCopy(PERSON *arr, const int N);

int main()
{
  int numRecords;
  PERSON * pPointer;
  string name;
  float amount;
  numRecords = numLines();
  pPointer = readData(numRecords);
  Display(pPointer, numRecords);
  FindRichest(pPointer, numRecords);
  customerEntry(name, amount);
  Deposit(pPointer, numRecords, name, amount);
  customerEntry(name, amount);
  Deposit(pPointer, numRecords, name, amount);
  FindRichest(pPointer, numRecords);
  NewCopy(pPointer, numRecords);

  delete pPointer;

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
    numRecords++;
  }
  numRecords--;
  inData.close();
  return numRecords;
}

PERSON * readData(const int N)
{
  PERSON * personPointer;
  personPointer = new PERSON[N];

  ifstream inData;
  string first;
  string last;
  string full;

  inData.open("data.txt");
  inData >> first;
  for (int i=0; i < N; i++)
  {
    inData >> last;
    full = first + " " + last;  //scanf("%9s", first) + " " + scanf("%10s", last);
    strcpy(personPointer[i].Name, full.c_str());
    inData >> personPointer[i].Balance;
    inData >> first;
  }
  inData.close();

  return personPointer;
}

void customerEntry(string &name, float &amount)
{
  string first;
  string last;
  cout << "Enter your first name: ";
  cin >> first;
  cin.clear();
  cout << "Enter your last name: ";
  cin >> last;
  cin.clear();
  cout << "Enter the deposit amount: ";
  cin >> amount;
  cin.clear();
  name = first + " " + last;
}

void Deposit(PERSON *arr, const int N, const string custName, const float amount)
{
  string name;

  for(int i = 0; i < N ; i++)
  {
    name = arr[i].Name;
    if(name==custName)
    {
      arr[i].Balance = arr[i].Balance + amount;
    }
  }

}

void FindRichest(const PERSON *arr, const int N)
{
  float highest = 0;
  float amount = 0;

  for(int i = 0; i < N ; i++)
  {
    amount = arr[i].Balance;
    if(highest<amount)
    {
      highest = amount;
    }

}

void Display(PERSON *arr, const int N)
{
  cout << setw(20) << left << "Name" << setw(15) << left << "Balance" << endl;
  for (int i=0; i < N; i++)
    {
      cout << setw(20) << left << arr[i].Name << " " << setw(15) << left << arr[i].Balance << endl;
    }
}

void NewCopy(PERSON *arr, const int N)
{

}
