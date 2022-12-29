#pragma once
class clTree abstract
{
public:
    virtual void insert(int k)=0;
    virtual void print()=0;
    virtual bool find(int k)=0;
    virtual void erase(int k)=0;
};