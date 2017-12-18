//Лаба 5 , второе задание 
// Решил рассписать всё , что бы потом не думать на**я я юзал те или иные библиотеки и переменные


#include <iostream> // для ввода вывода
#include <cstring> //для gets_s
#include <ctime> // для рандома
using namespace std;

char names[10][10] = {"Hmilewoi", "Grek", "Waloshina", "Artem", "Drozd", "Srefano", "Boris", "Chalow", "Solodov", "Iasik"};
char firma[10][10] = {"Iti", "DrYgiy", "Iakist", "DrYgiy", "Iakist", "Iti", "DrYgiy", "Iakist", "Iti", "DrYgiy"};
 // наш список фирм , а вверху нас список всех имён потому что я подзаебался каждый раз это вбивать ручёнками

struct Bud // струкрура с названием буд(будова)
{
	char name[12];//имя клиента
	int type; // тип будовы
	int value; // её цена
	char phyrm[12]; // название фирмы
	int pr_credit; // процент кредита 
	int cache; //сумма вклада
	int dolg; // долг 
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
		if(cust[i].ostalos > 0 && cust[i].ostalos < min) // если невыплаченная сумма больше нуля(ну то есть вообще есть) и меньше минимума то записуем её в минимум
		 	min = cust[i].ostalos;

	for(i = 0; i < n; i++)
		if(cust[i].ostalos = min) // если невыплаченная сумма равна найденному минимуму то выводим фирму этой суммы
		{
			cout << "Phirma y kototoi y klienta minimalnaya neviplachenaya summa :\n" << cust[i].phyrm << endl;
			break;
		}
}

void zad8(Bud *cust, const int n)
{
	int i, max = 0, min = 100; //для поиска необходимы две переменные , наибольший возможный процент и наименьший

	for(i = 0; i < n; i++)
		if(cust[i].pr_credit > max) // просто ищем наибольшый процент
		 	max = cust[i].pr_credit;

	cout << "Naibolshiy procent :" << endl << max << endl; // выводим его

	for(i = 0; i < n; i++)
		if(cust[i].pr_credit <= min) // просто ищем наимельший процент
		 	min = cust[i].pr_credit;

	cout << "Naimenshiy procent :" << endl << min << endl; // выводим его
}

void zad7(Bud *cust, const int n)
{
	int i;
	cout << "Klientu s neviplachenoy summoy bolchey vklada :" << endl;
	for(i = 0; i < n; i++)
		if(cust[i].ostalos > cust[i].cache) // если невыплачено больше чем есть на счету, то выводим имя
			cout << cust[i].name << endl;
}

void zad6(Bud *cust, const int n)
{
	cout << "Max neviplachena summa :" << endl;
	int i, max = 0;
	for(i = 0; i < n; i++)
		if(cust[i].ostalos > max) // просто ищем наибольшую невыплаченную сумму 
		 max = cust[i].dolg;
	cout << max << endl;
}

void zad5(Bud *cust, const int n)
{
	int i, j = 0;
	cout << "Obschiy dolg :" << endl;

	for(i = 0; i < n; i++)
        j += cust[i].ostalos; // сумируем невыплаченную сумму каждого клиента

    cout << j << " ruskih dollarov" << endl;
}

void zad4(Bud *cust, const int n)
{
	int i;
	int max = 0; // переменная для определения наибольшей цены
	cout << "tip kotoriy mnoga stoit :" << endl;
	for(i = 0; i < n; i++) // определяем у какой постройки наибольшая цена
		if(max < cust[i].value)
			max = cust[i].value;

	for(i = 0; i < n; i++)
		if(max == cust[i].value) // сравниваем наибольшую найденную цену 
		{
			cout << cust[i].type << endl; // когда нашли, выводим привязанный к этой цене тип 
			break; // выходим из цыкла
		}
}

void zad3(Bud *cust, const int n)
{
	int i, j, b = 0, a[10], q = 1;
	cout << "Tip kotoriy zamovili >2 raz :" << endl;

	for (i = 0; i < n; i++)
		cout << cust[i].type << " "; // для проверки , перед продакшином можно и стереть (прост выводит все типы что у нас есть)

	for (i = 0; i < n; i++) // запускаем цикл который пробежит всех клиентов
	{
		for (j = 0; j < n; j++) // цикл в котором сравниваются каждый тим с каждым типом и если есть совпадение то b увеличивается на 1
			if (cust[i].type == cust[j].type)
				b++;
		a[i] = b; // когда один тип сравнился со всеми остальными , количетво совпадений записывается в массив
			b = 0;
	}
    cout << endl; //новая строка

	for (i = 0; i < n; i++) // цикл для вывода результата
		if (a[i] > 2)  // если совпадений больше двух то смотрим дальше
		{ //можно было бы просто написать вывести тип , но я не хотел что б они повторялись 
           
		    for (j = 0; j < i; j++)    // проверяет был ли этот символ ранее , если был , то заканчиваем цикл этот и q = 0
                if (cust[i].type == cust[j].type) 
                {
                    q = 0;
                    break;
                }
                    
            if(q) // если q = 0 то оно восппринимает это как лож и не выполняется , если же там 1 то выводит тип 
                cout << cust[i].type << endl;
            q = 1; // присваем опять q = 0 а то всё заглонет 

		}
}

void zad2(Bud *cust, const int n)
{
	int i;
	cout << "Te kto vse otdal :" << endl;	
	for (i = 0; i < n; i++) // запускаем цикл который пробежит всех клиентов
		if (cust[i].ostalos <= 0) // проверяем всё ли они выплатили
			cout << cust[i].name << endl;
}

void zad1(Bud *cust, const int n)
{
	int i;
	cout << "Klienti y kotorih cache in bank < value doma :" << endl;
	for (i = 0; i < n; i++) // запускаем цикл который пробежит всех клиентов
				if (cust[i].cache < cust[i].value) // проверяем меньше ли у них денег чем стоимость постройки
					cout << cust[i].name << endl; // если да , то выводим их имя 
}

void set_all(Bud *str, int m) // фунция принимает ссылку на область памяти в которой лежит массив (да, так можно ))) и число клиентов
{
	srand(time(0)); // запускаем рандом 
	for (int i = 0; i < m; i++) // запускаем цикл в котором будут присвоены значения всему шо пока что есть (все именна выдуманы , все числа случайны, все совпадения с реальностью случаные)
	{
		strcpy(str[i].name, names[i]); // заносим первое имя из нашего списка в сюда 
		str[i].type = 1 + rand() % 4; // тип постройки от 1 до 4 включительно
		str[i].value = 1000 + rand() % 2001; // цена от 1000 до 3000 включительно
		strcpy(str[i].phyrm, firma[i]);// заносим первую фирму из нашего списка в сюда 
		str[i].pr_credit = 1 + rand() % 50; // процент от 1 до 50 включительно
		str[i].cache = rand() % 5000;//у людей на счету от 0 до 5000 долларов включительно 
		str[i].dolg = str[i].value + str[i].pr_credit * str[i].value / 100; // тут мы высчитываем долг , цена дома + процент от цены
		str[i].ostalos = str[i].dolg - str[i].cache;

	}
}

void laba(Bud *cust, const int n)//ф-ция получает ссылку на память где хранятся списки и кол-во клиентов
{
	cout << "For exit - enter exit, for receive a response to a task, enter its number" << endl;
	char s[30]; // создаём символьный массив в которй будут записываться команды
	while (true) // запускаем бесконечный цикл 
	{
		cout << "What do you want? "; // просим у юзверя ввести комманду 
		gets_s(s); //получаем её

		if (!strcmp(s, "exit")) //сверяем её со словом exit,если они равны, то выходим из цыкла, и как следствие из функции 
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
		else if (!strcmp(s, "2.1")) // эт первое задание
			zad1(cust, n);

	}
}
int main1()
{
	const int n = 10; // количество клиентов
	Bud cust[n]; // какой то массив , забыл как называется а гуглить лень 
	set_all(cust, n); // передаём функции этот массив структурный и число клиентов

	laba(cust, n);//передаём функции уже сформированные, в прошлой функции,списки и кол-во клиентов
	return 0;
}