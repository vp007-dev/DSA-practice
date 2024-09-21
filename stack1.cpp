#include<stdio.h>
#include<iostream>
#define MAX_SIZE 101
using namespace std;
int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE - 1){
        cout << "ERROR STACKOVERFLOW" << endl;
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        cout << "ERROR : NO ELEMENT TO POP" << endl;
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

void Print(){
    cout << "STACK: " << endl;
    for(int i = 0; i <= top; i++){
        cout << A[i] << endl;
    }
    cout << "\n";
}


int main(){
    Push(2); Print();
    Push(5); Print();
    Push(10); Print();
    Pop();Print();
    Push(12); Print();

}