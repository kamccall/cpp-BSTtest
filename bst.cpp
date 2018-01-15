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
   // duplicate entries will fall out
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

Node* bst::Find(int number)
{
   return Find(head, number);
}

Node* bst::Find(Node*& nodePtr, int number)
{
   if(nodePtr == nullptr) return nullptr;
   else if (number < nodePtr->data) return Find(nodePtr->left, number);
   else if (number > nodePtr->data) return Find(nodePtr->right, number);
   else return nodePtr;
}

Node* bst::FindMax(Node* nodePtr)
{
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
      // leaf node: no children
      if(nodePtr->left == nullptr && nodePtr->right == nullptr)
      {
         delete nodePtr;
         nodePtr = nullptr;
      }
      else if(nodePtr->left == nullptr)
      {
         Node* tempPtr = nodePtr;
         nodePtr = nodePtr->right;
         delete tempPtr;
      }
      else if(nodePtr->right == nullptr)
      {
         Node* tempPtr = nodePtr;
         nodePtr = nodePtr->left;
         delete tempPtr;
      }
      else
      {
         Node* tempPtr = FindMax(nodePtr->left);
         nodePtr->data = tempPtr->data;
         nodePtr->left = Remove(nodePtr->left, tempPtr->data);
      }
   }
   return nodePtr;
}

// LINKED LIST STUFF ----------------------------------------------------------
llNode::llNode(): next(nullptr) {}

llNode::llNode(int number): data(number), next(nullptr) {}

ll::ll(): head(nullptr) {}

ll::~ll()
{
   llNode* nodePtr = head;

   if(nodePtr != nullptr)
   {
      do
      {
         llNode* nextNode = nodePtr->next;
         delete(nodePtr);
         nodePtr = nextNode;
      } while (nodePtr != nullptr);
   }
}

void ll::Add(int number)
{
   llNode* newNode = new llNode(number);
   Add(newNode, head);
}

void ll::Add(llNode* newNodePtr, llNode* headPtr)
{
   if (headPtr == nullptr)
   {
      head = newNodePtr;
   }
   else if(newNodePtr->data < headPtr->data)
   {
      newNodePtr->next = headPtr;
      head = newNodePtr;
   }
   else
   {
      llNode* nextNodePtr = headPtr->next;

      while(nextNodePtr != nullptr && newNodePtr->data > nextNodePtr->data)
      {
         headPtr = headPtr->next;
         nextNodePtr = headPtr->next;
      }

      headPtr->next = newNodePtr;

      if(nextNodePtr != nullptr)
      {
         newNodePtr->next = nextNodePtr;
      }
   }
}

void ll::Print() const
{
   Print(head);
}

void ll::Print(llNode* nodePtr) const
{
   if(nodePtr == nullptr) return;
   else
   {
      while(nodePtr != nullptr)
      {
         cout << nodePtr->data << endl;
         nodePtr = nodePtr->next;
      }
   }
}

void ll::Remove(int number)
{
   llNode* nodePtr = head;

   if (nodePtr == nullptr) return;
   else if(nodePtr->data == number)
   {
      head = nodePtr->next;
      delete(nodePtr);
   }
   else
   {
      llNode* nextNodePtr = nodePtr->next;
   
      while(nextNodePtr !=nullptr && number > nextNodePtr->data)
      {
         nodePtr = nodePtr->next;
         nextNodePtr = nodePtr->next;
      }

      if(nextNodePtr != nullptr)
      {
         if (nextNodePtr->data == number)
         {
            nodePtr->next = nextNodePtr->next;
            delete(nextNodePtr);
         }
      }
   }
}

