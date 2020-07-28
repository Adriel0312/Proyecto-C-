#include <iostream>
class Node{
    public:
        int value,fe;
        Node *left, *right;

        Node(int value){
            this->value=value;
            this->fe=0;
            this->left=NULL;
            this->right=NULL;
        }
};
