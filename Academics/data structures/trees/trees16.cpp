// The properties of a Red-Black Tree written line by line:
// 1. It's a Height Balanced Binary Search Tree, Similar to 2-3-4 Tree
// 2. Every Node is either Red or Black
// 3. Root of a Tree is Black
// 4. NULL is also Black
// 5. Number of Blacks on Paths from Root to leaf are same
// 6. No 2 consecutive Red, Parent and Children of Red are Black
// 7. New Inserted node is Red
// 8. Height in (logn <= h <= 2logn)


////////
// enum (short for enumeration) is a user-defined data type used to assign names to a fixed set of integral constants. Instead of using arbitrary numbers 
// throughout your code, enums allow you to use readable words, making your code significantly easier to read and maintain

// • enum: The keyword used to declare an enumeration.
// • Color: The name of your new custom data type.
// • RED and BLACK: The enumerators (the named constants belonging to this type).
////////

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class RedBlackTree
{
private:
    enum Color { RED, BLACK };

    struct Node
    {
        int key;
        Color color;
        Node *left, *right, *parent;

        Node(int value = 0, Color c = BLACK):key(value), color(c),left(nullptr), right(nullptr), parent(nullptr) {}
    };
    // Node *NIL is used as a shared black sentinel node that represents the absence of a real node. 
    // Instead of using nullptr for every missing child, this implementation uses NIL.
    Node *NIL;     // Shared black sentinel
    Node *root;
    int nodeCount;

    // --------------------------------------------------------
    // ROTATIONS
    // --------------------------------------------------------

    void LeftRotate(Node *x)
    {
        Node *y = x->right;

        x->right = y->left;

        if (y->left != NIL)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == NIL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void RightRotate(Node *y)
    {
        Node *x = y->left;

        y->left = x->right;

        if (x->right != NIL)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == NIL)
            root = x;
        else if (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;

        x->right = y;
        y->parent = x;
    }

    // --------------------------------------------------------
    // INSERTION FIX-UP
    // --------------------------------------------------------

    void InsertFixup(Node *z)
    {
        while (z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node *uncle = z->parent->parent->right;

                // Case 1: parent and uncle are red
                if (uncle->color == RED)
                {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    // Case 2: left-right (LR)
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        LeftRotate(z);
                    }

                    // Case 3: left-left (LL)
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RightRotate(z->parent->parent);
                }
            }
            else
            {
                // Mirror cases: parent is a right child
                Node *uncle = z->parent->parent->left;

                // Case 1: parent and uncle are red
                if (uncle->color == RED)
                {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    // Case 2: right-left (RL)
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        RightRotate(z);
                    }

                    // Case 3: right-right (RR)
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    LeftRotate(z->parent->parent);
                }
            }
        }

        root->color = BLACK;
    }

    // --------------------------------------------------------
    // SUBTREE HELPERS
    // --------------------------------------------------------

    Node *MinimumNode(Node *p) const
    {
        while (p != NIL && p->left != NIL)
            p = p->left;

        return p;
    }

    Node *MaximumNode(Node *p) const
    {
        while (p != NIL && p->right != NIL)
            p = p->right;

        return p;
    }

    // Replace subtree u with subtree v. Replace one subtree with another subtree by updating the appropriate parent and child pointers.
    // v can be NIL, so NIL->parent is updated intentionally.
    void Transplant(Node *u, Node *v)
    {
        if (u->parent == NIL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        v->parent = u->parent;
    }

    // --------------------------------------------------------
    // DELETION FIX-UP
    // --------------------------------------------------------

    void DeleteFixup(Node *x)
    {
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                Node *w = x->parent->right;

                // Case 1: sibling is red
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    LeftRotate(x->parent);
                    w = x->parent->right;
                }

                // Case 2: sibling and both its children are black
                if (w->left->color == BLACK &&
                    w->right->color == BLACK)
                {
                    if (w != NIL)
                        w->color = RED;

                    x = x->parent;
                }
                else
                {
                    // Case 3: far child is black
                    if (w->right->color == BLACK)
                    {
                        w->left->color = BLACK;
                        w->color = RED;
                        RightRotate(w);
                        w = x->parent->right;
                    }

                    // Case 4: far child is red
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    LeftRotate(x->parent);

                    x = root;
                }
            }
            else
            {
                // Mirror cases: x is a right child
                Node *w = x->parent->left;

                // Case 1: sibling is red
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    RightRotate(x->parent);
                    w = x->parent->left;
                }

                // Case 2: sibling and both its children are black
                if (w->right->color == BLACK &&
                    w->left->color == BLACK)
                {
                    if (w != NIL)
                        w->color = RED;

                    x = x->parent;
                }
                else
                {
                    // Case 3: far child is black
                    if (w->left->color == BLACK)
                    {
                        w->right->color = BLACK;
                        w->color = RED;
                        LeftRotate(w);
                        w = x->parent->left;
                    }

                    // Case 4: far child is red
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    RightRotate(x->parent);

                    x = root;
                }
            }
        }

        x->color = BLACK;
    }

    // --------------------------------------------------------
    // RECURSIVE TRAVERSALS
    // --------------------------------------------------------

    void RInorder(Node *p) const
    {
        if (p == NIL)
            return;

        RInorder(p->left);
        cout << p->key << " ";
        RInorder(p->right);
    }

    void RPreorder(Node *p) const
    {
        if (p == NIL)
            return;

        cout << p->key << " ";
        RPreorder(p->left);
        RPreorder(p->right);
    }

    void RPostorder(Node *p) const
    {
        if (p == NIL)
            return;

        RPostorder(p->left);
        RPostorder(p->right);
        cout << p->key << " ";
    }

    int RHeight(Node *p) const
    {
        if (p == NIL)
            return 0;

        return 1 + max(RHeight(p->left), RHeight(p->right));
    }

    void Destroy(Node *p)
    {
        if (p == NIL)
            return;

        Destroy(p->left);
        Destroy(p->right);
        delete p;
    }

    Node *SearchRecursive(Node *p, int key) const
    {
        if (p == NIL || p->key == key)
            return p;

        if (key < p->key)
            return SearchRecursive(p->left, key);

        return SearchRecursive(p->right, key);
    }

public:
    // --------------------------------------------------------
    // CONSTRUCTOR / DESTRUCTOR
    // --------------------------------------------------------

    RedBlackTree()
    {
        NIL = new Node(0, BLACK);
        NIL->left = NIL;
        NIL->right = NIL;
        NIL->parent = NIL;

        root = NIL;
        nodeCount = 0;
    }

    ~RedBlackTree()
    {
        Destroy(root);
        delete NIL;
    }

    // Avoid accidental shallow copies of owning pointers.
    RedBlackTree(const RedBlackTree&) = delete;
    RedBlackTree& operator=(const RedBlackTree&) = delete;

    // --------------------------------------------------------
    // INSERT
    // Duplicate keys are ignored.
    // --------------------------------------------------------

    bool Insert(int key)
    {
        Node *parent = NIL;
        Node *current = root;

        // Standard BST search for insertion position
        while (current != NIL)
        {
            parent = current;

            if (key == current->key)
                return false;

            if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }

        Node *z = new Node(key, RED);
        z->left = NIL;
        z->right = NIL;
        z->parent = parent;

        if (parent == NIL)
            root = z;
        else if (key < parent->key)
            parent->left = z;
        else
            parent->right = z;

        ++nodeCount;

        InsertFixup(z);
        return true;
    }

    // --------------------------------------------------------
    // DELETE
    // Returns false if key does not exist.
    // --------------------------------------------------------

    bool Delete(int key)
    {
        Node *z = SearchRecursive(root, key);

        if (z == NIL)
            return false;

        Node *y = z;
        Node *x;
        Color originalColor = y->color;

        if (z->left == NIL)
        {
            x = z->right;
            Transplant(z, z->right);
        }
        else if (z->right == NIL)
        {
            x = z->left;
            Transplant(z, z->left);
        }
        else
        {
            // Replace with in-order successor
            y = MinimumNode(z->right);
            originalColor = y->color;
            x = y->right;

            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                Transplant(y, y->right);

                y->right = z->right;
                y->right->parent = y;
            }

            Transplant(z, y);

            y->left = z->left;
            y->left->parent = y;

            y->color = z->color;
        }

        delete z;
        --nodeCount;

        if (originalColor == BLACK)
            DeleteFixup(x);

        // Maintain a canonical sentinel/root state
        root->color = BLACK;
        NIL->color = BLACK;

        return true;
    }

    // --------------------------------------------------------
    // SEARCH
    // --------------------------------------------------------

    bool Search(int key) const
    {
        return SearchRecursive(root, key) != NIL;
    }

    bool SearchIterative(int key) const
    {
        Node *p = root;

        while (p != NIL)
        {
            if (key == p->key)
                return true;

            if (key < p->key)
                p = p->left;
            else
                p = p->right;
        }

        return false;
    }

    // --------------------------------------------------------
    // MINIMUM / MAXIMUM
    // --------------------------------------------------------

    bool Minimum(int &result) const
    {
        if (root == NIL)
            return false;

        result = MinimumNode(root)->key;
        return true;
    }

    bool Maximum(int &result) const
    {
        if (root == NIL)
            return false;

        result = MaximumNode(root)->key;
        return true;
    }

    // --------------------------------------------------------
    // RECURSIVE TRAVERSALS
    // --------------------------------------------------------

    void InorderRecursive() const
    {
        RInorder(root);
        cout << '\n';
    }

    void PreorderRecursive() const
    {
        RPreorder(root);
        cout << '\n';
    }

    void PostorderRecursive() const
    {
        RPostorder(root);
        cout << '\n';
    }

    // --------------------------------------------------------
    // ITERATIVE INORDER
    // --------------------------------------------------------

    void InorderIterative() const
    {
        stack<Node*> st;
        Node *p = root;

        while (p != NIL || !st.empty())
        {
            while (p != NIL)
            {
                st.push(p);
                p = p->left;
            }

            p = st.top();
            st.pop();

            cout << p->key << " ";
            p = p->right;
        }

        cout << '\n';
    }

    // --------------------------------------------------------
    // ITERATIVE PREORDER
    // --------------------------------------------------------

    void PreorderIterative() const
    {
        if (root == NIL)
        {
            cout << '\n';
            return;
        }

        stack<Node*> st;
        st.push(root);

        while (!st.empty())
        {
            Node *p = st.top();
            st.pop();

            cout << p->key << " ";

            if (p->right != NIL)
                st.push(p->right);

            if (p->left != NIL)
                st.push(p->left);
        }

        cout << '\n';
    }

    // --------------------------------------------------------
    // ITERATIVE POSTORDER (ONE STACK)
    // --------------------------------------------------------

    void PostorderIterative() const
    {
        stack<Node*> st;
        Node *current = root;
        Node *lastVisited = NIL;

        while (current != NIL || !st.empty())
        {
            if (current != NIL)
            {
                st.push(current);
                current = current->left;
            }
            else
            {
                Node *peekNode = st.top();

                if (peekNode->right != NIL &&
                    lastVisited != peekNode->right)
                {
                    current = peekNode->right;
                }
                else
                {
                    cout << peekNode->key << " ";
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }

        cout << '\n';
    }

    // --------------------------------------------------------
    // LEVEL-ORDER TRAVERSAL
    // --------------------------------------------------------

    void LevelOrder() const
    {
        if (root == NIL)
        {
            cout << "(empty tree)\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = static_cast<int>(q.size());

            while (levelSize--)
            {
                Node *p = q.front();
                q.pop();

                cout << p->key
                     << (p->color == RED ? "(R) " : "(B) ");

                if (p->left != NIL)
                    q.push(p->left);

                if (p->right != NIL)
                    q.push(p->right);
            }

            cout << '\n';
        }
    }

    // --------------------------------------------------------
    // HEIGHT AND SIZE
    // Height is measured in nodes; empty tree height is 0.
    // --------------------------------------------------------

    int Height() const
    {
        return RHeight(root);
    }

    int Size() const
    {
        return nodeCount;
    }

    bool Empty() const
    {
        return root == NIL;
    }
};

// MAIN
int main()
{
    RedBlackTree tree;

    int values[] = {30, 20, 10, 15, 25, 40, 50, 45, 60};

    for (int value : values)
        tree.Insert(value);

    cout << "Level order (key and color):\n";
    tree.LevelOrder();

    cout << "\nRecursive inorder: ";
    tree.InorderRecursive();

    cout << "Iterative inorder: ";
    tree.InorderIterative();

    cout << "Recursive preorder: ";
    tree.PreorderRecursive();

    cout << "Iterative preorder: ";
    tree.PreorderIterative();

    cout << "Recursive postorder: ";
    tree.PostorderRecursive();

    cout << "Iterative postorder: ";
    tree.PostorderIterative();

    cout << "\nSearch 25: "
         << (tree.Search(25) ? "Found" : "Not found")
         << '\n';

    cout << "Iterative search 100: "
         << (tree.SearchIterative(100) ? "Found" : "Not found")
         << '\n';

    int value;

    if (tree.Minimum(value))
        cout << "Minimum: " << value << '\n';

    if (tree.Maximum(value))
        cout << "Maximum: " << value << '\n';

    cout << "Height (in nodes): " << tree.Height() << '\n';
    cout << "Number of nodes: " << tree.Size() << '\n';

    cout << "\nDeleting 20...\n";
    if (!tree.Delete(20))
        cout << "20 was not found.\n";

    tree.LevelOrder();

    cout << "\nDeleting 30...\n";
    if (!tree.Delete(30))
        cout << "30 was not found.\n";

    tree.LevelOrder();

    cout << "\nDeleting 10...\n";
    if (!tree.Delete(10))
        cout << "10 was not found.\n";

    tree.LevelOrder();

    cout << "\nFinal inorder: ";
    tree.InorderRecursive();

    cout << "Final size: " << tree.Size() << '\n';

    return 0;
}

