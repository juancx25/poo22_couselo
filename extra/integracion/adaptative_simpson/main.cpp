#include <iostream>
#include "../../templates/btree/btree.h"
#include <cmath>

using namespace std;
void btree_leafSum(bt_node<float>* node,float* value){
    if (!node) return;
    btree_leafSum(node->getLeft(),value);
    if (node->isLeaf()) *value += node->getValue();
    btree_leafSum(node->getRight(),value);
}

float f(float x) { return sin(x); }

int is_smaller_than_tolerance(float Sab, float Sac, float Scb, float err){
    int result = 0;
    if ((abs(Sac+Scb-Sab)/15) < err) result = 1;
    return result;
}

float simpson_simple(float f(float),float a,float b){
    return ((b-a)/6)*(f(a)+f(b)+4*f((a+b)/2));
}

void simpson_adap_util(float f(float),float a,float b, float err, bt_node<float>* root){
    float c = (b+a)/2;
    root->getLeft()->setValue(simpson_simple(f,a,c));
    root->getRight()->setValue(simpson_simple(f,a,c));
    //btn_insert_value(&(root->left),simpson_simple(f,a,c));
    //btn_insert_value(&(root->right),simpson_simple(f,c,b));
    if (is_smaller_than_tolerance(root->getValue(),root->getRight()->getValue(),root->getLeft()->getValue(),err) != 1){
        simpson_adap_util(f,a,c,err,root->getRight());
        simpson_adap_util(f,c,b,err,root->getLeft());
    }
    return;
}

float simpson_adaptative(float f(float),float a,float b, float err){
    float ans = 0;
    //bt_node<float>* root = btn_new(simpson_simple(f,a,b));
    bt_node<float>* root = new bt_node(simpson_simple(f,a,b));
    simpson_adap_util(f,a,b,err,root);
    btree_leafSum(root,&ans);
    //delete root;
    return ans;
}


int main()
{
    float ans = simpson_adaptative(f,0,1,1e-5);
    printf("La integral de la función es: %f\n",ans);
    return 0;
}
