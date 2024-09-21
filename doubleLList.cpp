#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int x){
    Node* newNode = new Node();
    newNode -> data = x;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}
void InsertToHead(int x){
    Node* newNode = GetNewNode(x);
    if (head == NULL){
        head = newNode;
        return;
    }

    head -> prev = newNode;
    newNode->next = head;
    head= newNode;
}

void InsertToTail(int x){
    Node * temp = head;
    Node* newNode = GetNewNode(x);
    if (head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next;
    temp -> next = newNode;
    newNode -> prev = temp;

    head -> prev = newNode;
    newNode->prev = head;
    head= newNode;
}


void Print(){
    struct Node* temp = head;
    cout << "list is" << endl;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void revPrint(){
    struct Node* temp = head;
    if (temp == NULL){
        return;
    }
    while (temp->next != NULL){
        temp = temp -> next;
    }
    cout << "Reverse list: " << endl;
    while(temp != NULL){
        cout << temp -> data << endl;
        temp = temp -> prev;
    }
}



int main(){
    head = NULL;
    InsertToHead(2); Print(); revPrint();
    InsertToHead(4); Print(); revPrint();
    InsertToHead(6); Print(); revPrint();
    InsertToTail(8); Print(); revPrint();
}