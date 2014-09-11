#include<iostream>
#include<cstdio>

int main(){

	int testCases, N, temp;

	scanf("%d",&testCases);

	while( testCases -- ){

		scanf("%d",&N);

		if( 360 % N == 0 )
			printf("y ");
		else
			printf("n ");


		if( N <= 360 )
			printf("y ");
		else
			printf("n ");

		
		temp =  N * (N + 1)  / 2;

		if ( temp <= 360 )
			printf("y\n");
		else
			printf("n\n");		

	}

	return 0;
}
