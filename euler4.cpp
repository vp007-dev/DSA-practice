#include <iostream>

using namespace std;

int sumofsq(){
    int sumofsq1 = 0;
    for (int i = 1; i<=100; i++){
        sumofsq1 = sumofsq1 + i*i;
    }
    return sumofsq1;
}

int squareofsum(){
    int squarofsum1 = 0;
    for (int i = 1; i <= 100; i++){
        squarofsum1 = squarofsum1 + i;
    }

    return squarofsum1 * squarofsum1;
}


int main(){

    int n1 = sumofsq();
    int n2 = squareofsum();
    cout << n2 - n1 << endl;
    return 0;
}