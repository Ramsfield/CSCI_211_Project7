//bst.h
//Michael Griffith
//Project 7
#ifndef BST_H
#define BST_H

#include<cstddef> //NULL
#include<vector> //Assists with print

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

    //Inner print function
     void printVec(std::vector<T>);

    //Insert
    bool insert(T insertData, Node* &cur);

    //Size 
    int size(Node* cur) {return (!cur)? 0 : 1 + size(cur->left) + size(cur->right); }

    //Height
    int height(Node*);

    //Find
    bool find(T, Node*);

    //Print
    void print(Node*, std::vector<T>&);

    //Breadth
    void breadth(Node*, int, std::vector<T>&);

    //Distance
    void distance(Node*,std::vector<int>&,int);

  public:

    //Insert
    bool insert(T insertData) { return insert(insertData, this->root);}

    //Size 
    int size() {return size(root);}

    //Height
    int height() { return height(root); }

    //Find
    bool find(T findData) { return find(findData, root); }

    //Print
    void print();

    //Breadth -- Prints based off of level
    void breadth();
    
    //Distance -- Prints average distance nodes are from root
    float distance();
};

#endif
