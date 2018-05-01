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
        ~Node() {delete left; delete right;} 
        T data;
        Node *left;
        Node *right;
    };
    Node* root = NULL;

    // PRIVATE FUNCTIONS

    //Inner print function
     void printVec(std::vector<T>);

    //Insert
    bool insert(T, Node*&);

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

    //Balanced
    bool balanced(Node*);

    //Rebalance (private function, inserts nodes back into tree)
    void rebalance(std::vector<T>&, int, int);

    //Clear -- DOES NOT SAVE NODES
    void clear(Node*&);

  public:

    //Insert
    bool insert(T insertData) { return insert(insertData, this->root);}

    //Size 
    int size() {return size(this->root);}

    //Height
    int height() { return height(this->root); }

    //Find
    bool find(T findData) { return find(findData, this->root); }

    //Print
    //Takes in and fills a vector with the nodes of the tree
    void print(std::vector<T>&);

    //Breadth -- Prints based off of level
    void breadth(std::vector<T> &);
    
    //Distance -- Prints average distance nodes are from root
    float distance();

    //Balanced
    int balanced();

    //Rebalance
    void rebalance();

    //Clear -- DANGEROUS STUFF MAN
    void clear() { clear(this->root); }
};

#endif
