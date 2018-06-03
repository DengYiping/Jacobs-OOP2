#include <iostream>
using namespace std;

int sum(int a[], int nr) {
	int s=0;
    // index will go out of bound
    // (gdb) break debug1.cpp:6
    // (gdb) run
    // (gdb) step
    // (gdb) print i
    // (gdb) print nr
	for(int i=0; i<nr; i++)
		s+=a[i];
	return s;
}

unsigned int difference(unsigned int a, unsigned int b) {
    //unsigned integer is never smaller than 0
    // (gdb) break debug1.cpp:13
    // (gdb) run
    // (gdb) print (a - b)
	if (a < b)
		return b-a;
	else
		return a-b;
}

int main() {
	int n;
	cout << "n=";
	cin >> n;
	int v[n];
	cout << "Enter values for the array" << endl;
	for(int i=0; i<n; i++)
		cin >> v[i];
	int result = sum(v, n);
	cout << "Result=" << result << endl;
	int x, y;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	cout << "Difference=" << difference(x, y) << endl;
	return 0;
}
