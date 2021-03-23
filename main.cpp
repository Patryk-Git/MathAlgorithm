#include <iostream>
#include "head.h"
#include <vector>

using namespace std;

int main(){
   

    int a, NextToXValue, constantTerm;
    a, NextToXValue, constantTerm = GetValue();
    int *power = new int[a];
    int *value = new int[a];
    HornerPointValue(power, value, a, NextToXValue, constantTerm);
    return 0;
}