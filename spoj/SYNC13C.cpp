//http://www.spoj.com/problems/SYNC13C/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int testCases, A, B;

	scanf("%d", &testCases);

	while(testCases--){
	
		scanf("%d %d", &A, &B);

		if( A % 2 == 1 && B % 2 == 1 ) 
			printf("Ramesh\n");
		else
			printf("Suresh\n");
	}	

	return 0;
}
