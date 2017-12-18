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

int main() {

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
	int min_name_int[100];

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
        main();        
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
        main();        
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
        main();
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
        main();        
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
        main();        
        break;

        // 6
        case 6:

        cout << "Товары с минимальными затратами, в названии которых есть слово 'телефон'" << endl;

        for(i = 1; i < amount; i++) {

            min_name_int[i] = (PRODUCT[i].name).find("телефон");

        }

        for(i = 1; i < amount; i++) {

            if(min_name_int[i] > 0) {
                min_cost = PRODUCT[i].costs;
                break;
            }

        }

        for(i = 1; i < amount; i++) {

            if(min_name_int[i] > 0 && min_cost > PRODUCT[i].costs) {

                min_cost = PRODUCT[i].costs;

            }

        }

        cout << min_cost << endl;

        for(i = 1; i < amount; i++) {

            if(min_name_int[i] > 0 && PRODUCT[i].costs == min_cost) {

                cout << PRODUCT[i].name << endl;

            }

        }

        cout << endl;
        main();
        break;

        // exit
        case 7: 

        break;

		default:

		cout << "Какую информацию вывести на экран?\n" << endl;		
        main();

	}

    // Удаление массивов

    delete []PRODUCT;
    delete []SALES;
    delete []PRICES;
    delete []COMP;

    cout << endl;
    return 0;
}