// COMSC-210 | Lab 17 | Gillian Rhett
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node*);
// my function prototypes
void push_front(Node*&, float); // add a node to the front
void push_back(Node*&, float); // add a node to the tail
void deleteNode(Node*&); // delete a node, user inputs index
void insertNode(Node*&); // insert a node, user inputs index
void deleteList(Node*&); // delete the entire linked list

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adding node at head
        push_front(head, tmp_val);
    }
    output(head);

    // I added this to demo push_back
    cout << "Enter a value to append to the tail: ";
    float valIn;
    cin >> valIn;
    push_back(head, valIn);
    output(head);

    // deleting a node
    deleteNode(head);

    output(head);

    // inserting a node
    insertNode(head);
    
    output(head);

    // deleting the linked list
    deleteList(head);

    output(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void push_front(Node* &hd, float val) { // add a node to the front
// pass-by-reference because head needs to point to the new node
    // step 1 make the new node
    Node* newnode = new Node;
    newnode->value = val;
    if (hd)
        newnode->next = hd;
    else // if the list is empty
        newnode->next = nullptr;

    // step 2 make head point to the new node
    hd = newnode;
}

void push_back(Node* &hd, float val) { // add a node to the tail
// pass-by-reference because the last node's next needs to change
    // step 1 make a new node
    Node* newnode = new Node;
    newnode->value = val;
    newnode->next = nullptr;

    // step 2 traverse the list to get to the last node
    if(!hd)
        hd = newnode; // if list is empty, this new node is the head
    else {
        Node *current = hd;
        while (current->next != nullptr) {
            current = current->next;
        }
        // make the tail point to the new node instead of nullptr
        current->next = newnode;
    }
}

void deleteNode(Node* &hd) { // delete a node
// pass-by-reference in case head node is deleted so pointer needs to change
    cout << "Which node to delete? " << endl;
    output(hd);
    cout << "Choice --> ";
    // validate input for min value (max is taken care of in the for loop)
    int entry = 0;
    while (entry <= 0) {
        cin >> entry;
        if (entry <= 0)
            cout << "enter at least 1: ";
    }

    // traverse that many times and delete that node
    Node *current = hd;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion
    int i;
    for (i = 0; i < (entry - 1) && current->next != nullptr; ++i) {
        prev = current;
        current = current->next;
    }
    // if they entered a number too high, it shows an error message and doesn't delete anything

    if (entry - 1 == i && current) {
    // if entry is a valid index number for this list, delete the current node
        if (prev == nullptr) {
            // deleting the head node
            hd = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    else
        cout << "Error: the last node is number " << i + 1 << endl;
}

void insertNode(Node* &hd) { // insert a node
// pass-by-reference so head pointer can be changed if the item is inserted at index 0
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    // validate input for min value (max is taken care of in the for loop)
    int entry = -1;
    while (entry < 0) {
        cin >> entry;
        if (entry < 0)
            cout << "enter at least 0: ";
    }

    current = hd;
    Node* prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry && current != nullptr; i++) {
        prev = current;
        current = current->next;
    } // if they entered a number too high, it inserts at the last node

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        hd = newnode;
    } else {
        prev->next = newnode;
    }
}

void deleteList(Node* &hd) { // delete the entire linked list
// pass-by-reference so head can be changed to nullptr
    Node* current = hd;
    while (current) {
        hd = current->next;
        delete current;
        current = hd;
    }
    hd = nullptr;
}