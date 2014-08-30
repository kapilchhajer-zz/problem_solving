//http://www.spoj.com/problems/UCV2013A/

#include<iostream>
#include<cstdio>
#define MODE 1000000007

using namespace std;
/*
unsigned long long int power( int N, int L){

	unsigned long long int result = 1;

	while( L != 0){

		if( L % 2 == 0){

			L = L / 2;
			N = (N * N) % MODE;
		}
		else{

			L--;
			result = (result * N ) % MODE;
		}
	}

	return result;
}
*/

int main(){

	unsigned long long int N, L, temp, result;

	scanf("%llu %llu", &N, &L);
	
	while( N != 0 && L != 0){
		
		temp = 1;
		result = 0;

		for( int i = L; i > 0; i--){
			temp =  (temp * N) % MODE;
			result =  (result + temp) % MODE; 
		}
		printf("%llu\n", result);	
		scanf("%llu %llu", &N, &L);
	}

	return 0;
}
