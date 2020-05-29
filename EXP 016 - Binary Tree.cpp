#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int key;
    Node *left;
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
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->key == key) return temp;
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    return NULL;
}
void print(Node *node);
void insert(Node *root, int parent, int key){
    Node *nodeToInsert = createNode(key); 
    Node *node = search(root, parent);
    if(node->left == NULL) {
        node->left = nodeToInsert;
        return;
    }
    if(node->right == NULL) {
        node->right = nodeToInsert;
        return;
    }
}

int main()
{
    cout << "Hello Trees" << endl;
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    /*
             1
            / \
           2   4
          /   / \
         3   5   6
    */
    insert(root, 2, 8);
    Node *node = search(root, 2);
    print(node);

    return 0;
}

void print(Node *node){
    printf("  %d\n", node->key);
    printf(" / \\\n");
    if(node->left != NULL){
        printf("%d   ", node->left->key);
    }else{
        printf("X   ");
    }
    if(node->right != NULL){
        printf("%d\n", node->right->key);
    }else{
        printf("X\n");
    }
}
