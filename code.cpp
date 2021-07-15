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
		// ... 2 cases
		if(m.count(key) != 0){
			auto it = m[key];
			it->value = value;
		}
		else{
			// check if cache is full or not 
			// remove the least recently used item from cache
			if(l.size() == maxSize){
				Node last = l.back();
				m.erase(last.key); // removes from hashmap
				l.pop_back(); // removes from linkedlist
			}
			Node n(key,value);
			l.push_front(n);
			m.insert({key, l.begin()});
		}

	}

	int* getValue(string key){
		// ...
		if(m.count(key) != 0){
			auto it = m[key];

			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			m.insert({key, l.begin()});

			return &l.begin()->value;
		}
		return NULL;

	}

	string mostRecentKey(){
		// ...

		return l.front().key;
	}



};


int main()
{
	/* code */
	LRUCache lru(3);
	lru.insertKeyValue("mango", 10);
	lru.insertKeyValue("apple", 20);
	lru.insertKeyValue("berries", 40);
	cout << lru.mostRecentKey()<< endl;

	lru.insertKeyValue("mango", 40);
	cout << lru.mostRecentKey() << endl;

	lru.insertKeyValue("banans", 50);

	if(lru.getValue("apple") == NULL){
		cout << "apple doesn't exist";
	}

	if(lru.getValue("strawberry") == NULL){
		cout << "strawberry doesn't exist" << endl;
	}

	if(lru.getValue("mango") == NULL){
		cout << "mango doesn't exist";
	}


	return 0;
}

