#include <iostream>
#include "tree24.h"

int main(int argc, char** argv){
	Tree24* tree = new Tree24();
	tree->insert(4);
	tree->insert(13);
	tree->insert(15);
	tree->insert(26);
	tree->print();
	return 0;
}

