#include <iostream>
using namespace std;

// Function to calculate GCD using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int result = 1;
    for (int i = 2; i <= 20; i++) {
        result = lcm(result, i);
    }
    cout << "The smallest positive number that is evenly divisible by all the numbers from 1 to 20 is: " << result << endl;
    return 0;
}
