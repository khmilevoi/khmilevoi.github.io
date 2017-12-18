#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <cctype>
using namespace std;

struct Tbuilding {
    char name[100];
    char city[100];
    int amountRooms;
    double price;
};

void main() {

    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i;
    int count_build;
    char str[100];

    do {
        cout << "??????? ???. ?????: ";
        cin >> count_build;
        cin.get();
	} while (count_build <= 0);

    cout << "????????? ?????? ? ??????????: " << endl;

    Tbuilding *BUILD = new Tbuilding[count_build];
    for(i = 0; i < count_build; ++i) {

        Tbuilding appartment;
        int n = i + 1;

        cout << "??????? ??? ?????? ?" << n << ": ";
        cin.getline(appartment.name, 99);

        cout << "??????? ???????? ?????? ?" << n << ": ";
        cin.getline(appartment.city, 99);
        
        cout << "??????? ???. ?????? ? ???????? ?" << n << ": ";
        cin.getline(str, 99);
        appartment.amountRooms = atoi(str);

        cout << "??????? ????????? ???????? ?" << n << ": ";
        cin.getline(str, 99);
        appartment.price = atof(str);

        BUILD[i] = appartment;

        cout << endl;

    }

    ofstream building("build.txt");

    building << setw(20) << "???" << setw(15) << "?????" << setw(15) << "???. ??????" << setw(15) << "?????????" << endl;
    cout << setw(20) << "???" << setw(15) << "?????" << setw(15) << "???. ??????" << setw(15) << "?????????" << endl;
    
    for(i = 0; i < count_build; ++i) {

    building << setw(20) << BUILD[i].name << setw(15) << BUILD[i].city << setw(15) << BUILD[i].amountRooms << setw(15) << BUILD[i].price << endl;
    cout << setw(20) << BUILD[i].name << setw(15) << BUILD[i].city << setw(15) << BUILD[i].amountRooms << setw(15) << BUILD[i].price << endl;            

    }

    system("pause");
}