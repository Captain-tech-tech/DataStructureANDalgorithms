// checking if it is +ive or -ive, if it is positive we have to push again and go to right child and if negative we should print
#include <iostream>
#include <cstdint>
#include <iomanip>

using namespace std;


class Node
{
public:

    Node *lchild;
    int data;
    Node *rchild;

    Node(int value)
    {
        data = value;
        lchild = nullptr;
        rchild = nullptr;
    }
};


// LINKED STACK
// IMPORTANT: The original stack stored int   :   int data;
// But tree traversal requires us to store Node*.Therefore we use intptr_t.
// intptr_t is an integer type capable of holding a pointer.

class LinkedStack
{
private:

    struct StackNode
    {
        intptr_t data;
        StackNode *next;

        StackNode(intptr_t val, StackNode *oldTop)
        {
            data = val;
            next = oldTop;
        }
    };

    StackNode *top;
    int size;

    bool isEmpty()
    {
        return top == nullptr;
    }

public:

    // Constructor
    LinkedStack()
    {
        top = nullptr;
        size = 0;
    }


    // Push
    void push(intptr_t val)
    {
        StackNode *newNode =
            new StackNode(val, top);

        top = newNode;
        size++;
    }


    // Pop
    intptr_t pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return 0;
        }

        StackNode *popNode = top;

        intptr_t topVal = popNode->data;

        top = top->next;

        delete popNode;

        size--;

        return topVal;
    }


    // Peek
    intptr_t peek()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return 0;
        }

        return top->data;
    }


    // Check empty
    bool empty()
    {
        return top == nullptr;
    }


    // Get size
    int getSize()
    {
        return size;
    }


    // Destructor
    ~LinkedStack()
    {
        while (top)
        {
            StackNode *curr = top;

            top = top->next;

            delete curr;
        }
    }
};


// TREE CLASS
class Tree
{
public:

    Node *root;


    // Constructor
    Tree()
    {
        root = nullptr;
    }


    // Create tree manually
    // -1 means no node.
    // Example:
    //
    //              1
    //            /   \
    //           2     3
    //          / \
    //         4   5
    //
    // Input:
    // Root = 1
    // Left of 1 = 2
    // Left of 2 = 4
    // Left of 4 = -1
    // Right of 4 = -1
    // Right of 2 = 5
    // ...

    void CreateTree()
    {
        int x;

        cout << "Enter root value (-1 for empty tree): ";
        cin >> x;

        if (x == -1)
        {
            root = nullptr;
            return;
        }

        root = new Node(x);

        CreateChildren(root);
    }


private:

    // Recursive helper used only for creating the tree

    void CreateChildren(Node *p)
    {
        int x;

        cout << "Enter left child of "
             << p->data
             << " (-1 for none): ";

        cin >> x;

        if (x != -1)
        {
            p->lchild = new Node(x);

            CreateChildren(p->lchild);
        }


        cout << "Enter right child of "
             << p->data
             << " (-1 for none): ";

        cin >> x;

        if (x != -1)
        {
            p->rchild = new Node(x);

            CreateChildren(p->rchild);
        }
    }


public:

    // ITERATIVE PREORDER
    // The stack replaces the recursive function call stack.
    void Preorder()
    {
        if (root == nullptr)
        {
            return;
        }

        LinkedStack st;

        Node *t = root;


        while (t != nullptr || !st.empty())
        {
            if (t != nullptr)
            {
                // Visit the current node
                cout << t->data << " ";

                // Save current node so that we can later
                // come back and process its right subtree.
                st.push(
                    reinterpret_cast<intptr_t>(t)
                );

                // Move to left subtree
                t = t->lchild;
            }
            else
            {
                // Get previous node
                t = reinterpret_cast<Node *>(st.pop());

                // Move to right subtree
                t = t->rchild;
            }
        }
    }


    // ITERATIVE INORDER
    void Inorder()
    {
        if (root == nullptr)
        {
            return;
        }

        LinkedStack st;

        Node *t = root;


        while (t != nullptr || !st.empty())
        {
            if (t != nullptr)
            {
                // Save current node
                st.push(
                    reinterpret_cast<intptr_t>(t)
                );

                // Go as far left as possible
                t = t->lchild;
            }
            else
            {
                // Get the last saved node
                t = reinterpret_cast<Node *>(st.pop());

                // Visit the node
                cout << t->data << " ";

                // Move to right subtree
                t = t->rchild;
            }
        }
    }


    // ITERATIVE POSTORDER
    // We use your SAME idea:
    // Positive pointer:
    //      First time we see the node.
    //      Push it again as negative.
    //      Then process its right subtree.
    // Negative pointer:
    //      Second time we see the node.
    //      Now both left and right subtrees have been
    //      processed, so we print the node.
    void Postorder()
    {
        if (root == nullptr)
        {
            return;
        }

        LinkedStack st;

        Node *t = root;


        while (t != nullptr || !st.empty())
        {
            if (t != nullptr)
            {
                // First visit to this node, We DON'T print it yet because Postorder is: Left -> Right -> Root

                intptr_t address =
                    reinterpret_cast<intptr_t>(t);

                // Push positive address.Positive means:"I have reached this node for the first time."
                st.push(address);

                // Go to left subtree
                t = t->lchild;
            }
            else
            {
                // Get the node from stack
                intptr_t temp = st.pop();


                // POSITIVE
                // This is the first time we are processing this node after coming back from the left subtree. We now need to process the right subtree.

                if (temp > 0)
                {
                    // Convert integer back into Node*
                    Node *p =
                        reinterpret_cast<Node *>(temp);

                    // Push the node again, but this time with a negative marker.
                    // Negative means: "Left and right subtrees will be processed;  print this node when we see it again."
                    st.push(-temp);

                    // Move to right subtree
                    t = p->rchild;
                }
                // NEGATIVE
                // This node has already had its left and right subtrees processed. Therefore we can finally print it.
                else
                {
                    // Convert negative value back to positive
                    intptr_t address = -temp;

                    Node *p =
                        reinterpret_cast<Node *>(address);


                    // Visit the node
                    cout << p->data << " ";

                    // Important: We don't move anywhere here. The next iteration will pop the next pending node from the stack.
                    t = nullptr;
                }
            }
        }
    }


    // DESTRUCTOR: Delete all tree nodes using postorder traversal.
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


    ~Tree()
    {
        DeleteTree(root);
    }
};

// MAIN
int main()
{
    Tree t;
    // Create the tree
    t.CreateTree();

    cout << "\n====================================\n";
    // PREORDER
    cout << "Preorder : ";
    t.Preorder();
    cout << endl;


    // INORDER
    cout << "Inorder  : ";
    t.Inorder();
    cout << endl;


    // POSTORDER
    cout << "Postorder: ";
    t.Postorder();
    cout << endl;
    cout << "====================================\n";

    return 0;
}


