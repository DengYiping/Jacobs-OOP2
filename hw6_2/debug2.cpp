#include <iostream>
#include <sstream>
using namespace std;

void foo(int *array, int n, int *positives) {
	for(int i=0; i<n; i++)
		if (array[i]>0)
            // (gdb) break debug2.cpp:8
            // (gdb) run
            // (gdb) continue
            // (gdb) print positives++
            /*
$1 = (int *) 0x7fffffffeaac
(gdb) step
6               for(int i=0; i<n; i++)
print positives
$2 = (int *) 0x7fffffffeab4
(gdb)
*/
            // it is obvious, the ++ has a higher precedence
            // and the pointer is been changed
			(*positives)++;
}

class Test {
	private:
		int *a;
		int n;
	public:
		Test() {
			a=NULL;
			n=0;
		}
		Test(int *a, int n) {
			this->n = n;
			if (this->a != NULL) {
				delete [] this->a;
			}
			this->a = new int[n];
			for(int i=0; i<n; i++)
				this->a[i] = a[i];
		}
		string toString() {
			ostringstream ss;
			ss << "Length: " << n << endl << "Elements: ";
			for(int i=0; i<n; i++)
				ss << a[i] << " ";
			ss << endl;
			return ss.str();
		}
		~Test() {
			delete [] a;
		}
};

int main() {
	int v[] = {1, 2, 3};
	int p=0;
	foo(v, 3, &p);
	cout << "Amount of positive values in the array=" << p << endl;
	Test arr[5];
	Test *obj1;
    // (gdb) run
    // it turns out that it is a stack object, so you cannot delete it
    // we can fix it by 
	obj1=&arr[0];
    // when you run, it gives you a error in gdb, following it, we can fix it
	Test *obj2= new Test(v, 3);
    // null pointer, let's allocate
    // we need to fix this also
	Test *obj3 = new Test(v, 3);
	cout << obj1->toString();
	cout << obj2->toString();
    // (gdb) print obj3
    // it is a null pointer, so we just allocate it
	cout << obj3->toString();
    // (gdb) run
    // bug is here, you cannot delete
	// delete obj1;
	delete obj2;
	delete obj3;
	return 0;
}
