
#include <iostream>
using namespace std;
//Template BST class code that was given during class


template <class T>
 class TreeNode{ //treenode class for the node left/right to be used in BST.

 public:

   TreeNode();
   TreeNode(T k); //data is our key key is the value in this example, could have two varaibles in this constructor
   ~TreeNode();

   T key;
   TreeNode<T> *left;
   TreeNode<T> *right;

 };
 template <class T>
 TreeNode<T>::TreeNode(){

   key=0;
   left = NULL;
   right = NULL;
 }

 template <class T>
 TreeNode<T>::TreeNode(T k){

   key=k;
   left = NULL;
   right = NULL;
 }


 template <class T>
 TreeNode<T>::~TreeNode(){
   delete key;
   delete left;
   delete right;
 }


template <class T>
class BST{
public:
  BST();
  ~BST();

  void insert(T k);
  bool deleteNode(T k);
  bool contains(T k); //returns true or false if the tree contains the inputted data
  bool isEmpty();
  T findData(T k); //Find data function added to find the specific data for a node rather than just finding the node which is exucuted in find
  TreeNode<T>* find(T k); //find the node pointer

  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  void printPreorder(TreeNode<T> *node); //preorder code based off the code given in class
  void printPreorder();

  void printTree(TreeNode<T> *node); //traversal methods

  void printTree();
  TreeNode<T>* getRoot();
  TreeNode<T>* getSuccessor(TreeNode<T> *d);

private:
  TreeNode<T> *root;
};




template <class T>
BST<T>::BST(){

  root= NULL;
}

template <class T>
BST<T>::~BST(){

}

template <class T>
void BST<T>::printTree(){
  TreeNode<T> *node = root;
  printTree(node);
}

template <class T>
TreeNode<T>* BST<T>::getRoot(){
  return root;
}

template <class T>
void BST<T>::printTree(TreeNode<T> *node){
  if(node== NULL){

    return;
  }

  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);


}

template <class T>
void BST<T>::printPreorder()
{
  TreeNode<T> *node = root;
  printPreorder(node);
}


template <class T>
void BST<T>::printPreorder(TreeNode<T> *root){

  if( root== NULL)
  return;
  cout << root->key <<endl;
  printPreorder(root->left);
  printPreorder(root->right);
}

template <class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T> *curr= root;
  if(root==NULL){

    return NULL;
  }

  while(curr->right != NULL){

    curr= curr->right;
  }

  return curr;
  //returning the tree node, could return the int
}



template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *curr= root;
  if(root==NULL){

    return NULL;
  }

  while(curr->left != NULL){

    curr= curr->left;
  }

  return curr; //this is the min
}

template <class T>
void BST<T>::insert(T k){
  TreeNode<T> *node= new TreeNode<T>(k);
  if( root == NULL){ //if empty tree
    root = node;
  }
  else{ //not an empty tree
    TreeNode<T> * curr= root;
    TreeNode<T> *parent= NULL;

    //start iterating
    //iterator version

    while(true){ //iterate and find the insertion point
      parent = curr;
      //go left
      if(k<curr->key){
        curr= curr ->left;


      if(curr == NULL){// we found ou rinsertion point

        parent->left = node;
        break;
      }
    }

  else{

      curr= curr ->right;


    if(curr == NULL){// we found ou rinsertion point

      parent->right = node;
      break;
    }
  }
    }

  }
}

template <class T>
bool BST<T>::contains(T k){ //returns true or falase if it contains the specific node

  if(root==NULL){ //empty treeNode

  return false;
  }
  else{

    TreeNode<T> *curr= root;

    while (curr->key != k ){

      if( k < curr->key){

        curr= curr->left;
      }


    else {
      curr= curr->right;
    }

    if(curr==NULL){

      return false;
    }
  }
    return true;
  }

  //return true;

}


template <class T>
TreeNode<T>* BST<T>::find(T k){ //returns the pointer to the node found

  if(root==NULL){ //empty treeNode

  return 0;
  }
  else
  {

    TreeNode<T> *curr= root;

    while (curr->key != k ){

      if( k < curr->key){

        curr= curr->left;
      }


    else {
      curr= curr->right;
    }

    if(curr==NULL){

      return 0;
    }
  }

    //cout << curr->key;
    return curr;
  }


}

template <class T>
T BST<T>::findData(T k){ //returns the actual data of the specific data

  TreeNode<T> *curr= root;

  if(root==NULL){ //empty treeNode

  return false;
  }
  else
  {

    //TreeNode<T> *curr= root;

    while (curr->key != k ){

      if( k < curr->key){

        curr= curr->left;
      }


    else {
      curr= curr->right;
    }

    if(curr==NULL){

      return 0;
    }
  }

    cout << curr->key;
    //cout << " here1" << endl;
    return curr->key;

  }




}


template <class T>
bool BST<T>::deleteNode(T k){ //delete code given in class

  if(root == NULL){

    return false;
  } //empty tree

    TreeNode<T> *curr= root;
    TreeNode<T> *parent= root;
    bool isLeft = true;

  //lets find the node that we are going to delete
  //leverage the contains method

  while(curr->key !=k) { //searching for nextToDelete

    parent = curr;
    if( k < curr->key){
      isLeft= true;
      curr= curr->left;
    }
  else{
    isLeft= false;
    curr= curr->right;
  }

  if(curr == NULL){
    return false;
  }
}

//once we get here, we found the node we are looking for
//We have found the node

//no children
if(curr->left == NULL && curr->right==NULL){
  if(curr == root){
    root= NULL; //null out the root
  }
  else if( isLeft){

    parent->left = NULL;
  }
  else{
    parent->right=NULL;
  }

}

//one child
//check either left or right

else if(curr->right== NULL){

  if(curr==root){
    root= curr->left;
  }
  else if(isLeft){
    parent->left= curr->left;
  }
  else{

    parent->right = curr->left;
  }
}

//no left child
else if(curr->left== NULL){

  if(curr==root){
    root= curr->right;
  }
  else if(isLeft){
    parent->left= curr->right;
  }
  else{

    parent->right = curr->right;
  }
}

//two children case
else{
  TreeNode<T> *successor= getSuccessor(curr);

  if(curr==root){

    root= successor;
  }
  else if (isLeft){

    parent->left= successor;
    }
  else{
    parent->right = successor;
    }

    //connect succesors left child to currents left children
    successor->left = curr->left;
  }
  return true;
}



template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ //d is the node to be deleted
  //successor is the left most child of the right
  //or the right most child of the left

  TreeNode<T> *sp = d; //sp= successor's parent
  TreeNode<T> *successor = d;
  TreeNode<T> *curr = d->right; //or curr->?
  //loop till we find successor
  //which will be one right, all the way to the left
  while(curr != NULL){

    sp= successor;
    successor= curr;
    curr = curr->left;
  }

  if(successor != d->right){//make sure it is a descendant of the right child
    sp->left = successor->right;
    successor->right =d->right;

  }

  return successor;
}

template <class T>

bool BST<T>::isEmpty(){
  return root == NULL;
}
