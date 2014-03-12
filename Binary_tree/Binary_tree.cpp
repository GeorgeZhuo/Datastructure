// 2013.12.21
// zhuozhaojin 

/* the compement of a Binary tree */

#include "Binary_tree.h"
#include <stdio.h>

template <class Entry>
Binary_node<Entry>::Binary_node() {
    left = NULL;
    right = NULL;
}

template <class Entry>
Binary_node<Entry>::Binary_node(Entry x) {
    data = x;
    left = NULL;
    right = NULL;
}

template <class Entry>
Binary_tree<Entry>::Binary_tree() {
/* creat a empty tree */
    root = NULL;
}

template <class Entry>
Binary_tree<Entry>::~Binary_tree() {
}

template <class Entry> 
bool Binary_tree<Entry>::empty() const {

    return root == NULL;
}

template <class Entry> 
void Binary_tree<Entry>::preorder(void (*visit)(Entry &x)) {
    recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry &x)) {
    recursive_inorder(root, visit);

}


template <class Entry>
void Binary_tree<Entry>::posorder(void (*visit)(Entry &x)) {
    recursive_posorder(root, visit);

}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &x)) {

    if (sub_root != NULL) {
	(*visit)(sub_root->data);
	recursive_preorder(sub_root->left, visit);
	recursive_preorder(sub_root->right, visit);
    }
}


template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &x)) {

    if (sub_root != NULL) {

	recursive_inorder(sub_root->left, visit);
	(*visit)(sub_root->data);
	recursive_inorder(sub_root->right, visit);
    }
}


template <class Entry>
void Binary_tree<Entry>::recursive_posorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &x)) {
    if (sub_root != NULL) {

	recursive_posorder(sub_root->left, visit);
	recursive_posorder(sub_root->right, visit);
	(*visit)(sub_root->data);
    }
}

/*template <class Entry>
  void Binary_tree<Entry>::clear() {
  if ()

  }*/
template <class Entry>
void Binary_tree<Entry>::insert(Entry &x) {
    search_insert(x, root);
}
template <class Entry>
void Binary_tree<Entry>::search_insert(Entry &x, Binary_node<Entry> *&sub_root) {
    if (sub_root == NULL) {
	sub_root = new Binary_node<Entry>(x);
    }
    else if (x < sub_root->data)
	search_insert(x, sub_root->left);
    else if (x > sub_root->data)
	search_insert(x, sub_root->right);
    else
	;
}
