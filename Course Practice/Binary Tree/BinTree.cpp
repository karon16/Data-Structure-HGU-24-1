//
// Created by Christopher Buhendwa on 5/8/24.
//

#include "BinTree.h"
#include "Queue.h"
#include "Stack.h"

void BinTree::iter_inorder(tree_node *ptr){
    Stack stack;
    for(;;) {
        for(; ptr; ptr = ptr->left_child)
            stack.Push(ptr); // add to stack
        ptr = stack.Pop(); // delete from stack
        if(!ptr) break; // empty stack
        cout << ptr->data;
        ptr = ptr->right_child ;
    }
}

void BinTree::level_order(tree_node *ptr)
{
    Queue queue;
    if(!ptr) return;
    queue.addq(ptr);
    for(;;) {
        ptr = queue.deleteq();
        if(!ptr) break;
        cout << ptr->data;
        if(ptr->left_child)
            queue.addq(ptr->left_child);
        if(ptr->right_child)
            queue.addq(ptr->right_child);
    }
}



void BinTree::inorder (tree_node *ptr){
    if (ptr) {
        inorder(ptr->left_child);
        cout << ptr->data;
        inorder(ptr->right_child);
    }
}

void BinTree::preorder (tree_node *ptr){
    if (ptr) {
        cout << ptr->data;
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}

void BinTree::postorder (tree_node *ptr)
{
    if (ptr) {
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        cout << ptr->data;
    }
}