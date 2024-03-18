#pragma once
#include <string>
#include <iostream>

using namespace std;


class Huffman {
private :
	string word;
	
public:
	Huffman()
	{}
	void sentences();
	//void makeTree(vector<ObjectInTree> stringVector);
	void pushTwoLastElems();
};