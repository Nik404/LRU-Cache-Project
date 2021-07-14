#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// Node to store the data (linked list)
class Node{
public:

	string key;
	int value;

	Node(string key, int value){
		this->key = key;
		this->value = value;
	}

};


//  LRU Cache Data Structure
class LRUCache{
public:
	int maxSize;
	list<Node> l;
	unordered_map<string, list<Node>::iterator> m;

	LRUCache(int maxSize){
		this->maxSize = maxSize > 1 ? maxSize : 1;
	}

	void insertKeyValue(string key, int value){
		// ...

	}

	int getValue(string key){
		// ...

	}

	string mostRecentKey(){
		// ...
		
	}



};


int main()
{
	/* code */
	return 0;
}

