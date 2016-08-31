#include <iostream>
#include <string>
using namespace std;

bool isPermuted(const string& s1, const string& s2){
	if(s1.length() != s2.length())
		return false;
		
	int ascii_cnt[256] = {0};
	
	for(int i = 0; i < s1.length(); i ++){
		int val = s1[i];
		ascii_cnt[val] ++;
	}
	
	for(int i = 0; i < s2.length(); i ++){
		int val = s2[i];
		ascii_cnt[val] --;
	}
	
	for(int i = 0; i < 256; i ++){
		if(ascii_cnt[i])
			return false;
	}
	
	return true;
}

int main() {
	// your code goes here
	string str[][2] = {{"abcd", "aabc"}, {"aabc", "abac"}};
	cout << isPermuted(str[0][0], str[0][1]) << endl;
	cout << isPermuted(str[1][0], str[1][1]) << endl;
	return 0;
}
