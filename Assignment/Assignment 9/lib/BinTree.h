//
// Created by Christopher Buhendwa on 5/8/24.
//

#ifndef ASSIGNMENT_BINTREE_H
#define ASSIGNMENT_BINTREE_H

using namespace std;

struct node_data{
    string key;
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
    void insert_node_left(const node_data& data);
    void insert_node_right(const node_data& data);
    tree_node* search(const string& key);
    tree_node* searchToReplace(const string& key);
    void insert_node(const node_data& data);
    void delete_tree(tree_node* tree);
    void delete_node(tree_node* ptr);
    void inorder(tree_node* ptr);
    void Print();

};


#endif //ASSIGNMENT_BINTREE_H
