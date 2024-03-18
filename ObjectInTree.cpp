#include"ObjectInTree.h"

ObjectInTree::ObjectInTree(string word, int number)
{
	this->number = number;
	this->word = word;
}

bool ObjectInTree::operator==(const ObjectInTree& other) const
{
	return (word == other.word) && (number == other.number);

}

bool ObjectInTree::operator()( ObjectInTree* obj) const{
	return obj->number = number;
}

ObjectInTree::ObjectInTree(const ObjectInTree& obj)
{
	this->number = obj.number;
	this->word = obj.word;
}