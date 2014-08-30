//http://www.spoj.com/problems/COINS/

#include<iostream>
#include<cstdio>

#define LL long long int
#define SIZE 1000001
using namespace std;

long int seive[SIZE] = {0}; 

LL calculateCoin( LL N ){

	if( N == 1)
		return 1;
	else if( N == 0)
		return 0;
	else if( N < SIZE )
		 if (seive[N] != 0)
			return seive[N];


	LL temp =  calculateCoin(N/2) + calculateCoin(N/3) + calculateCoin(N/4);
	

	if( temp < N )
	 	temp = N;
	
	if( N < SIZE )
		seive[N] = temp;

	return temp;

}


int main(){

	long int N;


	while( scanf("%ld", &N) != EOF){

		printf("%lld\n",calculateCoin(N));

	}

	return 0;
}
