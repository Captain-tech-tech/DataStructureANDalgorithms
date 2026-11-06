// 2-3 trees : multiway search tree with degree 3


// 2-3 trees are search trees like binary search trees. Binary tree has one key and two children



#include <iostream>
#include <queue>

using namespace std;


// ============================================================
// 2-3 TREE NODE
// ============================================================

class Node23
{
public:

    // A node can temporarily contain 3 keys
    // during insertion before splitting.
    // the arrays are intentionally sized larger (keys[3] and child[4]) to implement a design pattern called temporary overflow 
    // insertion.
    int keys[3];
    
    int keyCount;

    Node23 *child[4];

    int childCount;


    Node23()
    {
        keyCount = 0;
        childCount = 0;

        for (int i = 0; i < 4; i++)
            child[i] = nullptr;
    }


    bool isLeaf()   
    {
        return childCount == 0;
    }
};


// ============================================================
// 2-3 TREE
// ============================================================

class Tree23
{
private:

    Node23 *root;


    // ========================================================
    // INSERT KEY INTO NODE IN SORTED ORDER
    // ========================================================

    void InsertKey(Node23 *p, int key)
    {
        int i = p->keyCount - 1;


        while (i >= 0 && p->keys[i] > key)
        {
            p->keys[i + 1] = p->keys[i];
            i--;
        }

        p->keys[i + 1] = key;

        p->keyCount++;
    }


    // ========================================================
    // SPLIT A NODE
    //
    // Before:
    //
    // [10 | 20 | 30]
    //
    // Promote 20
    //
    // Left  = [10]
    // Right = [30]
    // ========================================================

    void SplitNode(Node23 *p, int &promotedKey, Node23 *&leftNode, Node23 *&rightNode)
    {
        promotedKey = p->keys[1];

        leftNode = new Node23();
        rightNode = new Node23();

        // Left key
        leftNode->keys[0] = p->keys[0];
        leftNode->keyCount = 1;

        // Right key
        rightNode->keys[0] = p->keys[2];
        rightNode->keyCount = 1;

        // ----------------------------------------------------
        // If p is internal, distribute children
        // ----------------------------------------------------

        if (!p->isLeaf())
        {
            leftNode->child[0] = p->child[0];
            leftNode->child[1] = p->child[1];
            leftNode->childCount = 2;

            rightNode->child[0] = p->child[2];
            rightNode->child[1] = p->child[3];
            rightNode->childCount = 2;
        }

        delete p;
    }

    // ========================================================
    // RECURSIVE INSERT
    //
    // Returns:
    //
    // nullptr
    //     → no split occurred
    //
    // Node23*
    //     → right node created by split
    //
    // promotedKey contains key going upward
    // ========================================================

    Node23* InsertRecursive(Node23 *p, int key, int &promotedKey, Node23 *&promotedRight)
    {
        // ----------------------------------------------------
        // LEAF
        // ----------------------------------------------------
        if (p->isLeaf())
        {
            InsertKey(p, key);

            // No overflow
            if (p->keyCount <= 2)
            {
                promotedRight = nullptr;

                return p;
            }

            // Overflow
            Node23 *leftNode;
            Node23 *rightNode;

            SplitNode(p, promotedKey, leftNode, rightNode);

            promotedRight = rightNode;

            return leftNode;
        }

        // ----------------------------------------------------
        // Find child
        // ----------------------------------------------------

        int i = 0;

        while (i < p->keyCount && key > p->keys[i])
        {
            i++;
        }


        // ----------------------------------------------------
        // Insert recursively
        // ----------------------------------------------------

        int childPromotedKey;

        Node23 *childPromotedRight = nullptr;


        Node23 *newLeft = InsertRecursive(p->child[i], key, childPromotedKey, childPromotedRight);


        // ----------------------------------------------------
        // Child did not split
        // ----------------------------------------------------

        if (childPromotedRight == nullptr)
        {
            p->child[i] = newLeft;

            return p;
        }


        // ----------------------------------------------------
        // Child split
        //
        // Need to insert promoted key into current node
        // ----------------------------------------------------

        p->child[i] = newLeft;


        // Shift children right
        for (int j = p->childCount; j > i + 1; j--)
        {
            p->child[j] = p->child[j - 1];
        }


        p->child[i + 1] = childPromotedRight;


        // Insert promoted key
        int j = p->keyCount - 1;

        while (j >= i)
        {
            p->keys[j + 1] = p->keys[j];
            j--;
        }


        p->keys[i] = childPromotedKey;

        p->keyCount++;
        p->childCount++;


        // ----------------------------------------------------
        // Current node does not overflow
        // ----------------------------------------------------

        if (p->keyCount <= 2)
        {
            return p;
        }


        // ----------------------------------------------------
        // Current node also overflowed
        // ----------------------------------------------------

        Node23 *leftNode;
        Node23 *rightNode;

        SplitNode(p, promotedKey, leftNode, rightNode);

        promotedRight = rightNode;

        return leftNode;
    }


    // ========================================================
    // SEARCH
    // ========================================================

    Node23* SearchRecursive(Node23 *p, int key)
    {
        if (p == nullptr)
            return nullptr;


        int i = 0;


        while (i < p->keyCount && key > p->keys[i])
        {
            i++;
        }

        if (i < p->keyCount && key == p->keys[i])
        {
            return p;
        }

        if (p->isLeaf())
            return nullptr;

        return SearchRecursive(p->child[i], key);
    }


    // ========================================================
    // INORDER-STYLE SORTED DISPLAY
    // ========================================================

    void Inorder(Node23 *p)
    {
        if (p == nullptr)
            return;


        if (p->keyCount == 1)
        {
            Inorder(p->child[0]);

            cout << p->keys[0] << " ";

            Inorder(p->child[1]);
        }

        else if (p->keyCount == 2)
        {
            Inorder(p->child[0]);

            cout << p->keys[0] << " ";

            Inorder(p->child[1]);

            cout << p->keys[1] << " ";

            Inorder(p->child[2]);
        }
    }


    // ========================================================
    // LEVEL ORDER
    // ========================================================

    void LevelOrder(Node23 *p)
    {
        if (p == nullptr)
            return;


        queue<Node23*> q;

        q.push(p);


        while (!q.empty())
        {
            int size = q.size();


            while (size--)
            {
                Node23 *current = q.front();
                q.pop();


                cout << "[";

                for (int i = 0;
                     i < current->keyCount;
                     i++)
                {
                    cout << current->keys[i];

                    if (i + 1 < current->keyCount)
                        cout << " | ";
                }

                cout << "] ";


                for (int i = 0;
                     i < current->childCount;
                     i++)
                {
                    q.push(current->child[i]);
                }
            }

            cout << endl;
        }
    }


    // ========================================================
    // DELETE TREE
    // ========================================================

    void DeleteTree(Node23 *p)
    {
        if (p == nullptr)
            return;


        for (int i = 0; i < p->childCount;i++)
        {
            DeleteTree(p->child[i]);
        }


        delete p;
    }


public:

    Tree23()
    {
        root = nullptr;
    }


    // ========================================================
    // INSERT
    // ========================================================

    void Insert(int key)
    {
        // Empty tree
        if (root == nullptr)
        {
            root = new Node23();

            root->keys[0] = key;

            root->keyCount = 1;

            return;
        }


        int promotedKey;

        Node23 *promotedRight = nullptr;


        Node23 *newLeft = InsertRecursive(root,key,promotedKey,promotedRight);


        // ----------------------------------------------------
        // Root did not split
        // ----------------------------------------------------

        if (promotedRight == nullptr)
        {
            root = newLeft;

            return;
        }


        // ----------------------------------------------------
        // Root split
        // Create new root
        // ----------------------------------------------------

        Node23 *newRoot = new Node23();


        newRoot->keys[0] = promotedKey;

        newRoot->keyCount = 1;


        newRoot->child[0] = newLeft;

        newRoot->child[1] = promotedRight;

        newRoot->childCount = 2;


        root = newRoot;
    }


    // ========================================================
    // SEARCH
    // ========================================================

    bool Search(int key)
    {
        return SearchRecursive(root, key) != nullptr;
    }


    // ========================================================
    // INORDER
    // ========================================================

    void Inorder()
    {
        Inorder(root);
    }


    // ========================================================
    // LEVEL ORDER
    // ========================================================

    void LevelOrder()
    {
        LevelOrder(root);
    }


    // ========================================================
    // DESTRUCTOR
    // ========================================================

    ~Tree23()
    {
        DeleteTree(root);
    }
};


// ============================================================
// MAIN - 2-3 TREE
// ============================================================

int main()
{
    Tree23 tree;


    int values[] =
    {
        30,
        20,
        10,
        15,
        25,
        40,
        50,
        45,
        60,
        70,
        65
    };


    int n = sizeof(values) / sizeof(values[0]);


    for (int i = 0; i < n; i++)
    {
        tree.Insert(values[i]);
    }


    cout << "2-3 Tree Level Order:\n";

    tree.LevelOrder();


    cout << "\nSorted keys:\n";

    tree.Inorder();

    cout << endl;


    int key = 40;


    if (tree.Search(key))
        cout << "\n" << key << " found\n";
    else
        cout << "\n" << key << " not found\n";


    return 0;
}



// 2-3-4 tree implementation
#include <iostream>
#include <queue>

using namespace std;


// ============================================================
// 2-3-4 TREE NODE
// ============================================================

class Node234
{
public:

    // Maximum 3 keys
    int keys[3];

    int keyCount;


    // Maximum 4 children
    Node234 *child[4];

    int childCount;


    Node234()
    {
        keyCount = 0;
        childCount = 0;

        for (int i = 0; i < 4; i++)
            child[i] = nullptr;
    }


    bool isLeaf()
    {
        return childCount == 0;
    }


    bool isFull()
    {
        return keyCount == 3;
    }
};


// ============================================================
// 2-3-4 TREE
// ============================================================

class Tree234
{
private:

    Node234 *root;


    // ========================================================
    // SPLIT FULL CHILD
    //
    // Parent:
    //
    //       [40]
    //
    // Full child:
    //
    //       [10 | 20 | 30]
    //
    // After:
    //
    //       [20 | 40]
    //       /   |   \
    //    [10] [30] ...
    // ========================================================

    void SplitChild(Node234 *parent, int index)
    {
        Node234 *fullChild =
            parent->child[index];


        Node234 *left =
            new Node234();

        Node234 *right =
            new Node234();


        // ----------------------------------------------------
        // Middle key is promoted
        // ----------------------------------------------------

        int middleKey =
            fullChild->keys[1];


        // Left node gets first key
        left->keys[0] =
            fullChild->keys[0];

        left->keyCount = 1;


        // Right node gets last key
        right->keys[0] =
            fullChild->keys[2];

        right->keyCount = 1;


        // ----------------------------------------------------
        // If full child has children,
        // distribute them
        // ----------------------------------------------------

        if (!fullChild->isLeaf())
        {
            left->child[0] =
                fullChild->child[0];

            left->child[1] =
                fullChild->child[1];

            left->childCount = 2;


            right->child[0] =
                fullChild->child[2];

            right->child[1] =
                fullChild->child[3];

            right->childCount = 2;
        }


        // ----------------------------------------------------
        // Shift parent's children
        // ----------------------------------------------------

        for (int i = parent->childCount;
             i > index + 1;
             i--)
        {
            parent->child[i] =
                parent->child[i - 1];
        }


        parent->child[index] = left;

        parent->child[index + 1] = right;


        parent->childCount++;


        // ----------------------------------------------------
        // Shift parent's keys
        // ----------------------------------------------------

        for (int i = parent->keyCount;
             i > index;
             i--)
        {
            parent->keys[i] =
                parent->keys[i - 1];
        }


        parent->keys[index] =
            middleKey;

        parent->keyCount++;


        delete fullChild;
    }


    // ========================================================
    // INSERT INTO NON-FULL NODE
    // ========================================================

    void InsertNonFull(Node234 *p, int key)
    {
        int i = p->keyCount - 1;


        // ====================================================
        // CASE 1: LEAF
        // ====================================================

        if (p->isLeaf())
        {
            // Shift keys to the right
            while (i >= 0 &&
                   key < p->keys[i])
            {
                p->keys[i + 1] =
                    p->keys[i];

                i--;
            }


            // Duplicate
            if (i >= 0 &&
                p->keys[i] == key)
            {
                return;
            }


            p->keys[i + 1] = key;

            p->keyCount++;

            return;
        }


        // ====================================================
        // INTERNAL NODE
        // ====================================================

        while (i >= 0 &&
               key < p->keys[i])
        {
            i--;
        }


        // Duplicate
        if (i >= 0 &&
            key == p->keys[i])
        {
            return;
        }


        // Child index
        int childIndex = i + 1;


        // ----------------------------------------------------
        // If child is full, split it first
        // ----------------------------------------------------

        if (p->child[childIndex]->isFull())
        {
            SplitChild(p, childIndex);


            // After split, middle key is now in p.
            // Decide which side to enter.

            if (key == p->keys[childIndex])
                return;


            if (key > p->keys[childIndex])
                childIndex++;
        }


        InsertNonFull(
            p->child[childIndex],
            key);
    }


    // ========================================================
    // SEARCH
    // ========================================================

    Node234* SearchRecursive(
        Node234 *p,
        int key)
    {
        if (p == nullptr)
            return nullptr;


        int i = 0;


        while (i < p->keyCount &&
               key > p->keys[i])
        {
            i++;
        }


        if (i < p->keyCount &&
            key == p->keys[i])
        {
            return p;
        }


        if (p->isLeaf())
            return nullptr;


        return SearchRecursive(
            p->child[i],
            key);
    }


    // ========================================================
    // INORDER-STYLE SORTED DISPLAY
    // ========================================================

    void Inorder(Node234 *p)
    {
        if (p == nullptr)
            return;


        for (int i = 0; i < p->keyCount; i++)
        {
            if (!p->isLeaf())
                Inorder(p->child[i]);


            cout << p->keys[i] << " ";
        }


        if (!p->isLeaf())
        {
            Inorder(
                p->child[p->keyCount]);
        }
    }


    // ========================================================
    // LEVEL ORDER
    // ========================================================

    void LevelOrder(Node234 *p)
    {
        if (p == nullptr)
            return;


        queue<Node234*> q;

        q.push(p);


        while (!q.empty())
        {
            int levelSize = q.size();


            while (levelSize--)
            {
                Node234 *current =
                    q.front();

                q.pop();


                cout << "[";


                for (int i = 0;
                     i < current->keyCount;
                     i++)
                {
                    cout << current->keys[i];

                    if (i + 1 <
                        current->keyCount)
                    {
                        cout << " | ";
                    }
                }


                cout << "] ";


                for (int i = 0;
                     i < current->childCount;
                     i++)
                {
                    q.push(
                        current->child[i]);
                }
            }


            cout << endl;
        }
    }


    // ========================================================
    // DELETE ENTIRE TREE
    // ========================================================

    void DeleteTree(Node234 *p)
    {
        if (p == nullptr)
            return;


        for (int i = 0;
             i < p->childCount;
             i++)
        {
            DeleteTree(p->child[i]);
        }


        delete p;
    }


public:

    // ========================================================
    // CONSTRUCTOR
    // ========================================================

    Tree234()
    {
        root = nullptr;
    }


    // ========================================================
    // INSERT
    // ========================================================

    void Insert(int key)
    {
        // ----------------------------------------------------
        // Empty tree
        // ----------------------------------------------------

        if (root == nullptr)
        {
            root = new Node234();

            root->keys[0] = key;

            root->keyCount = 1;

            return;
        }


        // ----------------------------------------------------
        // Duplicate
        // ----------------------------------------------------

        if (Search(key))
            return;


        // ----------------------------------------------------
        // Root is full
        // ----------------------------------------------------

        if (root->isFull())
        {
            Node234 *newRoot =
                new Node234();


            newRoot->child[0] =
                root;

            newRoot->childCount = 1;


            // Split old root
            SplitChild(
                newRoot,
                0);


            root = newRoot;
        }


        // ----------------------------------------------------
        // Root is guaranteed non-full
        // ----------------------------------------------------

        InsertNonFull(
            root,
            key);
    }


    // ========================================================
    // SEARCH
    // ========================================================

    bool Search(int key)
    {
        return SearchRecursive(
            root,
            key) != nullptr;
    }


    // ========================================================
    // INORDER
    // ========================================================

    void Inorder()
    {
        Inorder(root);
    }


    // ========================================================
    // LEVEL ORDER
    // ========================================================

    void LevelOrder()
    {
        LevelOrder(root);
    }


    // ========================================================
    // DESTRUCTOR
    // ========================================================

    ~Tree234()
    {
        DeleteTree(root);
    }
};


// ============================================================
// MAIN - 2-3-4 TREE
// ============================================================

int main()
{
    Tree234 tree;


    int values[] =
    {
        30,
        20,
        10,
        15,
        25,
        40,
        50,
        45,
        60,
        70,
        65
    };


    int n =
        sizeof(values) /
        sizeof(values[0]);


    // ========================================================
    // INSERT
    // ========================================================

    for (int i = 0; i < n; i++)
    {
        tree.Insert(values[i]);
    }


    // ========================================================
    // LEVEL ORDER
    // ========================================================

    cout << "2-3-4 Tree Level Order:\n";

    tree.LevelOrder();


    // ========================================================
    // SORTED ORDER
    // ========================================================

    cout << "\nSorted keys:\n";

    tree.Inorder();

    cout << endl;


    // ========================================================
    // SEARCH
    // ========================================================

    int key = 40;


    if (tree.Search(key))
        cout << "\n" << key << " found\n";
    else
        cout << "\n" << key << " not found\n";


    return 0;
}
























