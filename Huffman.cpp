#include "Huffman.h";
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include "CBinaryTree.cpp"
#include"ObjectInTree.h"
#include "BinaryTree.cpp"

struct CustomRule {
	bool operator()(const pair<char, int >& a, const pair<char, int>& b)
	{
		return a.second > b.second;
	}
};

void Huffman::sentences()
{
	unordered_map<char, int> countedWords;
	string sentences;
	getline(cin, sentences);

	for (char& c : sentences)
	{
		++countedWords[c];
	}

	vector<pair<char, int>> sortedVector(countedWords.begin(), countedWords.end());

	sort(sortedVector.begin(), sortedVector.end(), CustomRule());

	vector<ObjectInTree*> stringVector;//array for object in tree

	for (auto it = sortedVector.rbegin(); it != sortedVector.rend(); it++) {
		string MyWord(1, it->first);
		ObjectInTree* objectInTree = new ObjectInTree(MyWord, it->second);
		stringVector.push_back(objectInTree);
	}

	vector<vector<ObjectInTree*>> sortedWords;
	string word; 
	vector<ObjectInTree*>::iterator it;
	vector<pair<string, int>> treeWords;
	
	int vec = stringVector.size();
	for (int i = 0; i < vec-1; ++i) {
		ObjectInTree* lastElement = stringVector.front();
		stringVector.erase(stringVector.begin());
		ObjectInTree* secondLastElement = stringVector.front();
		stringVector.erase(stringVector.begin());
		
		word.append(lastElement->word);
		word.append(secondLastElement->word);

		int num = secondLastElement->number + lastElement->number;

		ObjectInTree* newObject = new ObjectInTree(word, num);//ue 2/29

		//pushTwoLastElems(lastElement,secondLastElement,newObject,treeWords);

		if (i == 0)
		{
			treeWords.push_back(make_pair(lastElement->word, 1));//mama mie mimi. mama umi mimi.
			treeWords.push_back(make_pair(secondLastElement->word, 0));
		}

		else if (i == 5)
		{
			treeWords.push_back(make_pair(lastElement->word, 1));//mama mie mimi. mama umi mimi.
			treeWords.push_back(make_pair(secondLastElement->word, 0));
			treeWords.push_back((make_pair(newObject->word, 0)));
		}
		else
		{
			treeWords.push_back(make_pair(lastElement->word, 0));//mama mie mimi. mama umi mimi.
			treeWords.push_back(make_pair(secondLastElement->word, 1));
		}
		word = "";
		num = 0;

		delete lastElement;
		delete secondLastElement;

		int s = 0;
		
		for (auto it = stringVector.begin();it!=stringVector.end();++it,++s)
		{
			if (newObject->number == (*it)->number) 
			{
				break;
			}
			else if (newObject->number < (*it)->number)
			{
				break;
			}
			
		}
		stringVector.insert(stringVector.begin() + s, newObject);
		
	}

	CBinaryTree<string, int> myTree;

	for (auto it = treeWords.rbegin();it!=treeWords.rend();++it)
	{
		myTree.insert_new((*it));
		myTree.inOrderTraversal();
	}
}


int main()
{
	Huffman huffman;

	huffman.sentences();

	return 0;
}