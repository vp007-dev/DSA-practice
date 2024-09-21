#include<iostream>
#include<string>

using namespace std;

bool isPal(int num){
    string s  = to_string(num);
    string rev = string(s.rbegin(), s.rend());
    return s == rev;
}


int main(){
    int maxpal = 0;
    for (int i = 999; i >= 100; i--){
        for (int j = i; j>= 100; j--){
            int product = i * j;
            if(isPal(product) && product > maxpal){
                maxpal = product;
            }
        }
    }
    cout << maxpal << endl;
}