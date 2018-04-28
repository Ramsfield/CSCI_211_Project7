//main.cpp
//Michael Griffith
//Project 7
#include<iostream> //Used for standard out
#include"bst.h"

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
        std::cout << "insert <" << inputData << "> failed. String already in tree.\n";
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
      std::cout << "{";
      tree.print();
      std::cout << "}\n";
      std::cin.ignore();
    }

    //Print Function (Breadth First)
    else if (commandInput == "breadth")
    {
      std::cout << "{";
      tree.breadth();
      std::cout << "}\n";
      std::cin.ignore();
    }

    //FIXME Logic is incredibly screwed up
    else if (commandInput == "distance")
    {
      std::cout << tree.distance() << std::endl;
      std::cin.ignore();
    }

    //TODO
    else if (commandInput == "balanced")
      std::cout << "Not currently functional\n";
    //TODO
    else if (commandInput == "rebalance")
      std::cout << "Not currently functional\n";

    //Height command
    else if (commandInput == "height")
    {
      std::cout << tree.height() << std::endl;
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
