#include "8.cpp"
#include "7.cpp"
#include "ex_3.cpp"
#include <iostream>
#include <cstring> 
using namespace std;
void main()
{
    char s[10];
    while(true)
    {
        cout << "Enter exit ,for exit \nEnter name person who done exercise for get in his programm\n";
        cout << "What do you want? ";
        gets_s(s);
        if (!strcmp(s, "exit"))
			return;
		else  if(!strcmp(s, "Egor"))
			main1();
        else  if(!strcmp(s, "Ann"))
            main2();
        else if(!strcmp(s, "Alex"))
            main3();
    }
}