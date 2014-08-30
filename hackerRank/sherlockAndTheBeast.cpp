//https://www.hackerrank.com/challenges/sherlock-and-the-beast

#include<iostream>
#include<cstdio>

using namespace std;

int main(){


	int testCases, N, fiveCount, threeCount, i;

	scanf("%d", &testCases);

	while( testCases-- ){

		fiveCount = threeCount = 0;

		scanf("%d", &N);
		
		fiveCount  = N / 3;
		N = N % 3;
		
		if( N == 1 && fiveCount >= 3){

			N = 0;
			fiveCount = fiveCount - 3;
			threeCount = threeCount + 2;
		}		
		else if( N == 2 && fiveCount >= 1){

			N = 0;
			fiveCount = fiveCount - 1;
			threeCount = threeCount + 1;
		}

		if( N != 0){

			printf("-1\n");
			continue;
		}

		for( i = 0; i < fiveCount; i++)
			printf("555");

		
		for( i = 0; i < threeCount; i++)
			printf("33333");

		printf("\n");
	}	


	return 0;
}
