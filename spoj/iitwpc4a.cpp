//http://www.spoj.com/problems/IITWPC4A/

#include<iostream>
#include<cstdio>
#include<cstring>

#define MAX 100005
using namespace std;

int main(){

	unsigned long long int testCases, i, M, N, count;
	unsigned long long int Min, Max, sum;
	char str[MAX];

	scanf("%llu", &testCases);
	
	while( testCases-- ){

		Min = Max = sum = count = 0;

		scanf("%s", str);
		scanf("%llu %llu", &M, &N);	

		if( M == N){
			
			Min = Max = strlen(str);
			printf("%llu %llu\n", Min, Max);
			continue;
		}


		for( i = 0; str[i] != '\0'; i++){

			
			if( str[i] == 'a'){
			
				count++;
			}
			else{

				if ( count >= M ){

					sum = sum  -  (count / M) * (M - N);
				
				}
		
				count = 0;
			}

			sum++;
		}
		
		if ( count >= M )
			sum = sum  -  (count / M) * (M - N);
				
				

		if( M < N){
	
			Max = sum;
			Min = i;
		}
		else{

			Min = sum;
			Max = i;
		}	
		
		printf("%llu %llu\n", Min, Max);

	}

	return 0;
}
