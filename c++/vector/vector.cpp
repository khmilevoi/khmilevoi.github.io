// #include "stdafx.h"
#include <iostream>
using namespace std;

// Vector

template <typename T>
class Vector {
public:
	Vector();
	Vector(const Vector<T> &);
	~Vector();
	void Push(T);
	void Pop();
	bool Push(int, T);
	void Print() const;
	T Peep(int ind);
	int getSize() const;

private:
	T data;
	Vector<T> *next;
	Vector<T> *nod_begin;
	Vector<T> *nod_end;
	int index;
	int size;
};

template <typename T>
Vector<T>::Vector() {
	nod_begin = NULL;
	nod_end = NULL;
	size = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T> &d) {
	TNod<T> *cur_el = d.nod_begin;
	while (cur_el) {
		Push(cur_el->data);
		cur_el = cur_el->next;
	}
}

template <typename T>
Vector<T>::~Vector() {
	while (nod_begin)
		Pop();
}

template <typename T>
void Vector<T>::Push(T num) {
	if (0 == num) {
		++size;
	}
	else {
		++size;        
		Vector<T> *cash = new Vector<T>;
		cash->data = num;
		cash->next = NULL;
		cash->index = size++;
		if (nod_begin)
			nod_end->next = cash;
		nod_end = cash;
		if (!nod_begin)
			nod_begin = nod_end;
	}
}
template <typename T>
void Vector<T>::Pop() {
	if (!nod_begin)
		return;
	Vector<T> *cash = nod_begin;
	nod_begin = nod_begin->next;
	delete cash;
}

template <typename T>
bool Vector<T>::Push(int ind, T num) {
	Vector<T> *cur_el = nod_begin;
	while (cur_el) {
		if (ind == cur_el->index) {
			cur_el->data = num;
			return true;
		}
		cur_el = cur_el->next;
	}
	Vector<T> *cash = new Vector<T>;
	cash->data = num;
	cash->next = NULL;
	cash->index = ind;
	if (nod_begin)
		nod_end->next = cash;
	nod_end = cash;
	if (!nod_begin)
		nod_begin = nod_end;
	return false;
}

template <typename T>
T Vector<T>::Peep(int ind) {
	Vector<T> *cur_el = nod_begin;
	while (cur_el) {
		if (ind == cur_el->index) {
			return cur_el->data;
		}
		cur_el = cur_el->next;
	}
	return NULL;
}

template <typename T>
void Vector<T>::Print() const {
	Vector<T> *cur_el = nod_begin;
	while (cur_el) {
		cout << cur_el->data << ends;
		cur_el = cur_el->next;
	}
	cout << endl;
}

template <typename T>
int Vector<T>::getSize() const {
	return size;
}


// Matr

template <typename T>
class Matr {
public:
	Matr(int = 2, int = 2);
	Matr(Matr &);
	~Matr();
	void setMatr();
	Matr<T> Plus(Matr<T> &);
	Matr<T> Mult(Matr<T> &);
	Matr<T> Mult(T = 1);
	double Det();
	void Print() const;

private:
	Vector<T> *matr;
	int row;
	int col;
};

template <typename T>
Matr<T>::Matr(int mRow, int mCol) {
	try {
		if (mRow < 1 || mCol < 1)
			throw ">ERROR(Constructor Matr): incorrect parameter(s)";
	}
	catch (char *str) {
		cout << row << ends << col << endl;
		cout << str << endl;
	}
	row = mRow;
	col = mCol;
}

template <typename T>
Matr<T>::Matr(Matr<T> &d) {
	col = d.col;
	row = d.row;
	for (int i = 0; i < row * col; i++)
		matr->Push(d.matr->Peep(i));
}

template <typename T>
Matr<T>::~Matr() {
	matr->~Vector();
}

template <typename T>
void Matr<T>::setMatr() {
	T cashData;
	if (matr->getSize() == 0) {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cout << "matr[" << i << "][" << j << "] = ";
				cin >> cashData;
				matr->Push(cashData);
			}
		cout << endl;
	}
	else {
		int counter = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cout << "matr[" << i << "][" << j << "] = ";
				cin >> cashData;
				matr->Push(counter, cashData);
				counter++;
			}
		cout << endl;
	}
}

template <typename T>
Matr<T> Matr<T>::Plus(Matr<T> &d) {
	try {
		if (row != d.row || col != d.col)
			throw ">ERROR(Plus): these matrices do not fold";
	}
	catch (char *str) {
		cout << str << endl;
		return NULL;
	}
	Matr<T> p(row, col);
	for (int i = 0; i < row * col; i++)
		p.matr->Push(matr->Peep(i) + d.matr->Peep(i));
	return p;
}

template <typename T>
Matr<T> Matr<T>::Mult(Matr<T> &d) {
	try {
		if (col != d.row)
			throw ">ERROR(Mult): these matrices should not be multiplied";
	}
	catch (char *str) {
		cout << str << endl;
		return NULL;
	}
	Matr<T> m(row, d.col);
	T a = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < d.col; j++) {
			for (int k = 0; k < col; k++)
				a += matr->Peep(row * i + k) * d.matr->Peep(j + row * k);
			m.matr->Push(a);
			a = 0;
		}
	}
	return m;
}

template <typename T>
Matr<T> Matr<T>::Mult(T num) {
	Matr<T> m(row, col);
	for (int i = 0; i < row * col; i++)
		m.matr->Push(matr->Peep(i) * num);
	return m;
}

template <typename T>
double Matr<T>::Det() {
	try {
		if (row != col)
			throw ">ERROR(Det): this matrix can not compute the determinant";
	}
	catch (char *str) {
		cout << str << endl;
		return NULL;
	}
	if (row == 1)
		return matr->Peep(0);
	if (row == 2)
		return matr->Peep(0) * matr->Peep(3) - matr->Peep(1) * matr->Peep(2);
	else {
		Vector<double> cash;
		for (int i = 0; i < row * row; i++) {
			cash.Push(matr->Peep(i));
		}
		const double eps = 0.0001;
		double det = 1;
		for (int i = 0; i < row; i++) {
			int k = i;
			for (int j = i + 1; j < row; j++)
				if (abs(cash.Peep(row * j + i)) > abs(cash.Peep(row * k + i)))
					k = j;
			if (abs(cash.Peep(row * k + i)) < eps) {
				det = 0;
				break;
			}
			for (int p = 0; p < row; p++) {
				double tmp = cash.Peep(row * i + p);
				cash.Push(row * i + p, cash.Peep(row * k + p));
				cash.Push(row * k + p, tmp);
			}
			if (i != k) {
				det = -det;
			}
			det *= cash.Peep(row * i + i);
			for (int j = i + 1; j < row; j++) {
				cash.Push(row * i + j, cash.Peep(row * i + j) / cash.Peep(row * i + i));
			}
			for (int j = 0; j < row; j++) {
				if (j != i && abs(cash.Peep(row * j + i)) > eps) {
					for (int k = i + 1; k < row; k++) {
						cash.Push(row * j + k, cash.Peep(row * j + k) - cash.Peep(row * i + k) * cash.Peep(row * j + i));
					}
				}
			}
		}
		return det;
	}
}

template <typename T>
void Matr<T>::Print() const {
	int counter = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matr->Peep(counter) << ends;
			counter++;
		}
		cout << endl;
	}
}

int main() {
	Matr<int> a(3, 3);
	a.setMatr();
	a.Print();
	cout << endl;
	a.Mult(a).Print();
	cout << endl;
	a.Plus(a).Print();
	cout << endl;
	cout << a.Det() << endl;
	Matr<int> b(a);
	b.Print();
	b.setMatr();
	b.Print();
	cout << endl;
	b.Mult(b).Print();
	cout << endl;
	b.Plus(b).Print();
	cout << endl;
	cout << b.Det() << endl;
	return 0;
}