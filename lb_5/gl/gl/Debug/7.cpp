//Лаба 5 , первое задание
#include <iostream> // для ввода вывода
#include <cstring> //для gets_s
#include <ctime> // для рандома
#include <vector> // подключаем модель Векторов
using namespace std;

char country[10][10] = {"Ukrain", "Russia", "USA", "Russia", "Ukrain", "Ukrain", "Russia", "USA", "Ukrain", "Russia"};
char firm[10][10] = {"Iti", "DrYgiy", "Iakist", "Neyman", "Vafli", "Pusir", "Ruslo", "Lopital", "Microsoft", "Meshkov"};
char vestovar[10][10] = {"Komp", "Piki", "Tochilki", "Stooliya", "Telek", "Monitor", "Komp", "Knife", "Knigi", "Komp"};
 // наш список фирм , а вверху нас список всех имён потому что я подзаебался каждый раз это вбивать ручёнками

struct Tov // струкрура с названием Тов(товар)
{
	char name[12]; //имя товара
	char phyrm[12]; //название фирмы
	char count[12]; // страна
	int value; // цена товара
	int kolvo; // количество
	int year; // год
	int month; // месяц
	int day; // день
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
	vector<int> a(q); //создаём вектор (как массив ток лучше )
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

void z8(Tov *str, const int n) // тут проблема , исправьте, мне в голову ничего другого не пришло кроме как тупо написать это всё ручками
{
	const int q = 10;
	int i, j;
	vector<int> a(q);//создаём вектор (как массив ток лучше )
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
		if(str[i].year == 2013 && !strcmp(str[i].count, "USA")) //если товар за 2013 год и от сша, то прибовляем цену за его товары
			sum += (str[i].value * str[i].kolvo);
	cout << "Summa vartosti tovarov za 2013 year USA :\n" << sum << " ruskih dollarov" << endl;
	sum = 0;
	for(i = 0; i < n; i++)
		if(str[i].year == 2013 && !strcmp(str[i].count, "Ukrain")) //если товар за 2013 год и от украины, то прибовляем цену за его товары
			sum += (str[i].value * str[i].kolvo);
	cout << "Summa vartosti tovarov za 2013 year Ukrain :\n" << sum << " ruskih dollarov" << endl;
	sum = 0;
	for(i = 0; i < n; i++)
		if(str[i].year == 2013 && !strcmp(str[i].count, "Russia")) //если товар за 2013 год и от рашки, то прибовляем цену за его товары
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

	for(i = 0; i < n; i++) //запускаем цикл 
	{//находим какая страна встречается чаще всего
		for(j = 0; j < n; j++)
			if(c[i] == c[j])
				b++;
		a[i] = b; // записываем сколько раз встречается какая фирма
	}

	for(i = 0; i < n; i++)
		if(a[i] > max) //находим под каким номером фирма встречается чаще всего
			max = a[i];

	for(i = 0; i < n; i++)
		if(a[i] == max) // выводим фирму которая записана под этим номером 
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
		if(!strcmp(str[i].count, "Ukrain") && str[i].year == 2013 && str[i].value > 2000) //если выполняются одновременно все условия выводить фирма
			cout << str[i].phyrm << endl;
}

void z3(Tov *str, const int n)
{
	int i, sum = 0;

	for(i = 0; i < n; i++)
		if(str[i].year == 2013 || str[i].year == 2012 || str[i].year == 2011) //если товар за 2011 -2013 года , то прибовляем цену за его товары
			sum += (str[i].value * str[i].kolvo);

	cout << "Summa vartosti tovarov za 2011-2013 years :\n" << sum << " ruskih dollarov" << endl;
}

void z2(Tov *str, const int n) //в этой функции делаем тоже самое что и в предыдущей
{								// только ищем минимум а не максимум
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
	for(i = 0; i < n; i++) //запускаем цикл 
	{//находим какая фирма встречается чаще всего
		for(j = 0; j < n; j++)
			if(str[i].phyrm == str[j].phyrm)
				b++;
		a[i] = b; // записываем сколько раз встречается какая фирма
	}

	for(i = 0; i < n; i++)
		if(a[i] > max) //находим под каким номером фирма встречается чаще всего
			max = a[i];

	for(i = 0; i < n; i++)
		if(a[i] == max) // выводим фирму которая записана под этим номером 
		{
			cout << "Phirma tovar kotoroy prihodit samo chasto :\n" << str[i].phyrm << endl;
			break;
		}
}

void gat(Tov *str, const int n)
{
	cout << "For exit - enter exit, for receive a response to a task, enter its number" << endl;
	char s[12]; // создаём символьный массив в которй будут записываться команды
	while (true) // запускаем бесконечный цикл 
	{
		cout << "What do you want? "; // просим у юзверя ввести комманду 
		gets_s(s); //получаем её

		if (!strcmp(s, "exit")) //сверяем её со словом exit,если они равны, то выходим из цыкла, и как следствие из функции 
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
void set_all(Tov *str, int m) // фунция принимает ссылку на область памяти в которой лежит массив (да, так можно ))) и число клиентов
{
	int b;
	srand(time(0)); // запускаем рандом 
	for (int i = 0; i < m; i++) // запускаем цикл в котором будут присвоены значения всему шо пока что есть (все именна выдуманы , все числа случайны, все совпадения с реальностью случаные)
	{
		b = rand() % 10;
		strcpy(str[i].phyrm, firm[b]); // заносим первую фирму из нашего списка в сюда 
		strcpy(str[i].name, vestovar[b]); //первое название товара
		strcpy(str[i].count, country[b]);
		str[i].value = 1 + rand() % 4000; //цена товара от 1 до 4000 включительно
		str[i].kolvo = 1 + rand() % 20; // колво товара от 1 до 20 включительно
		str[i].year = 2010 + rand() % 6; // год от 2010 до 2015 включительно
		str[i].month = 1 + rand() % 12; // рандомные меяца от 1 до 12 клбчительно
		str[i].day = 1 + rand() % 28; // рандомные дни от 1 до 28 , потому что в рот я ебал напрягаться
	}
}

void main2()
{
	const int n = 1000; // количество клиентов
	Tov tovar[n]; // какой то массив , забыл как называется а гуглить лень 
    set_all(tovar, n); // отправляем массив в функцию и количество товара , для заполнения

	gat(tovar, n);
}