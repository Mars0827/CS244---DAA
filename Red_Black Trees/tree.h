#include "node.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class BSTree {
    node* root;
    int size;

    public:
    BSTree() {
        root = NULL;
        size = 0;
    }
    
    //need to fix propagation
    bool insert(int num) {
        if(!root){
            node* r = new node();
            r->element = num;
            r->is_red = false;
            r->parent = NULL;
            root = r;
            size++;
            return true;
        }

        node* curr = root;
        node* par = NULL;

        while(curr != NULL){
            par = curr;
            if(num < curr->element)
                curr = curr->left;
            else 
                curr = curr->right;
        }

        node* n = new node();
        n->element = num;
        n->parent = par;
        n->is_red = true;

        if(num < par->element)
            par->left = n;
        else 
            par->right = n;

        restructure(n);
        size++;
        return true;
    }

    void recolor(node* par){
        par->is_red = false;
        par->right->is_red = true;
        par->left->is_red = true;
    }

    void restructure(node* curr){
        node* par = curr->parent;
        node* gpar = par->parent;

        if(!par || !gpar || !par->is_red || !curr->is_red)
            return;

        node* uncle;

        if(gpar->left == par)
            uncle = gpar->right;
        else 
            uncle = gpar->left;

        if(!uncle || !uncle->is_red){
            cout << "INSERTION Violation: Case 1" << endl;
            if(par->left == curr && gpar->left==par){
                zigRight(par);
                recolor(par);
                cout << "ZIGRIGHT" << endl;
            } else if (par->left != curr && gpar->left==par){
                zigLeft(curr);
                zigRight(curr);
                recolor(curr);
                cout << "ZIGZAGRIGHT" << endl;
            } else if (par->right == curr && gpar->right == par){
                zigLeft(par);
                recolor(par);
                cout << "ZIGLEFT" << endl;
            } else {
                zigRight(curr);
                zigLeft(curr);
                recolor(curr);
                cout << "ZIGZAGLEFT" << endl;
            }
        } else {
            cout << "INSERTION Violation: Case 2" << endl;

            par->is_red = false;
            uncle->is_red = false;

            if(gpar != root){
                gpar->is_red = true;
            }
            
            return;
        }
        return;
    }

    void zigLeft(node* curr){
        node* par = curr->parent;
        node* gpar = par->parent;

        par->right = curr->left;
        
        if(curr->left)
            curr->left->parent = par;

        curr->left = par;
        par->parent = curr;

        curr->parent = gpar;

        if(!gpar)
            root = curr;
        else if(gpar->left == par)
            gpar->left = curr;
        else 
            gpar->right = curr;
    }

    void zigRight(node* curr){
        node* par = curr->parent;
        node* gpar = par->parent;

        par->left = curr->right;
        
        if(curr->right)
            curr->right->parent = par;

        curr->right = par;
        par->parent = curr;

        curr->parent = gpar;

        if(!gpar)
            root = curr;
        else if(gpar->left == par)
            gpar->left = curr;
        else 
            gpar->right = curr;
    }

    // WARNING. Do not modify these methods below.
    // Doing so will nullify your score for this activity.
    void print() {
        if (isEmpty()) {
            cout << "EMPTY" << endl;
            return;
        }
        cout << "PRE-ORDER: ";
        print_preorder(root);
        cout << endl << "IN-ORDER: ";
        print_inorder(root);
        cout << endl << "POST-ORDER: ";
        print_postorder(root);
        cout << endl << "STATUS: " << check_health(root, NULL) << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print_preorder(node* curr) {
        cout << curr->element;
        if (curr->is_red) {
            cout << "(R) ";
        } else {
            cout << "(B) ";
        }
        if (curr->left != NULL) {
            print_preorder(curr->left);
        }
        if (curr->right != NULL) {
            print_preorder(curr->right);
        }
    }

    void print_inorder(node* curr) {
        if (curr->left != NULL) {
            print_inorder(curr->left);
        }
        cout << curr->element;
        if (curr->is_red) {
            cout << "(R) ";
        } else {
            cout << "(B) ";
        }
        if (curr->right != NULL) {
            print_inorder(curr->right);
        }
    }

    void print_postorder(node* curr) {
        if (curr->left != NULL) {
            print_postorder(curr->left);
        }
        if (curr->right != NULL) {
            print_postorder(curr->right);
        }
        cout << curr->element;
        if (curr->is_red) {
            cout << "(R) ";
        } else {
            cout << "(B) ";
        }
    }

    // WARNING. Do not modify this method.
    // Doing so will nullify your score for this activity.
    bool check_health(node* curr, node* parent) {
        bool health = curr->parent == parent;
        if (curr->left != NULL) {
            health &= check_health(curr->left, curr);
        }
        if (curr->right != NULL) {
            health &= check_health(curr->right, curr);
        }
        return health;
    }
};