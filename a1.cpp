#include <iostream>
using namespace std;

int fibo(int n) {
    if (n <= 1)
        return n; 
    return fibo(n - 1) + fibo(n - 2);
}

int fib(int n) {
    if (n <= 1)
        return n;
    
    int prev1 = 0, prev2 = 1;
    int f = 0;

    for (int i = 2; i <= n; i++) {
        f = prev1 + prev2;
        prev1 = prev2;
        prev2 = f;
    }

    return f;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number (Recursive) is: " << fibo(n) << endl;
    cout << "Fibonacci number (Non-recursive) is: " << fib(n) << endl;
    return 0;
}

