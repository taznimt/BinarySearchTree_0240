

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
    void inorder(node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr->leftchild);
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }
    void preorder(node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr->leftchild);
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }
    void postorder(node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr->leftchild);
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) :";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            x.insert(word);
            break;
        }
        case '2':
        {
            x.inorder(x. ROOT);
            break;
        }
        case '3':
        {
            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {
            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
              cout << "Invalid option" << endl;
              break;
        
        }
        }
    }
    

}

