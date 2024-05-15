//
// Created by Christopher Buhendwa on 5/8/24.
//

#ifndef COURSE_PRACTICE_BINTREE_H
#define COURSE_PRACTICE_BINTREE_H

typedef struct node {
    int data;
    struct node *left_child, *right_child;
} tree_node;

class BinTree{
private:
    tree_node *root;
public:
    BinTree();
    ~BinTree();
    bool IsEmpty();
    void MakeBT(BinTree *b1, int item, BinTree *b2);
    tree_node* Lchild(tree_node *bt);
    tree_node* Rchild(tree_node *bt);
    void copy(BinTree *source);
    tree_node* copy(tree_node* node);
    void insert_node(int data);
    void delete_node(int data);
    bool equal(tree_node* first, tree_node* second);
    bool equal(BinTree* second);
    void Print();
    // added fuction
    void BinTree::postorder (tree_node *ptr);
    void BinTree::preorder (tree_node *ptr);
    void BinTree::inorder (tree_node *ptr);
    void BinTree::iter_inorder(tree_node *ptr);
    void BinTree::level_order(tree_node *ptr)

// etc
};

#endif //COURSE_PRACTICE_BINTREE_H
