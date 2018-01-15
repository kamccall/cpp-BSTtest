#include "bst.h"
#include <iostream>
using namespace std;

int main()
{
   bst tree;
   tree.Add(10);
   tree.Add(5);
   tree.Add(27);
   tree.Add(14);
   tree.Add(7);
   tree.Add(30);
   tree.Add(9);
   tree.Add(39);
   tree.Add(19);
   tree.Add(29);
   cout << "printing BST tree..." << endl;
   tree.Print();
   cout << endl;

   cout << "remove 30, add 28..." << endl;
   tree.Remove(30);
   tree.Add(28);
   tree.Print();
   cout << endl;

   cout << "remove 5, remove 39..." << endl;
   tree.Remove(5);
   tree.Remove(39);
   tree.Print();

   // tree1.Print();

   // tree1.Print();
}