#include <iostream>
#include "nodeTree.h"
using namespace std;
class AVLTree{
    private:
        Node *Root;

    public:
        AVLTree(){
            Root=NULL;
        }

        Node* getRoot(){
        return Root;
        }

        int getFe(Node *data){// Obtener factor equilibrio
            if (data==NULL){
                return -1;
            }else {
                return data->fe;
            }
        }
        void preorden(Node *r){
            if (r!=NULL){
                cout<<r->value<<",";
                preorden(r->left);
                preorden(r->right);
            }
        }
        void insert(int data){
            Node *newNode= new Node(data);
            if (Root==NULL){
                Root=newNode;
            }else {
                Root=insertAvl(newNode,Root);
            }
        }
        Node * insertAvl(Node *newNode, Node *sTree){

            Node *newFather=sTree;

            if (newNode->value<sTree->value){
                if (sTree->left==NULL){
                    sTree->right=newNode;
                }else {
                    sTree->left=insertAvl(newNode,sTree->left);
                    if ((getFe(sTree->left)-getFe(sTree->right)==2)){
                        if (newNode->value<sTree->left->value){
                            newFather=leftRotation(sTree);
                        }else {
                            newFather=leftRotationD(sTree);
                        }
                    }
                }
            }else if (newNode->value > sTree->value){
                if (sTree->right==NULL){
                    sTree->right=newNode;
                }else {
                    sTree->right=insertAvl(newNode, sTree->right);
                    if ((getFe(sTree->right)-getFe(sTree->left)==2)){
                        if (newNode->value>sTree->right->value){
                            newFather=rightRotation(sTree);
                        } else {
                            newFather=rightRotationD(sTree);
                        }
                    }
                }
            }else {
            }
            if((sTree->left==NULL) && (sTree->right!=NULL)) {
                sTree->fe=sTree->right->fe+1;
            }else{
                if ((sTree->right==NULL) && (sTree->left!=NULL)) {
                    sTree->fe=sTree->left->fe+1;
                }else {
                    int max;
                    if (getFe(sTree->left)>getFe(sTree->right)){
                        max= getFe(sTree->left);
                    }else {
                        max= getFe(sTree->right);
                    }
                    sTree->fe=max+1;
                }
            }
            return newFather;
        }
        Node * leftRotationD(Node *c){
            Node *temp;
            c->left=rightRotation(c->left);
            temp=leftRotation(c);
            return temp;
        }

        Node * rightRotationD(Node *c){
            Node *temp;
            c->right=leftRotation(c->right);
            temp=rightRotation(c);
            return temp;
        }

        Node * leftRotation(Node *c){ //Rotacion simple a la izqierda
            Node *aux=c->left;
            c->left=aux->right;
            aux->right=c;
            int maxValuec;
            int maxValueaux;

            if (getFe(c->left)>getFe(c->right)){
                maxValuec=getFe(c->left)+1;
            }else {
                maxValuec= getFe(c->right)+1;
            }
            c->fe=maxValuec;
            if (getFe(aux->left)>getFe(aux->right)){
                maxValueaux= getFe(aux->left)+1;
            }else {
                maxValueaux= getFe(aux->right)+1;
            }
            aux->fe=maxValueaux;
            return aux;
        }

        Node * rightRotation(Node *c){ //Rotacion simple a la derecha
            Node *aux=c->right;
            c->right=aux->left;
            aux->left=c;
            int maxValuec;
            int maxValueaux;

            if (getFe(c->left)>getFe(c->right)){
                maxValuec= getFe(c->left);
            }else {
                maxValuec= getFe(c->right);
            }
            c->fe=maxValuec+1;
            if (getFe(aux->left)>getFe(aux->right)){
                maxValueaux= getFe(aux->left);
            }else {
                maxValueaux= getFe(aux->right);
            }      
            aux->fe=maxValueaux+1;
            return aux;
        }
};
