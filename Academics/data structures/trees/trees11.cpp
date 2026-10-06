






// Binary tree : every node can have maximum 2 children or a node can have a maximum of degree 2   deg(t) = 2
// childrens can 0,1 or 2





// generating tree with the help of queue


#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;

    // Constructor
    Node(int value)
    {
        data = value;
        lchild = nullptr;
        rchild = nullptr;
    }
};


// This queue stores Node* because we need to store addresses

class Queue
{
private:

    // Node of the linked queue
    struct QueueNode
    {
        Node *data;
        QueueNode *next;

        QueueNode(Node *ptr)
        {
            data = ptr;
            next = nullptr;
        }
    };

    QueueNode *front;
    QueueNode *rear;

public:

    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Check whether queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Add a tree node to the queue
    void enqueue(Node *ptr)
    {
        QueueNode *newNode = new QueueNode(ptr);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove and return a tree node
    Node* dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }

        QueueNode *temp = front;

        Node *ptr = front->data;

        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        return ptr;
    }
};


class Tree
{
public:

    Node *root;

    // Constructor
    Tree()
    {
        root = nullptr;
    }


    void CreateTree()
    {
        int x;

        cout << "Enter root value: ";
        cin >> x;

        // If user enters -1, create an empty tree
        if (x == -1)
        {
            root = nullptr;
            return;
        }

        // Create root node
        root = new Node(x);

        // Queue is used for level-order construction
        Queue q;

        // Put root into queue
        q.enqueue(root);


        // Continue until all nodes have been processed
        while (!q.isEmpty())
        {
            // Get the current node
            Node *p = q.dequeue();


            // ------------------------------------------------
            // Create LEFT child
            // ------------------------------------------------

            cout << "Enter left child of " << p->data << ": ";
            cin >> x;

            if (x != -1)
            {
                Node *temp = new Node(x);

                p->lchild = temp;

                // Add new child to queue
                q.enqueue(temp);
            }


            // ------------------------------------------------
            // Create RIGHT child
            // ------------------------------------------------

            cout << "Enter right child of " << p->data << ": ";
            cin >> x;

            if (x != -1)
            {
                Node *temp = new Node(x);

                p->rchild = temp;

                // Add new child to queue
                q.enqueue(temp);
            }
        }
    }

// for counting number of nodes
    int Count(Node *p)
    {
        int x, y;

        if (p != nullptr)
        {
            x = Count(p->lchild);
            y = Count(p->rchild);
            return x + y + 1;
        }
        return 0;
    }
    // int count(Node *p)     // for counting number of nodes
    // {
    //     if(root)
    //         return count(root->lchild)+count(root->rchild)+1;
    //     return 0;
    // }


    // (1)
    // for counting number of leaf nodes
    int countLeafNodes(Node *p)
    {
        int x,y;
        if(p!=nullptr)
        {
            x = countLeafNodes(p->lchild);
            y = countLeafNodes(p->rchild);
            if(p->lchild==nullptr && p->rchild==nullptr)   // this condition because leaf nodes are with the degree 0
                return x+y+1;
            else
                return x+y;
        }
        return 0;
    }

    // (2)
    // for counting number of non-leaf nodes with degree 2 only
    int countNonLeafNodes(Node *p)
    {
        int x,y;
        if(p!=nullptr)
        {
            x = countLeafNodes(p->lchild);
            y = countLeafNodes(p->rchild);
            if(p->lchild!=nullptr && p->rchild!=nullptr)   // this condition because non-leaf nodes are with the degree 2 here
                return x+y+1;
            else
                return x+y;
        }
        return 0;
    }

    // (3)
    // for counting number of non-leaf nodes with degree 1 or 2 both
    int countNonleafnodes(Node *p)
    {
        int x,y;
        if(p!=nullptr)
        {
            x = countLeafNodes(p->lchild);
            y = countLeafNodes(p->rchild);
            if(p->lchild!=nullptr || p->rchild!=nullptr)   // this condition because non-leaf nodes are with the degree 1 or 2 here
                return x+y+1;
            else
                return x+y;
        }
        return 0;
    }    


    // (4)
    // for counting number of non-leaf nodes with degree 1 only
    int countNonleafNodes(Node *p)
    {
        int x,y;
        if(p!=nullptr)
        {
            x = countLeafNodes(p->lchild);
            y = countLeafNodes(p->rchild);
            // if((p->lchild!=nullptr && p->rchild==nullptr) || (p->lchild==nullptr && p->rchild!=nullptr)) // this condition because non-leaf nodes are with the degree 1 or 2 here
            // or
            if(p->lchild!=nullptr ^ p->rchild!=nullptr)
                return x+y+1;
            else
                return x+y;
        }
        return 0;
    }    

    
    // PREORDER
    // Root -> Left -> Right
    void Preorder(Node *p)   // there are n nodes and n+1 nullptr in the binary tree  so total number of calls = n+n+1 = 2n+1
    {
        if (p == nullptr)
        {
            return;
        }

        // Visit root
        cout << p->data << " ";

        // Visit left subtree
        Preorder(p->lchild);

        // Visit right subtree
        Preorder(p->rchild);
    }


    // INORDER
    // Left -> Root -> Right
    void Inorder(Node *p)
    {
        if (p == nullptr)
        {
            return;
        }

        // Visit left subtree
        Inorder(p->lchild);

        // Visit root
        cout << p->data << " ";

        // Visit right subtree
        Inorder(p->rchild);
    }


    // POSTORDER
    // Left -> Right -> Root
    void Postorder(Node *p)
    {
        if (p == nullptr)
        {
            return;
        }

        // Visit left subtree
        Postorder(p->lchild);

        // Visit right subtree
        Postorder(p->rchild);

        // Visit root
        cout << p->data << " ";
    }


    // LEVEL ORDER

    void Levelorder()
    {
        // Empty tree
        if (root == nullptr)
        {
            return;
        }

        Queue q;

        // Start with root
        q.enqueue(root);

        while (!q.isEmpty())
        {
            // Remove node from front
            Node *p = q.dequeue();

            // Visit node
            cout << p->data << " ";


            // Add left child if it exists
            if (p->lchild != nullptr)
            {
                q.enqueue(p->lchild);
            }


            // Add right child if it exists
            if (p->rchild != nullptr)
            {
                q.enqueue(p->rchild);
            }
        }
    }

    // HEIGHT
    int Height(Node *p)
    {
        // Empty subtree
        if (p == nullptr)
        {
            return 0;
        }

        // Find height of left subtree
        int x = Height(p->lchild);

        // Find height of right subtree
        int y = Height(p->rchild);

        // Take the larger subtree height
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }


    // Destructor helper
    // Deletes every node using postorder traversal.

    void DeleteTree(Node *p)
    {
        if (p == nullptr)
        {
            return;
        }

        DeleteTree(p->lchild);
        DeleteTree(p->rchild);

        delete p;
    }


    // Destructor
    ~Tree()
    {
        DeleteTree(root);
    }
};


int main()
{
    Tree t;

    // Create tree
    t.CreateTree();


    cout << "\n\n";


    cout << "Preorder: ";
    t.Preorder(t.root);
    cout << endl;


    cout << "Inorder: ";
    t.Inorder(t.root);
    cout << endl;


    cout << "Postorder: ";
    t.Postorder(t.root);
    cout << endl;


    cout << "Level Order: ";
    t.Levelorder();
    cout << endl;


    cout << "Height (nodes): "
         << t.Height(t.root)
         << endl;

    cout << "Number of nodes = "<< t.Count(t.root)<< endl;

    return 0;
}








