#include <iostream>
using namespace std;

// Vector

template <typename T>
class Vector {
  public:
    Vector();
    Vector(const Vector<T> &);
    ~Vector();
    T Push(T = 0);
    T Push(int, T);
    T Pop();
    T Peep(int = 0) const;
    void Print() const;
    int getSize() const;

  private:
    T data;
    Vector<T> *head;
    Vector<T> *tail;
    int index;
    int size;
};

template <typename T>
Vector<T>::Vector() {
    head = NULL;
    tail = NULL;
    size = 0;
    index = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T> &d) {
    Vector<T> *cash = d.head;
    while (cash) {
        Push(cash->data);
        cash = cash->tail;
    }
}

template <typename T>
Vector<T>::~Vector() {
    while (head)
        Pop();
}

template <typename T>
T Vector<T>::Push(T num) {
    if (num) {
        Vector<T> *cash = new Vector<T>;
        cash->data = num;
        cash->tail = NULL;
        cash->index = index;
        if (head) {
            tail->tail = cash;
            tail = cash;
        } else {
            head = tail = cash;
        }
    }
    size++;
    index++;
    return num;
}

template <typename T>
T Vector<T>::Push(int ind, T num) {
    try {
        if (ind < 0 || ind >= size)
            throw ">ERROR(Push): incorrect parameter(s)";
    } catch (char *str) {
        cout << str << endl;
    }
    Vector<T> *cash = head;
    while (cash) {
        if (ind == cash->index) {
            cash->data = num;
            return num;
        }
        cash = cash->tail;
    }
    Vector<T> *add = new Vector<T>;
    add->data = num;
    add->tail = NULL;
    add->index = ind;
    tail->tail = add;
    tail = add;
    return num;
}

template <typename T>
T Vector<T>::Pop() {
    if (!head) {
        return NULL;
    } else {
        T cashData;
        Vector<T> *cash = head;
        cashData = cash->data;
        head = head->tail;
        delete cash;
        return cashData;
    }
}

template <typename T>
T Vector<T>::Peep(int ind) const {
    try {
        if (ind < 0 || ind >= size)
            throw ">ERROR(Peep): incorrect parameter(s)";
    } catch (char *str) {
        cout << str << endl;
    }
    Vector<T> *cash = head;
    while (cash) {
        if (ind == cash->index) {
            return cash->data;
        }
        cash = cash->tail;
    }
    return NULL;
}

template <typename T>
void Vector<T>::Print() const {
    Vector<T> *cash = head;
    while (cash) {
        cout << cash->data << ends;
        cash = cash->tail;
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
    Matr(T **, int = 2, int = 2);
    ~Matr();
    void setMatr();
    Matr<T> Plus(Matr<T> &);
    Matr<T> Mult(Matr<T> &);
    Matr<T> Mult(T = 1);
    double Det();
    void Print() const;
    friend Matr<T> Comparison(Matr<T> a, Matr<T> b) {
        if(a.Det() > b.Det()) {
            return a;
        } else {
            return b;
        }
    }

  private:
    Vector<T> matr;
    int row;
    int col;
};

template <typename T>
Matr<T>::Matr(int mRow, int mCol) {
    try {
        if (mRow < 1 || mCol < 1)
            throw ">ERROR(Constructor Matr): incorrect parameter(s)";
    } catch (char *str) {
        cout << str << endl;
    }
    row = mRow;
    col = mCol;
}

template <typename T>
Matr<T>::Matr(Matr<T> &d) {
    row = d.row;
    col = d.col;
    for (int i = 0; i < row * col; i++)
        matr.Push(d.matr.Peep(i));
}

template <typename T>
Matr<T>::Matr(T **mas, int mRow, int mCol) {
    row = mRow;
    col = mCol;
    if(matr.getSize() == 0) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                matr.Push(mas[i][j]);
            }
        }
    } else {
        int counter = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                matr.Push(counter, mas[i][j]);
                counter++;
            }
        }
    }
}

template <typename T>
Matr<T>::~Matr() {
    matr.~Vector();
}

template <typename T>
void Matr<T>::setMatr() {
    T cashData;
    if (matr.getSize() == 0) {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                cout << "matr[" << i << "][" << j << "] = ";
                cin >> cashData;
                matr.Push(cashData);
            }
        cout << endl;
    } else {
        int counter = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                cout << "matr[" << i << "][" << j << "] = ";
                cin >> cashData;
                matr.Push(counter, cashData);
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
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    Matr<T> p(row, col);
    for (int i = 0; i < row * col; i++)
        p.matr.Push(matr.Peep(i) + d.matr.Peep(i));
    return p;
}

template <typename T>
Matr<T> Matr<T>::Mult(Matr<T> &d) {
    try {
        if (col != d.row)
            throw ">ERROR(Mult): these matrices should not be multiplied";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    Matr<T> m(row, d.col);
    T a = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < d.col; j++) {
            for (int k = 0; k < col; k++)
                a += matr.Peep(row * i + k) * d.matr.Peep(j + row * k);
            m.matr.Push(a);
            a = 0;
        }
    }
    return m;
}

template <typename T>
Matr<T> Matr<T>::Mult(T num) {
    Matr<T> m(row, col);
    for (int i = 0; i < row * col; i++)
        m.matr.Push(matr.Peep(i) * num);
    return m;
}

template <typename T>
double Matr<T>::Det() {
    try {
        if (row != col)
            throw ">ERROR(Det): this matrix can not compute the determinant";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    if (row == 1)
        return matr.Peep(0);
    if (row == 2)
        return matr.Peep(0) * matr.Peep(3) - matr.Peep(1) * matr.Peep(2); 
    else {
        Vector<double> cash;
        for (int i = 0; i < row * row; i++) {
            cash.Push(matr.Peep(i));
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
            cout << matr.Peep(counter) << ends;
            counter++;
        }
        cout << endl;
    }
}

int main() {
    Matr<int> d(3, 3);
    d.setMatr();
    d.Print();
    cout << endl;
    cout << d.Det();
    cout << endl;
    return 0;
}