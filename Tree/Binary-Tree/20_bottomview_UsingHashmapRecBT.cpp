/**
 *  author:- piyushkumar96
 *  description:- bottom view of Binary Tree using Hash Map (Recursion)
 *  TimeComplexity:- O(n)
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    int hd;
    struct Node *left, *right;
    Node(int data){
        this->data = data; 
        this->hd = INT_MAX;
        this->left = NULL;
        this->right = NULL;
    }
}*root;

class BinaryTree {
   
    public:
        BinaryTree(){
            root = NULL;
        }
        queue<struct Node *> q;
        void insertNode(int item);
        Node* deleteNode(struct Node *root, int item);
        void delDeepestNode(struct Node *root, struct Node *node);
        void levelorderTraversal(struct Node *root);
        void bottomview(struct Node *root);
        

};
  
// helper function
void bottomviewUtil(Node * root, int height, int hd, map <int, pair <int, int> > & m) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
      
    // If node for a particular  horizontal distance is not present, add to the map.
    if(m.find(hd) == m.end()){
        m[hd] = make_pair(root->data, height);

    } // Compare height for already present node at similar horizontal distance
    else{
        pair<int,int> p = m[hd];
        if(p.second <= height){
            m[hd].second = height;
            m[hd].first = root->data;  
        }
    }

    bottomviewUtil(root->left, height + 1, hd - 1, m);
    bottomviewUtil(root->right, height + 1, hd + 1, m);

}

// bottom view function 
void BinaryTree::bottomview(struct Node *root){
    
    if(root == NULL)
        return ;
    map<int, pair<int,int> > m;
    
    bottomviewUtil(root, 0, 0, m);

    map<int, pair<int,int> >::iterator it;

    for(it = m.begin(); it != m.end(); it++){
        cout<<it->second.first<<" ";
    }
    cout<<"\n";

}       

// level order traversal iterative function
void BinaryTree::levelorderTraversal(struct Node *root){
   
   if(root == NULL){
       cout<<"Tree is Empty \n";
       return ;
   }
   queue<Node *> qu;
   qu.push(root);
   while(!qu.empty()){
       struct Node *tmp = qu.front();
       qu.pop();
       cout<<tmp->data<<" ";
       if(tmp->left){
           qu.push(tmp->left);
       }
       if(tmp->right){
           qu.push(tmp->right);
       }
   }
     
}

// insert function
void BinaryTree::insertNode(int item){
     Node *newnode = new Node(item);
     if(root == NULL){
         root=newnode;
     }else{
         Node *temp = q.front();
         if(!temp->left){
             temp->left = newnode;
         }else{
             temp->right = newnode;
             q.pop();
         }
     }
     q.push(newnode);
}

// delete helper function
void BinaryTree::delDeepestNode(struct Node *root, struct Node *dnode){
    struct Node *tmpNode;
    queue<Node *> qu;
    qu.push(root);

    while(!qu.empty()){
        tmpNode = qu.front();
        qu.pop();
        if(tmpNode->left){
            if(tmpNode->left == dnode){
                tmpNode->left=NULL;
                delete(dnode);
                return;
            }else{
                qu.push(tmpNode->left);
            }
        }
        if(tmpNode->right){
            if(tmpNode->right == dnode){
                tmpNode->right=NULL;
                delete(dnode);
                return;
            }else {
                qu.push(tmpNode->right);
            }
        }
    }
}

// delete function 
struct Node* BinaryTree::deleteNode(struct Node *root, int item){
    struct Node *delNode = NULL, *tmpNode; 
    queue< Node *> qu;
    
    if(root == NULL){
        cout<<" Tree is empty "<<"\n";
        return NULL;
    }else if((root->right == NULL) && (root->left == NULL) ){
          if(root->data == item){
              delNode = root;
              delete(delNode);
              return NULL;
          }
          return root;
    }
    
    qu.push(root);
    while(!qu.empty()){
        tmpNode = qu.front();
        qu.pop();

        if(tmpNode->data == item){
            delNode = tmpNode;
        }
        if(tmpNode->left){
            qu.push(tmpNode->left);
        }
        
        if(tmpNode->right){
            qu.push(tmpNode->right);
        }
        
    }
   
    if(tmpNode){
        int temp = tmpNode->data;
        delDeepestNode(root, tmpNode);
        delNode->data = temp;
    }
    return root;
}


int main(){

   //ios::sync_with_stdio(false);
   //cin.tie(0);
   int i, n, item;
   BinaryTree t;
   
   while(1){
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(levelorder) \n 3. bottom view of tree \n 4. DeleteNode \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    t.insertNode(item);
                    break;

           case 2:  cout<<"Levelorder Traversal :- ";
                    t.levelorderTraversal(root);
                    break;

           case 3:  
                    cout<<"bottom view of Tree :- \n";
                    t.bottomview(root);
                    break;

           case 4:  cout<<" Enter element to be deleted ";
                    cin>>item;
                    root = t.deleteNode(root,item);
                    break;                                                 

           default: exit(1);
                    break;
       }

   }

    return 0;
}