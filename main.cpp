//main.cpp
//Michael Griffith
//Project 7
#include<iostream> //Used for standard out
#include"bst.h"
#include<vector> //Used for print

/*
 * Utilized for printing both breadth and depth. Asks BST for a vector of the elements
 * then runs through, printing them
 */
void printVec(std::vector<std::string>&);

int main()
{
  std::string commandInput; //Used to interface with user
  BST<std::string> tree; //Initialize the tree
  while(std::cin.peek() != EOF) //Keep going while there is no end
  {
    std::cin >> commandInput;

    //Echo Command
    if(commandInput == "echo")
    {
      std::cin.ignore(); //That pesky whitespace
      std::string output; //Stores what the user wants echo'd
      getline(std::cin, output);
      std::cout << output << std::endl;
    }

    //Insert Command
    else if (commandInput == "insert")
    {
      std::cin.ignore(); //That pesky whitespace
      std::string inputData;
      getline(std::cin, inputData);

      if(!tree.insert(inputData)) //Insert it
        std::cerr << "insert <" << inputData << "> failed. String already in tree.\n";
    }

    //Size Command
    else if (commandInput == "size")
      std::cout << tree.size() << std::endl;

    //Find Command
    else if (commandInput == "find")
    {
      std::cin.ignore(); //That pesky whitespace
      std::string inputData;
      std::cin >> inputData;
      std::cin.ignore(); //Set up for next cin

      std::cout << "<" << inputData << "> is ";
      if(!tree.find(inputData))
        std::cout << "not ";
      std::cout << "in tree.\n";
    }

    //Print Function (Depth First)
    else if (commandInput == "print")
    {
      std::vector<std::string> stringVec;
      std::cout << "{";
      tree.print(stringVec); //Fill up the vec
      printVec(stringVec); //Print out the vec
      std::cout << "}\n";
      std::cin.ignore();
    }

    //Print Function (Breadth First)
    else if (commandInput == "breadth")
    {
      std::vector<std::string> stringVec;
      std::cout << "{";
      tree.breadth(stringVec); //Fill vector
      printVec(stringVec); //Print vector
      std::cout << "}\n";
      std::cin.ignore();
    }

    //Distance Function
    else if (commandInput == "distance")
    {
      std::cout << "Average distance of nodes to root = " << tree.distance() << std::endl;
      std::cin.ignore();
    }


    //Balanced Function
    //Balanced returns height if it is balanced, -1 if not balanced
    else if (commandInput == "balanced")
    {
      std::cout << "Tree is ";

      //Check if tree is balanced
      if(tree.balanced() == -1)
        std::cout << "not ";

      std::cout << "balanced.\n";
      std::cin.ignore();
    }

    //TODO
    else if (commandInput == "rebalance")
    {
      tree.rebalance();
      std::cin.ignore();
    }

    //Height command -- Added for debugging use
    else if (commandInput == "height")
    {
      std::cout << tree.height() << std::endl;
      std::cin.ignore();
    }
    
    //Clear command -- Added for debugging use
    else if (commandInput == "clear")
    {
      tree.clear();
      std::cin.ignore();
    }
    else
    {
      std::cerr << "Illegal command <" << commandInput << ">.\n";
      std::string trash;        //Gotta let the garbage man know
      getline(std::cin, trash); //I've found some garbage.
    }
  }
  return 0;
}

void printVec(std::vector<std::string> &stringVec)
{
  for(unsigned int i = 0; i < stringVec.size(); i++)
  {
    std::cout << stringVec[i];
    if(!(i==stringVec.size()-1))
      std::cout << ", "; // Checks if it is the last thing printing out
  }
}
