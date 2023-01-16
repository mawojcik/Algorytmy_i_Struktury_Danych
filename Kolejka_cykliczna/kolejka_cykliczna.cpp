#include <iostream>

using namespace std;
const int maxlength = 50;
typedef int elementtype;
typedef int position;

class Kolejka {
protected:
    elementtype Queue[maxlength];
    position Front; // Indeks elementu czołowego
    position Rear; // Indeks ostatniego elementu
public:
    Kolejka() = default;
    ~Kolejka() = default;
    int AddOne(int i);
    void Init();
    void Enqueue(elementtype x);
    void Dequeue();
    elementtype FrontElem();
    void Makenull();
    bool Empty();
};

int Kolejka::AddOne(int i) {
    return ((i + 1) % maxlength);
}

void Kolejka::Init() {
    Front = 0;
    Rear = maxlength - 1;
}

void Kolejka::Enqueue(elementtype x) {
    if (AddOne(AddOne(Rear)) != Front) // Kolejka niejest pełna
    {
        Rear = AddOne(Rear);
        Queue[Rear] = x;
    }
}

void Kolejka::Dequeue() {
    if (!Empty())
    {
        Front = AddOne(Front);
    }
}

elementtype Kolejka::FrontElem() {
    if (!Empty())
        return Queue[Front];
    return -1;
}

void Kolejka::Makenull() {
    Front = 0;
    Rear = maxlength - 1;
}

bool Kolejka::Empty() {
    return AddOne(Rear) == Front;
}

int main() {
    Kolejka kolejka;

    kolejka.Init();

    if (kolejka.Empty()) {
        cout << "Kolejka jest pusta" << endl;
    } else {
        cout << "Kolejka NIE jest pusta" << endl;
    }

    kolejka.Enqueue(5);

    if (kolejka.Empty()) {
        cout << "Kolejka jest pusta" << endl;
    } else {
        cout << "Kolejka NIE jest pusta" << endl;
    }

    cout << "Element z przodu: " << kolejka.FrontElem() << endl;

    kolejka.Dequeue();

    if (kolejka.Empty()) {
        cout << "Kolejka jest pusta" << endl;
    } else {
        cout << "Kolejka NIE jest pusta" << endl;
    }

    kolejka.Enqueue(4);
    kolejka.Enqueue(3);
    kolejka.Enqueue(2);
    cout << "Element z przodu: " << kolejka.FrontElem() << endl;
    kolejka.Enqueue(1);
    cout << "Element z przodu: " << kolejka.FrontElem() << endl;
    kolejka.Dequeue();
    cout << "Element z przodu: " << kolejka.FrontElem() << endl;
    kolejka.Enqueue(6);
    cout << "Element z przodu: " << kolejka.FrontElem() << endl;
    kolejka.Dequeue();
    kolejka.Dequeue();
    cout << "Element z przodu: " << kolejka.FrontElem() << endl;
    kolejka.Makenull();
    if (kolejka.Empty()) {
        cout << "Kolejka jest pusta" << endl;
    } else {
        cout << "Kolejka NIE jest pusta" << endl;
    }
    return 0;
}