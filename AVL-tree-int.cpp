// AVL-tree-int.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
#include "AVLTree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Программа запущена!\n";
       
    AVLTree* tree= new AVLTree();
    
    cout << "Введите количество чисел для размещения в АВЛ-дереве" << endl;
    int n;
    int k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Число " << i+1 << " ";
        if (i==0) 
        {
            cin >> k;           
            tree->insert(k);
        }            
        else
        {
            do {
                cin >> k;
            } while (tree->find(k)!=0);
            tree->insert(k);
        }
    };
    
    cout << "АВЛ-дерево:\n";

    //tree->print();
    tree->fOtvet();

    //cout << tree->find(3) << endl;
    //cout << tree->find(15) << endl;
    //cout << "----\n";
    
    //tree->erase(4);
    //tree->print();    
   
    
    cout << "\nПрограмма завершена!\n";
    //return 0;
}