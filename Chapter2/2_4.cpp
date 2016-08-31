#include <iostream>
using namespace std;

struct Node{
  Node* next;
  int data;
};

Node* arrange(Node* head, int x){
	if(head == NULL)
		return NULL;
		
	Node l1;
	Node* l1_cur;
	l1_cur = &l1;
	
	Node l2;
	Node* l2_cur;
	l2_cur = &l2;
	
	Node* cur = head;
	while(cur){
		if(cur -> data < x){
			l1_cur -> next = cur;
			l1_cur = l1_cur -> next;
		}else{
			l2_cur -> next = cur;
			l2_cur = l2_cur -> next;
		}
		cur = cur -> next;
	}
	
	l1_cur -> next = l2.next;
	l2_cur -> next = NULL;
	return l1.next;
}


int main() {
	// your code goes here
	Node n1;
	Node n2;
	Node n3;
	Node n4;
	Node n5;
	n1.next = &n2;
	n1.data = 1;
	n2.next = &n3;
	n2.data = 4;
	n3.next = &n4;
	n3.data = 2;
	n4.next = &n5;
	n4.data = 1;
	n5.next = NULL;
	n5.data = 3;
	
	arrange(&n1, 3);
	
	Node* cur = &n1;
	while(cur){
		cout << cur -> data << endl;
		cur = cur -> next;
	}
	return 0;
}
