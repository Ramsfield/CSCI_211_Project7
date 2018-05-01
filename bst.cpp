//bst.cpp
//Michael Griffith
//Project 7
#include"bst.h"
#include<iostream> //Print function
#include<queue> //Used for Rebalance

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

//Height Function
  template<class T>
int BST<T>::height(Node *cur)
{
  //Base Case: empty subtree
  if(!cur)
    return 0;
  int x = height(cur->left);
  int y = height(cur->right);

  return 1 + ((x>y) ? x : y);
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
void BST<T>::print(Node* cur, std::vector<T> &depthVec)
{
  //Base Case: Empty tree
  if(!cur)
    return;
  //In order depth first
  print(cur->left, depthVec);
  depthVec.push_back(cur->data);
  print(cur->right, depthVec);
}

//Print Function (No param)
  template<class T>
void BST<T>::print(std::vector<T> &depthVec) 
{
  depthVec.clear(); //Ensure we're working with an empty vector

  print(root, depthVec); //Fill that bad boy up
}

//Breadth Function
//Inserts into vector
  template<class T>
void BST<T>::breadth(Node* cur, int level, std::vector<T> &breadthQueue)
{
  if(!cur)
    return;
  if(level == 1)
    breadthQueue.push_back(cur->data);
  else 
  {
    breadth(cur->left, level-1, breadthQueue);
    breadth(cur->right, level-1, breadthQueue);
  }
}

//Breadth Function (No Param)
  template<class T>
void BST<T>::breadth(std::vector<T> &breadthQueue)
{
  breadthQueue.clear(); //Make sure vector is empty before we fill it
  for(int level = 1; level <= height(); level++)
  {
    breadth(root, level, breadthQueue); //Fill the vector
  }
}


//Distance Function -- Finds all distances
  template<class T>
void BST<T>::distance(Node* cur, std::vector<int> &dist, int cur_count)
{
  //No node
  if(!cur)
  {
    return;
  }

  dist.push_back(cur_count); //Add distance from root (Root will add "0", child will add 1, so on)

  distance(cur->left, dist, cur_count+1);
  distance(cur->right, dist, cur_count+1);

}

//Distance Function -- Finds average
  template<class T>
float BST<T>::distance()
{
  std::vector<int> dist;

  distance(root, dist, 0);

  float total(0);
  for(unsigned int i = 0; i < dist.size(); i++)
  {
    total += dist[i];
  }
  return ((dist.size() != 0) ? total/(dist.size()) : 0);
}

//Balanced Function -- Private, overloaded
  template<class T>
bool BST<T>::balanced(Node* cur, int dist)
{
  //Cur is null and at not max distance
  if(!cur && dist > 0)
    return false;
  //Cur is null and at max distance
  if(!cur)
    return true;
  //Recurse case
  return (balanced(cur->left, dist-1) && balanced(cur->right, dist-1)) ? true : false; //If both left and right return true, return true. Otherwise its false.
}

//Balaced Function -- depends on Distance
  template<class T>
int BST<T>::balanced()
{
  std::vector<int> dist; //Finds all distances so we can get largest

  distance(root, dist, 0);
  int largestDist(0);
  for(unsigned int i=0; i < dist.size(); i++) //Gets largest distance to make sure tree is balanced
  {
    if(dist[i] > largestDist)
      largestDist = dist[i];
  }

  return balanced(root, largestDist - 1) ? largestDist : -1;
}

//Rebalance Function
  template<class T>
void BST<T>::rebalance()
{
  std::vector<T> treeV;
  //Get all nodes
  print(root, treeV);
  //Clear tree
  clear();

  //Refill tree
  rebalance(treeV, 0, treeV.size() - 1);
}

//Algorithm for rebalancing
  template<class T>
void BST<T>::rebalance(std::vector<T> &treeV, int min, int max)
{
  //Base case: Only one item left to insert
  if(min == max)
  {
    insert(treeV[min]);
    return;
  }
  //Base case: Only two items left to insert
  if(min == max-1)
  {
    insert(treeV[min]);
    insert(treeV[max]);
    return;
  }
  /*
   *Get middle of the vector, insert into tree then split vector off into two vectors: one left, one right. 
   *Recursively act upon those vectors until we have 2 or 1 items left, base case those, and return.
   */
  int mid = (min+max)/2; // Middle of vector. Will math.floor if min+max is odd
  //Insert root
  insert(treeV[mid]);
  //Recursive cases: Work on left subtree
  rebalance(treeV, min, mid - 1);
  //Work on right subtree
  rebalance(treeV, mid + 1, max);
}

//Clear Function
  template<class T>
void BST<T>::clear(Node* &cur)
{
  //Base Case: end of tree
  if(!cur)
    return;
  //clear left subtree
  clear(cur->left);
  cur->left = NULL;
  //clear right subtree
  clear(cur->right);
  cur->right = NULL;

  //Clear root node
  delete cur;
  cur = NULL;
}

template class BST<std::string>;
