//bst.cpp
//Michael Griffith
//Project 7
#include"bst.h"

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

