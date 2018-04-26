//bst.cpp
//Michael Griffith
//Project 7
#include"bst.h"
#include<iostream> //Print function

//Insert function
  template<class T>
bool BST<T>::insert(T insertData, Node * &cur)
{
  //Base Case: Empty or current spot
  if(!cur)
  {
    cur = new Node(insertData);
    return true;
  }
  //Base Case: Item already in tree
  if(cur->data == insertData)
    return false;

  //Recurse Case: Item < Cur
  if(insertData < cur->data)
    return insert(insertData, cur->left);

  //Recurse Case: Implicit else (greater than)
  return insert(insertData, cur->right);
}

//Find Function
  template<class T>
bool BST<T>::find(T findData, Node* cur)
{
  //Base Case: Cur is null, item not in tree
  if(!cur)
    return false;
  //Base Case: Item found
  if(cur->data == findData)
    return true;
  //Recurse Case: Item less than cur
  if(findData < cur->data)
    return find(findData, cur->left);
  //Vacuous Recurse Case: Item Greater Than Cur
  return find(findData, cur->right);
}

//Print Function (Depth First)
  template<class T>
void BST<T>::print(Node* cur, Node* wednesday) //Wednesay delineates when I no longer need a ", "
{
  if(!cur)
    return;
  print(cur->left, wednesday);
  std::cout << cur->data;
  if(cur->data != wednesday->data)
    std::cout << ", ";
  print(cur->right, wednesday);
}

//Print Function (No param)
  template<class T>
void BST<T>::print() 
{
  Node* cur = root;
  if(!cur)
    return; //No need to print. It's empty.
  while(cur->right)
    cur = cur->right; //Delineates the last item we print

  print(root, cur); //Call actual print function
}

//Breadth Function (Breadth First Printing)
  template<class T>
void BST<T>::breadth(Node* cur, Node* wednesday) //Wednesay delineates when I no longer need a ", " Called Wednesday because it was the data I was working with
{
  //Base case. No need them seg faults now.
  if(!cur)
    return;
  std::cout << cur->data;
  if(cur->data != wednesday->data)
    std::cout << ", ";
  breadth(cur->left, wednesday);
  breadth(cur->right, wednesday);
}

//Breadth Function (No param)
  template<class T>
void BST<T>::breadth() 
{
  Node* cur = root;
  if(!cur)
    return; //No need to print. It's empty.
  while(cur->right)
    cur = cur->right; //Delineates the last item we print

  breadth(root, cur); //Call actual print function
}

template class BST<std::string>;
