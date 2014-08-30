//http://www.spoj.com/problems/ANARC08H/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node{
	int info;
	struct node *next;
};

int main(){

	
	int N, D;


	while( true ){
		scanf("%d %d", &N, &D);
		if( N == 0 && D == 0 )
			break;

		struct node *head = NULL, *prev = NULL, *curr = NULL;

		struct node *element;
		element = (struct node *) malloc( sizeof(struct node) );

		element->info = 1;
		head =  prev = element;
		
		for( int i = 2; i <= N; i++){
	
			element = (struct node *) malloc( sizeof(struct node) );
			element->info = i;
			prev->next = element;
			prev = element;
		}
		prev->next = head;

		curr = head;
		
		for( int i = 1; i < N; i++){

			for( int j = 1 ; j < D; j++){
				prev = curr;
				curr = curr->next;
			}

			if( curr == head){
				head = head ->next ;
				free(prev->next);
				prev->next = head;
				curr = head;
			}
			else{
				curr = curr->next;
				free(prev->next);
				prev->next = curr;
			}
		}

		
		printf("%d %d %d\n", N, D, head->info);

	}

	return 0;
}
