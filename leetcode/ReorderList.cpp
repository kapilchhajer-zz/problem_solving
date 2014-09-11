#include<iostream>
#include<cstdio>

using namespace std;

/**
 * Definition for singly-linked list. */

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

    ListNode* split(ListNode *head){
        
        ListNode *temp;
        temp = head->next;
        
        while(temp != NULL){
            
                if(temp->next != NULL){
                    
                    head = head->next;
                    temp = temp->next;
                }
                
                temp = temp->next;
                    
        }
        
        temp = head->next;
        head->next = NULL;
        return temp;
    }
    
    ListNode* reverse(ListNode *head){
    
        ListNode *prevNode = head , *currNode = head->next, *temp;
        
        prevNode->next = NULL; // first next part is set by NULL
    
        while(currNode != NULL){
            
            temp = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = temp;
        }
        
        return prevNode;
        
    }
    
    void mergeList(ListNode *first , ListNode *second){
    
            ListNode *temp;
            
            while(second != NULL){
             
                temp = first->next;
                first->next = second;
                second = second->next;
                first->next->next = temp;
                first = temp;
            }
    }
    
    void reorderList(ListNode *head) {
        
            if(head == NULL)
                    return ;
                    
            ListNode *secondListHead = split(head);
    
            if(secondListHead == NULL)
                    return ;
                    
            secondListHead = reverse(secondListHead);
            
            mergeList(head , secondListHead);
    }
};


int main(){

	ListNode *head;
	ListNode *node = new ListNode(1);
	head = node;
	Solution s;
	int i = 2;
	
	while( i < 9){
		
		ListNode *tempNode = new ListNode(i);
		node->next = tempNode;
		node = tempNode;
		i++;	
	}
	s.reorderList(head);

	while(head != NULL){
		cout<<head->val<<endl;
		head  = head->next;
	}
	return 0;
}
