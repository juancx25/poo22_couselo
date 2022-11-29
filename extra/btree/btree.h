#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <iostream>


template <class T> class bt_node {

    private:
        T data;
        bt_node* left;
        bt_node* right;

    public:
        /* ----- Constructors ----- */
        bt_node();
        bt_node(T data);

        /* ----- Destructors ----- */


        /* ----- Getters ----- */
        T getData();
        bt_node* getLeft();
        bt_node* getRight();


        /* ----- Setters ----- */
        void setData(T data);
        void setLeft(bt_node* left);
        void setRight(bt_node* right);

        /* ----- State check ----- */
        bool isLeaf();

};



/* ----- Constructors ----- */

template <class T> bt_node<T>::bt_node(){
    left = NULL;
    right = NULL;
}

template <class T> bt_node<T>::bt_node(T data){
    this->data = data;
    left = NULL;
    right = NULL;
}

/* ----- Getters ----- */
template <class T> T bt_node<T>::getData(){ return data; }
template <class T> bt_node<T>* bt_node<T>::getLeft(){ return left; }
template <class T> bt_node<T>* bt_node<T>::getRight(){ return right; }

/* ----- Setters ----- */
template <class T> void bt_node<T>::setData(T data){ this->data = data; }
template <class T> void bt_node<T>::setLeft(bt_node* left){ this->left = left; }
template <class T> void bt_node<T>::setRight(bt_node* right){ this->right = right; }

/* ----- State check ----- */
template <class T> bool bt_node<T>::isLeaf(){ return (!left && !right); }

/* ----- Traverse ----- */


#endif // BTREE_H_INCLUDED
