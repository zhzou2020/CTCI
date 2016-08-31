#include <iostream>
#include <stack>
using namespace std;

// similar to insertion sort
void sort(stack<int> * s){
	stack<int> s1;//smallest on the top
	stack<int> * sorted = &s1;
	
	while(!s -> empty()){
		int tmp = s -> top();
		s -> pop();
		while(!sorted -> empty() && tmp > sorted -> top()){
			s -> push(sorted -> top());
			sorted -> pop();
		}
		sorted -> push(tmp);
	}
	
	while(! sorted -> empty()){
		s -> push(sorted -> top());
		sorted -> pop();
	}
}
	
int main(){
    stack<int> my;
    int arr[] = {1, 7, 3, 4};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        my.push(arr[i]);
    }
    sort(&my);
    while(!my.empty()){
        cout<<my.top()<<'\n';
        my.pop();
    }
}
