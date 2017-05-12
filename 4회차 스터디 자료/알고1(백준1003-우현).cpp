#include <iostream>
using namespace std;

int fibonacci(int n, int &a, int &b);

int main() {
	int i, j, k;
	cin >> i; //프로그램을 실행할 횟수.
	int a = 0;
	int b = 0;
	for (j = 0; j < i; j++) {
		cin >> k;
		fibonacci(k, a, b);
		cout << a << " " << b << endl;
		a = 0;
		b = 0;
	}
}

int fibonacci(int n, int &a, int &b) {
	
	if (n == 0) {
		a++;
		return a;
	}
	else if (n == 1) {
		b++;
		return b;
	}
	else {
		return fibonacci(n - 1, a, b) + fibonacci(n - 2, a, b);
	}
}