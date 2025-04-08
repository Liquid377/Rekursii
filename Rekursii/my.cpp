#include <iostream>
#include <string>
#include <fstream>

#include "windows.h"
#include "math.h"

using namespace std;

string GpFile(int);

void ReadFromFile(string);
void WriteInFile(string, string);



double CalculateSum(int);
double CalculateSumHelper(int, double, double);
double Check(int);

void help();
void about();

int iMenu();