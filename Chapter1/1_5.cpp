#include <iostream>
#include <string>
using namespace std;

string compress(const string& str){
	string str_new;
	
	char last = '\0';
	char cur;
	int cnt = 0;
	for(int i = 0; i < str.length(); i ++){
		cur = str[i];
		if(cur == last){
			cnt ++;
		}else{
			if(cnt){
				str_new += last;
				char num = cnt + '0';
				str_new += num;
			}
			cnt = 1;
			last = cur;
		}
	}
	
	if(str.length() > str_new.length())
		return str_new;

	return str;
}

int main() {
	// your code goes here
	string str = "aabbbbcccd";
	cout << compress(str) << endl;
	return 0;
}
