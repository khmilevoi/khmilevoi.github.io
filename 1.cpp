#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>
#include <cmath> //если ты это читаешь то я разобрался с этой хуитой
using namespace std;//лаба апр 7-10 вариантов

class  lab
{
	public:
	vector<int> arr;

};
void chot9(lab obj1, int n)
{
	vector<int> arr1;
	vector<int> arr2;
	int max = -100;
	for(int i = 0; i < n; i++)
		if(obj1.arr[i] > max)
			max = obj1.arr[i];
	cout << endl << "Max = " << max;
	for(int i = 0; i < n; i++)
	{
		if(abs(obj1.arr[i] - max) <= abs(0.2 * max))
			arr1.push_back(obj1.arr[i]);
		else 
			arr2.push_back(obj1.arr[i]);
	}
	
	obj1.arr.clear();

	for(int i = 0; i < size(arr1); i++)
		obj1.arr.push_back(arr1[i]);

	for(int i = 0; i < size(arr2); i++)
		obj1.arr.push_back(arr2[i]);
		
	cout << endl << "\nV9 otsorterovaniy vector : " << endl;
	copy( obj1.arr.begin(),   // итератор начала массива
          obj1.arr.end(),     // итератор конца массива
          ostream_iterator<int>(cout," ")
		);

}

void sum9(lab obj1, int n)
{
	int sum = 0;
	for(int i = n - 1; i >= 0; i--)
		if(obj1.arr[i] < 0)
		{
			for(int j = i + 1; j < n; j++)
				sum += int(obj1.arr[j]);
			break;
		}
	cout << endl << "sum9 = " << sum; 
}

void kol9(lab obj1, int n)
{
	int numb = 0;
	for(int i = 0; i < n; i++)
		if(obj1.arr[i] < 3 )
			numb++;
	cout << endl << "9Number element what < 3 = " << numb;
}		

void sort8(lab obj1, int n) 
{
	vector<int> arr1;
	vector<int> arr2;
	for(int i = 0; i < n; i++)
	 {
		if(abs(obj1.arr[i]) <= 1)
			arr1.push_back(obj1.arr[i]);
		else
			arr2.push_back(obj1.arr[i]);
	}

	obj1.arr.clear();

	for(int i = 0; i < size(arr1); i++)
		obj1.arr.push_back(arr1[i]);

	for(int i = 0; i < size(arr2); i++)
		obj1.arr.push_back(arr2[i]);

	cout << endl << "V8 otsorterovaniy vector : " << endl;
	copy( obj1.arr.begin(),   // итератор начала массива
          obj1.arr.end(),     // итератор конца массива
          ostream_iterator<int>(cout," ")
		);

}

void sum8(lab obj1, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		if(obj1.arr[i] < 0)
		{
			while(obj1.arr[i + 1] >= 0 && i < n )
			{
				i++;
				sum += obj1.arr[i];
			}
			break;
		}
	cout << endl << "V8 Suma chegoto tam >> " << sum << endl;
}

void min8(lab obj1, int n)
{
	int min = obj1.arr[0], number;
	for(int i = 1; i < n; i++)
		if(obj1.arr[i] < min)
			min = obj1.arr[i];

	for(int i = 0; i < n; i++)
		if(obj1.arr[i] == min)
		{
			number = i;
			cout << endl << "Index min elementa >> " << number;
			break;
		}

}

void sort7(lab obj1, int n)// это пашет через жопу,мб так надо , мб можно сделать проще 
{
	int *array1 = new int [n/2];
	int *array2 = new int [n/2];
	int j = 0;
	for(int i = 0; i < n; i += 2)
	{
		array1[j] = obj1.arr[i];
		j++;
	}
	j = 0;
	for(int i = 1; i < n; i += 2)
	{
		array2[j] = obj1.arr[i];
		j++;
	}

	obj1.arr.clear();

	for(int i = 0; i < (n / 2); i++)
		obj1.arr.push_back(array1[i]);

	for(int i = 0; i < (n / 2); i++)
		obj1.arr.push_back(array2[i]);

	cout << endl << "V7 otsorterovaniy vector : " << endl;
	copy( obj1.arr.begin(),   // итератор начала массива
          obj1.arr.end(),     // итератор конца массива
          ostream_iterator<int>(cout," ")
		);
	delete [] array1;
	delete [] array2;
}

void sum7(lab obj1, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		if(obj1.arr[i] == 0)
		{
			do{
				sum += obj1.arr[i];
				i++;
			}while(obj1.arr[i] != 0 && i < n );
			break;
		}
	cout << endl << "V7 Suma chegoto tam >> " << sum << endl;

}

void max7(lab obj1, int n)
{
	int max = 0, number;
	for(int i = 0; i < n; i++)
		if(obj1.arr[i] >= max)
			max = obj1.arr[i];

	for(int i = 0; i < n; i++)
		if(obj1.arr[i] == max)
		{
			number = i;
			break;
		}

	cout << endl << "Index max elementa >> " << number;
}

int main()
{
	srand(time(0));
	lab obj1;
	int n;
	cout << "Enter value vectora >> ";
	cin >> n;
	for(int i = 0; i < n; i++)
		obj1.arr.insert(obj1.arr.end(),(- 100 + rand() % 201));

	cout << "Nash vector :" << endl; 
	copy( obj1.arr.begin(),   // итератор начала массива
          obj1.arr.end(),     // итератор конца массива
          ostream_iterator<int>(cout," ")
		);
	max7(obj1, n);
	sum7(obj1, n);
	sort7(obj1, n);

	min8(obj1, n);
	sum8(obj1, n);
	sort8(obj1, n);

	kol9(obj1, n);
	sum9(obj1, n);
	chot9(obj1, n);

	return 0;
}