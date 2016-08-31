#include <iostream>
using namespace std;

struct Node{
  Node* next;
  int data;
};

Node* reverse(Node* head){
	if(head == NULL || head -> next == NULL)
		return head;
	
	Node* cur = head -> next;
	Node* r_list = head;
	head -> next = NULL;
	
	while(cur){
		Node* tmp = cur -> next;
		cur -> next = r_list;
		r_list = cur;
		cur = tmp;
	}
	
	return r_list;
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
	
	Node* cur = reverse(&n1);
	while(cur){
		cout << cur -> data << endl;
		cur = cur -> next;
	}
	return 0;
}
