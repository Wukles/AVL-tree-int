#include <iostream>
#include <vector>
#include "AVLTree.h"

using namespace std;

unsigned char AVLTree::height(NODE* p)
{
    return p ? p->height : 0;
}

int AVLTree::bfactor(NODE* p)
{
    return height(p->right) - height(p->left);
}

void AVLTree::fixheight(NODE* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

NODE* AVLTree::rotateright(NODE* p)
{
    NODE* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

NODE* AVLTree::rotateleft(NODE* q)
{
    NODE* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

NODE* AVLTree::balance(NODE* p)
{
    
    fixheight(p);
    if (bfactor(p) == 2)
    {
        if (bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (bfactor(p) == -2)
    {
        if (bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

NODE* AVLTree::insert(NODE* p, int k)
{
    if (!p) {
        size++;                         
        return new NODE(k);
    }
    if (k < p->key)
        p->left = insert(p->left, k);
    else
        p->right = insert(p->right, k);

    return balance(p);
}

void AVLTree::erase(int k)
{

    NODE* p = root;
    NODE* parent = nullptr;
    while (p && p->key != k)
    {
        parent = p;
        if (p->key > k)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    if (!p)
        return;
    if (p->left == nullptr)
    {
        if (parent && parent->left == p)
            parent->left = p->right;
        if (parent && parent->right == p)
            parent->right = p->right;
        --size;
        delete p;
        fixheight(parent);
        return;
    }
    if (p->right == nullptr)
    {
        if (parent && parent->left == p)
            parent->left = p->left;
        if (parent && parent->right == p)
            parent->right = p->left;
        --size;
        delete p;
        fixheight(parent);
        return;
    }
    NODE* replace = p->right;
    while (replace->left)
        replace = replace->left;
    int replace_value = replace->key;
    erase(replace_value);
    p->key = replace_value;
}

void AVLTree::insert(int k)
{
    root = insert(root, k);
}

void AVLTree::print_dfs(NODE* p, int level)
{      
    if (p == nullptr)
        return;
    for (int i = 0; i < level; i++)
        cout << "    ";
    cout << p->key << endl;
    print_dfs(p->left, level + 1);
    print_dfs(p->right, level + 1);
}

void AVLTree::print()
{
    print_dfs(root, 0);
}

bool AVLTree::find(int k)
{
    NODE* p = root;
    while (p && p->key != k)
    {
        if (p->key > k)
            p = p->left;
        else
            p = p->right;
    }
    return p != nullptr;
}

void AVLTree::fOtvet()
{
    std::vector<NODE*> num;
        
    num.push_back(root);

    for (int i = 0; i < size; i++) {
        if (num[i]->left != nullptr) {
            num.push_back(num[i]->left);
        }
        if (num[i]->right != nullptr) {
            num.push_back(num[i]->right);
        }
    }

    for (auto NODE : num) {
        cout << NODE->key << " ";
    }
    cout << endl;
}