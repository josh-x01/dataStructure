/**
 * @file Question 2.cpp
 * @author Eyasu Yidnekachew Asres
 * @id UGR/22616/13
 * @brief This program insert data at the end of the list with O(1)
 * @date 2022-03-30
 */
#include <iostream>
using namespace std;

struct Node{
    string age;
    Node *next;
    Node* prev;
};

Node* head = NULL;
Node* tail;
Node* last;
Node* counter;

int display(){
    cout << endl;
    if (counter == 0){
        cout << "No data!\n\n";
        return 0;
    }
    Node *temp = head;
    while(temp != NULL){
        cout  << temp->age << "  ";
        temp = temp->next;
    }
    cout << endl << endl;
    return 0;
}

Node* createNode(){
    Node* newNode = new Node;
    cout << "Age: ";
    cin >> newNode->age;
    cout << endl;
    newNode->next = NULL;
    newNode->prev = NULL;
    counter++;
    return newNode;
}

void insertWithOrderZero(){
    if (head == NULL){
        last = createNode();
        head = last;
        tail = last;
    } else {
        last = createNode();
        tail->next = last;
        last->prev = tail;
        tail = last;
    }
}

int main(){
    cout << "This program insert a data at the end of the list with order zero!\n\n";
    char ch;
    while(true){
        cout << "1. Insert\n"
        << "2. Display\n"
        << "3. Close program\n"
        << "Enter number: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            insertWithOrderZero();
            break;
        case '2':
            display();
            break;
        case '3':
            return 0;
        default:
            cout << "Incorrect input!";
            return 0;
            break;
        }
    }
    return 0;
}