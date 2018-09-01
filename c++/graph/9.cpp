#include <iostream>
#include <iomanip>
using namespace std;

// Vector

template <typename T>
class Vector {
  public:
    Vector();
    Vector(const Vector<T> &);
    ~Vector();
    void Clean();
    Vector<T> &operator=(const Vector<T> &);
    void operator()(const T &);
    void operator()(const int &, const T &);
    void Pop();
    T operator[](const int &) const;
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
    if (this->getSize() != 0)
        this->~Vector();
    size = 0;
    index = 0;
    Vector<T> *cash = d.head;
    while (cash) {
        this->operator()(cash->data);
        cash = cash->tail;
    }
}

template <typename T>
Vector<T>::~Vector() {
    Clean();
}

template <typename T>
void Vector<T>::Clean() {
    while (head)
        Pop();
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &d) {
    if (this->getSize() != 0)
        this->~Vector();
    size = 0;
    index = 0;
    Vector<T> *cash = d.head;
    while (cash) {
        this->operator()(cash->data);
        cash = cash->tail;
    }
    return (*this);
}

template <typename T>
void Vector<T>::operator()(const T &num) {
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
    size++;
    index++;
}

template <typename T>
void Vector<T>::operator()(const int &ind, const T &num) {
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
}

template <typename T>
void Vector<T>::Pop() {
    if (head) {
        Vector<T> *cash = head;
        head = head->tail;
        delete cash;
        if (!head)
            tail = NULL;
        --size;
        --index;
    }
}

template <typename T>
T Vector<T>::operator[](const int &ind) const {
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
    return cash->data;
}

template <typename T>
int Vector<T>::getSize() const {
    return size;
}

// Graph

class ElOrientedGraph {
  public:
    ElOrientedGraph();
    ElOrientedGraph(const int &);
    void setWeight(const int &);
    int getWeight() const;
    virtual void Print() const = 0;

  protected:
    int weight;
};

ElOrientedGraph::ElOrientedGraph() {
    weight = 0;
}

ElOrientedGraph::ElOrientedGraph(const int &myWeight) {
    weight = myWeight;
}

void ElOrientedGraph::setWeight(const int &myWeight) {
    weight = myWeight;
}

int ElOrientedGraph::getWeight() const {
    return weight;
}

class Vertex : public ElOrientedGraph {
  public:
    Vertex();
    Vertex(const int &);
    Vertex(const Vertex &);
    Vertex setVertex(const int &);
    void Print() const;
};

Vertex::Vertex() : ElOrientedGraph(0) {
}

Vertex::Vertex(const int &myWeight) : ElOrientedGraph(myWeight) {
}

Vertex::Vertex(const Vertex &d) : ElOrientedGraph(d.weight) {
}

Vertex Vertex::setVertex(const int &myWeight) {
    setWeight(myWeight);
    return (*this);
}

void Vertex::Print() const {
    cout << "Weight of the vertex: ";
    cout << weight << endl;
}

class Arc : public ElOrientedGraph {
  public:
    Arc();
    Arc(const int &, const Vertex &, const Vertex &);
    Arc(const Arc &);
    ~Arc();
    const Vector<Vertex> &getCoor() const;
    Arc setArc(const int &, const Vertex &, const Vertex &);
    void Print() const;

  private:
    Vector<Vertex> coor;
};

Arc::Arc() : ElOrientedGraph(0) {
    coor(0);
    coor(0);
}

Arc::Arc(const int &myWeight, const Vertex &a, const Vertex &b) : ElOrientedGraph(myWeight) {
    coor.~Vector();
    coor(a);
    coor(b);
}

Arc::Arc(const Arc &d) : ElOrientedGraph(d.weight) {
    if(coor.getSize() != 0)
        coor.~Vector();
    coor(d.getCoor()[0]);
    coor(d.getCoor()[1]);
}

Arc::~Arc() {
    coor.~Vector();
}

const Vector<Vertex> &Arc::getCoor() const {
    return this->coor;
}

Arc Arc::setArc(const int &myWeight, const Vertex &a, const Vertex &b) {
    setWeight(myWeight);
    if (coor.getSize() != 0)
        coor.~Vector();
    coor(a);
    coor(b);
    return (*this);
}

void Arc::Print() const {
    cout << "Weight of the arc: ";
    cout << weight << endl;
    cout << "Begin of the arc: ";
    cout << coor[0].getWeight() << endl;
    cout << "End of the arc: ";
    cout << coor[1].getWeight() << endl;
}

class Graph {
  public:
    Graph();
    Graph(Graph &);
    ~Graph();
    void AddVertex(const Vertex &);
    void AddArc(const Arc &);
    int **MakeAdjacencyMatrix();
    int **MakeIncidenceMatrix();
    void PrintAdjacencyMatrix() const;
    void PrintIncidenceMatrix() const;
    int DijkstraAlgorithm(const Vertex &, const Vertex &) const;
    void PrintGraph();

  private:
    int **adjacencyMatrix;
    int **incidenceMatrix;
    Vector<Vertex> vertices;
    Vector<Arc> arcs;
};

Graph::Graph() {
    adjacencyMatrix = nullptr;
    incidenceMatrix = nullptr;
}

Graph::Graph(Graph &d) {
    if (vertices.getSize() != 0)
        vertices.~Vector();
    for (int i = 0; i < d.vertices.getSize(); i++)
        vertices(d.vertices[i]);

    if (arcs.getSize() != 0)
        arcs.~Vector();
    for (int i = 0; i < d.arcs.getSize(); i++)
        arcs(d.arcs[i]);
}

Graph::~Graph() {
    vertices.~Vector();
    arcs.~Vector();
    for (int i = 0; i < vertices.getSize(); i++) {
        delete[] adjacencyMatrix[i];
        delete[] incidenceMatrix[i];
    }
}

void Graph::AddVertex(const Vertex &d) {
    vertices(d);
}

void Graph::AddArc(const Arc &d) {
    arcs(d);
}

int **Graph::MakeAdjacencyMatrix() {

    adjacencyMatrix = new int *[vertices.getSize()];
    for (int i = 0; i < vertices.getSize(); i++) {
        adjacencyMatrix[i] = new int[vertices.getSize()];
        for (int j = 0; j < vertices.getSize(); j++)
            adjacencyMatrix[i][j] = 0;
    }
    for (int i = 0; i < arcs.getSize(); i++)
        adjacencyMatrix[arcs[i].getCoor()[0].getWeight() - 1][arcs[i].getCoor()[1].getWeight() - 1]++;
    return adjacencyMatrix;
}

int **Graph::MakeIncidenceMatrix() {

    incidenceMatrix = new int *[vertices.getSize()];
    for (int i = 0; i < vertices.getSize(); i++) {
        incidenceMatrix[i] = new int[arcs.getSize()];
        for (int j = 0; j < arcs.getSize(); j++)
            incidenceMatrix[i][j] = 0;
    }
    for (int i = 0; i < arcs.getSize(); i++) {
        if (arcs[i].getCoor()[0].getWeight() == arcs[i].getCoor()[1].getWeight())
            incidenceMatrix[arcs[i].getCoor()[0].getWeight() - 1][i] = -2; else {
            incidenceMatrix[arcs[i].getCoor()[0].getWeight() - 1][i]--;
            incidenceMatrix[arcs[i].getCoor()[1].getWeight() - 1][i]++;
        }
    }
    return incidenceMatrix;
}

int Graph::DijkstraAlgorithm(const Vertex &a, const Vertex &b) const {
    if(a.getWeight() == b.getWeight())
        return 0;
    
    int **weightOfEl = new int *[vertices.getSize()];
    for (int i = 0; i < vertices.getSize(); i++) {
        weightOfEl[i] = new int[vertices.getSize()];
        for (int j = 0; j < vertices.getSize(); j++)
            weightOfEl[i][j] = 0;
    }

    for (int i = 0; i < arcs.getSize(); i++)
        weightOfEl[arcs[i].getCoor()[0].getWeight() - 1][arcs[i].getCoor()[1].getWeight() - 1] = arcs[i].getWeight();

    int *distance = new int[vertices.getSize()];
    bool *visited = new bool[vertices.getSize()];
    int index, m = a.getWeight();

    for (int i = 0; i < vertices.getSize(); i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[a.getWeight() - 1] = 0;

    for (int i = 0; i < b.getWeight() - 1; i++) {
        int min = INT_MAX;
        for (int j = 0; j < vertices.getSize(); j++)
            if (!visited[j] && distance[j] <= min) {
                min = distance[j];
                index = i;
            }
        visited[index] = true;
        for (int i = 0; i < vertices.getSize(); i++)
            if (!visited[i] && weightOfEl[index][i] && distance[index] != INT_MAX && distance[index] + weightOfEl[index][i] < distance[i])
                distance[i] = distance[index] + weightOfEl[index][i];
    }
    if (distance[b.getWeight() - 1] != INT_MAX)
        return distance[b.getWeight() - 1];
    cout << ">ERROR: route unavailable" << endl;
    return INT_MAX;
}

void Graph::PrintAdjacencyMatrix() const {
    for (int i = 0; i < vertices.getSize(); i++) {
        for (int j = 0; j < vertices.getSize(); j++)
            cout << setw(3) << adjacencyMatrix[i][j];
        cout << endl;
    }
}

void Graph::PrintIncidenceMatrix() const {
    for (int i = 0; i < vertices.getSize(); i++) {
        for (int j = 0; j < arcs.getSize(); j++)
            cout << setw(3) << incidenceMatrix[i][j];
        cout << endl;
    }
}

void Graph::PrintGraph() {
    ElOrientedGraph *g = nullptr;
    for(int i = 0; i < vertices.getSize() + arcs.getSize(); i++) {
        if(i < vertices.getSize())
            g = new Vertex(vertices[i].getWeight());
        else
            g = new Arc(arcs[i - vertices.getSize()].getWeight(), arcs[i - vertices.getSize()].getCoor()[0].getWeight(), arcs[i - vertices.getSize()].getCoor()[1].getWeight());
        g->Print();
    }
    delete[] g;
}

int main() {
    Graph obj;
    Vertex a1, a2, a3, a4, a5, a6, a7, a8, a9;
    Arc b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20;

    obj.AddVertex(a1.setVertex(1));
    obj.AddVertex(a2.setVertex(2));
    obj.AddVertex(a3.setVertex(3));
    obj.AddVertex(a4.setVertex(4));
    obj.AddVertex(a5.setVertex(5));
    obj.AddVertex(a6.setVertex(6));
    obj.AddVertex(a7.setVertex(7));
    obj.AddVertex(a8.setVertex(8));
    obj.AddVertex(a9.setVertex(9));

    obj.AddArc(b1.setArc(6, a1, a2));
    obj.AddArc(b2.setArc(7, a1, a5));
    obj.AddArc(b3.setArc(5, a1, a4));
    obj.AddArc(b4.setArc(1, a2, a3));
    obj.AddArc(b5.setArc(8, a2, a6));
    obj.AddArc(b6.setArc(5, a2, a5));
    obj.AddArc(b7.setArc(3, a3, a6));
    obj.AddArc(b8.setArc(1, a4, a2));
    obj.AddArc(b9.setArc(2, a4, a5));
    obj.AddArc(b10.setArc(7, a4, a8));
    obj.AddArc(b11.setArc(3, a4, a7));
    obj.AddArc(b12.setArc(1, a5, a3));
    obj.AddArc(b13.setArc(8, a5, a9));
    obj.AddArc(b14.setArc(4, a5, a8));
    obj.AddArc(b15.setArc(1, a6, a5));
    obj.AddArc(b16.setArc(3, a6, a9));
    obj.AddArc(b17.setArc(1, a7, a5));
    obj.AddArc(b18.setArc(2, a7, a8));
    obj.AddArc(b19.setArc(1, a8, a6));
    obj.AddArc(b20.setArc(4, a8, a9));

    obj.MakeAdjacencyMatrix();
    obj.MakeIncidenceMatrix();
    obj.PrintAdjacencyMatrix(); cout << endl;
    obj.PrintIncidenceMatrix(); cout << endl;
    cout << "1 > 1: " << obj.DijkstraAlgorithm(a1, a1) << endl;
    cout << "1 > 2: " << obj.DijkstraAlgorithm(a1, a2) << endl;
    cout << "1 > 3: " << obj.DijkstraAlgorithm(a1, a3) << endl;
    cout << "1 > 4: " << obj.DijkstraAlgorithm(a1, a4) << endl;
    cout << "1 > 5: " << obj.DijkstraAlgorithm(a1, a5) << endl;
    cout << "1 > 6: " << obj.DijkstraAlgorithm(a1, a6) << endl;
    cout << "1 > 7: " << obj.DijkstraAlgorithm(a1, a7) << endl;
    cout << "1 > 8: " << obj.DijkstraAlgorithm(a1, a8) << endl;
    cout << "1 > 9: " << obj.DijkstraAlgorithm(a1, a9) << endl;
    cout << endl;
    obj.PrintGraph();
    return 0;
}