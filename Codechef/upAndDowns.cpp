#include<cstdio>
#include<iostream>

using namespace std;


int main(){

	int testCases, N;
	long int temp, first, second, third, i;
	scanf("%d",&testCases);

	while(testCases--){
		
		i = 0;

		scanf("%d",&N);

		first = second = third = 0;

		while( N-- ){
			
			i++;
			scanf("%ld",&temp);
			
			if( temp >= first){
			
				third   = second;	
				second  = first;
				first = temp;
			}
			else if (temp >= second){

				third = second;
				second = temp;	
			}
			else
				third = temp;

		
			if( i == 3 ){
				printf("%ld %ld ",second,first);	
				first = third;
				second = third = 0;		
			}

			if (i> 3 && i % 2 == 1){
				printf("%ld %ld ",third,first);	
				first = second;
				second = third = 0;
		
			}
				
		}
		if( i % 2 == 1)
			printf("%ld\n",first);
		else{

			printf("%ld %ld\n",second,first);
		}
	}	

	return 0;
}
