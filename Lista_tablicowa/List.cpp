#include <iostream>

using namespace std;

class List {
public:
    List() : int_array(new int[10]), length(0){};  // konstruktor domyślny

    int* int_array;
    int length;

    int First() {
        return int_array[0];
    }

    int End() {
        return length + 1;
    }

    int Next(int p) {
        if (length > p) return int_array[p + 1];
        return -1;
    }

    int Previous(int p) {
        if (length > p && p - 1 >= 0) return int_array[p - 1];
        return -1;
    }

    bool Insert(int x, int p) {
        if (p < 0 || p >= End()) return false;

        int* temporary_array = new int[End()];
        for (int i = 0; i < End(); i++) {
            if (i == p) {
                temporary_array[i] = x;
            } else if (i < p) {
                temporary_array[i] = int_array[i];
            } else {
                temporary_array[i] = int_array[i - 1];
            }
        }
        memcpy(int_array, temporary_array, End() * sizeof(int));
        length++;
        return true;
    }

    bool Delete(int p) {
        if (p < 0 || p >= End()) return false;

        while (p < length) {
            int_array[p] = int_array[p + 1];
            p++;
        }
        int_array[length] = 0;
        length--;
        return true;
    }

    int Locate(int x) {
        for (int i = 0; i < length; i++) {
            if (int_array[i] == x) return i;
        }
        return End();
    }

    int* Retrieve(int p) {
        if (p >= 0 || p <= length) {
            return &int_array[p];
        }
        return nullptr;
    }
};

void PrintList(List l) {
    for (int i = 0; i < l.End()-1; i++) {
        cout << " " << l.int_array[i];
    }
    cout << endl;
}

int main() {
    List l;

    cout << "Inserting to list" << endl;  // prezentacja Insert
    for (int i = 0; i < 20; i++) {
        l.Insert(i, i);
    }
    PrintList(l);

    cout << "Position of first element" << endl; // prezentacja First
    cout << l.First() << endl;

    cout << "Position after last element" << endl; // prezentacja End
    cout << l.End() << endl;

    cout << "Position after third element" << endl;
    cout << l.Next(3) << endl;

    cout << "Position before third element" << endl;
    cout << l.Previous(3) << endl;

    cout << "Delete fourth element" << endl; // prezentacja Delete
    l.Delete(4);
    PrintList(l);

    cout << "Position of number '3'" << endl; // prezentacja Locate
    cout << l.Locate(3) << endl;

    cout << "Pointer to third element " << endl; // prezentacja Retrieve
    cout << l.Retrieve(3) << endl;
}
