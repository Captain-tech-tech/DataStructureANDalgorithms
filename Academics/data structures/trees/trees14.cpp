// AVL trees 
// bf means balancing factor
// [BF(node)=height(left)-height(right)]
// -1 <= BF(node) <= +1


#include <iostream>
#include <queue>

using namespace std;


// NODE
class Node
{
public:
    int data;

    Node *lchild;
    Node *rchild;

    int height;


    Node(int value)
    {
        data = value;

        lchild = nullptr;
        rchild = nullptr;

        height = 1;
    }
};


// AVL TREE CLASS
class AVLTree
{
private:

    Node *root;


    // GET HEIGHT
    int NodeHeight(Node *p)
    {
        if (p == nullptr)
            return 0;

        return p->height;
    }


    // GET BALANCE FACTOR
    // BF = height(left) - height(right)
    int BalanceFactor(Node *p)
    {
        if (p == nullptr)
            return 0;

        return NodeHeight(p->lchild)
             - NodeHeight(p->rchild);
    }


    // UPDATE HEIGHT
    void UpdateHeight(Node *p)
    {
        if (p == nullptr)
            return;

        int leftHeight = NodeHeight(p->lchild);
        int rightHeight = NodeHeight(p->rchild);

        p->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }


    // ========================================================
    // LL ROTATION
    //
    //        p
    //       /
    //      pl
    //     /
    //    X
    //
    // After:
    //
    //       pl
    //      /  \
    //     X    p
    //
    // ========================================================

    Node* LLRotation(Node *p)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;


        // Rotation
        pl->rchild = p;
        p->lchild = plr;


        // Update heights
        UpdateHeight(p);
        UpdateHeight(pl);


        return pl;
    }


    // ========================================================
    // RR ROTATION
    //
    //    p
    //     \
    //      pr
    //       \
    //        X
    //
    // After:
    //
    //       pr
    //      /  \
    //     p    X
    //
    // ========================================================

    Node* RRRotation(Node *p)
    {
        Node *pr = p->rchild;
        Node *prl = pr->lchild;


        // Rotation
        pr->lchild = p;
        p->rchild = prl;


        // Update heights
        UpdateHeight(p);
        UpdateHeight(pr);


        return pr;
    }


    // ========================================================
    // LR ROTATION
    //
    //       p
    //      /
    //     pl
    //       \
    //        plr
    //
    // First: RR rotation on pl
    // Second: LL rotation on p
    //
    // ========================================================

    Node* LRRotation(Node *p)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;


        // First rotation
        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;


        // Second rotation
        plr->lchild = pl;
        plr->rchild = p;


        // Update heights
        UpdateHeight(pl);
        UpdateHeight(p);
        UpdateHeight(plr);


        return plr;
    }


    // ========================================================
    // RL ROTATION
    //
    //     p
    //      \
    //       pr
    //      /
    //     prl
    //
    // First: LL rotation on pr
    // Second: RR rotation on p
    //
    // ========================================================

    Node* RLRotation(Node *p)
    {
        Node *pr = p->rchild;
        Node *prl = pr->lchild;


        // First rotation
        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;


        // Second rotation
        prl->rchild = pr;
        prl->lchild = p;


        // Update heights
        UpdateHeight(pr);
        UpdateHeight(p);
        UpdateHeight(prl);


        return prl;
    }


    // RECURSIVE INSERT
    Node* RInsert(Node *p, int key)
    {
        // Empty position
        if (p == nullptr)
        {
            return new Node(key);
        }


        // Insert into left subtree
        if (key < p->data)
        {
            p->lchild = RInsert(p->lchild, key);
        }

        // Insert into right subtree
        else if (key > p->data)
        {
            p->rchild = RInsert(p->rchild, key);
        }

        // Duplicate
        else
        {
            return p;
        }

        // Update height
        UpdateHeight(p);


        // Calculate balance factor
        int bf = BalanceFactor(p);


        // LEFT HEAVY
        if (bf == 2)
        {
            // LL CASE
            if (BalanceFactor(p->lchild) >= 0)
            {
                return LLRotation(p);
            }

            // LR CASE
            else
            {
                return LRRotation(p);
            }
        }

        // RIGHT HEAVY
        if (bf == -2)
        {
            // RR CASE
            if (BalanceFactor(p->rchild) <= 0)
            {
                return RRRotation(p);
            }

            // RL CASE
            else
            {
                return RLRotation(p);
            }
        }

        return p;
    }


    // INORDER PREDECESSOR
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


    // RECURSIVE DELETE
    Node* RDelete(Node *p, int key)
    {
        // Node not found
        if (p == nullptr)
            return nullptr;

        // Search left
        if (key < p->data)
        {
            p->lchild = RDelete(p->lchild, key);
        }
        // Search right
        else if (key > p->data)
        {
            p->rchild = RDelete(p->rchild, key);
        }
        // Node found
        else
        {
            // CASE 1:
            // No child
            if (p->lchild == nullptr &&
                p->rchild == nullptr)
            {
                delete p;
                return nullptr;
            }

            // CASE 2:
            // Only right child
            if (p->lchild == nullptr)
            {
                Node *temp = p->rchild;
                delete p;
                return temp;
            }

            // CASE 3:
            // Only left child
            if (p->rchild == nullptr)
            {
                Node *temp = p->lchild;
                delete p;
                return temp;
            }

            // CASE 4:
            // Two children
            Node *q = InPre(p->lchild);

            // Copy predecessor value
            p->data = q->data;

            // Delete predecessor
            p->lchild =
                RDelete(p->lchild, q->data);
        }

        // Update height after deletion
        UpdateHeight(p);

        // Calculate balance factor
        int bf = BalanceFactor(p);

        // LEFT HEAVY AFTER DELETION
        if (bf == 2)
        {
            int childBF = BalanceFactor(p->lchild);

            // L1 CASE
            // BF(p) = +2
            // BF(left child) = +1
            // LL rotation
            if (childBF == 1)
            {
                return LLRotation(p);
            }

            // L0 CASE
            // BF(p) = +2
            // BF(left child) = 0
            // LL rotation
            else if (childBF == 0)
            {
                return LLRotation(p);
            }

            // L-1 CASE
            // BF(p) = +2
            // BF(left child) = -1
            // LR rotation
            else if (childBF == -1)
            {
                return LRRotation(p);
            }
        }

        // RIGHT HEAVY AFTER DELETION
        if (bf == -2)
        {
            int childBF = BalanceFactor(p->rchild);

            // R-1 CASE
            // BF(p) = -2
            // BF(right child) = -1
            // RR rotation
            if (childBF == -1)
            {
                return RRRotation(p);
            }

            // R0 CASE
            // BF(p) = -2
            // BF(right child) = 0
            // RR rotation
            else if (childBF == 0)
            {
                return RRRotation(p);
            }

            // R1 CASE
            // BF(p) = -2
            // BF(right child) = +1
            // RL rotation
            else if (childBF == 1)
            {
                return RLRotation(p);
            }
        }

        return p;
    }


    // ========================================================
    // RECURSIVE SEARCH
    // ========================================================

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


    // ========================================================
    // RECURSIVE INORDER
    // ========================================================

    void RInorder(Node *p)
    {
        if (p == nullptr)
            return;

        RInorder(p->lchild);

        cout << p->data << " ";

        RInorder(p->rchild);
    }


    // ========================================================
    // RECURSIVE PREORDER
    // ========================================================

    void RPreorder(Node *p)
    {
        if (p == nullptr)
            return;

        cout << p->data << " ";

        RPreorder(p->lchild);

        RPreorder(p->rchild);
    }


    // ========================================================
    // RECURSIVE POSTORDER
    // ========================================================

    void RPostorder(Node *p)
    {
        if (p == nullptr)
            return;

        RPostorder(p->lchild);

        RPostorder(p->rchild);

        cout << p->data << " ";
    }


    // ========================================================
    // DELETE ENTIRE TREE
    // ========================================================

    void DeleteTree(Node *p)
    {
        if (p == nullptr)
            return;

        DeleteTree(p->lchild);
        DeleteTree(p->rchild);

        delete p;
    }


public:

    // ========================================================
    // CONSTRUCTOR
    // ========================================================

    AVLTree()
    {
        root = nullptr;
    }


    // ========================================================
    // GET ROOT
    // ========================================================

    Node* getRoot()
    {
        return root;
    }


    // ========================================================
    // INSERT
    // ========================================================

    void Insert(int key)
    {
        root = RInsert(root, key);
    }


    // ========================================================
    // DELETE
    // ========================================================

    void Delete(int key)
    {
        root = RDelete(root, key);
    }


    // ========================================================
    // SEARCH
    // ========================================================

    bool Search(int key)
    {
        return RSearch(root, key) != nullptr;
    }


    // ========================================================
    // INORDER
    // ========================================================

    void Inorder()
    {
        RInorder(root);
    }


    // ========================================================
    // PREORDER
    // ========================================================

    void Preorder()
    {
        RPreorder(root);
    }


    // ========================================================
    // POSTORDER
    // ========================================================

    void Postorder()
    {
        RPostorder(root);
    }


    // ========================================================
    // HEIGHT
    // ========================================================

    int Height()
    {
        return NodeHeight(root);
    }


    // ========================================================
    // DISPLAY BALANCE FACTOR
    // ========================================================

    void DisplayBalanceFactors(Node *p)
    {
        if (p == nullptr)
            return;

        DisplayBalanceFactors(p->lchild);

        cout << "Node " << p->data
             << "  Height = " << p->height
             << "  BF = " << BalanceFactor(p)
             << endl;

        DisplayBalanceFactors(p->rchild);
    }


    void DisplayBalanceFactors()
    {
        DisplayBalanceFactors(root);
    }


    // ========================================================
    // LEVEL ORDER
    // ========================================================

    void LevelOrder()
    {
        if (root == nullptr)
            return;

        queue<Node*> q;

        q.push(root);


        while (!q.empty())
        {
            int levelSize = q.size();


            while (levelSize > 0)
            {
                Node *p = q.front();
                q.pop();

                cout << p->data << " ";


                if (p->lchild != nullptr)
                    q.push(p->lchild);

                if (p->rchild != nullptr)
                    q.push(p->rchild);

                levelSize--;
            }

            cout << endl;
        }
    }


    // ========================================================
    // CREATE AVL TREE FROM ARRAY
    // ========================================================

    void Create(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            Insert(arr[i]);
        }
    }


    // ========================================================
    // DESTRUCTOR
    // ========================================================

    ~AVLTree()
    {
        DeleteTree(root);
    }
};


// ============================================================
// MAIN
// ============================================================

int main()
{
    AVLTree tree;


    // ========================================================
    // CREATE AVL TREE
    // ========================================================

    int values[] =
    {
        30,
        20,
        10,
        15,
        25,
        40,
        50,
        45
    };

    int n = sizeof(values) / sizeof(values[0]);


    tree.Create(values, n);


    // ========================================================
    // TRAVERSALS
    // ========================================================

    cout << "Preorder : ";
    tree.Preorder();
    cout << endl;


    cout << "Inorder  : ";
    tree.Inorder();
    cout << endl;


    cout << "Postorder: ";
    tree.Postorder();
    cout << endl;


    // ========================================================
    // LEVEL ORDER
    // ========================================================

    cout << "\nLevel Order:\n";
    tree.LevelOrder();


    // ========================================================
    // HEIGHT
    // ========================================================

    cout << "\nHeight = "
         << tree.Height()
         << endl;


    // ========================================================
    // BALANCE FACTORS
    // ========================================================

    cout << "\nBalance Factors:\n";

    tree.DisplayBalanceFactors();


    // ========================================================
    // SEARCH
    // ========================================================

    int key = 25;

    if (tree.Search(key))
        cout << "\n" << key << " found\n";
    else
        cout << "\n" << key << " not found\n";


    // ========================================================
    // DELETE
    // ========================================================

    cout << "\nBefore deletion:\n";

    cout << "Inorder: ";
    tree.Inorder();
    cout << endl;


    cout << "\nDeleting 20...\n";

    tree.Delete(20);


    cout << "After deletion:\n";

    cout << "Inorder: ";
    tree.Inorder();
    cout << endl;


    cout << "\nLevel Order after deletion:\n";
    tree.LevelOrder();


    cout << "\nBalance Factors after deletion:\n";
    tree.DisplayBalanceFactors();


    return 0;
}












