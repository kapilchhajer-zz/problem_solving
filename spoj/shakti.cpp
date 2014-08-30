//http://www.spoj.com/problems/SHAKTI/	

#include<cstdio>

int main(){

	long int testCases, N;

	scanf("%ld", &testCases);

	while( testCases-- ){
		
		scanf("%ld", &N);

		N % 2 ? printf("Sorry Shaktiman\n") : printf("Thankyou Shaktiman\n");
	}

	return 0;
}
