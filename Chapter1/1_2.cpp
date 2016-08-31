#include <iostream>
#include <string.h>
using namespace std;

void reverse(char* str){
	int len = strlen(str);
	
	for(int i = 0; i < len / 2; i ++){
		char tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
}

int main() {
	// your code goes here
	char input[][10] = {"abcd", "abcda"};
	cout << input[0] << endl;
	reverse(input[0]);
	cout << input[0] << endl;
	cout << input[1] << endl;
	reverse(input[1]);
	cout << input[1] << endl;
	return 0;
}
