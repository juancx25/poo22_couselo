#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <cstddef>
#include <iostream>
#include "bt_node.h"
using namespace std;

template <class T> class btree;
template <class T> ostream& operator << (ostream&, btree<T>&);

template <class T=int> class btree{
    private:
        bt_node<T>* root;

        ostream& print_preorder(ostream& os, bt_node<T>* root);
    public:
        /* Constructores */
        btree();
        btree(bt_node<T>* root);
        btree(T val);

        /* Getters */
        bt_node<T>* getRoot();
        //bt_node<T>* find(T val);

        /* Setters */
        void setRoot(bt_node<T>* node);
        void insert();

        /* Traverse */


        /* I/O */
        friend ostream& operator<< <> (ostream & os, btree<T>& bt);

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

/* Setters */
template <class T> void btree<T>::setRoot(bt_node<T>* node){ root = node; }

/* I/O */
template <class T> ostream& btree<T>::print_preorder(ostream& os, bt_node<T>* root){
    if (root){
        os << root->getValue();
        os << print_preorder(os,root->getLeft());
        os << print_preorder(os,root->getRight());
    }
    return os;
}

template <class T> ostream& operator << (ostream & os, btree<T>& bt){
    os << bt.print_preorder(os,bt.getRoot());
    return os;
}

#endif // BTREE_H_INCLUDED
