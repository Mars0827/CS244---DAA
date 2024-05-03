#include <iostream>
#include <cstdlib>
using namespace std;
class Node {
	int* data;
	Node** children;
	int size;
	Node* parent;
	
	public:
		Node(int num, Node* parent){
			data = (int*) malloc(4 * sizeof(int));
			data[0] = num;
			size = 1;
			children = (Node**) calloc(sizeof(Node*), 5);
			this->parent = parent;
		}
		void print(){
			cout << "size: " << size << endl;
			for(int i = 0; i < size; i++){
				cout << data[i] << " ";
			}
			
			for(int i = 0 ; i < size; i++){
				if(children){
					children[i]->print();
				}
			}
			
			cout << endl;
		}
		
		int getData(int i){
			return data[i];
		}
		
		Node* getchildren(int i){
			return children[i];
		}
		
		int getSize(){
			return size;
		}
		
		bool addKey(int num){
			int i;
			for(i = size; i > 0; i--){
				if(data[i-1] > num){
					data[i] = data[i-1];
				} else {
					break;
				}
			}
			data[i] = num;
			return ++size != 4;
		}
		
		Node* getParent(){
			return parent;
		}
		
		int indexOf(int num){
			for(int i = 0 ; i < size; i++){
				if(num == data[i]){
					return i;
				}
			}
		}
		
		void insertChildren(Node* wp, Node* w2p, int pos){
			for(int i = size-1; i > pos; i--){
				children[i+1] = children[i];
			}
			children[pos] = wp;
			children[pos+1] = w2p;
		}
		
};

