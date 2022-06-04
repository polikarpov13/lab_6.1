#include "Array.h" 
#include <iostream> 
#include <time.h> 
#include <stdexcept> 
#include <exception> 
#include <cmath> 

using namespace std;

typedef Array::value_type* TArray;

Array Calc(int n, TArray a) {

	Array::value_type sum = 0, abs_avg = 0;

	for (int i = 0; i < n; i++) {

		sum += a[i];

	}

	abs_avg = abs(sum / n);

	Array result(2);

	result[0] = sum;

	result[1] = abs_avg;

	return result;

}



int main() {

	int n;

	cout << "n = ";

	cin >> n;

	srand((unsigned)time(NULL));

	Array::value_type A = -50.0;

	Array::value_type B = 50.0;

	TArray a = new Array::value_type[n];

	cout << "Data 1: [ ";

	for (int i = 0; i < n; i++) {
		a[i] = A + rand() % int(B - A + 1);
		cout << a[i] << " ";
	}

	cout << "]" << endl;

	Array::value_type last = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] < 0) 
			last = a[i];
	}

	for (int i = 0; i < n; i++) {

		a[i] += last / 2.;

	}

	cout << "Data 2: [ ";

	for (int i = 0; i < n; i++) {

		cout << a[i] << " ";

	}

	cout << "]" << endl;

	Array result = Calc(n, a);

	cout << "Result: [ " << result << "]" << endl;

	cin.get();

	cin.get();

	return 0;

}