// A Binary Search Tree (BST) is a special type of binary tree in which the nodes are arranged according 
// to their values so that searching becomes efficient.

//              Node
//             /    \
//            /      \
//    smaller values  larger values

// for a node with value x:
// All values in left subtree  < x
// All values in right subtree > x

// Search = O(log n)
// Insert = O(log n)
// Delete = O(log n)


// Binary Search Tree
// │
// ├── Each node has at most 2 children
// │
// ├── Left subtree < node
// │
// ├── Right subtree > node
// │
// ├── Usually no duplicate keys
// │
// ├── Inorder traversal → sorted ascending order
// │
// ├── Search / Insert / Delete
// │      ├── Average/balanced: O(log n)
// │      └── Worst case: O(n)
// │
// └── Number of BSTs with n distinct keys
//        = Catalan number
//        = 1/(n+1) × C(2n,n)




#include <iostream>
#include <stack>
#include <queue>

using namespace std;


// NODE CLASS
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int value)
    {
        data = value;
        lchild = nullptr;
        rchild = nullptr;
    }
};


// BINARY SEARCH TREE CLASS
class BST
{
private:

    Node *root;

    // RECURSIVE SEARCH
    Node* RSearch(Node *p, int key)
    {
        if (p == nullptr)
            return nullptr;

        if (p->data == key)
            return p;

        if (key < p->data)
            return RSearch(p->lchild, key);

        return RSearch(p->rchild, key);
    }

    // RECURSIVE INSERT
    Node* RInsert(Node *p, int key)
    {
        if (p == nullptr)
        {
            return new Node(key);
        }

        if (key < p->data)
        {
            p->lchild = RInsert(p->lchild, key);
        }
        else if (key > p->data)
        {
            p->rchild = RInsert(p->rchild, key);
        }

        // If key == p->data, duplicate is ignored

        return p;
    }


    // RECURSIVE PREORDER
    // Root -> Left -> Right
    void RPreorder(Node *p)
    {
        if (p == nullptr)
            return;

        cout << p->data << " ";

        RPreorder(p->lchild);

        RPreorder(p->rchild);
    }


    // RECURSIVE INORDER
    // Left -> Root -> Right
    void RInorder(Node *p)
    {
        if (p == nullptr)
            return;

        RInorder(p->lchild);

        cout << p->data << " ";

        RInorder(p->rchild);
    }


    // RECURSIVE POSTORDER
    // Left -> Right -> Root
    void RPostorder(Node *p)
    {
        if (p == nullptr)
            return;

        RPostorder(p->lchild);

        RPostorder(p->rchild);

        cout << p->data << " ";
    }

    // RECURSIVE HEIGHT
    // Height = number of nodes in longest path
    int RHeight(Node *p)
    {
        if (p == nullptr)
            return 0;

        int x = RHeight(p->lchild);
        int y = RHeight(p->rchild);

        return (x > y) ? x + 1 : y + 1;
    }

    // INORDER PREDECESSOR
    // Largest value in left subtree
    Node* InPre(Node *p)
    {
        if (p == nullptr)
            return nullptr;

        while (p->rchild != nullptr)
        {
            p = p->rchild;
        }

        return p;
    }

    // INORDER SUCCESSOR
    // Smallest value in right subtree
    Node* InSucc(Node *p)
    {
        if (p == nullptr)
            return nullptr;

        while (p->lchild != nullptr)
        {
            p = p->lchild;
        }

        return p;
    }


    // RECURSIVE DELETE
    Node* RDelete(Node *p, int key)
    {
        if (p == nullptr)
            return nullptr;

        // Search in left subtree
        if (key < p->data)
        {
            p->lchild = RDelete(p->lchild, key);
        }

        // Search in right subtree
        else if (key > p->data)
        {
            p->rchild = RDelete(p->rchild, key);
        }

        // Node found
        else
        {
            // ----------------------------------------------
            // CASE 1: No child
            // ----------------------------------------------

            if (p->lchild == nullptr &&
                p->rchild == nullptr)
            {
                delete p;
                return nullptr;
            }

            // CASE 2: Only right child
            if (p->lchild == nullptr)
            {
                Node *temp = p->rchild;

                delete p;

                return temp;
            }

            // CASE 3: Only left child
            if (p->rchild == nullptr)
            {
                Node *temp = p->lchild;

                delete p;

                return temp;
            }

            // CASE 4: Two children
            Node *q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = RDelete(p->lchild, q->data);
        }
        return p;
    }

    // DELETE ENTIRE TREE
    void DeleteTree(Node *p)
    {
        if (p == nullptr)
            return;

        DeleteTree(p->lchild);
        DeleteTree(p->rchild);
        delete p;
    }

public:

    // CONSTRUCTOR
    BST()
    {
        root = nullptr;
    }

    // GET ROOT
    Node* getRoot()
    {
        return root;
    }

    // ITERATIVE SEARCH
    Node* Search(int key)
    {
        Node *p = root;

        while (p != nullptr)
        {
            if (key == p->data)
                return p;

            else if (key < p->data)
                p = p->lchild;

            else
                p = p->rchild;
        }

        return nullptr;
    }


    // PUBLIC RECURSIVE SEARCH
    Node* RecursiveSearch(int key)
    {
        return RSearch(root, key);
    }


    // ITERATIVE INSERT
    void Insert(int key)
    {
        // Empty tree
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }

        Node *p = root;
        Node *parent = nullptr;


        while (p != nullptr)
        {
            parent = p;

            if (key == p->data)
            {
                // Duplicate
                return;
            }

            else if (key < p->data)
            {
                p = p->lchild;
            }

            else
            {
                p = p->rchild;
            }
        }

        Node *newNode = new Node(key);

        if (key < parent->data)
            parent->lchild = newNode;

        else
            parent->rchild = newNode;
    }


    // PUBLIC RECURSIVE INSERT
    void RecursiveInsert(int key)
    {
        root = RInsert(root, key);
    }

    // ITERATIVE PREORDER
    // Uses built-in stack
    void Preorder()
    {
        if (root == nullptr)
            return;

        stack<Node*> st;

        st.push(root);


        while (!st.empty())
        {
            Node *p = st.top();
            st.pop();

            cout << p->data << " ";


            // Push right first
            if (p->rchild != nullptr)
                st.push(p->rchild);


            // Push left second
            // so left is processed first
            if (p->lchild != nullptr)
                st.push(p->lchild);
        }
    }


    // PUBLIC RECURSIVE PREORDER
    void RecursivePreorder()
    {
        RPreorder(root);
    }

    // ITERATIVE INORDER
    // Uses built-in stack
    void Inorder()
    {
        stack<Node*> st;

        Node *p = root;


        while (p != nullptr || !st.empty())
        {
            if (p != nullptr)
            {
                st.push(p);

                p = p->lchild;
            }

            else
            {
                p = st.top();
                st.pop();

                cout << p->data << " ";

                p = p->rchild;
            }
        }
    }

    // PUBLIC RECURSIVE INORDER
    void RecursiveInorder()
    {
        RInorder(root);
    }

    // ITERATIVE POSTORDER
    // Uses ONE built-in stack
    void Postorder()
    {
        if (root == nullptr)
            return;

        stack<Node*> st;

        Node *p = root;
        Node *lastVisited = nullptr;


        while (p != nullptr || !st.empty())
        {
            if (p != nullptr)
            {
                st.push(p);

                p = p->lchild;
            }

            else
            {
                Node *topNode = st.top();


                // Right subtree exists
                // and has not been visited
                if (topNode->rchild != nullptr &&
                    lastVisited != topNode->rchild)
                {
                    p = topNode->rchild;
                }

                else
                {
                    cout << topNode->data << " ";

                    lastVisited = topNode;

                    st.pop();
                }
            }
        }
    }


    // PUBLIC RECURSIVE POSTORDER
    void RecursivePostorder()
    {
        RPostorder(root);
    }

    // ITERATIVE HEIGHT
    // Uses built-in queue
    int Height()
    {
        if (root == nullptr)
            return 0;

        queue<Node*> q;

        q.push(root);

        int height = 0;


        while (!q.empty())
        {
            int nodes = q.size();

            height++;


            while (nodes > 0)
            {
                Node *p = q.front();
                q.pop();


                if (p->lchild != nullptr)
                    q.push(p->lchild);

                if (p->rchild != nullptr)
                    q.push(p->rchild);

                nodes--;
            }
        }

        return height;
    }


    // PUBLIC RECURSIVE HEIGHT
    int RecursiveHeight()
    {
        return RHeight(root);
    }

    // RECURSIVE DELETE
    void RecursiveDelete(int key)
    {
        root = RDelete(root, key);
    }


    // ITERATIVE DELETE
    void Delete(int key)
    {
        Node *p = root;
        Node *parent = nullptr;


        // Find node
        while (p != nullptr && p->data != key)
        {
            parent = p;

            if (key < p->data)
                p = p->lchild;

            else
                p = p->rchild;
        }


        // Not found
        if (p == nullptr)
            return;


        // CASE 4: Two children
        if (p->lchild != nullptr &&
            p->rchild != nullptr)
        {
            Node *predParent = p;
            Node *pred = p->lchild;


            // Find inorder predecessor
            while (pred->rchild != nullptr)
            {
                predParent = pred;
                pred = pred->rchild;
            }


            // Copy predecessor's value
            p->data = pred->data;


            // Now delete predecessor
            p = pred;
            parent = predParent;
        }


        // Now p has at most one child
        Node *child = nullptr;


        if (p->lchild != nullptr)
            child = p->lchild;

        else
            child = p->rchild;


        // Deleting root
        if (parent == nullptr)
        {
            root = child;

            delete p;

            return;
        }

        // Connect parent to child
        if (parent->lchild == p)
            parent->lchild = child;

        else
            parent->rchild = child;


        delete p;
    }


    // DISPLAY ALL TRAVERSALS
    void DisplayTraversals()
    {
        cout << "\n========================================\n";
        cout << "             TRAVERSALS\n";
        cout << "========================================\n";


        cout << "Recursive Preorder : ";
        RecursivePreorder();
        cout << endl;


        cout << "Iterative Preorder : ";
        Preorder();
        cout << endl;


        cout << "Recursive Inorder  : ";
        RecursiveInorder();
        cout << endl;


        cout << "Iterative Inorder  : ";
        Inorder();
        cout << endl;


        cout << "Recursive Postorder: ";
        RecursivePostorder();
        cout << endl;


        cout << "Iterative Postorder: ";
        Postorder();
        cout << endl;
    }


    // DISPLAY SEARCH RESULT
    void DisplaySearch(int key)
    {
        cout << "\n========================================\n";
        cout << "               SEARCH\n";
        cout << "========================================\n";


        if (RecursiveSearch(key) != nullptr)
            cout << "Recursive Search: " << key << " found\n";
        else
            cout << "Recursive Search: " << key << " not found\n";


        if (Search(key) != nullptr)
            cout << "Iterative Search: " << key << " found\n";
        else
            cout << "Iterative Search: " << key << " not found\n";
    }


    // DISPLAY HEIGHT
    void DisplayHeight()
    {
        cout << "\n========================================\n";
        cout << "                HEIGHT\n";
        cout << "========================================\n";


        cout << "Recursive Height : "
             << RecursiveHeight()
             << endl;


        cout << "Iterative Height : "
             << Height()
             << endl;
    }


    // DISPLAY DELETE RESULT
    void DisplayDeletion(int key)
    {
        cout << "\nDeleting " << key << " recursively...\n";

        RecursiveDelete(key);

        cout << "Inorder after deletion: ";
        Inorder();
        cout << endl;
    }


    // DESTRUCTOR
    ~BST()
    {
        DeleteTree(root);
    }
};




