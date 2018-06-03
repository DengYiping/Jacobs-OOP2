#include <iostream>
using namespace std;

int sum(int a[], int nr) {
	int s=0;
	for(int i=0; i<=nr; i++)
		s+=a[i];
	return s;
}

unsigned int difference(unsigned int a, unsigned int b) {
	if (a-b < 0)
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
