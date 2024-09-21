#include<iostream>

using namespace std;

int main(){
    
    int t1 = 0;
    int t2 = 1;
    int nextno = t1+t2;
    int evensum = 0;
    while (nextno < 4000000){
        
        // cout << nextno << endl;
        
        if(nextno % 2 == 0){
            evensum = evensum + nextno;
        }
        t1 = t2;
        t2 = nextno;
        nextno = t1+t2;
    }

    cout << evensum << endl;

    



    return 0;
}