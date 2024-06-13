

#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    string info;
    node* leftchild;
    node* rightchild;

    // Constructor for the node class
    node(string i, node* l, node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};
class BinaryTree
{
public:
    node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr;
    }
    void insert(string element) //Insert a node in the search tree
    {
        node* newnode = new node(element, nullptr, nullptr); // Allocate memory for the new node
        newnode->info = element; // Assign value to the data field of the new node
        newnode->leftchild = nullptr; // Make left child of the new node point to NULL
        newnode->rightchild = nullptr; // Make right child of the new node point to NULL

        node* parent = nullptr;
        node* currentnode = nullptr;
        search(element, parent, currentnode); // Locate teh node which will be the parent of the node to be insert

        if (parent == nullptr) // If the parent is NULL (Tree is empty)
        {
            ROOT = newnode; // Mark the new node as ROOT
            return; //Exit
        }

        if (element < parent->info) // If the value in the data field of the new node is less than that of the parent
        {
            parent->leftchild = newnode; // Make the left child of the parent point to the new node
        }
        else if (element > parent->info) // If the value in the data field of the new node is greater than that of the parent
        {
            parent->rightchild = newnode; //  Make the right child of the parent point to the new node
        }
    }
    void search(string element, node*& parent, node*& currentnode)
    {
        //this function searches the currentnode of the specified node as well as the current node of its parent
        currentnode = ROOT;
        parent = NULL;
        while ((currentnode != NULL) && (currentnode->info != element))
        {
            parent = currentnode;
            if (element < currentnode->info)
                currentnode = currentnode->leftchild;
            else
                currentnode = currentnode->rightchild;
        }
    }
};

int main()
{
    
}


