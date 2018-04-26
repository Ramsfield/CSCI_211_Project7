//main.cpp
//Michael Griffith
//Project 7
#include<iostream> //Used for standard out
#include"bst.h"
#include"bst.cpp"

int main()
{
  std::string commandInput; //Used to interface with user
  BST<std::string> tree; //Initialize the tree
  while(std::cin.peek() != EOF) //Keep going while there is no end
  {
    std::cin >> commandInput;

    if(commandInput == "echo")
    {
      std::cin.ignore(); //That pesky whitespace
      std::string output; //Stores what the user wants echo'd
      getline(std::cin, output);
      std::cout << output << std::endl;
    }

    else if (commandInput == "insert")
    {
      std::cin.ignore(); //That pesky whitespace
      std::string inputData;
      std::cin >> inputData;
      std::cin.ignore(); //Set up for next cin

      if(!tree.insert(inputData)) //Insert it
        std::cout << "insert <" << inputData << "> failed. String already in tree.\n";
    }
    else if (commandInput == "size")
      std::cout << tree.size() << std::endl;
    else if (commandInput == "find")
      std::cout << "Not currently functional\n";
    else if (commandInput == "print")
      std::cout << "Not currently functional\n";
    else if (commandInput == "breadth")
      std::cout << "Not currently functional\n";
    else if (commandInput == "distance")
      std::cout << "Not currently functional\n";
    else if (commandInput == "balanced")
      std::cout << "Not currently functional\n";
    else if (commandInput == "rebalance")
      std::cout << "Not currently functional\n";
    else
    {
      std::cerr << "Illegal command <" << commandInput << ">.\n";
      std::string trash;        //Gotta let the garbage man know
      getline(std::cin, trash); //I've found some garbage.
    }
  }
  return 0;
}
