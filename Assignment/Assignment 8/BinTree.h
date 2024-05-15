//
// Created by Christopher Buhendwa on 5/8/24.
//

#ifndef ASSIGNMENT_BINTREE_H
#define ASSIGNMENT_BINTREE_H

using namespace std;

struct node_data{
    int key;
    string name;
};

typedef struct node {
    node_data data;
    struct node *left_child, *right_child;
} tree_node;


class BinTree{
private:
    tree_node* root;
public:
    BinTree();
    ~BinTree();
    bool IsEmpty();
    void MakeBT(BinTree *b1, int item, BinTree *b2);
    tree_node* Lchild(tree_node *bt){return bt->left_child;};
    tree_node* Rchild(tree_node *bt){return bt->right_child;};
    void insert_node_left(node_data data);
    void insert_node_right(node_data data);
    tree_node* search(int key);
    tree_node* search_to_delete(int key);
    void insert_node(node_data data);
    void delete_tree(tree_node* tree);
    void delete_node(tree_node* ptr);
    void inorder(tree_node* ptr);
    void Print();
    bool equal(tree_node *first, tree_node *second);
    bool equal(BinTree* second);
    tree_node* copy(tree_node* original);
    void copy(BinTree* source);
};


#endif //ASSIGNMENT_BINTREE_H
