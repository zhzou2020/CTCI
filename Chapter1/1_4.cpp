#include <iostream>
#include <string>
using namespace std;

void replace(string& str){
	int cnt = 0;
	int len = str.length();
	
	for(int i = 0; i < len; i ++){
		if(str[i] == ' ')
			cnt ++;
	}
	
	int new_len = len + cnt * 2;
	str[new_len] = '\0';
	
	for(int i = len - 1; i >= 0; i --){
		if(str[i] == ' '){
			str[new_len - 1] = '0';
			str[new_len - 2] = '2';
			str[new_len - 3] = '%';
			new_len -= 3;
		}else{
			str[-- new_len] = str[i];
		}
	}
}
	
int main() {
	// your code goes here
	string str1 = "my dog";
	string str2 = "Mr John Smith";
	replace(str1);
	replace(str2);
	
	cout << str1 << endl;
	cout << str2 << endl;
	return 0;
}
