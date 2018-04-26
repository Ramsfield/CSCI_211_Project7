//bst.h
//Michael Griffith
//Project 7
#ifndef BST_H
#define BST_H

#include<cstddef> //NULL

template<class T> 
class BST{
  private:
    class Node{
      public:
        Node(T data, Node *left = NULL, Node *right=NULL) : data(data), left(left), right(right) {}
        T data;
        Node *left;
        Node *right;
    };
    Node* root = NULL;

  public:
    //Insert
    bool insert(T insertData) { return insert(insertData, this->root);}
    bool insert(T insertData, Node* &cur);
    //Size 
    int size(Node* cur) {return (!cur)? 0 : 1 + size(cur->left) + size(cur->right); }
    int size() {return size(root);}
};

#endif
