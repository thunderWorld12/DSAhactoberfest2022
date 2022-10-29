
//     Time Complexity: O(Q) 
//     Space Complexity: O(capacity)


here we have to main functiion to be perform to add key value pair using put(key,value) function

#include <map>

class Node
{
public:
    Node *left, *right;
    int key, val;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->left = this->right = NULL;
    }
};

class LRUCache
{
public:
    map<int, Node *> nodemap;
    Node *head, *tail;
    int capacity, size;

    // Initialize LRUCache
    LRUCache(int capacity)
    {
        head = tail = NULL;
        this->capacity = capacity;
        this->size = 0;
    }
    
    // Add node at rear of linked list,
    void addToRear(Node *nd)
    {
        if (head == NULL)
        {
            head = tail = nd;
            return;
        }

        tail->right = nd;
        nd->left = tail;

        tail = nd;

        return;
    }
    
    void deleteNode(Node *nd)
    {
        if (nd->left != NULL)
        {
            nd->left->right = nd->right;
        }
        else
        {
            head = nd->right;
        }

        if (nd->right != NULL)
        {
            nd->right->left = nd->left;
        }
        else
        {
            tail = nd->left;
        }

        nd->left = nd->right = NULL;
    }

    // Return the value of the given key
    int get(int key)
    {
        if (nodemap.find(key) == nodemap.end())
        {
            return -1;
        }

        deleteNode(nodemap[key]);
        addToRear(nodemap[key]);

        return nodemap[key]->val;
    }

    // Inserts a key and it's value into the LRUCache
    void put(int key, int value)
    {
        if (nodemap.find(key) != nodemap.end())
        {
            nodemap[key]->val = value;

            deleteNode(nodemap[key]);
            addToRear(nodemap[key]);
        }
        else
        {
            Node *nd = new Node(key, value);
            nodemap[key] = nd;

            if (size == capacity)
            {
                nodemap.erase(head->key);
                deleteNode(head);
                addToRear(nd);
            }
            else
            {
                size++;
                addToRear(nd);
            }
        }
    }
};
