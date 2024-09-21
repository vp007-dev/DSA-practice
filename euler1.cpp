#include<iostream>


using namespace std;
int main()
{
    int sum = 0;
    for (int i = 1; i < 1000; i++){
        if(i % 3 == 0 or i % 5 == 0){
            cout << "Divisible by 3 or 5" <<i<< endl;

            sum = sum + i;

        }
    }
    cout << sum << endl;

    return 0;
}

