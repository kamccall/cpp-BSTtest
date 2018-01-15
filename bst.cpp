#include "bst.h"
#include <iostream>
using namespace std;

Node::Node(): left(nullptr), right(nullptr) {}

Node::Node(int number): data(number), left(nullptr), right(nullptr) {}

bst::bst(): head(nullptr) {}

bst::~bst()
{
   if (head != nullptr)
   {
      Clear(head);
   }
}

void bst::Clear(Node* nodePtr)
{
   if (nodePtr->left != nullptr) Clear(nodePtr->left);
   if (nodePtr->right != nullptr) Clear(nodePtr->right);
   delete(nodePtr);
}

void bst::Add(int number)
{
   Node* newNode = new Node(number);
   Add(newNode, head);
}

void bst::Add(Node* newNodePtr, Node*& headPtr)
{
   if(headPtr == nullptr)
   {
      headPtr = newNodePtr;
   }
   else if(newNodePtr->data < headPtr->data)
   {
      Add(newNodePtr, headPtr->left);
   }
   else if(newNodePtr->data > headPtr->data)
   {
      Add(newNodePtr, headPtr->right);
   }
   // assumes no duplicate entries
}

void bst::Print() const
{
   Print(head);
}

void bst::Print(Node* nodePtr) const
{
   // cout << "head4: " << head << endl;
   if(nodePtr == nullptr) return;
   if (nodePtr->left != nullptr) Print(nodePtr->left);
   cout << nodePtr->data << endl;
   if (nodePtr->right != nullptr) Print(nodePtr->right);
}

// Node* bst::Find(int number)
// {
//    return Find(head, number);
// }

// Node* bst::Find(Node*& nodePtr, int number)
// {
//    if(nodePtr == nullptr) return nullptr;
//    else if (number < nodePtr->data) return Find(nodePtr->left, number);
//    else if (number > nodePtr->data) return Find(nodePtr->right, number);
//    else return nodePtr;
// }

Node* bst::FindMax(Node* nodePtr)
{
   // passed the left sub-tree below a target, gets max and returns pointer
   if(nodePtr == nullptr) return nullptr;
   while (nodePtr->right != nullptr)
   {
      nodePtr = nodePtr->right;
   }
   return nodePtr;
}

void bst::Remove(int number)
{
   Remove(head, number);
}

Node* bst::Remove(Node* nodePtr, int number)
{
   // called from node above one to delete
   if(nodePtr == nullptr) return nullptr;
   else if(number < nodePtr->data)
   {
      nodePtr->left = Remove(nodePtr->left, number);
   }   
   else if(number > nodePtr->data)
   {
      nodePtr->right = Remove(nodePtr->right, number);
   }
   else
   {
      // no children
      if(nodePtr->left == nullptr && nodePtr->right == nullptr)
      {
         delete nodePtr;
         nodePtr = nullptr;
      }
      // only 1 (right) child
      else if(nodePtr->left == nullptr)
      {
         Node* tempPtr = nodePtr;
         nodePtr = nodePtr->right;
         delete tempPtr;
      }
      // only 1 (left) child
      else if(nodePtr->right == nullptr)
      {
         Node* tempPtr = nodePtr;
         nodePtr = nodePtr->left;
         delete tempPtr;
      }
      // has 2 children, so swap data w/ in-order predecessor
      else
      {
         Node* tempPtr = FindMax(nodePtr->left);
         nodePtr->data = tempPtr->data;
         nodePtr->left = Remove(nodePtr->left, tempPtr->data);
      }
   }
   return nodePtr;
}