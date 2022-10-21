#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <cstddef>
#include <iostream>
#include "bt_node.h"

template <class T> class btree;
template <class T> std::ostream& operator << (std::ostream&, btree<T>&);

template <class T=int> class btree{
    private:
        bt_node<T>* root;

        void print_preorder(bt_node<T>* root);
        unsigned int __getCount(bt_node<T>* root);
        void __insert(bt_node<T>** root,bt_node<T>* newNode);
    public:
        /* Constructores */
        btree();
        btree(bt_node<T>* root);
        btree(T val);

        /* Getters */
        bt_node<T>* getRoot();
        //bt_node<T>* find(T val);
        unsigned int getCount();

        /* Setters */
        void setRoot(bt_node<T>* node);
        void insert(bt_node<T>* newNode);

        /* Traverse */


        /* I/O */
        friend std::ostream& operator<< <> (std::ostream & os, btree<T>& bt);

};

/* Constructores */
template <class T> btree<T>::btree(){
    root = NULL;

}
template <class T> btree<T>::btree(bt_node<T>* node){
    root = node;
}
template <class T> btree<T>::btree(T val){
    root = new bt_node<T>(val);
}

/* Getters */
template <class T> bt_node<T>* btree<T>::getRoot(){ return root; }


//----------------------------------------------------------------------------

template <class T> unsigned int btree<T>::__getCount(bt_node<T>* root){
    unsigned int result = 0;
    if (root){
        result = 1 + __getCount(root->getLeft()) + __getCount(root->getRight());
    }
    return result;
}

template <class T> unsigned int btree<T>::getCount(){
    return __getCount(root);
}
//----------------------------------------------------------------------------


/* Setters */
template <class T> void btree<T>::setRoot(bt_node<T>* node){ root = node; }

//----------------------------------------------------------------------------

template <class T> void btree<T>::__insert(bt_node<T>** root,bt_node<T>* newNode){

    if (!root) return;
    if (!(*root)){
        *(root) = newNode;
    }
    else{
        if ()
    }
}

template <class T> void btree<T>::insert(bt_node<T>* newNode){

    if (!newNode) return;

    __insert(&root,newNode);

    return;

}

//----------------------------------------------------------------------------

/* I/O */
template <class T> void btree<T>::print_preorder(bt_node<T>* root){
    if (root){
        std::cout << (root->getValue());
        std::cout << (root->getLeft());
        std::cout << (root->getRight());
    }
    return;
}

template <class T> std::ostream& operator << (std::ostream & os, btree<T>& bt){

    bt.print_preorder(bt.root);

    return os;
}

#endif // BTREE_H_INCLUDED
