#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<cstring>
using namespace std;

void reverse(char C[], int n){
    stack<char> S;
    for(int i = 0; i < n; i++){
        S.push(C[i]);
    }
    for(int i = 0; i<n; i++){
        C[i] = S.top();
        S.pop();
    }
}

int main(){
    char C[51];
    printf("enter a string: ");
    gets(C);
    reverse(C, strlen(C));
    printf("OUTPUT= %s", C);
}