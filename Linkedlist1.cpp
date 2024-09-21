#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
void Insert(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print(){
    struct Node* temp = head;
    cout << "list is" << endl;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}


int main(){
    head = NULL;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "enter the number: " << endl;
        cin >> x;
        Insert(x);
        Print();
    }
}