//http://www.spoj.com/problems/DCEPC11B/

#include<iostream>
#include<cstdio>

int main(){

	long int testCases;
	long long int N, P, mul;

	scanf("%ld", &testCases);


	while( testCases-- ){

		mul = 1;

		scanf("%lld %lld", &N, &P);

		if( N >= P){

			printf("0\n");
			continue;
		}
	
		for( long long int i = N + 1; i < P; i++)
			mul = ( mul * i ) % P;
		

		long long int A1, A2, A3, B1, B2, B3, T1, T2, T3, quotient;

		A1 = B2 = 1;
		A2 = B1 = 0;
		A3 = P;
		B3 = mul;
		

		while( B3 != 1){

			quotient = A3 / B3;
			
			T1  =  B1;
			T2  =  B2;
			T3  =  B3;

			B1 = A1 - ( quotient * B1 );
			B2 = A2 - ( quotient * B2 );
			B3 = A3 - ( quotient * B3 );

			A1 = T1;
			A2 = T2;
			A3 = T3;
		}	

		if( B2 < 0)
			B2 = P + B2;

		printf("%lld\n",(B2 * (P - 1)) % P);
	}

	return 0;
}
