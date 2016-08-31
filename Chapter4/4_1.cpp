#include<iostream>
#include<cmath>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
};

void insertNode(Node* &head, int data){
    if(head == NULL){
        Node *p = new Node;
        p -> data = data;
        p -> left = NULL;
        p -> right = NULL;
        head = p;
        return;
    }

    if(data <= head -> data){
        if(head -> left == NULL){
            Node *p = new Node;
            p -> data = data;
            p -> left = NULL;
            p -> right = NULL;
            head -> left = p;
            return;
        }
        insertNode(head -> left, data);
    }
    else{
        if(head -> right == NULL){
            Node *p = new Node;
            p -> data = data;
            p -> left = NULL;
            p -> right = NULL;
            head -> right = p;
            return;
        }
        insertNode(head -> right, data);
    }
}

int height(Node* root){
    if(root == NULL)
        return 0;
    return max(height(root -> left), height(root -> right)) + 1;
}

bool isBalanced(Node* root){
    if(root == NULL)
        return true;
    int diff = height(root -> left) - height(root -> right);
    if(abs(diff) > 1)
        return false;
    else
        return (isBalanced(root -> left) && isBalanced(root -> right));
}

int main(){
    Node *root;
    root = NULL;
    int arr[] = {4, 7, 2, 1, 6, 8};
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++)
        insertNode(root, arr[i]);
    cout << isBalanced(root) << endl;
}
