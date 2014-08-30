//https://www.hackerrank.com/challenges/game-of-rotation

#include<cstdio>
#include<iostream>

using namespace std;



int main(){


	long int N;

	scanf("%ld", &N);

	long int Arr[N];
	long long int sum = 0, store = 0, max;

	for( int i = 0; i < N; i++){

		scanf("%ld", &Arr[i]);

		sum = sum + Arr[i];
		store = store + (Arr[i] * (i + 1));
	}

	max = store;

	for( int i = N - 1; i != 0; i--){
		
		store = store + sum - (N * Arr[i]);	

		if( store > max )
			max = store;
	}


	printf("%lld\n", max);	


	return 0;
}
