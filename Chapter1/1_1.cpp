#include <iostream>
#include <string>
using namespace std;

bool isUnique(const string& str){
	if(str.length() > 256)
		return false;
	
	bool ascii_set[256] = {false};
	
	for(int i = 0; i < str.length(); i++){
		int val = str[i];
		if(ascii_set[val])
			return false;
		
		ascii_set[val] = true;
	}
	
	return true;
}

// limit = 64
bool isUnique2(string str){
	if(str.length() > 256)
		return false;
	
	unsigned long ascii_set = 0;
	
	for(int i = 0; i < str.length(); i++){
		int val = str[i] - 'a';
		if(1 & (ascii_set >> val))
			return false;
		
		ascii_set |= 1 << val;
	}
	
	return true;
}

int main() {
	// your code goes here
	string input[] = {"asdhj", "ahfdja"};
	cout << isUnique(input[0]) << isUnique2(input[0]) << endl;
	cout << isUnique(input[1]) << isUnique2(input[1]) << endl;
	return 0;
}
