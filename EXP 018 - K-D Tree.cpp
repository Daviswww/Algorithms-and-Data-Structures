#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node{
    int key;
    vector<Node *> child; 
};

Node* createNode(int key){
    Node* node = new Node();
    node->key = key;
    return node;
}

Node* search(Node *root, int key){
    queue<Node*> q;
    q.push(root);
    if(root->key == key){
        return root;
    }else{
        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            for(int i = 0; i < temp->child.size(); i++){
                if(temp->child[i]->key == key){
                    return temp->child[i];
                }
                if(!temp->child[i]->child.empty()){
                    q.push(temp->child[i]);
                }
            }
        }
    }
    return NULL;
}


void insert(Node *root, int parent, int key) 
{ 
    Node *nodeToInsert = createNode(key);
    Node *node = search(root, parent);
    if(node != NULL){
        (node->child).push_back(nodeToInsert);
    }else{
        cout << "No" << endl;
        return;
    }
} 
int main()
{
    Node *root = createNode(1);
    (root->child).push_back(createNode(2));
    insert(root, 2, 3);
    insert(root, 1, 4);
    Node *node = search(root, 1);
    
    cout << node->child[0]->key << endl;

    return 0;
}
