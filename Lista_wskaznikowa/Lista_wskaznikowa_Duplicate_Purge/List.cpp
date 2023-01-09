#include <iostream>

class ArrayList {
public:
    int *arr = new int[4];
    int last = 0;

    int First() {
        return 0;
    }

    int End() {
        return last + 1;
    }

    int Next(int p) {
        return (End() >= p + 1) ? (p + 1) : -1;
    }

    int Previous(int p) {
        return (p - 1 >= 0 && End() >= p) ? (p - 1) : -1;
    }

    bool Insert(int x, int p) {
        if (p > End() || p < 0) {
            return false;
        }

        for (int i = End(); i > p; i--) {
            arr[i] = arr[i - 1];
        }

        arr[p] = x;
        last++;
        return true;
    }

    bool Delete(int p) {
        if (p >= End() || p < 0)
            return false;
        while (p < last) {
            arr[p] = arr[p + 1];
            p++;
        }
        arr[last] = 0;
        last--;
        return true;
    }

    int Locate(int x) {
        for (int i = 0; i < last; i++) {
            if (arr[i] == x)
                return i;
        }

        return End();
    }

    int Retrieve(int p) {
        return (p <= last || p >= 0) ? arr[p] : INT_MIN;
    }

    void Duplicate() {
        int *arrToDuplicate = new int[100];

        if (2 * End() > 100) {
            arrToDuplicate = new int[200];
        }

        for (int i = 0; i < End(); i++) {
            arrToDuplicate[i] = arr[i];
            arrToDuplicate[End() + i] = arr[i];
        }

        arr = arrToDuplicate;
        last += last + 1;
    }

    void Purge() {
        for (int i = 0; i < End(); i++) {
            for (int j = 0; j < End(); j++) {
                if (arr[i] == arr[j] && i != j) {
                    Delete(j);
                }
            }
        }
    }
};


void print(ArrayList l)
{
    int i=l.First();
    while (i!=l.End())
    {
        printf ("  %d,", l.Retrieve(i));
        i=l.Next(i);
    }
    printf("\n");

}

        //TEST

int main() {
    ArrayList l;
    l.last=-1;
    l.Insert(100,l.First());
    print (l);

    for (int i=0; i<3;i++)
        l.Insert(i,l.First());
    print (l);
    std::cout << "Duplicated: ";
    l.Duplicate();
    print(l);
    l.Insert(50, 3);
    l.Insert(50, 3);
    std::cout << "Dodaje 2 razy 50 żeby ukazac dzialanie purge";
    print(l);
    l.Purge();
    std::cout << "Purged: ";
    print(l);
    return 0;
}
