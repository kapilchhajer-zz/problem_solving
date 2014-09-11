//http://www.codechef.com/problems/NUKES/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){

	long int A,N,K;

	scanf("%ld %ld %ld",&A,&N,&K);

	long int *reactor,i=0;	
	
	reactor = (long int *) calloc(K,sizeof(long int));
	N++;

	while(A != 0){
		
		reactor[i] = A % N;
		i++;
		A = A / N;
	
		if( i == K)
			break;

	}

	reactor[K-1] = reactor[K - 1] % N;

	for(i = 0; i < K; i++)
		printf("%ld ",reactor[i]);
	
	printf("\n");
	
	return 0;
}
