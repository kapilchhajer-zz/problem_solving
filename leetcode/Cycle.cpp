#include<iostream>
#include<cstdio>

using namespace std;


struct ListNode{
	
	int val;
	ListNode *next;
	
	ListNode(int x) : val(x) , next(NULL) { };
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
  
        ListNode *slowPtr, *fastPtr;    

	if(head == NULL)
		return NULL;
    	
	slowPtr = head;
	fastPtr = head->next;

	// detect cycle or not
	while( slowPtr!= fastPtr && fastPtr && fastPtr->next != NULL){
	
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
	}

	// cycle not present
	if(fastPtr == NULL || fastPtr->next == NULL)
		return false;
	
	

	return true;	
    }
};

int main(){
       
	ListNode *head, *temp;
	ListNode *node = new ListNode(1);
	head = node;
	Solution s;
	int i = 2;
	
	while( i < 9){
		
		ListNode *tempNode = new ListNode(i);
		node->next = tempNode;
		//if( i == 5)
		//	temp = tempNode;
		node = tempNode;
		i++;	
	}  

	//node->next = temp;
	//temp = NULL;
	bool flag = s.hasCycle(head);

	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;


	return 0;
}
