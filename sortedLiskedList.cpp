/**
 * @file sorting.cpp
 * @author Eyasu Yidnekachew Asres
 * @brief This program insert data with descending order
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

void insertAtProperPosition(){
    Node *newNode = createData();
    int num = newNode->num;
    Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    while (temp != NULL)
    {
        if (num < temp->num)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = newNode;
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev = newNode;
            }
            else
            {

                newNode->next = temp;
                temp->prev = newNode;
                head = newNode;
            }
            return;
        }
        if (temp->next == NULL)
        {
            break;
        }

        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
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
    cout << "1. Insert Data\n"
    << "2. Delete the first item\n"
    << "3. Delete the last item\n"
    << "4. Delete at any pos\n"
    << "5. print item\n"
    << "6. Search Data\n"
    << "Other close the program\n"
    << "Choose number: ";
    int num;
    cin >> num;
    switch (num)
    {
    case 1:
        insertAtProperPosition();
        cout << endl;
        break;
    case 2:
        deleteFirst();
        cout << endl;
        break;
    case 3:
        deleteLast();
        cout << endl;
        break;
    case 4:
        deleteTheMid();
        cout << endl;
        break;
    case 5:
        printData();
        cout << endl;
        break;
    case 6:
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