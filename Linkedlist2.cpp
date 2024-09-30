#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
void Insert(int data, int n){
    Node* temp1 = new Node();
    temp1 -> data = data;
    temp1 -> next = NULL;
    if(n == 1){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i <n-2; i++){
        temp2 = temp2 -> next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    
};

void Print(){
    struct Node* temp = head;
    cout << "list is" << endl;
    while(temp != NULL){
        cout << temp->data;
        cout << " ";
        temp = temp->next;
    }
}

void Delete(int n){
    struct Node* temp1 = head;
    if(n==1){
        head = temp1->next;
        delete(temp1);
        return;
    }
    // int i;
    for(int i = 0; i < n-2; i++){
        temp1 = temp1->next;
    }
    struct Node* temp2 = temp1 -> next;
    temp1->next = temp2->next;
    delete(temp2);
}


int main(){
    head = NULL;
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Print();
    Delete(2);
    Print();
}





//make calculator
