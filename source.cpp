#include "bst.h"
#include <iostream>
using namespace std;

int main()
{
   bst tree1;
   tree1.Add(10);
   tree1.Add(5);
   tree1.Add(27);
   tree1.Add(14);
   tree1.Add(7);
   tree1.Add(30);
   tree1.Add(9);
   tree1.Add(39);
   tree1.Add(19);
   tree1.Add(28);
   cout << "printing BST tree..." << endl;
   tree1.Print();

   tree1.Remove(30);
   tree1.Print();


   // tree1.Print();

   // tree1.Print();

   // ll tree2;
   // tree2.Add(10);
   // tree2.Add(5);
   // tree2.Add(27);
   // tree2.Add(14);
   // tree2.Add(2);
   // tree2.Add(7);
   // tree2.Add(30);
   // tree2.Add(9);
   // cout << "printing linked list..." << endl;
   // tree2.Print();

   // cout << "removing..." << endl;
   // tree2.Remove(14);
   // tree2.Remove(2);
   // tree2.Remove(30);
   // tree2.Remove(5);
   // tree2.Remove(27);
   // tree2.Remove(40);
   // tree2.Remove(1);
   // tree2.Print();
}