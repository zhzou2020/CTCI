#include <iostream>
using namespace std;

int steps = 0;
// recursive implementation
// if use stack as container, it will be the same
void hanoi(int size, char a, char b, char c){
	if(size == 1){
		steps ++;
		cout << "move from " << a << " to " << b << " with " << c << endl;
		return;
	}

	hanoi(size - 1, a, c, b);
	cout<< "move from " << a << " to " << b << " with " << c << endl;
	steps ++;
	hanoi(size - 1, c, b, a);
}

int main() {
	// your code goes here
	hanoi(4, 'A', 'B', 'C');
	cout << steps << endl;
	return 0;
}
