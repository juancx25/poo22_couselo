#ifndef BT_NODE_H_INCLUDED
#define BT_NODE_H_INCLUDED

template <class T=int> class bt_node{

    private:
        T value;
        bt_node* left;
        bt_node* right;

    public:
        /* Constructores */
        bt_node();
        bt_node(T val);

        /* Destructores */
        //~bt_node();

        /* Getters */
        T getValue();
        bt_node* getLeft();
        bt_node* getRight();

        /* Setters */
        void setValue(T val);
        void setLeft(bt_node* n);
        void setRight(bt_node* n);

        /*  */
        bool isLeaf();

};

/* Constructores */
template <class T> bt_node<T>::bt_node(){

    T* aux = new T();
    value = *aux;

    left = NULL;
    right = NULL;
}

template <class T> bt_node<T>::bt_node(T val){

    value = val;

    left = NULL;
    right = NULL;
}

/* Getters */

template <class T> T bt_node<T>::getValue(){ return value; }

template <class T> bt_node<T>* bt_node<T>::getLeft(){ return left; }

template <class T> bt_node<T>* bt_node<T>::getRight(){ return right; }


/* Setters */

template <class T> void bt_node<T>::setValue(T val){ value = val; }

template <class T> void bt_node<T>::setLeft(bt_node<T>* n){ left = n; }

template <class T> void bt_node<T>::setRight(bt_node<T>* n){ right = n; }



template <class T> bool bt_node<T>::isLeaf(){
    bool result = false;
    if ((!left) && (!right)) result = true;
    return result;
}


#endif // BT_NODE_H_INCLUDED
