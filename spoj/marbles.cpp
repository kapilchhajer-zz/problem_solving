//http://www.spoj.com/problems/MARBLES/

#include<iostream>
#include<cstdio>

using namespace std;


int main(){

	unsigned long long int N, K, L, temp, result;
	int testCases;

	scanf("%d",&testCases);

	while( testCases-- ){

		scanf("%llu%llu", &N, &K);

		N--; K--;
	
		L = N - K;

		if( L < K){
		
			temp = K;
			K  = L;
			L = temp;

		}


		if( K == 0 ){

			result = 1;
		}
		else if( K == 1 ){

			result = N;
		}
		else{

			result = 1;
			K = 1;

			for( temp = L + 1; temp <= N ; temp++ ){
					
				result = result * temp / K ;
				K++; 
			}
		}
		
		printf("%llu\n",result);
	}

	return 0;
}
