//https://oj.leetcode.com/problems/lru-cache/

#include<iostream>
#include<cstdio>
#include<map>
#include<cstdlib>

using namespace std;

struct dLinkList{

	int key, value;
	dLinkList *prev, *next;

	dLinkList(int kk , int vv) : key(kk), value(vv), prev(NULL), next(NULL) {}
};


class LRUCache{

	int capacity, nodeCount;
	struct dLinkList *head, *rear;
	map<int , struct dLinkList *> mymap;
	map<int , struct dLinkList *>  :: iterator  it;
public:

	LRUCache(int capacity) {
        
		this->capacity = capacity;
		nodeCount = 0;
		head = NULL;	
		rear = NULL;
	}
    

	int get(int key) {
		
		it = mymap.find(key);
		
		if( head == NULL || it == mymap.end())
			return -1;

		moveAtBegining(it->second);
		return it->second->value ;
	}
    
	void insertNodeAtBegining(struct dLinkList *node){

		
		node->prev = NULL;
		node->next = head;
		head->prev = node;
		head = node;
	}


	void moveAtBegining(struct dLinkList *node){

		// if list contain only one element it's ok because we don't have to change head and end
		
		if(head == node)
			return;

		if(rear == node)
			rear = node->prev;

		node->prev->next = node->next;
	
		if(node->next != NULL)
			node->next->prev = node->prev;
		

		insertNodeAtBegining(node);
	}

	void deleteEndNode(){

		struct dLinkList *temp = rear;

		if(head == rear){
			head = rear = NULL;
		}
		else{
			rear = rear->prev;
			rear->next = NULL;
		}

		mymap.erase(temp->key);
		nodeCount--;
		
	}

	void set(int key, int value) {
        
		it = mymap.find(key);		

		if( it != mymap.end()){

			it->second->value = value;
			moveAtBegining(it->second);
			return;
		}
			
		if( nodeCount >= capacity){
			deleteEndNode();
		}
	
	
		dLinkList *node = new dLinkList(key, value);	

		
		if(nodeCount == 0){
			head = node;
			rear = node;
		}
		else	
			insertNodeAtBegining(node);		
	
		mymap.insert( pair<int , struct dLinkList *>( key , node));

		nodeCount++;
	}


};



int main(){


	LRUCache lru(2);

	cout<<lru.get(2);
	lru.set(2,6);
	cout<<" "<<lru.get(1);
	lru.set(1,5);
	lru.set(1,2);
	cout<< " "<<lru.get(1)<<" "<<lru.get(2)<<endl;
	/*lru.set(2 , 2);
	lru.set(1 , 1);
	cout<<" value of  2 "<<lru.get(2)<<endl;
	lru.set(4 , 4);
	cout<<" value of 5 "<<lru.get(1)<<endl;
	cout<<" value of 5 "<<lru.get(2)<<endl;
*/	return 0;
} 
