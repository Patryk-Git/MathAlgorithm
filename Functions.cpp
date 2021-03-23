#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetValue(){
     int firstPower, NextToXValue, constantTerm;
    printf("Podaj wartosc najwyzszej potegi: ");
    cin >> firstPower;
    if(firstPower==0){
        while(firstPower <= 0){
            printf("Pierwsza potega nie moze wynosic 0!");
            cin >> firstPower;
        }
    }
    printf("Podaj liczbe stojaca przed x do potegi %d: ", firstPower);
    cin >> NextToXValue;
    if(NextToXValue==0){
        while(NextToXValue <= 0){
            printf("Pierwsza wartosc przy x nie moze wynosic 0!\nPodaj jeszcze raz! " );
            cin >> NextToXValue;
        }
    }

    return firstPower, NextToXValue, constantTerm;
}

float CalculatePoint(int power[], int value[], int tabSize, int constantTerm){
    
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
    return result;
}

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
    cout << function << endl;
    for (int i = 0; i < tabSize; i++ ){
        cout << value[i];
    }
    cout << "\n\n\n";
    for (int i = 0; i < tabSize; i++ ){
        cout << power[i];
    }

}
void HornerPointValue(int power[], int value[], int firstPower, int nextToXValue, int constantTerm){

    int b;
    for(int i = 0; i < firstPower; i++){
        power[i] = 0;
        value[i] = 0;
    }
    power[firstPower-1] = firstPower;
    value[firstPower-1] = nextToXValue;
    for(int i=1; i<firstPower; i++){
        printf("Podaj nastepna potege x: ");
        cin >> b;
        if(b > 0) power[firstPower-1] = b;
        printf("Podaj liczba stojaca przy tym x: ");
        cin >> nextToXValue;
        value[firstPower-1] = nextToXValue;
        if(b <= 1) break;
    }
    printf("Podaj wyraz wolny: ");
    cin >> constantTerm;
    PrintFunction(power, value, constantTerm, firstPower);
    
    printf("Wartosc w punkcie wynosi: %.2f", CalculatePoint(power, value, firstPower, constantTerm));
}


