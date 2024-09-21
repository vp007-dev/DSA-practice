#include<iostream>

using namespace std;

#define MAX_SIZE 101

class Queue
{
private:
    int A[MAX_SIZE];
    int front, rear;
    
public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool IsEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFool(){
        return (rear+1)%MAX_SIZE == front ? true : false;
    }

    void EnQueue(int x){
        if(isFool()){
            cout << "QUEUE IS FULLL" << endl;
            return;
        }
        if(IsEmpty()){
            front = rear = 0;
        }
        else{
            rear = (rear+1) % MAX_SIZE;
        }
        A[rear] = x;
    }

    void deQueue(){
        if(IsEmpty()){
            cout << "EMPTY QUEUE" << endl;
        }
        else if(front == rear){
            rear = front = -1;
        }
        else{
            front = (front + 1) % MAX_SIZE;
        }
    }

    int Front(){
        if(front == -1){
            cout << "EMPTY QUEUE" << endl;
            return -1;
        }
        return A[front];

    }

    void Print(){
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        cout <<"Queue         :";
        for (int i = 0; i < count; i++){
            int index = (front + i) % MAX_SIZE;
            cout << A[index] << " ";
        }
        cout << "\n\n";
    }
        
};


int main(){
    Queue Q;
    Q.EnQueue(2); Q.Print();
    Q.EnQueue(3); Q.Print();
    Q.EnQueue(4); Q.Print();
    Q.EnQueue(5); Q.Print();
    Q.deQueue(); Q.Print();Q.deQueue(); Q.Print();Q.deQueue(); Q.Print();Q.deQueue(); Q.Print();Q.deQueue(); Q.Print();Q.deQueue(); Q.Print();Q.deQueue(); Q.Print();
    Q.EnQueue(2); Q.Print();
    Q.EnQueue(3); Q.Print();
    Q.EnQueue(4); Q.Print();
    Q.EnQueue(5); Q.Print();
}