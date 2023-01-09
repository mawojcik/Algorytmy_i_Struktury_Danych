#include <iostream>

using namespace std;
const int maxlength=20;
typedef int elementtype;
typedef int position;

class Stos {
private:
    elementtype S[maxlength];
    position Top;

public:
    Stos() {
        Top = -1;
    }
    void Push(elementtype x) {
        if (Top < maxlength - 1) {
            Top++;
            S[Top] = x;
        } else {
            cout << "Brak miejsca na stosie" << endl;
        }
    }
    void Pop() {
        if (!Empty()) {
            Top--;
        } else {
            cout << "Stos jest pusty" << endl;
        }
    }
    bool Empty() {
        return Top == -1;
    }
    elementtype TopElem() {
        if (!Empty()) {
            return S[Top];
        } else {
            cout << "Stos jest pusty" << endl;
        }
    }
    void Makenull() {
        Top = -1;
    }
};

int main() {
    Stos s;

    // TESTY
    if (s.Empty()) {
        cout << "Stos jest pusty" << endl;
    } else {
        cout << "Stos NIE jest pusty" << endl;
    }

    cout << "Dodaje 5 na stos" << endl;
    s.Push(5);  //push element onto the stack

    cout << "Wartosc ze szczytu stosu:" << endl;
    cout << s.TopElem() << endl;   //print the top element of the stack

    if (s.Empty()) {
        cout << "Stos jest pusty" << endl;
    } else {
        cout << "Stos NIE jest pusty" << endl;
    }

    cout << "Usuwam element ze szczytu stosu" << endl;
    s.Pop();    //pop the top element

    if (s.Empty()) {
        cout << "Stos jest pusty" << endl;
    } else {
        cout << "Stos NIE jest pusty" << endl;
    }

    cout << "Dodaje 2 na stos" << endl;
    s.Push(2);  //push element onto the stack

    cout << "Dodaje 3 na stos" << endl;
    s.Push(3);  //push element onto the stack

    cout << "Wartosc ze szczytu stosu:" << endl;
    cout << s.TopElem() << endl;   //print the top element of the stack

    cout << "Oprozniam stos." << endl;
    s.Makenull();       // make the stack empty

    if (s.Empty()) {
        cout << "Stos jest pusty" << endl;
    } else {
        cout << "Stos NIE jest pusty" << endl;
    }
    return 0;
}