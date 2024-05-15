//
// Created by Christopher Buhendwa on 5/8/24.
//

#include <iostream>
#include "BinTree.h"

using namespace std;

BinTree::BinTree(){
    root = nullptr;
}

BinTree::~BinTree(){
    delete_tree(root);
    cout << "Tree deleted" << endl;
    root = nullptr;
}

void BinTree::delete_tree(tree_node* tree){
    if (tree) {
        delete_tree(tree->left_child);
        delete_tree(tree->right_child);
        delete(tree);
    }
}

bool BinTree::IsEmpty(){
    return (root == nullptr);
}

void BinTree::insert_node_left(node_data data){
    tree_node *ptr = new tree_node;
    ptr->data.key = data.key;
    ptr->data.name = data.name;
    ptr->left_child = ptr->right_child = nullptr;
    if(IsEmpty()) root = ptr;
    else{
        tree_node *cur = root;
        for(;cur->left_child;cur=cur->left_child);
        cur->left_child = ptr;
    }
}

void BinTree::insert_node_right(node_data data){
    tree_node *ptr = new tree_node;
    ptr->data.key = data.key;
    ptr->data.name = data.name;
    ptr->left_child = ptr->right_child = nullptr;
    if(IsEmpty()) root = ptr;
    else{
        tree_node *cur = root;
        for(;cur->right_child;cur=cur->right_child);
        cur->right_child = ptr;
    }
}

tree_node* BinTree::search(const string& key) {
    tree_node *tree = root;
    while(tree){
        if(key == tree->data.key){
            return nullptr; // key is present
        }
        else if(key.compare(tree->data.key) < 0){
            if(tree->left_child == nullptr){
                return tree;
            }
            else {
                tree = tree->left_child;
            }
        }else if(tree->right_child == nullptr){
            return tree;
        }else{
            tree = tree->right_child;
        }
    }
    return nullptr;
}

tree_node* BinTree::searchToReplace(const std::string &key) {
    tree_node *tree = root;
    while(tree){
        if(key == tree->data.key){
            return tree; // key is present
        }
        else if(key.compare(tree->data.key) < 0){
            if(tree->left_child == nullptr){
                return nullptr;
            }
            else {
                tree = tree->left_child;
            }
        }else if(tree->right_child == nullptr){
            return nullptr;
        }else{
            tree = tree->right_child;
        }
    }
    return tree;
}


void BinTree::insert_node(const node_data& data) {
    tree_node *ptr = nullptr, *parent = nullptr;
    parent = search(data.key);
    if(parent || IsEmpty()) { // if num is not in the tree
        ptr = new tree_node;
        if(ptr == nullptr) {
            cerr << "The memory is full" << endl;
            exit(1);
        }
        ptr->data.key = data.key;
        ptr->data.name = data.name;
        ptr->left_child = ptr->right_child = nullptr;
        if(IsEmpty())
            root = ptr;
        else { // The tree is not empty
            if(data.key < parent->data.key) parent->left_child = ptr;
            else parent->right_child = ptr;
        }
    }else{
        cout << data.key << " is already in the tree" << endl;
    }
}

void BinTree::inorder(tree_node* ptr){
    if (ptr) {
        inorder(ptr->left_child);
        cout << "(" << ptr->data.key << " " << ptr->data.name << ")";
        inorder(ptr->right_child);
    }
}
void BinTree::Print(){
    inorder(root);
    cout << endl;
}

void BinTree::delete_node(tree_node *ptr) {
    if (ptr == nullptr) {
        // Node not found
        return;
    }

    // Case 1: Node has no children
    if (ptr->left_child == nullptr && ptr->right_child == nullptr) {
        if (ptr == root) {
            delete ptr;
            root = nullptr;
        } else {
            tree_node *parent = nullptr;
            parent = root;
            while (parent->left_child != ptr && parent->right_child != ptr) {
                if (ptr->data.key < parent->data.key) {
                    parent = parent->left_child;
                } else {
                    parent = parent->right_child;
                }
            }

            if (parent->left_child == ptr) {
                parent->left_child = nullptr;
            } else {
                parent->right_child = nullptr;
            }

            delete ptr;
        }
    }
        // Case 2: Node has one child
    else if (ptr->left_child == nullptr || ptr->right_child == nullptr) {
        tree_node *child = (ptr->left_child != nullptr) ? ptr->left_child : ptr->right_child;

        if (ptr == root) {
            root = child;
        } else {
            tree_node *parent = nullptr;
            parent = root;
            while (parent->left_child != ptr && parent->right_child != ptr) {
                if (ptr->data.key < parent->data.key) {
                    parent = parent->left_child;
                } else {
                    parent = parent->right_child;
                }
            }

            if (parent->left_child == ptr) {
                parent->left_child = child;
            } else {
                parent->right_child = child;
            }
        }

        delete ptr;
    }
        // Case 3: Node has two children
    else {
        tree_node *successor = ptr->right_child;
        while (successor->left_child != nullptr) {
            successor = successor->left_child;
        }

        ptr->data = successor->data;

        delete_node(successor);
    }
}
