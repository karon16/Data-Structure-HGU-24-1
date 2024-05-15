//
// Created by Christopher Buhendwa on 5/8/24.
//

#include <iostream>
#include "BinTree.h"

using namespace std;
int main() {
    BinTree* tree1 = new BinTree();
    BinTree* tree2 = new BinTree();
    BinTree* tree3 = new BinTree();
    tree1->insert_node_left(3);
    tree1->insert_node_left(1);
    tree1->insert_node_right(5);
    tree1->Print();
    tree2->insert_node_right(3);
    tree2->insert_node_right(1);
    tree2->Print();
    if (tree1->equal(tree2)) cout << "Equal!" << endl;
    else cout << "Not equal" << endl;
    delete tree2;
    tree3->copy(tree1);
    tree3->Print();
    if (tree1->equal(tree3)) cout << "Equal" << endl;
    else cout << "Not equal" << endl;
}