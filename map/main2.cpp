#include "avl.hpp"
#include "pair.hpp"
#include <iostream>
#include <chrono>

using namespace std;
#define COUNT 10

template <class F>
void print2DUtil(F *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->r, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->val.first <<"\n";
    //cout<< root->parent << "\n";
    // Process left child
    print2DUtil(root->l, space);
}

// Wrapper over print2DUtil()
template<typename F>
void print2D(F *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

using namespace ft;

int main()
{
    Avl<int, int, less<int>, allocator<ft::pair<int,int>>>bla;
    int i = 0;
    while (i < 20)
    {
        bla.insert(&(bla.root), ft::pair<int, int>(i, i), NULL);
        i++;
    }
    std::cout << "nbr of nodes in tree: " << bla.nbrofnodes << "\n";
    i = 0;
    while (i < 10)
    {
        bla.root = bla.erase(bla.root, i);
        i++;
    }
    print2D(bla.root);
    std::cout << "nbr of nodes in tree: " << bla.nbrofnodes << "\n";
}
