/**
 *  author:- piyushkumar96
 *  description:- Binary Tree is balanced or not
 *  TimeComplexity:- O(n)
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
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
        void isBalanced(struct Node *root);
        

};

// check BT is balance or not
bool isBalancedUtil(struct Node *root, int *height){

    /* lh --> Height of left subtree 
       rh --> Height of right subtree */
    int lh = 0, rh = 0;

    /* l will be true if left subtree is balanced 
    and r will be true if right subtree is balanced */
    int l = 0, r = 0;

    // root is NULL then BT is balanced
    if(root == NULL){
        *height = 0;
        return 1; 
    }

    /* Get the heights of left and right subtrees in lh and rh And store the returned values in l and r */
     l = isBalancedUtil(root->left, &lh);
     r = isBalancedUtil(root->right, &lh);

    /* Height of current node is max of heights of left and  right subtrees plus 1*/
    *height = (lh > rh ? lh : rh) + 1;

    /* If difference between heights of left and right subtrees is more than 2 then this node is not balanced  so return 0 */
    if((lh - rh) >= 2 || (rh - lh) >= 2)
        return 0;
    /* If this node is balanced and left and right subtrees are balanced then return true */
    else
        return l && r;

    // if reached here then tree is not balanced
    return 0;
}

void BinaryTree::isBalanced(struct Node *root){
    int height = 0;

    cout<<isBalancedUtil(root, &height) <<"\n";
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
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(levelorder) \n 3. Check balance of tree \n 4. DeleteNode \n Press any key to Exit \n";
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

           case 3:  cout<<"Check balance of Tree :- ";
                    t.isBalanced(root);
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