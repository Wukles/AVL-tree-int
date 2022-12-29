#pragma once
#include "Node.h"
#include "clTree.h"
class AVLTree : public clTree
{
private:
    unsigned char height(NODE* p);
    int bfactor(NODE* p);
    void fixheight(NODE* p);
    
    NODE* rotateright(NODE* p);
    NODE* rotateleft(NODE* q);

    NODE* balance(NODE* p);
    NODE* insert(NODE* p, int k);
    void print_dfs(NODE* p, int level);
public:
    int size = 0;
    AVLTree() : root(nullptr) {};
    void insert(int k) override;
    void print() override;
    bool find(int k) override;
    void erase(int k) override;
    void fOtvet();

private:
    NODE* root;
};