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
    ListNode *detectCycle(ListNode *head) {
  
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
		return NULL;
	

	//detect cycle length

	int cycleLength = 1;

	while(slowPtr != fastPtr->next){

		fastPtr = fastPtr->next;
		cycleLength++;		
	} 
	
	ListNode *startPtr , *kPtr;	

	int k = 0;
	startPtr = kPtr = head;
	
	while( k < cycleLength){
		kPtr = kPtr->next;
		k++;
	}

	while( startPtr != kPtr){
		
		startPtr = startPtr->next;
		kPtr = kPtr->next;
	}
	
	return startPtr;
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
		if( i == 5)
			temp = tempNode;
		node = tempNode;
		i++;	
	}  

	node->next = temp;
	temp = NULL;
	temp = s.detectCycle(head);
	if(temp == NULL)
		cout<<"NULL"<<endl;
	else	
		cout<<temp->val<<endl;

	return 0;
}
