#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *mid;
    Node *right;
};

Node* createNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
  
Node* search(Node* root, int key){
    if(root == NULL)
        return NULL;
    queue< Node* > q;
    Node* out;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp->key == key) out = temp;
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    return out;
}

void insert(Node *root, int parent, int key){
    Node *nodeToInsert = createNode(key);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left == NULL && temp->key == parent){
            cout << "Gate: " << temp->key << endl;
            temp->left = nodeToInsert;
            return;
        }else if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right == NULL && temp->key == parent){
            cout << "Gate: " << temp->key << endl;
            temp->right = nodeToInsert;
            return;
        }else if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    cout << "No parent or full!!" << endl;
}

int main()
{
    cout << "Hello Trees" << endl;
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    insert(root, 3, 8);
    Node *node = search(root, 4);
    cout << node->left->key << endl;
    return 0;
}
