/*Name : PRAGYAN BANERJEE
Roll. : 200123080
Write a program to implement Search, Insert and Deletion in 2-3 trees.*/
#include <iostream>
using namespace std;
class Node {
   public:
  Node *left;
  Node *right;
  Node *mid;
  Node *tmp;
  Node *p;
  int m;
  int height;
};
bool isroot(Node *t)
{
    if (t->p == NULL)
        return true;
    else
        return false;
}
bool isleaf(Node *t)
{
    if(t->left == NULL && t->mid == NULL && t->right == NULL)
        return true;
    else
        return false;
}
Node *sort4(Node *t)
{
    Node *a[4];
    a[0] = new Node();
    a[1] = new Node();
    a[2] = new Node();
    a[3] = new Node();
    a[0] = t->left;
    a[1] = t->mid;
    a[2] = t->right;
    a[3] = t->tmp;
    int j;
    Node *kk;
    for (int i = 1; i < 4; i++)
    {
        kk->m = a[i]->m;
        j = i - 1;
        while (j >= 0 && a[j]->m > kk->m)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = kk;
    }
    t->left = a[0];
    t->mid = a[1];
    t->right = a[2];
    t->tmp = a[3];
    return t;
}
Node *sort3(Node *t)
{
    Node *a[3];
    a[0] = new Node();
    a[1] = new Node();
    a[2] = new Node();
    a[0] = t->left;
    a[1] = t->mid;
    a[2] = t->right;
    int j;
    Node *kk;
    for (int i = 1; i < 3; i++)
    {
        kk->m = a[i]->m;
        j = i - 1;
        while (j >= 0 && a[j]->m > kk->m)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = kk;
    }
    t->left = a[0];
    t->mid = a[1];
    t->right = a[2];
    return t;
}
Node *sort2(Node *t)
{
    Node *a[2];
    a[0] = new Node();
    a[1] = new Node();
    a[0] = t->left;
    a[1] = t->mid;
    int j;
    Node *kk;
    for (int i = 1; i < 2; i++)
    {
        kk->m = a[i]->m;
        j = i - 1;
        while (j >= 0 && a[j]->m > kk->m)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = kk;
    }
    t->left = a[0];
    t->mid = a[1];
    return t;
}
Node *isfour(Node *t)
{
    Node *x;
    x = new Node();
    x->left = t->right;
    x->mid = t->tmp;
    t->right->p = x;
    t->tmp->p = x;
    t->right = NULL;
    t->tmp = NULL;
    Node *pp;
    x = new Node();
    pp = t->p;
    if(t->p == NULL)
    {
        t->p->left = t;
        t->p->mid = x;
    }
    else if (pp->mid == NULL)
    {
        t->p->mid = x;
        x->p = t->p;
        t->p = sort2(t->p);
    }
    else if (pp->right == NULL)
    {
        t->p->right = x;
        x->p = t->p;
        t->p = sort3(t->p);
    }
    else
    {
        x->p = t->p;
        t->p->tmp =x;
        t->p = sort4(t->p);
        isfour(t->p);
    }
    return t;
}
Node *insert(Node *t, Node *node, int key)
{
    cout << "inserting..." << endl;
    if(isroot(t))
    {
        Node *x;
        x = new Node();
        x->m = t->m;
        x->left = t->left;
        x->mid = t->mid;
        x->right = t->right;
        t->left = x;
        t->mid = node;
        x->p = t;
        node->p = t;
    }
    else if (isleaf(t->left) && isleaf(t->mid) && isleaf(t->right))
    {
        t->tmp = node;
        t->tmp->m = key;
        t = sort4(t);
        isfour(t);
    }
    else
    {
        if (key <= t->left->m)
        {
            insert(t->left, node, key);
        }
        else if (key > t->left->m && key <= t->mid->m)
        {
            insert(t->mid, node, key);
        }
        else
        {
            insert (t->right, node, key);
        }
    }
    return t;
}
void search (Node *t, int key)
{
    if (key == t->m)
    {
        cout << "FOUND " << key << endl;
        return;
    }
    else if(t == NULL)
    {
        cout << "NOT FOUND " << key << endl;
        return;
    }
    else
    {
        if (key <= t->left->m)
        {
            search(t->left, key);
        }
        else if (key > t->left->m && key <= t->mid->m)
        {
            search(t->mid, key);
        }
        else
        {
            search(t->right, key);
        }
    }
}
int main ()
{
    cout << "START" << endl;
    Node *root = NULL;
    root = new Node();
    Node *node1 = NULL;
    node1 = new Node();
    node1->m = 1;
    root = insert(root, node1, 1);
    cout << "INSERTED " << node1->m << endl;
    Node *node2 = NULL;
    node2 = new Node();
    node2->m = 2;
    root = insert(root, node2, 2);
    cout << "INSERTED " << node2->m << endl;
    Node *node3 = NULL;
    node3 = new Node();
    node3->m = 3;
    root = insert(root, node3, 3);
    cout << "INSERTED " << node3->m << endl;
    Node *node4 = NULL;
    node4 = new Node();
    node4->m = 4;
    root = insert(root, node4, 4);
    cout << "INSERTED " << node4->m << endl;
    Node *node5 = NULL;
    node5 = new Node();
    node5->m = 5;
    root = insert(root, node5, 5);
    cout << "INSERTED " << node5->m << endl;
    search (root, 0);
    cout << "DONE" << endl;
    return 0;
}