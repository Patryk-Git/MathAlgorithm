#include "Functions.cpp"

void PrintFunction(int power[], int value[], int constantTerm);
void HornerPointValue(int power[], int value[], int firstPower, int nextToXValue, int constantTerm);
int IsZeroValue(int power[], int value[], int zeroIndex, int tabSize);
float CalculatePoint(int power[], int value[], int tabSize, int constantTerm);
int GetValue();