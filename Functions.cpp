#include <iostream>
#include <string>
#include <vector>

using namespace std;


float CalculatePoint(int *power, int *value, int tabSize, int constantTerm){
    
    int point;
    tabSize -= 1;
    float result = value[tabSize];
    printf("Podaj dla jakiego punktu chcesz obliczc wartsc: ");
    //Zabezpiecz!
    cin >> point;
    for(int i = tabSize; i >= 0; i--){
        if(i!=0){
            result = (result*point) + value[i-1];
        }else{
            result = (result*point) + constantTerm;
        }
    }
    cout << "Wartosc dla punktu wynosi: " << result << endl;
}

int IsZeroFunction(int *power, int *value, int *zeroIndex, int tabSize){
    bool isZero = false;
    for(int i = 0; i < tabSize; i++){
        if(power[i] == 0 || value[i] == 0){
            isZero = true;
            break;  
        }
    }
    if(isZero){
        for(int i = 0; i < tabSize; i++){
            if(power[i] == 0 || value[i] == 0){
                zeroIndex[i] = -1;
            }else zeroIndex[i] = 1;
        }
    }
}

void PrintFunction(int *power, int *value, int constantTerm, int tabSize, bool check){
    string function = "";
    int *zeroIndex = new int[tabSize];
    IsZeroFunction(power, value, zeroIndex, tabSize);
    printf("Twoja funkcja to: \n");
    for(int i = tabSize; i >= 0; i--){

        if(value[i] > 0 && zeroIndex[i] != -1 && power[i] > 0){
            if(i!=0){
                 function += to_string(value[i]) + "x^^" + to_string(power[i]) + " + ";
            }
            else if(i == 0){
                if(constantTerm < 0){
                    function += to_string(value[i]) + "x^^" + to_string(power[i]) + " "  + to_string(constantTerm);
                }else if(constantTerm != 0){
                    function += to_string(value[i]) + "x^^" + to_string(power[i]) + " + "  + to_string(constantTerm);
                }else if(constantTerm == 0){
                     function += to_string(value[i]) + "x^^" + to_string(power[i]);
                }
            }
        }
        else if(value[i] < 0 && zeroIndex[i] != -1 && constantTerm != 0){
            function += to_string(value[i]) + "x^^" + to_string(power[i]) + " ";
        }
    }
    if(!check){
        cout << function;
    }else{
        function += to_string(constantTerm);
        cout << function;
    }
    
    delete zeroIndex;
}

void Divide(int *power, int* value, int tabSize, int constantTerm, int val){
    
    int *newValue = new int[tabSize-1];  
    int *newPower = new int[tabSize-1];
    int *isZero = new int[tabSize-1]; 
    bool check = true; 
    int temp = value[tabSize-1];
    for(int i = 0; i <= tabSize; i++){
        newValue[i] = 1;
        newPower[i] = 0;
    }
    newValue[tabSize] = temp;
    for(int i = tabSize-1; i > 0; i--){
            if(power[i-1] > 0) {newPower[i] = power[i-1];}
            temp = (val * temp) + value[i-1];
            newValue[i-1] = temp;
    }
    PrintFunction(newPower, newValue, temp, tabSize-1, check);
    int change = (val * temp) + constantTerm;
    if(check != 0){
         cout << "\nReszta wynosi: " << check << endl;
     }

     delete newValue, newPower, isZero;
}


int HornerPointValue(){

    int a, b, NextToXValue, constantTerm;
    printf("Podaj wartosc najwyzszej potegi: ");
    cin >> a;
    if(a==0){
        while(a <= 0){
            printf("Pierwsza potega nie moze wynosic 0!");
            cin >> a;
        }
    }
    printf("Podaj liczbe stojaca przed x do potegi %d: ", a);
    cin >> NextToXValue;
    if(NextToXValue==0){
        while(NextToXValue <= 0){
            printf("Pierwsza wartosc przy x nie moze wynosic 0!\nPodaj jeszcze raz! " );
            cin >> NextToXValue;
        }
    }
    int *power =  new int[a];
    int *value = new int[a];
    for(int i = 0; i <= a; i++){
        power[i] = 0;
        value[i] = 1;
    }
    power[a-1] = a;
    value[a-1] = NextToXValue;
    for(int i=1; i<a; i++){
        printf("\nPodaj nastepna potege x: ");
        cin >> b;
        if(b > 0) power[b-1] = b;
        printf("\nPodaj liczba stojaca przy tym x: ");
        cin >> NextToXValue;
        value[b-1] = NextToXValue;
        if(b <= 1) break;
    }
    printf("Podaj wyraz wolny: ");
    cin >> constantTerm;
    PrintFunction(power, value, constantTerm, a, false);
    cout << endl;
    CalculatePoint(power, value, a, constantTerm);
    Divide(power, value, a, constantTerm, 2);

    delete power, value;
}



