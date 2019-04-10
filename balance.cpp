#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

struct  Person {
char  Name[20];
float Balance; };

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
      cout << "New Balance: " << fixed << setprecision(2) << arr[i].Balance << endl;
      break;
    }
    if(i == N-1)
    {
      if(custName != name)
      {
        cout << "Record Not Found..." << endl;
      }
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

  for(int i = 0; i < N ; i++)
  {
    if(highest==arr[i].Balance)
    {
      cout << "Highest Paid: " << arr[i].Name << " " << fixed << setprecision(2) << arr[i].Balance << endl;
    }
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
  ofstream outFile;
  outFile.open("data.txt");
  for(int i = 0; i < N ; i++)
  {
    outFile << arr[i].Name << " " << arr[i].Balance << endl;
  }
  outFile.close();
  cout << "File Updated..." << endl;
}
