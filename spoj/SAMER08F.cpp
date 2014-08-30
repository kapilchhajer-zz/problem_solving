//http://www.spoj.com/problems/SAMER08F/


#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	long int N, square[101];

	square[0] = 0;
	N = 1;

	for( int i = 1; i <= 100; i++, N = N + 2)
		square[i] = square[i -1] + i * i;	


	scanf("%ld", &N);

	while( N != 0){

		printf("%ld\n", square[N]);	
		scanf("%ld", &N);

	}
	return 0;
}
