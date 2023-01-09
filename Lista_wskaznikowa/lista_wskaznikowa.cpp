#include <iostream>
using namespace std;

class Node {
public:
    int data = 0;
    Node *next = nullptr;
    Node() = default;
    explicit Node(int data) {
        this->data = data;
    }
};

class LinkedList {
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }
    Node *next(Node *);
    Node *previous(Node *);
    Node *first();
    Node *end();
    void insertNode(Node *, int);
    Node *locate(int);
    int retrieve(Node *);
    Node *makenull();
    void printList();
    void deleteNode(Node *);
};

Node *LinkedList::first() {
    return head;
}

Node *LinkedList::end() {
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

Node *LinkedList::next(Node *p) {
    if (p == nullptr) {
        cout << "p is null!" << endl;
        return nullptr;
    }
    return p->next;
}

Node *LinkedList::previous(Node *p) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->next == p) {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

void LinkedList::deleteNode(Node *p) {
    Node *temp1, *temp2 = nullptr;
    if (head == nullptr) {
        cout << "List empty." << endl;
        return;
    }
    temp1 = head;
    if (p == head) {
        head = head->next;
        delete temp1;
        return;
    }
    while (temp1 != p) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;
}

void LinkedList::insertNode(Node* p, int data) {
    Node* n = new Node(data);
    if (first() == nullptr) {
        head = n;
        return;
    }
    if (head == p) {
        n->next = head;
        head = n;
    }
    else {
        Node *temp1, *temp2 = head;
        for (; temp2 != p; temp1 = temp2, temp2 = temp2->next);
        n->next = temp1->next;
        temp1->next = n;
    }
}

Node *LinkedList::locate(int data) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int LinkedList::retrieve(Node *p) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp == p) {
            return temp->data;
        }
        temp = temp->next;
    }
    return -1;
}

Node *LinkedList::makenull() {
    Node *current = head;
    Node *end = this->end();
    Node *next;
    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }
    head = nullptr;
    return end;
}

void LinkedList::printList() {
    Node *temp = head;
    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    auto *list = new LinkedList();
    cout << "POLECENIE: Wstaw 5 na początek (wykorzystując First())" << endl;
    list->insertNode(list->first(), 5);
    cout << "Pierwszy element: " << list->retrieve(list->first()) << endl;

    cout << "POLECENIE: Wstaw 2 na początek (wykorzystując First())" << endl;
    list->insertNode(list->first(), 2);
    cout << "Pierwszy element: " << list->retrieve(list->first()) << endl;
    cout << "Drugi element: " << list->retrieve(list->first()->next) << endl;

    cout << "POLECENIE: Wstaw 1 za pierwszym elementem (wykorzystując First() i Next())" << endl;
    list->insertNode(list->first()->next, 1);
    cout << "Wypisana lista: ";
    list->printList();
    cout << endl;

    cout << "POLECENIE: Wstaw 100 na koniec listy (wykorzystując END)" << endl;
    list->insertNode(list->next(list->end()), 100);
    cout << "Wypisana lista: ";
    list->printList();
    cout << endl;

    cout << "POLECENIE: Usuń element znajdujący się przed wartością 100 wykorzystując Locate() i Previous()" << endl;
    list->deleteNode(list->previous(list->locate(100)));

    cout << "Wypisana lista: ";
    list->printList();
    cout << endl;

//    list->makenull();
//    cout << "Wypisana lista (po makenull()): ";
//    list->printList();
//    cout << endl;
    return 0;
}