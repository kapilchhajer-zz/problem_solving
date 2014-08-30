//http://www.spoj.com/problems/AP2/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	long long int testCases, A, L, N, sum, D;

	scanf("%lld",&testCases);

	while( testCases-- ){
	
		scanf("%lld %lld %lld", &A, &L, &sum);

		N = sum * 2 / ( A + L );

		sum = sum - 2 * ( A + L );
		
	
		D = ( ( ( 2 * sum) / ( N - 4)  ) - 2 * A ) / ( N - 5 );

		A = A - 2 * D;

		printf("%lld\n" , N );
		for(long long int i = A , k = 1; k <= N ; k++, i = i + D)
			printf("%lld ",i);

		printf("\n");
	}
	

	return 0;
}
