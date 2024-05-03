#include "node.h"
class Tree24 {
	Node* root;
	int size;
	public:
		Tree24(){
			root = NULL;
			size = 0;
		}
		
		void insert(int num){
			if(!root){
				root = new Node(num, NULL);
			} else {
				Node* w = search(num);
				bool ok = w->addKey(num);
				
				//Check if overflow
				while(!ok){ //if overflow
					Node* u;
					int pos;
					if(w == root){
						u = new Node(w->getData(2), NULL);
						root = u;
						pos = 0;
						ok = true;
					} else {
						u = w->getParent();
						ok = u->addKey(w->getData(2));
						pos = u->indexOf(w->getData(2));
					}
					Node* wp = new Node(w->getData(0), u);
					wp->addKey(w->getData(1));
					Node* w2p = new Node(w->getData(3), u);
					u->insertChildren(wp, w2p, pos);
					w = u;
				}
			}
			size++;
		}
		
		Node* search(int num){
			return search(num, root);
			/*if(!root){
				return NULL;
			} 
			
			for(int i = 0; i < root->getSize(); i++){
				if(num == root->getData(i)){
					return root;
				} else if(num < root->getData(i)){
					
				}
			}*/
		
		}
		Node* search(int num, Node* n){
			int index = n->getSize();
			for(int i = 0; i < n->getSize(); i++){
				if(num == n->getData(i)){
					return n;
				} else if(num < n->getData(i)){
					index = i;
					break;
				}
			}
			
			if(!n->getchildren(index)) {
				//cout << "Child not found returning parent instead...";
				return n;
			} //else {
				//cout << "Child found";
			//}
		}
		
		
		void print(){
			root->print();
		}
};

