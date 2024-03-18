#pragma once
#include <string>
using namespace std;

class ObjectInTree {
public:
	int number;
	string word;

	ObjectInTree(string word, int number);
	ObjectInTree(const ObjectInTree& obj);
	bool operator()( ObjectInTree* obj) const;
	bool operator==(const ObjectInTree& other) const;
};
