#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Sort {
    vector<int> mas;
  public:
    Sort();
    Sort(int);
    void Print() const;
    void Bubble();
    void Cocktail();
    void Insertion();
    void TreeS();
    void Quick(int, int);
    void Heap();
};

Sort::Sort() {
    auto r = [](int max, int min) { return rand() % (max - min + 1) + min; };
    for (int i = 0; i < 10; i++)
        mas.push_back(r(10, 0));
}

Sort::Sort(int num) {
    auto r = [](int max, int min) { return rand() % (max - min + 1) + min; };
    for (int i = 0; i < num; i++)
        mas.push_back(r(num, 0));
}

void Sort::Print() const {
    for (int i = 0; i < mas.size(); i++)
        cout << mas[i] << ends;
    cout << endl;
}

void Sort::Bubble() {
    for (int i = 0; i < mas.size() - 1; i++)
        for (int j = 0; j < mas.size() - 1 - i; j++)
            if (mas[j] > mas[j + 1])
                swap(mas[j], mas[j + 1]);
}

void Sort::Cocktail() {
    int l = 0;
    int r = mas.size() - 1;
    for (int count = 0; count < mas.size() / 2; count++) {
        for (int i = l; i < r; i++)
            if (mas[i] > mas[i + 1])
                swap(mas[i], mas[i + 1]);
        r--;
        for (int i = r; i > l; i--)
            if (mas[i - 1] > mas[i])
                swap(mas[i - 1], mas[i]);
        l++;
    }
}

void Sort::Insertion() {
    int tmp = 0;
    for (int i = 1; i < mas.size(); i++) {
        tmp = mas[i];
        for (int j = 0; j < i; j++)
            if (mas[j] > tmp) {
                for (int k = i; k > j; k--)
                    swap(mas[k - 1], mas[k]);
                break;
            }
    }
}

class Tree : public Sort {
    int num;
    Tree *left;
    Tree *right;

  public:
    Tree() {num = 0; left = nullptr; right = nullptr;}
    void Push(int);
    void Print() const;
};

void Tree::Push(int n) {
    if (this->left == nullptr && this->right == nullptr) {
        this->left = new Tree();
        this->right = new Tree();
        this->num = n;
    }
    else if (this->num > n)
        this->left->Push(n);
    else
        this->right->Push(n);
}
void Tree::Print() const {
    if (this->left != nullptr || this->right != nullptr) {
        this->left->Print();
        cout << this->num << ends;
        this->right->Print();
    }
}

void Sort::TreeS() {
    Tree t;
    for (int i : mas)
        t.Push(i);
    // t.Print();
    // cout << endl;
}

void Sort::Quick(int l, int r) {
    int left = l;
    int right = r;
    int m = (l + r) / 2;
    while(l <= r) {
        while(mas[l] < mas[m]) l++;
        while(mas[r] > mas[m]) r--;
        if(l <= r) {
            swap(mas[l], mas[r]);
            l++;
            r--;
        }
    }
    if(r > left) Quick(left, r);
    if(l < right) Quick(l, right);
}

void Sort::Heap() {
    for(int i = mas.size() / 2 - 1; i >= 0; i--) {
        int j = i;
        while(true) {
            int l = 2 * j + 1;
            int r = 2 * j + 2;
            int tmp = j;
            if(mas[tmp] < mas[l] && l < mas.size()) 
                tmp = l;
            if(mas[tmp] < mas[r] && r < mas.size()) 
                tmp = r;
            if(tmp != j) {
                swap(mas[j], mas[tmp]);
                j = tmp;
            } else 
                break;
        }
    }
    for(int i = mas.size() - 1; i >= 0; i--) {
        swap(mas[0], mas[i]);
        int j = i;
        while(true) {
            int l = 2 * j + 1;
            int r = 2 * j + 2;
            int tmp = j;
            if(mas[tmp] < mas[l] && l < mas.size()) 
                tmp = l;
            if(mas[tmp] < mas[r] && r < mas.size()) 
                tmp = r;
            if(tmp != j) {
                swap(mas[j], mas[tmp]);
                j = tmp;
            } else 
                break;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    Sort s(n);
    s.Print();
    auto b = clock();
    s.Heap();
    auto e = clock();
    s.Print();
    cout << e - b << endl;
}