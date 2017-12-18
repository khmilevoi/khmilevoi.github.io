#include "stdafx.h"
#include <iostream>
#include <cstring> 
#include <vector> 
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
        else  if(!strcmp(s, "Alex"))
            main3();
    }
}

//׀›׀°׀±׀° 5 , ׀²ׁ‚׀¾ׁ€׀¾׀µ ׀·׀°׀´׀°׀½׀¸׀µ 
// ׀ ׀µׁˆ׀¸׀» ׁ€׀°ׁ�ׁ�׀¿׀¸ׁ�׀°ׁ‚ׁ� ׀²ׁ�ׁ‘ , ׁ‡ׁ‚׀¾ ׀±ׁ‹ ׀¿׀¾ׁ‚׀¾׀¼ ׀½׀µ ׀´ׁƒ׀¼׀°ׁ‚ׁ� ׀½׀°**ׁ� ׁ� ׁ�׀·׀°׀» ׁ‚׀µ ׀¸׀»׀¸ ׀¸׀½ׁ‹׀µ ׀±׀¸׀±׀»׀¸׀¾ׁ‚׀µ׀÷׀¸ ׀¸ ׀¿׀µׁ€׀µ׀¼׀µ׀½׀½ׁ‹׀µ


#include <iostream> // ׀´׀»ׁ� ׀²׀²׀¾׀´׀° ׀²ׁ‹׀²׀¾׀´׀°
#include <cstring> //׀´׀»ׁ� gets_s
#include <ctime> // ׀´׀»ׁ� ׁ€׀°׀½׀´׀¾׀¼׀°
using namespace std;

char names[10][10] = {"Hmilewoi", "Grek", "Waloshina", "Artem", "Drozd", "Srefano", "Boris", "Chalow", "Solodov", "Iasik"};
char firma[10][10] = {"Iti", "DrYgiy", "Iakist", "DrYgiy", "Iakist", "Iti", "DrYgiy", "Iakist", "Iti", "DrYgiy"};
 // ׀½׀°ׁˆ ׁ�׀¿׀¸ׁ�׀¾׀÷ ׁ„׀¸ׁ€׀¼ , ׀° ׀²׀²׀µׁ€ׁ…ׁƒ ׀½׀°ׁ� ׁ�׀¿׀¸ׁ�׀¾׀÷ ׀²ׁ�׀µׁ… ׀¸׀¼ׁ‘׀½ ׀¿׀¾ׁ‚׀¾׀¼ׁƒ ׁ‡ׁ‚׀¾ ׁ� ׀¿׀¾׀´׀·׀°׀µ׀±׀°׀»ׁ�ׁ� ׀÷׀°׀¶׀´ׁ‹׀¹ ׁ€׀°׀· ׁ�ׁ‚׀¾ ׀²׀±׀¸׀²׀°ׁ‚ׁ� ׁ€ׁƒׁ‡ׁ‘׀½׀÷׀°׀¼׀¸

struct Bud // ׁ�ׁ‚ׁ€ׁƒ׀÷ׁ€ׁƒׁ€׀° ׁ� ׀½׀°׀·׀²׀°׀½׀¸׀µ׀¼ ׀±ׁƒ׀´(׀±ׁƒ׀´׀¾׀²׀°)
{
	char name[12];//׀¸׀¼ׁ� ׀÷׀»׀¸׀µ׀½ׁ‚׀°
	int type; // ׁ‚׀¸׀¿ ׀±ׁƒ׀´׀¾׀²ׁ‹
	int value; // ׀µׁ‘ ׁ†׀µ׀½׀°
	char phyrm[12]; // ׀½׀°׀·׀²׀°׀½׀¸׀µ ׁ„׀¸ׁ€׀¼ׁ‹
	int pr_credit; // ׀¿ׁ€׀¾ׁ†׀µ׀½ׁ‚ ׀÷ׁ€׀µ׀´׀¸ׁ‚׀° 
	int cache; //ׁ�ׁƒ׀¼׀¼׀° ׀²׀÷׀»׀°׀´׀°
	int dolg; // ׀´׀¾׀»׀³ 
	int ostalos;
};

void zad10(Bud *cust, const int n)
{
	int i, max = 0;
	for(i = 0; i < n; i++)
		if(cust[i].pr_credit > 10)
			if(cust[i].value > max)
				max = cust[i].value;

	for(i = 0; i < n; i++)
		if(max = cust[i].value)
		{
			cout << "Type s naibolshey stoimost :\n" << cust[i].type << endl;
			break;
		}
}

void zad9(Bud *cust, const int n)
{
	int i, min = 10000;
	for(i = 0; i < n; i++)
		if(cust[i].ostalos > 0 && cust[i].ostalos < min) // ׀µׁ�׀»׀¸ ׀½׀µ׀²ׁ‹׀¿׀»׀°ׁ‡׀µ׀½׀½׀°ׁ� ׁ�ׁƒ׀¼׀¼׀° ׀±׀¾׀»ׁ�ׁˆ׀µ ׀½ׁƒ׀»ׁ�(׀½ׁƒ ׁ‚׀¾ ׀µׁ�ׁ‚ׁ� ׀²׀¾׀¾׀±ׁ‰׀µ ׀µׁ�ׁ‚ׁ�) ׀¸ ׀¼׀µ׀½ׁ�ׁˆ׀µ ׀¼׀¸׀½׀¸׀¼ׁƒ׀¼׀° ׁ‚׀¾ ׀·׀°׀¿׀¸ׁ�ׁƒ׀µ׀¼ ׀µׁ‘ ׀² ׀¼׀¸׀½׀¸׀¼ׁƒ׀¼
		 	min = cust[i].ostalos;

	for(i = 0; i < n; i++)
		if(cust[i].ostalos = min) // ׀µׁ�׀»׀¸ ׀½׀µ׀²ׁ‹׀¿׀»׀°ׁ‡׀µ׀½׀½׀°ׁ� ׁ�ׁƒ׀¼׀¼׀° ׁ€׀°׀²׀½׀° ׀½׀°׀¹׀´׀µ׀½׀½׀¾׀¼ׁƒ ׀¼׀¸׀½׀¸׀¼ׁƒ׀¼ׁƒ ׁ‚׀¾ ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׁ„׀¸ׁ€׀¼ׁƒ ׁ�ׁ‚׀¾׀¹ ׁ�ׁƒ׀¼׀¼ׁ‹
		{
			cout << "Phirma y kototoi y klienta minimalnaya neviplachenaya summa :\n" << cust[i].phyrm << endl;
			break;
		}
}

void zad8(Bud *cust, const int n)
{
	int i, max = 0, min = 100; //׀´׀»ׁ� ׀¿׀¾׀¸ׁ�׀÷׀° ׀½׀µ׀¾׀±ׁ…׀¾׀´׀¸׀¼ׁ‹ ׀´׀²׀µ ׀¿׀µׁ€׀µ׀¼׀µ׀½׀½ׁ‹׀µ , ׀½׀°׀¸׀±׀¾׀»ׁ�ׁˆ׀¸׀¹ ׀²׀¾׀·׀¼׀¾׀¶׀½ׁ‹׀¹ ׀¿ׁ€׀¾ׁ†׀µ׀½ׁ‚ ׀¸ ׀½׀°׀¸׀¼׀µ׀½ׁ�ׁˆ׀¸׀¹

	for(i = 0; i < n; i++)
		if(cust[i].pr_credit > max) // ׀¿ׁ€׀¾ׁ�ׁ‚׀¾ ׀¸ׁ‰׀µ׀¼ ׀½׀°׀¸׀±׀¾׀»ׁ�ׁˆׁ‹׀¹ ׀¿ׁ€׀¾ׁ†׀µ׀½ׁ‚
		 	max = cust[i].pr_credit;

	cout << "Naibolshiy procent :" << endl << max << endl; // ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׀µ׀³׀¾

	for(i = 0; i < n; i++)
		if(cust[i].pr_credit <= min) // ׀¿ׁ€׀¾ׁ�ׁ‚׀¾ ׀¸ׁ‰׀µ׀¼ ׀½׀°׀¸׀¼׀µ׀»ׁ�ׁˆ׀¸׀¹ ׀¿ׁ€׀¾ׁ†׀µ׀½ׁ‚
		 	min = cust[i].pr_credit;

	cout << "Naimenshiy procent :" << endl << min << endl; // ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׀µ׀³׀¾
}

void zad7(Bud *cust, const int n)
{
	int i;
	cout << "Klientu s neviplachenoy summoy bolchey vklada :" << endl;
	for(i = 0; i < n; i++)
		if(cust[i].ostalos > cust[i].cache) // ׀µׁ�׀»׀¸ ׀½׀µ׀²ׁ‹׀¿׀»׀°ׁ‡׀µ׀½׀¾ ׀±׀¾׀»ׁ�ׁˆ׀µ ׁ‡׀µ׀¼ ׀µׁ�ׁ‚ׁ� ׀½׀° ׁ�ׁ‡׀µׁ‚ׁƒ, ׁ‚׀¾ ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׀¸׀¼ׁ�
			cout << cust[i].name << endl;
}

void zad6(Bud *cust, const int n)
{
	cout << "Max neviplachena summa :" << endl;
	int i, max = 0;
	for(i = 0; i < n; i++)
		if(cust[i].ostalos > max) // ׀¿ׁ€׀¾ׁ�ׁ‚׀¾ ׀¸ׁ‰׀µ׀¼ ׀½׀°׀¸׀±׀¾׀»ׁ�ׁˆׁƒׁ� ׀½׀µ׀²ׁ‹׀¿׀»׀°ׁ‡׀µ׀½׀½ׁƒׁ� ׁ�ׁƒ׀¼׀¼ׁƒ 
		 max = cust[i].dolg;
	cout << max << endl;
}

void zad5(Bud *cust, const int n)
{
	int i, j = 0;
	cout << "Obschiy dolg :" << endl;

	for(i = 0; i < n; i++)
        j += cust[i].ostalos; // ׁ�ׁƒ׀¼׀¸ׁ€ׁƒ׀µ׀¼ ׀½׀µ׀²ׁ‹׀¿׀»׀°ׁ‡׀µ׀½׀½ׁƒׁ� ׁ�ׁƒ׀¼׀¼ׁƒ ׀÷׀°׀¶׀´׀¾׀³׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀°

    cout << j << " ruskih dollarov" << endl;
}

void zad4(Bud *cust, const int n)
{
	int i;
	int max = 0; // ׀¿׀µׁ€׀µ׀¼׀µ׀½׀½׀°ׁ� ׀´׀»ׁ� ׀¾׀¿ׁ€׀µ׀´׀µ׀»׀µ׀½׀¸ׁ� ׀½׀°׀¸׀±׀¾׀»ׁ�ׁˆ׀µ׀¹ ׁ†׀µ׀½ׁ‹
	cout << "tip kotoriy mnoga stoit :" << endl;
	for(i = 0; i < n; i++) // ׀¾׀¿ׁ€׀µ׀´׀µ׀»ׁ�׀µ׀¼ ׁƒ ׀÷׀°׀÷׀¾׀¹ ׀¿׀¾ׁ�ׁ‚ׁ€׀¾׀¹׀÷׀¸ ׀½׀°׀¸׀±׀¾׀»ׁ�ׁˆ׀°ׁ� ׁ†׀µ׀½׀°
		if(max < cust[i].value)
			max = cust[i].value;

	for(i = 0; i < n; i++)
		if(max == cust[i].value) // ׁ�ׁ€׀°׀²׀½׀¸׀²׀°׀µ׀¼ ׀½׀°׀¸׀±׀¾׀»ׁ�ׁˆׁƒׁ� ׀½׀°׀¹׀´׀µ׀½׀½ׁƒׁ� ׁ†׀µ׀½ׁƒ 
		{
			cout << cust[i].type << endl; // ׀÷׀¾׀³׀´׀° ׀½׀°ׁˆ׀»׀¸, ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׀¿ׁ€׀¸׀²ׁ�׀·׀°׀½׀½ׁ‹׀¹ ׀÷ ׁ�ׁ‚׀¾׀¹ ׁ†׀µ׀½׀µ ׁ‚׀¸׀¿ 
			break; // ׀²ׁ‹ׁ…׀¾׀´׀¸׀¼ ׀¸׀· ׁ†ׁ‹׀÷׀»׀°
		}
}

void zad3(Bud *cust, const int n)
{
	int i, j, b = 0, a[10], q = 1;
	cout << "Tip kotoriy zamovili >2 raz :" << endl;

	for (i = 0; i < n; i++)
		cout << cust[i].type << " "; // ׀´׀»ׁ� ׀¿ׁ€׀¾׀²׀µׁ€׀÷׀¸ , ׀¿׀µׁ€׀µ׀´ ׀¿ׁ€׀¾׀´׀°׀÷ׁˆ׀¸׀½׀¾׀¼ ׀¼׀¾׀¶׀½׀¾ ׀¸ ׁ�ׁ‚׀µׁ€׀µׁ‚ׁ� (׀¿ׁ€׀¾ׁ�ׁ‚ ׀²ׁ‹׀²׀¾׀´׀¸ׁ‚ ׀²ׁ�׀µ ׁ‚׀¸׀¿ׁ‹ ׁ‡ׁ‚׀¾ ׁƒ ׀½׀°ׁ� ׀µׁ�ׁ‚ׁ�)

	for (i = 0; i < n; i++) // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ†׀¸׀÷׀» ׀÷׀¾ׁ‚׀¾ׁ€ׁ‹׀¹ ׀¿ׁ€׀¾׀±׀µ׀¶׀¸ׁ‚ ׀²ׁ�׀µׁ… ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
	{
		for (j = 0; j < n; j++) // ׁ†׀¸׀÷׀» ׀² ׀÷׀¾ׁ‚׀¾ׁ€׀¾׀¼ ׁ�ׁ€׀°׀²׀½׀¸׀²׀°ׁ�ׁ‚ׁ�ׁ� ׀÷׀°׀¶׀´ׁ‹׀¹ ׁ‚׀¸׀¼ ׁ� ׀÷׀°׀¶׀´ׁ‹׀¼ ׁ‚׀¸׀¿׀¾׀¼ ׀¸ ׀µׁ�׀»׀¸ ׀µׁ�ׁ‚ׁ� ׁ�׀¾׀²׀¿׀°׀´׀µ׀½׀¸׀µ ׁ‚׀¾ b ׁƒ׀²׀µ׀»׀¸ׁ‡׀¸׀²׀°׀µׁ‚ׁ�ׁ� ׀½׀° 1
			if (cust[i].type == cust[j].type)
				b++;
		a[i] = b; // ׀÷׀¾׀³׀´׀° ׀¾׀´׀¸׀½ ׁ‚׀¸׀¿ ׁ�ׁ€׀°׀²׀½׀¸׀»ׁ�ׁ� ׁ�׀¾ ׀²ׁ�׀µ׀¼׀¸ ׀¾ׁ�ׁ‚׀°׀»ׁ�׀½ׁ‹׀¼׀¸ , ׀÷׀¾׀»׀¸ׁ‡׀µׁ‚׀²׀¾ ׁ�׀¾׀²׀¿׀°׀´׀µ׀½׀¸׀¹ ׀·׀°׀¿׀¸ׁ�ׁ‹׀²׀°׀µׁ‚ׁ�ׁ� ׀² ׀¼׀°ׁ�ׁ�׀¸׀²
			b = 0;
	}
    cout << endl; //׀½׀¾׀²׀°ׁ� ׁ�ׁ‚ׁ€׀¾׀÷׀°

	for (i = 0; i < n; i++) // ׁ†׀¸׀÷׀» ׀´׀»ׁ� ׀²ׁ‹׀²׀¾׀´׀° ׁ€׀µ׀·ׁƒ׀»ׁ�ׁ‚׀°ׁ‚׀°
		if (a[i] > 2)  // ׀µׁ�׀»׀¸ ׁ�׀¾׀²׀¿׀°׀´׀µ׀½׀¸׀¹ ׀±׀¾׀»ׁ�ׁˆ׀µ ׀´׀²ׁƒׁ… ׁ‚׀¾ ׁ�׀¼׀¾ׁ‚ׁ€׀¸׀¼ ׀´׀°׀»ׁ�ׁˆ׀µ
		{ //׀¼׀¾׀¶׀½׀¾ ׀±ׁ‹׀»׀¾ ׀±ׁ‹ ׀¿ׁ€׀¾ׁ�ׁ‚׀¾ ׀½׀°׀¿׀¸ׁ�׀°ׁ‚ׁ� ׀²ׁ‹׀²׀µׁ�ׁ‚׀¸ ׁ‚׀¸׀¿ , ׀½׀¾ ׁ� ׀½׀µ ׁ…׀¾ׁ‚׀µ׀» ׁ‡ׁ‚׀¾ ׀± ׀¾׀½׀¸ ׀¿׀¾׀²ׁ‚׀¾ׁ€ׁ�׀»׀¸ׁ�ׁ� 
           
		    for (j = 0; j < i; j++)    // ׀¿ׁ€׀¾׀²׀µׁ€ׁ�׀µׁ‚ ׀±ׁ‹׀» ׀»׀¸ ׁ�ׁ‚׀¾ׁ‚ ׁ�׀¸׀¼׀²׀¾׀» ׁ€׀°׀½׀µ׀µ , ׀µׁ�׀»׀¸ ׀±ׁ‹׀» , ׁ‚׀¾ ׀·׀°׀÷׀°׀½ׁ‡׀¸׀²׀°׀µ׀¼ ׁ†׀¸׀÷׀» ׁ�ׁ‚׀¾ׁ‚ ׀¸ q = 0
                if (cust[i].type == cust[j].type) 
                {
                    q = 0;
                    break;
                }
                    
            if(q) // ׀µׁ�׀»׀¸ q = 0 ׁ‚׀¾ ׀¾׀½׀¾ ׀²׀¾ׁ�׀¿׀¿ׁ€׀¸׀½׀¸׀¼׀°׀µׁ‚ ׁ�ׁ‚׀¾ ׀÷׀°׀÷ ׀»׀¾׀¶ ׀¸ ׀½׀µ ׀²ׁ‹׀¿׀¾׀»׀½ׁ�׀µׁ‚ׁ�ׁ� , ׀µׁ�׀»׀¸ ׀¶׀µ ׁ‚׀°׀¼ 1 ׁ‚׀¾ ׀²ׁ‹׀²׀¾׀´׀¸ׁ‚ ׁ‚׀¸׀¿ 
                cout << cust[i].type << endl;
            q = 1; // ׀¿ׁ€׀¸ׁ�׀²׀°׀µ׀¼ ׀¾׀¿ׁ�ׁ‚ׁ� q = 0 ׀° ׁ‚׀¾ ׀²ׁ�ׁ‘ ׀·׀°׀³׀»׀¾׀½׀µׁ‚ 

		}
}

void zad2(Bud *cust, const int n)
{
	int i;
	cout << "Te kto vse otdal :" << endl;	
	for (i = 0; i < n; i++) // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ†׀¸׀÷׀» ׀÷׀¾ׁ‚׀¾ׁ€ׁ‹׀¹ ׀¿ׁ€׀¾׀±׀µ׀¶׀¸ׁ‚ ׀²ׁ�׀µׁ… ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
		if (cust[i].ostalos <= 0) // ׀¿ׁ€׀¾׀²׀µׁ€ׁ�׀µ׀¼ ׀²ׁ�ׁ‘ ׀»׀¸ ׀¾׀½׀¸ ׀²ׁ‹׀¿׀»׀°ׁ‚׀¸׀»׀¸
			cout << cust[i].name << endl;
}

void zad1(Bud *cust, const int n)
{
	int i;
	cout << "Klienti y kotorih cache in bank < value doma :" << endl;
	for (i = 0; i < n; i++) // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ†׀¸׀÷׀» ׀÷׀¾ׁ‚׀¾ׁ€ׁ‹׀¹ ׀¿ׁ€׀¾׀±׀µ׀¶׀¸ׁ‚ ׀²ׁ�׀µׁ… ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
				if (cust[i].cache < cust[i].value) // ׀¿ׁ€׀¾׀²׀µׁ€ׁ�׀µ׀¼ ׀¼׀µ׀½ׁ�ׁˆ׀µ ׀»׀¸ ׁƒ ׀½׀¸ׁ… ׀´׀µ׀½׀µ׀³ ׁ‡׀µ׀¼ ׁ�ׁ‚׀¾׀¸׀¼׀¾ׁ�ׁ‚ׁ� ׀¿׀¾ׁ�ׁ‚ׁ€׀¾׀¹׀÷׀¸
					cout << cust[i].name << endl; // ׀µׁ�׀»׀¸ ׀´׀° , ׁ‚׀¾ ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׀¸ׁ… ׀¸׀¼ׁ� 
}

void set_all(Bud *str, int m) // ׁ„ׁƒ׀½ׁ†׀¸ׁ� ׀¿ׁ€׀¸׀½׀¸׀¼׀°׀µׁ‚ ׁ�ׁ�ׁ‹׀»׀÷ׁƒ ׀½׀° ׀¾׀±׀»׀°ׁ�ׁ‚ׁ� ׀¿׀°׀¼ׁ�ׁ‚׀¸ ׀² ׀÷׀¾ׁ‚׀¾ׁ€׀¾׀¹ ׀»׀µ׀¶׀¸ׁ‚ ׀¼׀°ׁ�ׁ�׀¸׀² (׀´׀°, ׁ‚׀°׀÷ ׀¼׀¾׀¶׀½׀¾ ))) ׀¸ ׁ‡׀¸ׁ�׀»׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
{
	srand(time(0)); // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ€׀°׀½׀´׀¾׀¼ 
	for (int i = 0; i < m; i++) // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ†׀¸׀÷׀» ׀² ׀÷׀¾ׁ‚׀¾ׁ€׀¾׀¼ ׀±ׁƒ׀´ׁƒׁ‚ ׀¿ׁ€׀¸ׁ�׀²׀¾׀µ׀½ׁ‹ ׀·׀½׀°ׁ‡׀µ׀½׀¸ׁ� ׀²ׁ�׀µ׀¼ׁƒ ׁˆ׀¾ ׀¿׀¾׀÷׀° ׁ‡ׁ‚׀¾ ׀µׁ�ׁ‚ׁ� (׀²ׁ�׀µ ׀¸׀¼׀µ׀½׀½׀° ׀²ׁ‹׀´ׁƒ׀¼׀°׀½ׁ‹ , ׀²ׁ�׀µ ׁ‡׀¸ׁ�׀»׀° ׁ�׀»ׁƒׁ‡׀°׀¹׀½ׁ‹, ׀²ׁ�׀µ ׁ�׀¾׀²׀¿׀°׀´׀µ׀½׀¸ׁ� ׁ� ׁ€׀µ׀°׀»ׁ�׀½׀¾ׁ�ׁ‚ׁ�ׁ� ׁ�׀»ׁƒׁ‡׀°׀½ׁ‹׀µ)
	{
		strcpy(str[i].name, names[i]); // ׀·׀°׀½׀¾ׁ�׀¸׀¼ ׀¿׀µׁ€׀²׀¾׀µ ׀¸׀¼ׁ� ׀¸׀· ׀½׀°ׁˆ׀µ׀³׀¾ ׁ�׀¿׀¸ׁ�׀÷׀° ׀² ׁ�ׁ�׀´׀° 
		str[i].type = 1 + rand() % 4; // ׁ‚׀¸׀¿ ׀¿׀¾ׁ�ׁ‚ׁ€׀¾׀¹׀÷׀¸ ׀¾ׁ‚ 1 ׀´׀¾ 4 ׀²׀÷׀»ׁ�ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾
		str[i].value = 1000 + rand() % 2001; // ׁ†׀µ׀½׀° ׀¾ׁ‚ 1000 ׀´׀¾ 3000 ׀²׀÷׀»ׁ�ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾
		strcpy(str[i].phyrm, firma[i]);// ׀·׀°׀½׀¾ׁ�׀¸׀¼ ׀¿׀µׁ€׀²ׁƒׁ� ׁ„׀¸ׁ€׀¼ׁƒ ׀¸׀· ׀½׀°ׁˆ׀µ׀³׀¾ ׁ�׀¿׀¸ׁ�׀÷׀° ׀² ׁ�ׁ�׀´׀° 
		str[i].pr_credit = 1 + rand() % 50; // ׀¿ׁ€׀¾ׁ†׀µ׀½ׁ‚ ׀¾ׁ‚ 1 ׀´׀¾ 50 ׀²׀÷׀»ׁ�ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾
		str[i].cache = rand() % 5000;//ׁƒ ׀»ׁ�׀´׀µ׀¹ ׀½׀° ׁ�ׁ‡׀µׁ‚ׁƒ ׀¾ׁ‚ 0 ׀´׀¾ 5000 ׀´׀¾׀»׀»׀°ׁ€׀¾׀² ׀²׀÷׀»ׁ�ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾ 
		str[i].dolg = str[i].value + str[i].pr_credit * str[i].value / 100; // ׁ‚ׁƒׁ‚ ׀¼ׁ‹ ׀²ׁ‹ׁ�ׁ‡׀¸ׁ‚ׁ‹׀²׀°׀µ׀¼ ׀´׀¾׀»׀³ , ׁ†׀µ׀½׀° ׀´׀¾׀¼׀° + ׀¿ׁ€׀¾ׁ†׀µ׀½ׁ‚ ׀¾ׁ‚ ׁ†׀µ׀½ׁ‹
		str[i].ostalos = str[i].dolg - str[i].cache;

	}
}

void laba(Bud *cust, const int n)//ׁ„-ׁ†׀¸ׁ� ׀¿׀¾׀»ׁƒׁ‡׀°׀µׁ‚ ׁ�ׁ�ׁ‹׀»׀÷ׁƒ ׀½׀° ׀¿׀°׀¼ׁ�ׁ‚ׁ� ׀³׀´׀µ ׁ…ׁ€׀°׀½ׁ�ׁ‚ׁ�ׁ� ׁ�׀¿׀¸ׁ�׀÷׀¸ ׀¸ ׀÷׀¾׀»-׀²׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
{
	cout << "For exit - enter exit, for receive a response to a task, enter its number" << endl;
	char s[30]; // ׁ�׀¾׀·׀´׀°ׁ‘׀¼ ׁ�׀¸׀¼׀²׀¾׀»ׁ�׀½ׁ‹׀¹ ׀¼׀°ׁ�ׁ�׀¸׀² ׀² ׀÷׀¾ׁ‚׀¾ׁ€׀¹ ׀±ׁƒ׀´ׁƒׁ‚ ׀·׀°׀¿׀¸ׁ�ׁ‹׀²׀°ׁ‚ׁ�ׁ�ׁ� ׀÷׀¾׀¼׀°׀½׀´ׁ‹
	while (true) // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׀±׀µׁ�׀÷׀¾׀½׀µׁ‡׀½ׁ‹׀¹ ׁ†׀¸׀÷׀» 
	{
		cout << "What do you want? "; // ׀¿ׁ€׀¾ׁ�׀¸׀¼ ׁƒ ׁ�׀·׀²׀µׁ€ׁ� ׀²׀²׀µׁ�ׁ‚׀¸ ׀÷׀¾׀¼׀¼׀°׀½׀´ׁƒ 
		gets_s(s); //׀¿׀¾׀»ׁƒׁ‡׀°׀µ׀¼ ׀µׁ‘

		if (!strcmp(s, "exit")) //ׁ�׀²׀µׁ€ׁ�׀µ׀¼ ׀µׁ‘ ׁ�׀¾ ׁ�׀»׀¾׀²׀¾׀¼ exit,׀µׁ�׀»׀¸ ׀¾׀½׀¸ ׁ€׀°׀²׀½ׁ‹, ׁ‚׀¾ ׀²ׁ‹ׁ…׀¾׀´׀¸׀¼ ׀¸׀· ׁ†ׁ‹׀÷׀»׀°, ׀¸ ׀÷׀°׀÷ ׁ�׀»׀µ׀´ׁ�ׁ‚׀²׀¸׀µ ׀¸׀· ׁ„ׁƒ׀½׀÷ׁ†׀¸׀¸ 
			return;
		else if (!strcmp(s, "2.10"))
			zad10(cust, n);
		else if (!strcmp(s, "2.9"))
			zad9(cust, n);
		else if (!strcmp(s, "2.8"))
			zad8(cust, n);
		else if (!strcmp(s, "2.7"))
			zad7(cust, n);
		else if (!strcmp(s, "2.6"))
			zad6(cust, n);
        else if (!strcmp(s, "2.5"))
        	zad5(cust, n);
		else if (!strcmp(s, "2.4"))
			zad4(cust, n);
		else if (!strcmp(s, "2.3"))
			zad3(cust, n);
		else if (!strcmp(s, "2.2"))
			zad2(cust, n);
		else if (!strcmp(s, "2.1")) // ׁ�ׁ‚ ׀¿׀µׁ€׀²׀¾׀µ ׀·׀°׀´׀°׀½׀¸׀µ
			zad1(cust, n);

	}
}
int main1()
{
	const int n = 10; // ׀÷׀¾׀»׀¸ׁ‡׀µׁ�ׁ‚׀²׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
	Bud cust[n]; // ׀÷׀°׀÷׀¾׀¹ ׁ‚׀¾ ׀¼׀°ׁ�ׁ�׀¸׀² , ׀·׀°׀±ׁ‹׀» ׀÷׀°׀÷ ׀½׀°׀·ׁ‹׀²׀°׀µׁ‚ׁ�ׁ� ׀° ׀³ׁƒ׀³׀»׀¸ׁ‚ׁ� ׀»׀µ׀½ׁ� 
	set_all(cust, n); // ׀¿׀µׁ€׀µ׀´׀°ׁ‘׀¼ ׁ„ׁƒ׀½׀÷ׁ†׀¸׀¸ ׁ�ׁ‚׀¾ׁ‚ ׀¼׀°ׁ�ׁ�׀¸׀² ׁ�ׁ‚ׁ€ׁƒ׀÷ׁ‚ׁƒׁ€׀½ׁ‹׀¹ ׀¸ ׁ‡׀¸ׁ�׀»׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²

	laba(cust, n);//׀¿׀µׁ€׀µ׀´׀°ׁ‘׀¼ ׁ„ׁƒ׀½׀÷ׁ†׀¸׀¸ ׁƒ׀¶׀µ ׁ�ׁ„׀¾ׁ€׀¼׀¸ׁ€׀¾׀²׀°׀½׀½ׁ‹׀µ, ׀² ׀¿ׁ€׀¾ׁˆ׀»׀¾׀¹ ׁ„ׁƒ׀½׀÷ׁ†׀¸׀¸,ׁ�׀¿׀¸ׁ�׀÷׀¸ ׀¸ ׀÷׀¾׀»-׀²׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
	return 0;
}
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;


struct Teconomic_activity {

    struct Tproduct {

    string name;
    double costs;
    double profit;

    };

    int vol_sales;

    double prices;

    struct Tcompany {

        string name;
        string kind_activity;

    };

};

int main3() {

    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	srand(time(NULL));

    int i, j;

    // Обрабатываемые данные

    const int amount = 10 + 1;
    // // Продукты

    Teconomic_activity::Tproduct *PRODUCT = new Teconomic_activity::Tproduct[amount];

    // // // Название

    PRODUCT[1].name = "Столы";
    PRODUCT[2].name = "Мобильные телефоны";
    PRODUCT[3].name = "Ручки";
    PRODUCT[4].name = "Уборка";
    PRODUCT[5].name = "Домашние телефоны";
    PRODUCT[6].name = "Ремонт телефонов";
    PRODUCT[7].name = "Стулья";
    PRODUCT[8].name = "Картофель";
    PRODUCT[9].name = "Клавиатуры";
    PRODUCT[10].name = "Мониторы";

    // // // Затраты

    PRODUCT[1].costs = 10000 + rand() % 490000;
    PRODUCT[2].costs = 10000 + rand() % 490000;
    PRODUCT[3].costs = 10000 + rand() % 490000;
    PRODUCT[4].costs = 10000 + rand() % 490000;
    PRODUCT[5].costs = 10000 + rand() % 490000;
    PRODUCT[6].costs = 10000 + rand() % 490000;
    PRODUCT[7].costs = 10000 + rand() % 490000;
    PRODUCT[8].costs = 10000 + rand() % 490000;
    PRODUCT[9].costs = 10000 + rand() % 490000;
    PRODUCT[10].costs = 10000 + rand() % 490000;

    // // // Чистая прибыль

    PRODUCT[1].profit = 100000 + rand() % 900000;    
    PRODUCT[2].profit = 100000 + rand() % 900000;
    PRODUCT[3].profit = 100000 + rand() % 900000;
    PRODUCT[4].profit = 100000 + rand() % 900000;
    PRODUCT[5].profit = 100000 + rand() % 900000;
    PRODUCT[6].profit = 100000 + rand() % 900000;
    PRODUCT[7].profit = 100000 + rand() % 900000;
    PRODUCT[8].profit = 100000 + rand() % 900000;
    PRODUCT[9].profit = 100000 + rand() % 900000;
    PRODUCT[10].profit = 100000 + rand() % 900000;

    // Объем продаж

    Teconomic_activity *SALES = new Teconomic_activity[amount];

    SALES[1].vol_sales = 5000 + rand() % 15000;
    SALES[2].vol_sales = 5000 + rand() % 15000;
    SALES[3].vol_sales = 5000 + rand() % 15000;
    SALES[4].vol_sales = 5000 + rand() % 15000;    
    SALES[5].vol_sales = 5000 + rand() % 15000;    
    SALES[6].vol_sales = 5000 + rand() % 15000;    
    SALES[7].vol_sales = 5000 + rand() % 15000;    
    SALES[8].vol_sales = 5000 + rand() % 15000;    
    SALES[9].vol_sales = 5000 + rand() % 15000;    
    SALES[10].vol_sales = 5000 + rand() % 15000;    

    // Себестоимость

    Teconomic_activity *PRICES = new Teconomic_activity[amount];
    
    PRICES[1].prices = 1 + rand() % 50;
    PRICES[2].prices = 1 + rand() % 50;
    PRICES[3].prices = 1 + rand() % 50;
    PRICES[4].prices = 1 + rand() % 50;    
    PRICES[5].prices = 1 + rand() % 50;    
    PRICES[6].prices = 1 + rand() % 50;    
    PRICES[7].prices = 1 + rand() % 50;    
    PRICES[8].prices = 1 + rand() % 50;    
    PRICES[9].prices = 1 + rand() % 50;    
    PRICES[10].prices = 1 + rand() % 50;    

    // Фирма

    Teconomic_activity::Tcompany *COMP = new Teconomic_activity::Tcompany[amount];

    // // Название

    COMP[1].name = "Table in.";
    COMP[2].name = "Phone in.";
    COMP[3].name = "Pen in.";
    COMP[4].name = "Clean in.";
    COMP[5].name = "HomePh in.";
    COMP[6].name = "FIXPh in.";
    COMP[7].name = "Chair in.";
    COMP[8].name = "Potato in.";
    COMP[9].name = "KeyBo in.";
    COMP[10].name = "Mon in.";

    // // Вид деятельности

    COMP[1].kind_activity = "Продажа";
    COMP[2].kind_activity = "Продажа";
    COMP[3].kind_activity = "Продажа";
    COMP[4].kind_activity = "Услуги";
    COMP[5].kind_activity = "Продажа";
    COMP[6].kind_activity = "Услуги";
    COMP[7].kind_activity = "Продажа";
    COMP[8].kind_activity = "Продажа";
    COMP[9].kind_activity = "Продажа";
    COMP[10].kind_activity = "Продажа";

    // Вывод таблицы

    cout << setw(14) << "Фирма" << setw(15) << "Деятельность" << setw(20) << "Товар" << setw(10) << "Затраты" << setw(20) << "Чистая прибыль" << setw(15) << "Себестоимость" << setw(15) << "Объем продаж" << endl;
    cout << setw(110) << "---------------------------------------------------------------------------------------------------------" << endl;

    for(i = 1; i < amount; i++) {

        cout << setw(3) << i << ") " << setw(10) << COMP[i].name << setw(15) << COMP[i].kind_activity << setw(20) << PRODUCT[i].name << setw(10) << PRODUCT[i].costs << setw(20) << PRODUCT[i].profit << setw(15) << PRICES[i].prices << setw(15) << SALES[i].vol_sales << endl;

    }

	cout << endl;

	// Операции с данными

	int choice_user;

	cout << "Какую информацию вывести на экран?\n1)Полную себестоимость реализованного товара\n2)Самый рентабельный вид деятельности\n3)Фирмы у которых чистая прибыль больше чем среднее значение по всем фирмам\n4)Самый нерентабельный вид деятельности\n5)Фирмы, у которых вид деятельности 'Услуги', а объем продаж больше 10000\n6)Товары с минимальными затратами, в названии которых есть слово 'телефон'\n" << endl;
	cout << "Введите номер команды: ";
	cin >> choice_user;
	cout << endl;

    // 1
    int amount_price = 0;

    // 2 
    double max_profit_sale = 0, max_profit_services = 0;
    string temp_services = "Услуги", temp_sale = "Продажа";

    // 3
    double average_profit = 0;

    // 6
    double min_cost = 0;

	switch(choice_user) {


		// 1 
		case 1:

		cout << "Полная себестоимость реализованного товара" << endl;
		
		for(i = 1; i < amount; i++) {

			cout << setw(3) << i << ") " << PRODUCT[i].name << ": " << PRICES[i].prices * SALES[i].vol_sales << endl;
            amount_price += PRICES[i].prices * SALES[i].vol_sales;

		}

        cout << "Полная себестоимость всех товаров: " << amount_price << endl;
        
        cout << endl;
        main3();        
        break;
		// 2
		case 2:

		cout << "Самый рентабельный вид деятельности" << endl;

        
        for(i = 1; i < amount; i++) {

            if(COMP[i].kind_activity == temp_services) {
                max_profit_services += PRODUCT[i].profit;
            } else if(COMP[i].kind_activity == temp_sale) {
                max_profit_sale += PRODUCT[i].profit;                
            }

        }
        cout << max_profit_sale << endl << max_profit_services << endl;

        if(max_profit_sale > max_profit_services) {
            cout << temp_sale;
        }  else if(max_profit_sale < max_profit_services) {
            cout << temp_services;
        } else {
            cout << temp_sale << endl << temp_services;
        }

        cout << endl;
        main3();        
		break;
        // 3
        case 3:

        cout << "Фирмы у которых чистая прибыль больше чем среднее значение по всем фирмам" << endl;

        for(i = 1; i < amount; i++) {

            average_profit += PRODUCT[i].profit;

        }
        average_profit /= amount - 1;

        cout << "Среднее значение чистой прибыли: " << average_profit << endl;

        for(i = 1; i < amount; i++) {
            if(PRODUCT[i].profit > average_profit) {
                cout << COMP[i].name << endl;
            } else {
                cout << "---" << endl;
            }
        }

        cout << endl;
        main3();
        break;
        // 4
        case 4:

		cout << "Самый нерентабельный вид деятельности" << endl;

        
        for(i = 1; i < amount; i++) {

            if(COMP[i].kind_activity == temp_services) {
                max_profit_services += PRODUCT[i].profit;
            } else if(COMP[i].kind_activity == temp_sale) {
                max_profit_sale += PRODUCT[i].profit;                
            }

        }
        cout << max_profit_sale << endl << max_profit_services << endl;

        if(max_profit_sale < max_profit_services) {
            cout << temp_sale;
        }  else if(max_profit_sale > max_profit_services) {
            cout << temp_services;
        } else {
            cout << temp_sale << endl << temp_services;
        }

        cout << endl;
        main3();        
        break;

        // 5
        case 5:

        cout << "Фирмы, у которых вид деятельности 'Услуги', а объем продаж больше 10000" << endl;

        for(i = 1; i < amount; i++) {

            if(COMP[i].kind_activity == temp_services && SALES[i].vol_sales > 10000) {
                cout << COMP[i].name << endl;
            }

        }

        cout << endl;
        main3();        
        break;

        // 6
        case 6:

        cout << "Товары с минимальными затратами, в названии которых есть слово 'телефон'" << endl;

        min_cost = PRODUCT[1].costs;            
        for(i = 1; i < amount; i++) {

            if(min_cost > PRODUCT[i].costs && (PRODUCT[i].name).find("телефон")) {

                min_cost = PRODUCT[i].costs;

            }

        }

        for(i = 1; i < amount; i++) {

            if((PRODUCT[i].name).find("телефон") && PRODUCT[i].costs == min_cost) {

                cout << PRODUCT[i].name << endl;

            }

        }

        cout << endl;
        main3();
        break;

        // exit
        case 7: 

        break;

		default:

		cout << "Какую информацию вывести на экран?\n" << endl;		
        main3();

	}

    // Удаление массивов

    delete []PRODUCT;
    delete []SALES;
    delete []PRICES;
    delete []COMP;

    cout << endl;
    system("pause");
    return 0;
}
//׀›׀°׀±׀° 5 , ׀¿׀µׁ€׀²׀¾׀µ ׀·׀°׀´׀°׀½׀¸׀µ
#include <iostream> // ׀´׀»ׁ� ׀²׀²׀¾׀´׀° ׀²ׁ‹׀²׀¾׀´׀°
#include <cstring> //׀´׀»ׁ� gets_s
#include <ctime> // ׀´׀»ׁ� ׁ€׀°׀½׀´׀¾׀¼׀°
#include <vector> // ׀¿׀¾׀´׀÷׀»ׁ�ׁ‡׀°׀µ׀¼ ׀¼׀¾׀´׀µ׀»ׁ� ׀’׀µ׀÷ׁ‚׀¾ׁ€׀¾׀²
using namespace std;

char country[10][10] = {"Ukrain", "Russia", "USA", "Russia", "Ukrain", "Ukrain", "Russia", "USA", "Ukrain", "Russia"};
char firm[10][10] = {"Iti", "DrYgiy", "Iakist", "Neyman", "Vafli", "Pusir", "Ruslo", "Lopital", "Microsoft", "Meshkov"};
char vestovar[10][10] = {"Komp", "Piki", "Tochilki", "Stooliya", "Telek", "Monitor", "Komp", "Knife", "Knigi", "Komp"};
 // ׀½׀°ׁˆ ׁ�׀¿׀¸ׁ�׀¾׀÷ ׁ„׀¸ׁ€׀¼ , ׀° ׀²׀²׀µׁ€ׁ…ׁƒ ׀½׀°ׁ� ׁ�׀¿׀¸ׁ�׀¾׀÷ ׀²ׁ�׀µׁ… ׀¸׀¼ׁ‘׀½ ׀¿׀¾ׁ‚׀¾׀¼ׁƒ ׁ‡ׁ‚׀¾ ׁ� ׀¿׀¾׀´׀·׀°׀µ׀±׀°׀»ׁ�ׁ� ׀÷׀°׀¶׀´ׁ‹׀¹ ׁ€׀°׀· ׁ�ׁ‚׀¾ ׀²׀±׀¸׀²׀°ׁ‚ׁ� ׁ€ׁƒׁ‡ׁ‘׀½׀÷׀°׀¼׀¸

struct Tov // ׁ�ׁ‚ׁ€ׁƒ׀÷ׁ€ׁƒׁ€׀° ׁ� ׀½׀°׀·׀²׀°׀½׀¸׀µ׀¼ ׀¢׀¾׀²(ׁ‚׀¾׀²׀°ׁ€)
{
	char name[12]; //׀¸׀¼ׁ� ׁ‚׀¾׀²׀°ׁ€׀°
	char phyrm[12]; //׀½׀°׀·׀²׀°׀½׀¸׀µ ׁ„׀¸ׁ€׀¼ׁ‹
	char count[12]; // ׁ�ׁ‚ׁ€׀°׀½׀°
	int value; // ׁ†׀µ׀½׀° ׁ‚׀¾׀²׀°ׁ€׀°
	int kolvo; // ׀÷׀¾׀»׀¸ׁ‡׀µׁ�ׁ‚׀²׀¾
	int year; // ׀³׀¾׀´
	int month; // ׀¼׀µׁ�ׁ�ׁ†
	int day; // ׀´׀µ׀½ׁ�
};

void z10(Tov *str, const int n)
{
	cout << "Firma kotra v 2013 year iz Ukrain dostavila kompu :\n" ;
	int i;
	for(i = 0; i < n; i++)
		if(str[i].year == 2013 && !strcmp(str[i].count, "Ukrain") && !strcmp(str[i].name, "Komp"))
		{
			cout << str[i].phyrm << endl;
			break;
		}
}

void z9(Tov *str, const int n)
{
	const int q = 10;
	int i, j;
	vector<int> a(q); //ׁ�׀¾׀·׀´׀°ׁ‘׀¼ ׀²׀µ׀÷ׁ‚׀¾ׁ€ (׀÷׀°׀÷ ׀¼׀°ׁ�ׁ�׀¸׀² ׁ‚׀¾׀÷ ׀»ׁƒׁ‡ׁˆ׀µ )
	for(j = 0; j < q; j++)
		for(i = 0; i < n; i++)
			if(!strcmp(str[i].phyrm, firm[j]))
				a[j] += str[i].kolvo;
	j = 0;
	for(i = 0; i < q; i++)
		if(a[i] > j)
			j = a[i];

	for(i = 0; i < q; i++)
		if(a[i] == j)
			cout << "Firma s max kolvom tovarov :\n" << firm[i] << endl;

}

void z8(Tov *str, const int n) // ׁ‚ׁƒׁ‚ ׀¿ׁ€׀¾׀±׀»׀µ׀¼׀° , ׀¸ׁ�׀¿ׁ€׀°׀²ׁ�ׁ‚׀µ, ׀¼׀½׀µ ׀² ׀³׀¾׀»׀¾׀²ׁƒ ׀½׀¸ׁ‡׀µ׀³׀¾ ׀´ׁ€ׁƒ׀³׀¾׀³׀¾ ׀½׀µ ׀¿ׁ€׀¸ׁˆ׀»׀¾ ׀÷ׁ€׀¾׀¼׀µ ׀÷׀°׀÷ ׁ‚ׁƒ׀¿׀¾ ׀½׀°׀¿׀¸ׁ�׀°ׁ‚ׁ� ׁ�ׁ‚׀¾ ׀²ׁ�ׁ‘ ׁ€ׁƒׁ‡׀÷׀°׀¼׀¸
{
	const int q = 10;
	int i, j;
	vector<int> a(q);//ׁ�׀¾׀·׀´׀°ׁ‘׀¼ ׀²׀µ׀÷ׁ‚׀¾ׁ€ (׀÷׀°׀÷ ׀¼׀°ׁ�ׁ�׀¸׀² ׁ‚׀¾׀÷ ׀»ׁƒׁ‡ׁˆ׀µ )
	for(j = 0; j < q; j++)
		for(i = 0; i < n; i++)
			if(str[i].year == 2013)
				if(!strcmp(str[i].phyrm, firm[j]))
					a[j] += str[i].value * str[i].kolvo;
	j = 0;
	for(i = 0; i < q; i++)
		if(a[i] > j)
			j = a[i];

	for(i = 0; i < q; i++)
		if(a[i] == j)
			cout << "Firma s max kolvom summi value tovarov za 2013 year :\n" << firm[i] << endl;
}

void z7(Tov *str, const int n)
{
	int i, sum = 0;

	for(i = 0; i < n; i++)
		if(str[i].year == 2013 && !strcmp(str[i].count, "USA")) //׀µׁ�׀»׀¸ ׁ‚׀¾׀²׀°ׁ€ ׀·׀° 2013 ׀³׀¾׀´ ׀¸ ׀¾ׁ‚ ׁ�ׁˆ׀°, ׁ‚׀¾ ׀¿ׁ€׀¸׀±׀¾׀²׀»ׁ�׀µ׀¼ ׁ†׀µ׀½ׁƒ ׀·׀° ׀µ׀³׀¾ ׁ‚׀¾׀²׀°ׁ€ׁ‹
			sum += (str[i].value * str[i].kolvo);
	cout << "Summa vartosti tovarov za 2013 year USA :\n" << sum << " ruskih dollarov" << endl;
	sum = 0;
	for(i = 0; i < n; i++)
		if(str[i].year == 2013 && !strcmp(str[i].count, "Ukrain")) //׀µׁ�׀»׀¸ ׁ‚׀¾׀²׀°ׁ€ ׀·׀° 2013 ׀³׀¾׀´ ׀¸ ׀¾ׁ‚ ׁƒ׀÷ׁ€׀°׀¸׀½ׁ‹, ׁ‚׀¾ ׀¿ׁ€׀¸׀±׀¾׀²׀»ׁ�׀µ׀¼ ׁ†׀µ׀½ׁƒ ׀·׀° ׀µ׀³׀¾ ׁ‚׀¾׀²׀°ׁ€ׁ‹
			sum += (str[i].value * str[i].kolvo);
	cout << "Summa vartosti tovarov za 2013 year Ukrain :\n" << sum << " ruskih dollarov" << endl;
	sum = 0;
	for(i = 0; i < n; i++)
		if(str[i].year == 2013 && !strcmp(str[i].count, "Russia")) //׀µׁ�׀»׀¸ ׁ‚׀¾׀²׀°ׁ€ ׀·׀° 2013 ׀³׀¾׀´ ׀¸ ׀¾ׁ‚ ׁ€׀°ׁˆ׀÷׀¸, ׁ‚׀¾ ׀¿ׁ€׀¸׀±׀¾׀²׀»ׁ�׀µ׀¼ ׁ†׀µ׀½ׁƒ ׀·׀° ׀µ׀³׀¾ ׁ‚׀¾׀²׀°ׁ€ׁ‹
			sum += (str[i].value * str[i].kolvo);
	cout << "Summa vartosti tovarov za 2013 year Russia :\n" << sum << " ruskih dollarov" << endl;
}

void z6(Tov *str, const int n)
{
	int i;
	cout << "Phirma kotoraya postovliaet monitoru in mart into 2013 year och diochivo :\n";
	for(i = 0; i < n; i++)
		if(!strcmp(str[i].name, "Monitor") && str[i].value < 1500 && str[i].month == 3 && str[i].year == 2013)
			cout << str[i].phyrm << endl;
}

void z5(Tov *str, const int n)
{
	int i, j, b = 0, a[1000], max = 0;
	char c[1000][10];
	for(i = 0; i < n; i++)
		if(str[i].year == 2013 || str[i].year == 2012 || str[i].year == 2011)
			for(j = 0; j < n; j++)
				strcpy(c[j], str[i].count);

	for(i = 0; i < n; i++) //׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ†׀¸׀÷׀» 
	{//׀½׀°ׁ…׀¾׀´׀¸׀¼ ׀÷׀°׀÷׀°ׁ� ׁ�ׁ‚ׁ€׀°׀½׀° ׀²ׁ�ׁ‚ׁ€׀µׁ‡׀°׀µׁ‚ׁ�ׁ� ׁ‡׀°ׁ‰׀µ ׀²ׁ�׀µ׀³׀¾
		for(j = 0; j < n; j++)
			if(c[i] == c[j])
				b++;
		a[i] = b; // ׀·׀°׀¿׀¸ׁ�ׁ‹׀²׀°׀µ׀¼ ׁ�׀÷׀¾׀»ׁ�׀÷׀¾ ׁ€׀°׀· ׀²ׁ�ׁ‚ׁ€׀µׁ‡׀°׀µׁ‚ׁ�ׁ� ׀÷׀°׀÷׀°ׁ� ׁ„׀¸ׁ€׀¼׀°
	}

	for(i = 0; i < n; i++)
		if(a[i] > max) //׀½׀°ׁ…׀¾׀´׀¸׀¼ ׀¿׀¾׀´ ׀÷׀°׀÷׀¸׀¼ ׀½׀¾׀¼׀µׁ€׀¾׀¼ ׁ„׀¸ׁ€׀¼׀° ׀²ׁ�ׁ‚ׁ€׀µׁ‡׀°׀µׁ‚ׁ�ׁ� ׁ‡׀°ׁ‰׀µ ׀²ׁ�׀µ׀³׀¾
			max = a[i];

	for(i = 0; i < n; i++)
		if(a[i] == max) // ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׁ„׀¸ׁ€׀¼ׁƒ ׀÷׀¾ׁ‚׀¾ׁ€׀°ׁ� ׀·׀°׀¿׀¸ׁ�׀°׀½׀° ׀¿׀¾׀´ ׁ�ׁ‚׀¸׀¼ ׀½׀¾׀¼׀µׁ€׀¾׀¼ 
		{
			cout << "Country tovar kotoroy prihodil samo chasto s 2011 po 2013 year :\n" << c[i] << endl;
			break;
		}

}

void z4(Tov *str, const int n)
{
	cout << "Ukrain has in 2013 year and with value > 2000 takih postachalnikiv :\n";
 	int i;
	for(i = 0; i < n; i++)
		if(!strcmp(str[i].count, "Ukrain") && str[i].year == 2013 && str[i].value > 2000) //׀µׁ�׀»׀¸ ׀²ׁ‹׀¿׀¾׀»׀½ׁ�ׁ�ׁ‚ׁ�ׁ� ׀¾׀´׀½׀¾׀²ׁ€׀µ׀¼׀µ׀½׀½׀¾ ׀²ׁ�׀µ ׁƒׁ�׀»׀¾׀²׀¸ׁ� ׀²ׁ‹׀²׀¾׀´׀¸ׁ‚ׁ� ׁ„׀¸ׁ€׀¼׀°
			cout << str[i].phyrm << endl;
}

void z3(Tov *str, const int n)
{
	int i, sum = 0;

	for(i = 0; i < n; i++)
		if(str[i].year == 2013 || str[i].year == 2012 || str[i].year == 2011) //׀µׁ�׀»׀¸ ׁ‚׀¾׀²׀°ׁ€ ׀·׀° 2011 -2013 ׀³׀¾׀´׀° , ׁ‚׀¾ ׀¿ׁ€׀¸׀±׀¾׀²׀»ׁ�׀µ׀¼ ׁ†׀µ׀½ׁƒ ׀·׀° ׀µ׀³׀¾ ׁ‚׀¾׀²׀°ׁ€ׁ‹
			sum += (str[i].value * str[i].kolvo);

	cout << "Summa vartosti tovarov za 2011-2013 years :\n" << sum << " ruskih dollarov" << endl;
}

void z2(Tov *str, const int n) //׀² ׁ�ׁ‚׀¾׀¹ ׁ„ׁƒ׀½׀÷ׁ†׀¸׀¸ ׀´׀µ׀»׀°׀µ׀¼ ׁ‚׀¾׀¶׀µ ׁ�׀°׀¼׀¾׀µ ׁ‡ׁ‚׀¾ ׀¸ ׀² ׀¿ׁ€׀µ׀´ׁ‹׀´ׁƒׁ‰׀µ׀¹
{								// ׁ‚׀¾׀»ׁ�׀÷׀¾ ׀¸ׁ‰׀µ׀¼ ׀¼׀¸׀½׀¸׀¼ׁƒ׀¼ ׀° ׀½׀µ ׀¼׀°׀÷ׁ�׀¸׀¼ׁƒ׀¼
	int i, j, b = 0, min = 500, a[1000];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			if(str[i].phyrm == str[j].phyrm)
				b++;
		a[i] = b;
	}
	
	for(i = 0; i < n; i++)
		if(a[i] < min)
			min = a[i];

	for(i = 0; i < n; i++)
		if(a[i] == min)
		{
			cout << "Phirma tovar kotoroy prihodit samo redko :\n" << str[i].phyrm << endl;
			break;
		}
}

void z1(Tov *str, const int n)
{
	int i, j, b = 0, max = 0, a[1000];
	for(i = 0; i < n; i++) //׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ†׀¸׀÷׀» 
	{//׀½׀°ׁ…׀¾׀´׀¸׀¼ ׀÷׀°׀÷׀°ׁ� ׁ„׀¸ׁ€׀¼׀° ׀²ׁ�ׁ‚ׁ€׀µׁ‡׀°׀µׁ‚ׁ�ׁ� ׁ‡׀°ׁ‰׀µ ׀²ׁ�׀µ׀³׀¾
		for(j = 0; j < n; j++)
			if(str[i].phyrm == str[j].phyrm)
				b++;
		a[i] = b; // ׀·׀°׀¿׀¸ׁ�ׁ‹׀²׀°׀µ׀¼ ׁ�׀÷׀¾׀»ׁ�׀÷׀¾ ׁ€׀°׀· ׀²ׁ�ׁ‚ׁ€׀µׁ‡׀°׀µׁ‚ׁ�ׁ� ׀÷׀°׀÷׀°ׁ� ׁ„׀¸ׁ€׀¼׀°
	}

	for(i = 0; i < n; i++)
		if(a[i] > max) //׀½׀°ׁ…׀¾׀´׀¸׀¼ ׀¿׀¾׀´ ׀÷׀°׀÷׀¸׀¼ ׀½׀¾׀¼׀µׁ€׀¾׀¼ ׁ„׀¸ׁ€׀¼׀° ׀²ׁ�ׁ‚ׁ€׀µׁ‡׀°׀µׁ‚ׁ�ׁ� ׁ‡׀°ׁ‰׀µ ׀²ׁ�׀µ׀³׀¾
			max = a[i];

	for(i = 0; i < n; i++)
		if(a[i] == max) // ׀²ׁ‹׀²׀¾׀´׀¸׀¼ ׁ„׀¸ׁ€׀¼ׁƒ ׀÷׀¾ׁ‚׀¾ׁ€׀°ׁ� ׀·׀°׀¿׀¸ׁ�׀°׀½׀° ׀¿׀¾׀´ ׁ�ׁ‚׀¸׀¼ ׀½׀¾׀¼׀µׁ€׀¾׀¼ 
		{
			cout << "Phirma tovar kotoroy prihodit samo chasto :\n" << str[i].phyrm << endl;
			break;
		}
}

void gat(Tov *str, const int n)
{
	cout << "For exit - enter exit, for receive a response to a task, enter its number" << endl;
	char s[12]; // ׁ�׀¾׀·׀´׀°ׁ‘׀¼ ׁ�׀¸׀¼׀²׀¾׀»ׁ�׀½ׁ‹׀¹ ׀¼׀°ׁ�ׁ�׀¸׀² ׀² ׀÷׀¾ׁ‚׀¾ׁ€׀¹ ׀±ׁƒ׀´ׁƒׁ‚ ׀·׀°׀¿׀¸ׁ�ׁ‹׀²׀°ׁ‚ׁ�ׁ�ׁ� ׀÷׀¾׀¼׀°׀½׀´ׁ‹
	while (true) // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׀±׀µׁ�׀÷׀¾׀½׀µׁ‡׀½ׁ‹׀¹ ׁ†׀¸׀÷׀» 
	{
		cout << "What do you want? "; // ׀¿ׁ€׀¾ׁ�׀¸׀¼ ׁƒ ׁ�׀·׀²׀µׁ€ׁ� ׀²׀²׀µׁ�ׁ‚׀¸ ׀÷׀¾׀¼׀¼׀°׀½׀´ׁƒ 
		gets_s(s); //׀¿׀¾׀»ׁƒׁ‡׀°׀µ׀¼ ׀µׁ‘

		if (!strcmp(s, "exit")) //ׁ�׀²׀µׁ€ׁ�׀µ׀¼ ׀µׁ‘ ׁ�׀¾ ׁ�׀»׀¾׀²׀¾׀¼ exit,׀µׁ�׀»׀¸ ׀¾׀½׀¸ ׁ€׀°׀²׀½ׁ‹, ׁ‚׀¾ ׀²ׁ‹ׁ…׀¾׀´׀¸׀¼ ׀¸׀· ׁ†ׁ‹׀÷׀»׀°, ׀¸ ׀÷׀°׀÷ ׁ�׀»׀µ׀´ׁ�ׁ‚׀²׀¸׀µ ׀¸׀· ׁ„ׁƒ׀½׀÷ׁ†׀¸׀¸ 
			return;
		else  if(!strcmp(s, "1.10"))
			z10(str, n);
		else  if(!strcmp(s, "1.9"))
			z9(str, n);
		else  if(!strcmp(s, "1.8"))
			z8(str, n);
		else  if(!strcmp(s, "1.7"))
			z7(str, n);
		else  if(!strcmp(s, "1.6"))
			z6(str, n);
		else  if(!strcmp(s, "1.5"))
			z5(str, n);
		else  if(!strcmp(s, "1.4"))
			z4(str, n);
		else  if(!strcmp(s, "1.3"))
			z3(str, n);
		else  if(!strcmp(s, "1.1"))
			z1(str, n);
		else  if(!strcmp(s, "1.2"))
			z2(str, n);

	}
}
void set_all(Tov *str, int m) // ׁ„ׁƒ׀½ׁ†׀¸ׁ� ׀¿ׁ€׀¸׀½׀¸׀¼׀°׀µׁ‚ ׁ�ׁ�ׁ‹׀»׀÷ׁƒ ׀½׀° ׀¾׀±׀»׀°ׁ�ׁ‚ׁ� ׀¿׀°׀¼ׁ�ׁ‚׀¸ ׀² ׀÷׀¾ׁ‚׀¾ׁ€׀¾׀¹ ׀»׀µ׀¶׀¸ׁ‚ ׀¼׀°ׁ�ׁ�׀¸׀² (׀´׀°, ׁ‚׀°׀÷ ׀¼׀¾׀¶׀½׀¾ ))) ׀¸ ׁ‡׀¸ׁ�׀»׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
{
	int b;
	srand(time(0)); // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ€׀°׀½׀´׀¾׀¼ 
	for (int i = 0; i < m; i++) // ׀·׀°׀¿ׁƒׁ�׀÷׀°׀µ׀¼ ׁ†׀¸׀÷׀» ׀² ׀÷׀¾ׁ‚׀¾ׁ€׀¾׀¼ ׀±ׁƒ׀´ׁƒׁ‚ ׀¿ׁ€׀¸ׁ�׀²׀¾׀µ׀½ׁ‹ ׀·׀½׀°ׁ‡׀µ׀½׀¸ׁ� ׀²ׁ�׀µ׀¼ׁƒ ׁˆ׀¾ ׀¿׀¾׀÷׀° ׁ‡ׁ‚׀¾ ׀µׁ�ׁ‚ׁ� (׀²ׁ�׀µ ׀¸׀¼׀µ׀½׀½׀° ׀²ׁ‹׀´ׁƒ׀¼׀°׀½ׁ‹ , ׀²ׁ�׀µ ׁ‡׀¸ׁ�׀»׀° ׁ�׀»ׁƒׁ‡׀°׀¹׀½ׁ‹, ׀²ׁ�׀µ ׁ�׀¾׀²׀¿׀°׀´׀µ׀½׀¸ׁ� ׁ� ׁ€׀µ׀°׀»ׁ�׀½׀¾ׁ�ׁ‚ׁ�ׁ� ׁ�׀»ׁƒׁ‡׀°׀½ׁ‹׀µ)
	{
		b = rand() % 10;
		strcpy(str[i].phyrm, firm[b]); // ׀·׀°׀½׀¾ׁ�׀¸׀¼ ׀¿׀µׁ€׀²ׁƒׁ� ׁ„׀¸ׁ€׀¼ׁƒ ׀¸׀· ׀½׀°ׁˆ׀µ׀³׀¾ ׁ�׀¿׀¸ׁ�׀÷׀° ׀² ׁ�ׁ�׀´׀° 
		strcpy(str[i].name, vestovar[b]); //׀¿׀µׁ€׀²׀¾׀µ ׀½׀°׀·׀²׀°׀½׀¸׀µ ׁ‚׀¾׀²׀°ׁ€׀°
		strcpy(str[i].count, country[b]);
		str[i].value = 1 + rand() % 4000; //ׁ†׀µ׀½׀° ׁ‚׀¾׀²׀°ׁ€׀° ׀¾ׁ‚ 1 ׀´׀¾ 4000 ׀²׀÷׀»ׁ�ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾
		str[i].kolvo = 1 + rand() % 20; // ׀÷׀¾׀»׀²׀¾ ׁ‚׀¾׀²׀°ׁ€׀° ׀¾ׁ‚ 1 ׀´׀¾ 20 ׀²׀÷׀»ׁ�ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾
		str[i].year = 2010 + rand() % 6; // ׀³׀¾׀´ ׀¾ׁ‚ 2010 ׀´׀¾ 2015 ׀²׀÷׀»ׁ�ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾
		str[i].month = 1 + rand() % 12; // ׁ€׀°׀½׀´׀¾׀¼׀½ׁ‹׀µ ׀¼׀µׁ�ׁ†׀° ׀¾ׁ‚ 1 ׀´׀¾ 12 ׀÷׀»׀±ׁ‡׀¸ׁ‚׀µ׀»ׁ�׀½׀¾
		str[i].day = 1 + rand() % 28; // ׁ€׀°׀½׀´׀¾׀¼׀½ׁ‹׀µ ׀´׀½׀¸ ׀¾ׁ‚ 1 ׀´׀¾ 28 , ׀¿׀¾ׁ‚׀¾׀¼ׁƒ ׁ‡ׁ‚׀¾ ׀² ׁ€׀¾ׁ‚ ׁ� ׀µ׀±׀°׀» ׀½׀°׀¿ׁ€ׁ�׀³׀°ׁ‚ׁ�ׁ�ׁ�
	}
}

void main2()
{
	const int n = 1000; // ׀÷׀¾׀»׀¸ׁ‡׀µׁ�ׁ‚׀²׀¾ ׀÷׀»׀¸׀µ׀½ׁ‚׀¾׀²
	Tov tovar[n]; // ׀÷׀°׀÷׀¾׀¹ ׁ‚׀¾ ׀¼׀°ׁ�ׁ�׀¸׀² , ׀·׀°׀±ׁ‹׀» ׀÷׀°׀÷ ׀½׀°׀·ׁ‹׀²׀°׀µׁ‚ׁ�ׁ� ׀° ׀³ׁƒ׀³׀»׀¸ׁ‚ׁ� ׀»׀µ׀½ׁ� 
    set_all(tovar, n); // ׀¾ׁ‚׀¿ׁ€׀°׀²׀»ׁ�׀µ׀¼ ׀¼׀°ׁ�ׁ�׀¸׀² ׀² ׁ„ׁƒ׀½׀÷ׁ†׀¸ׁ� ׀¸ ׀÷׀¾׀»׀¸ׁ‡׀µׁ�ׁ‚׀²׀¾ ׁ‚׀¾׀²׀°ׁ€׀° , ׀´׀»ׁ� ׀·׀°׀¿׀¾׀»׀½׀µ׀½׀¸ׁ�

	gat(tovar, n);
}