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
void push_front(Node*, float); // add a node to the front
void push_back(Node*, float); // add a node to the tail
void deleteNode(Node*&); // delete a node, user inputs index
void insertNode(Node*&); // insert a node, user inputs index
void deleteList(Node*&); // delete the entire linked list

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head // TODO replace this with push_front
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // I added this to demo push_back
    cout << "Enter a value to add to the tail: ";
    float valIn;
    cin >> valIn;
    push_back(head, valIn);

    // deleting a node
    deleteNode(head);

    output(head);

    // insert a node
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

    // step 2 make the new node point to what was item 0
    
    // step 3 make head point to the new node
}

void push_back(Node* hd, float val) { // add a node to the tail
// doesn't need pass-by-reference because this won't change the head pointer
    // step 1 traverse the list to get to the last node

    // step 2 make a new node and make the tail point to it instead of nullptr

}

void deleteNode(Node* &hd) { // delete a node
// pass-by-reference in case head node is deleted so pointer needs to change
    cout << "Which node to delete? " << endl;
    output(hd);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = hd;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            hd = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
}

void insertNode(Node* &hd) { // insert a node
// pass-by-reference so head pointer can be changed if the item is inserted at index 0
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = hd;
    Node* prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

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