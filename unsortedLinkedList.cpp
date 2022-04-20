/**
 * @file unsorted.cpp
 * @author Eyasu Yidnekachew Asres
 * @id UGR/22616/13
 * @brief This program insert data with order O(1) 
 * and delete data with O(1)
 * search data is also available in this program
 * @date 2022-03-31
 * @copyright Copyright (c) 2022
 */

#include <iostream>
using namespace std;

struct Node{
    int num;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
int nodeCounter = 0;

Node* createData(){
    Node* newNode = new Node;
    cout << "\tEnter Number: ";
    cin >> newNode->num;
    newNode->next = NULL;
    newNode->prev = NULL;
    nodeCounter++;
    return newNode;
}

int search(int key){
    int i = 1;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->num == key){
            cout << endl << "Found! " << key << " is " << i << "th item\n";
            return i;
        }
        i++;
        temp = temp->next;
    }
    cout << "\nNot found!\n";
    return -1;
}

void insertAtBeginning(){
    Node* ptr = createData();
    if(head == NULL){
        head = tail = ptr;
    } else {
        Node* temp = head;
        ptr->next = temp;
        head = ptr;
    }
    cout << "\tItem added successfully\n";
}

void insertAtEnd(){
    Node* ptr = createData();
    if (head == NULL){
        head = tail = ptr;
    } else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
    cout << "\tItem added successfully\n";
}

int deleteFirst(){
    if (head == NULL){
        cout << "No data!";
        return 0;
    }
    if (nodeCounter == 1){
    Node* temp = head;
    head = NULL;
    delete temp;
    nodeCounter--;
    } else {
        Node* temp = head;
        head->next->prev = NULL;
        head = head->next;
        delete temp;
        nodeCounter--;
    }
    cout <<  "\tItem deleted successfully!\n";
    return 0;
}

int deleteLast(){
    if (head == NULL){
        cout << "No data!";
        return 0;
    }
    if (nodeCounter == 1){
        Node* temp = head;
        head = NULL;
        delete temp;
        nodeCounter--;
    } else {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        nodeCounter--;
    }
    cout <<  "\tItem deleted successfully!\n";
    return 0;
}

int deleteTheMid(){
    int pos;
    cout << "\tSelect Item: ";
    cin >> pos;
    if (pos < 0 || pos > nodeCounter + 1){
        cout << "No item found at this position\n";
        return 0;
    }
    if (pos == 1){
        deleteFirst();
    } else if (pos == nodeCounter + 1){
        deleteLast();
    } else {
        Node* temp = head;
        pos--;
        while (--pos){
            temp = temp->next;
        }
        Node* deleteItem = temp->next;
        temp->next = deleteItem->next;
        temp->next->prev = temp;
        delete deleteItem;    
        nodeCounter--; 
        cout <<  "\tItem deleted successfully!\n";
    }
    return 0;
}

void printData(){
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->num << " ";
        temp = temp->next;
    }
        cout << endl;
}

int menu(){
    cout << "1. Insert at the Beginning\n"
    << "2. Insert at the end\n"
    << "3. Delete the first item\n"
    << "4. Delete the last item\n"
    << "5. Delete at any pos\n"
    << "6. print item\n"
    << "7. Search Data\n"
    << "Other close the program\n"
    << "Choose number: ";
    int num;
    cin >> num;
    switch (num)
    {
    case 1:
        insertAtBeginning();
        cout << endl;
        break;
    case 2:
        insertAtEnd();
        break;
    case 3:
        deleteFirst();
        cout << endl;
        break;
    case 4:
        deleteLast();
        cout << endl;
        break;
    case 5:
        deleteTheMid();
        cout << endl;
        break;
    case 6:
        printData();
        cout << endl;
        break;
    case 7:
        cout << "Enter the number you want to search: ";
        int num;
        cin >> num;
        search(num);
        cout << endl;
        break;
    default:
        return -1;
        break;
    }
    return 0;
}

int main(){
    int stop;
    while(stop != -1){
        stop = menu();
    }
    return 0;
}