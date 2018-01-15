using namespace std;

// BST STUFF
struct Node
{
public:
   int data;
   Node* left;
   Node* right;

   Node();
   Node(int number);
};

class bst
{
private:
   Node* head;
   void Print(Node* headPtr) const;
   void Add(Node* newNodePtr, Node*& headPtr);
   // Node* Find(Node*& nodePtr, int number);
   Node* Remove(Node* nodePtr, int number);

public:
   bst();
   ~bst();
   void Clear(Node* nodePtr);
   void Add(int number);
   // Node* Find(int number);
   Node* FindMax(Node* nodePtr);
   void Print() const;
   void Remove(int number);
};