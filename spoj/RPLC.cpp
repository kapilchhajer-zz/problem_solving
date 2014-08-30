//http://www.spoj.com/problems/RPLC/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	long long int testCases,k = 1, N, initial, min, temp;

	scanf("%lld", &testCases);

	while( testCases-- ){

		initial = 0;
		min = 1;
		scanf("%lld", &N);

		for( int i = 0; i < N; i++){

			scanf(" %lld", &temp);
			initial = initial + temp;
			
			if( initial < min )
				min = initial;
		}

		if( min < 0)
			min = -1 * min + 1;
		else if ( min == 0)
			min = 1;


		printf("Scenario #%lld: %lld\n", k, min); 

		k++;
	}

	return 0;
}
