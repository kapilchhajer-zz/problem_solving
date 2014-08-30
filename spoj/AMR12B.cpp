//http://www.spoj.com/problems/AMR12B/

#include<iostream>
#include<cstdio>
#include<vector>

#define pb push_back

using namespace std;

int main(){


	int N, M, X, Y, testCases;

	scanf("%d", &testCases);

	while( testCases-- ){

		scanf("%d %d", &N, &M);

		int  anamoly[N + 1];

		for(int i = 1; i <= N; i++)
			anamoly[i] = i - 1;

		for( int i = 1; i <= M; i++){
			scanf("%d %d", &X, &Y);
			
			if( X < Y){
	
				anamoly[X]++;
				anamoly[Y]--;			

			}	
			else{

				anamoly[Y]++;
				anamoly[X]--;			
			}			
			
		}
	
		int i;

		for(i = 1; i <= N; i++){


			if( anamoly[i] == N - 1 ){

				printf("2 %d\n",i);
				break;
			}
		}

		if( i > N )
			printf("1\n");

		
	}

	return 0;
}
