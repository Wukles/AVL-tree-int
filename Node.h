#pragma once

struct NODE
{
    int key;
    //int vbalance;
    unsigned char height;
    NODE* left;
    NODE* right;
    NODE(int k) : key(k), left(nullptr), right(nullptr), height(1){}
};