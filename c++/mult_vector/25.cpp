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
    void operator()(int, T);
    T Pop();
    T operator[](int) const;
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
void Vector<T>::operator()(int ind, T num) {
    try {
        if (ind < 0 || ind >= size)
            throw ">ERROR(): incorrect parameter(s)";
    } catch (char *str) {
        cout << str << endl;
    }
    Vector<T> *cash = head;
    while (cash) {
        if (ind == cash->index) {
            cash->data = num;
        }
        cash = cash->tail;
    }
    Vector<T> *add = new Vector<T>;
    add->data = num;
    add->tail = NULL;
    add->index = ind;
    tail->tail = add;
    tail = add;
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
T Vector<T>::operator[](int ind) const {
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
int Vector<T>::getSize() const {
    return size;
}

// MultVector

template <typename T>
class MultVector {
  public:
    MultVector(int = 2);
    MultVector(MultVector &);
    MultVector(int, T *);
    ~MultVector();
    int getDimSpace() const {
        return dSpace;
    }
    void operator=(MultVector<T> &);
    MultVector<T> operator+(MultVector<T> &);
    MultVector<T> operator-(MultVector<T> &);
    MultVector<T> operator*(T);
    int operator*(MultVector<T> &);
    bool operator==(MultVector<T> &);
    bool operator!=(MultVector<T> &);
    bool operator>=(MultVector<T> &);
    bool operator<=(MultVector<T> &);
    bool operator>(MultVector<T> &);
    bool operator<(MultVector<T> &);
    operator T *() const;

    friend ostream &operator<<(ostream &out, const MultVector<T> &d) {
        char a = 'z';
        out << "Initial coordinates" << endl;
        for (int i = 0; i < d.dSpace; i++) {
            out << a << ": " << d.coordinates[i] << endl;
            --a;
        }
        a = 'z';
        out << "The finite coordinates" << endl;
        for (int i = d.dSpace; i < 2 * d.dSpace; i++) {
            out << a << ": " << d.coordinates[i] << endl;
            --a;
        }
        return out;
    }

    friend istream &operator>>(istream &in, MultVector<T> &d) {
        T cashData;
        if (d.coordinates.getSize() == 0) {
            cout << "Enter initial coordinates" << endl;
            char a = 'z';
            for (int i = 0; i < d.dSpace; i++) {
                cout << a << ": ";
                --a;
                cin >> cashData;
                d.coordinates.Push(cashData);
            }
            cout << "Enter the finite coordinates" << endl;
            a = 'z';
            for (int i = 0; i < d.dSpace; i++) {
                cout << a << ": ";
                --a;
                cin >> cashData;
                d.coordinates.Push(cashData);
            }
        } else {
            cout << "Enter initial coordinates" << endl;
            char a = 'z';
            for (int i = 0; i < d.dSpace; i++) {
                cout << a << ": ";
                --a;
                cin >> cashData;
                d.coordinates(i, cashData);
            }
            cout << "Enter the finite coordinates" << endl;
            a = 'z';
            for (int i = d.dSpace; i < 2 * d.dSpace; i++) {
                cout << a << ": ";
                --a;
                cin >> cashData;
                d.coordinates(i, cashData);
            }
        }
        cout << endl;
        return in;
    }

  private:
    Vector<T> coordinates;
    int dSpace;
};

template <typename T>
MultVector<T>::MultVector(int mDSpace) {
    try {
        if (mDSpace < 1)
            throw ">ERROR(Constructor MultVector): incorrect parameter(s)";
    } catch (char *str) {
        cout << str << endl;
    }
    dSpace = mDSpace;
}

template <typename T>
MultVector<T>::MultVector(MultVector<T> &d) {
    dSpace = d.dSpace;
    if (coordinates.getSize() == 0)
        for (int i = 0; i < 2 * dSpace; i++)
            coordinates.Push(d.coordinates[i]);
    else
        for (int i = 0; i < 2 * dSpace; i++)
            coordinates(i, d.coordinates[i]);
}

template <typename T>
MultVector<T>::MultVector(int mDSpace, T *coor) {
    try {
        if (mDSpace < 1)
            throw ">ERROR(Constructor MultVector): incorrect parameter(s)";
    } catch (char *str) {
        cout << str << endl;
    }
    dSpace = mDSpace;
    if (coordinates.getSize() == 0) {
        for (int i = 0; i < 2 * dSpace; i++) {
            coordinates.Push(coor[i]);
        }
    } else {
        for (int i = 0; i < 2 * dSpace; i++) {
            coordinates(i, coor[i]);
        }
    }
}

template <typename T>
MultVector<T>::~MultVector() {
    coordinates.~Vector();
}

template <typename T>
void MultVector<T>::operator=(MultVector<T> &d) {
    dSpace = d.dSpace;
    if (coordinates.getSize() == 0) {
        for (int i = 0; i < dSpace * 2; i++)
            coordinates.Push(d.coordinates[i]);
    } else {
        coordinates.~Vector();
        for (int i = 0; i < dSpace * 2; i++)
            coordinates.Push(d.coordinates[i]);
    }
}

template <typename T>
MultVector<T> MultVector<T>::operator+(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Plus): these vectors do not fold";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    MultVector<T> p(dSpace);
    for (int i = 0; i < 2 * dSpace; i++)
        p.coordinates.Push(coordinates[i] + d.coordinates[i]);
    return p;
}

template <typename T>
MultVector<T> MultVector<T>::operator-(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Minus): these vectors are not subtracted";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    MultVector<T> p(dSpace);
    for (int i = 0; i < 2 * dSpace; i++)
        p.coordinates.Push(coordinates[i] - d.coordinates[i]);
    return p;
}

template <typename T>
MultVector<T> MultVector<T>::operator*(T num) {
    MultVector<T> p(dSpace);
    for (int i = 0; i < 2 * dSpace; i++)
        p.coordinates.Push(coordinates[i] * num);
    return p;
}

template <typename T>
int MultVector<T>::operator*(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Plus): these winds can not calculate the scalar product";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    int ans = 0;
    for (int i = 0; i < dSpace; i++) {
        ans += (coordinates[i + dSpace] - coordinates[i]) * (d.coordinates[i + dSpace] - d.coordinates[i]);
    }
    return ans;
}

template <typename T>
bool MultVector<T>::operator==(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Comparison ==): these vectors do not comparised";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    for (int i = 0; i < dSpace; i++) {
        if ((coordinates[i + dSpace] - coordinates[i]) != (d.coordinates[i + dSpace] - d.coordinates[i]))
            return false;
    }
    return true;
}

template <typename T>
bool MultVector<T>::operator!=(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Comparison !=): these vectors do not comparised";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    return !(*this == d);
}

template <typename T>
bool MultVector<T>::operator>=(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Comparison >=): these vectors do not comparised";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    for (int i = 0; i < dSpace; i++) {
        if ((coordinates[i + dSpace] - coordinates[i]) < (d.coordinates[i + dSpace] - d.coordinates[i]))
            return false;
    }
    return true;
}

template <typename T>
bool MultVector<T>::operator<=(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Comparison <=): these vectors do not comparised";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    for (int i = 0; i < dSpace; i++) {
        if ((coordinates[i + dSpace] - coordinates[i]) > (d.coordinates[i + dSpace] - d.coordinates[i]))
            return false;
    }
    return true;
}

template <typename T>
bool MultVector<T>::operator>(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Comparison >): these vectors do not comparised";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    for (int i = 0; i < dSpace; i++) {
        if ((coordinates[i + dSpace] - coordinates[i]) <= (d.coordinates[i + dSpace] - d.coordinates[i]))
            return false;
    }
    return true;
}

template <typename T>
bool MultVector<T>::operator<(MultVector<T> &d) {
    try {
        if (dSpace != d.dSpace)
            throw ">ERROR(Comparison <): these vectors do not comparised";
    } catch (char *str) {
        cout << str << endl;
        return NULL;
    }
    for (int i = 0; i < dSpace; i++) {
        if ((coordinates[i + dSpace] - coordinates[i]) >= (d.coordinates[i + dSpace] - d.coordinates[i]))
            return false;
    }
    return true;
}

template <typename T>
MultVector<T>::operator T *() const {
    T *mas = new T[coordinates.getSize()];
    for (int i = 0; i < coordinates.getSize(); i++) {
        mas[i] = coordinates[i];
    }
    return mas;
}

int main() {
    cout << ">a" << endl;
    MultVector<int> a(3), a_copy;
    cin >> a;
    a_copy = a;
    cout << ">a_copy" << endl;
    cout << a_copy;
    cout << endl;

    cout << ">b" << endl;
    int *mas = new int[4];
    for (int i = 0; i < a.getDimSpace() * 2; i++) {
        mas[i] = i + 5;
    }
    MultVector<int> b(a.getDimSpace(), mas);
    cout << b;
    cout << endl;

    cout << ">Plus" << endl;
    cout << a + b << endl;
    cout << ">Minus" << endl;
    cout << a - b << endl;
    cout << ">Mult" << endl;
    cout << a * 5 << endl;
    cout << ">Scalar product" << endl;
    cout << a * b << endl;
    int *g = (int *)a;
    for (int i = 0; i < a.getDimSpace() * 2; i++) {
        cout << i << " => " << g[i] << endl;
    }
    cout << endl;
    g = (int *)b;
    for (int i = 0; i < b.getDimSpace() * 2; i++) {
        cout << i << " => " << g[i] << endl;
    }
    cout << endl;
    cout << "== " << (a == b) << endl;
    cout << "!= " << (a != b) << endl;
    cout << ">= " << (a >= b) << endl;
    cout << "<= " << (a <= b) << endl;
    cout << "> " << (a > b) << endl;
    cout << "< " << (a < b) << endl;
    return 0;
}