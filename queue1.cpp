#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp -> data = x;
    temp -> next = NULL;
    if(front == NULL && rear = NULL){
        front  = rear = temp;
        return;
    }
    rear -> next = temp;
    rear = temp;
}

void dequeue(){
    struct Node* temp = front;
    if(front == NULL) return;
    if(front == rear){
        front  =  rear = NULL;
    }
    else{
        front = front->next;
    }
    free(temp);
}

int Front(){
    if(front == NULL){
        cout << "QUEUE IS EMPTY";
        return;
    }
    return front->data;
}

void Print(){
    struct Node* temp = front;
    while(temp != NULL){
        cout << temp -> data;
        temp = temp -> next;
    }
    cout << "\n";
}


int main(){
    enqueue(2); Print();
    enqueue(3); Print();
    enqueue(4); Print();
    dequeue(); Print();
    dequeue(); Print();
    dequeue(); Print();
}