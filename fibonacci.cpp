//Fibonacci recursive 

#include <iostream>
using namespace std;

int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci_recursive(n) << endl;
    return 0;
}

//Fibonacci non recursive 

#include <iostream>
using namespace std;

int fibonacci_iterative(int n) {
    if (n <= 1)
        return n;
    
    int a = 0, b = 1, result;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci_iterative(n) << endl;
    return 0;
}
