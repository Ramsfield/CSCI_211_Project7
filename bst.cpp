//bst.cpp
//Michael Griffith
//Project 7
#include"bst.h"
#include<iostream> //Print function

//Vector print function
  template<class T>
void BST<T>::printVec(std::vector<T> vec)
{
  int sz = size(); //Get amount of nodes
  for(int i = 0; i < sz ; i++)
  {
    std::cout << vec[i];
    if(!(i == sz-1)) //If not last item in list
      std::cout << ", ";
  }
}

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
void BST<T>::print() 
{
  std::vector<T> depthVec;

  print(root, depthVec);

  printVec(depthVec);
}

//Breadth Function
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
void BST<T>::breadth()
{
  std::vector<T> breadthQueue;
  for(int level = 1; level <= height(); level++)
  {
    breadth(root, level, breadthQueue);
  }
  printVec(breadthQueue);
}


//Distance Function -- Finds all distances
  template<class T>
void BST<T>::distance(Node* cur, std::vector<int> &dist, int cur_count)
{
  //When reaching 
  if(!cur)
  {
    if(cur_count != 0)
      dist.push_back(cur_count - 1);
  }
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
    std::cout << dist[i] << "\n";
    total += dist[i];
  }
  return ((dist.size() != 0) ? total/(dist.size()) : 0);
}

template class BST<std::string>;
