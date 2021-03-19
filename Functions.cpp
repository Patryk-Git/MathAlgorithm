#include <iostream>
#include <string>
#include <vector>

using namespace std;

int IsZeroFunction(int power[], int value[], int zeroIndex[], int tabSize){
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
void PrintFunction(int power[], int value[], int constantTerm, int tabSize){
    string function = "";
    int *zeroIndex = new int[tabSize];
    IsZeroFunction(power, value, zeroIndex, tabSize);
    printf("Twoja funkcja to: \n");
    for(int i = tabSize; i >= 0; i--){

        if(value[i] > 0 && zeroIndex[i] != -1){
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
        }else if(value[i] < 0 && zeroIndex[i] != -1 && constantTerm != 0){
            function += to_string(value[i]) + "x^^" + to_string(power[i]) + " ";
        }
    }
    cout << function;
}
int HornerPointValue(){

    int a,b, NextToXValue, constantTerm;
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
    for(int i = 0; i < a; i++){
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
    PrintFunction(power, value, constantTerm, a);
}


