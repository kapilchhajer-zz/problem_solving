//http://www.spoj.com/problems/ACPC10A/

#include<cstdio>

int main(){

	long int  P, Q, R;

	scanf("%ld %ld %ld", &P, &Q, &R );

	while( !(P == 0 && P == R ) ){

		if( Q - P == R - Q )
			printf("AP %ld\n", R + (R -Q));
		else
			printf("GP %ld\n", R * (R / Q) );
	
	
		scanf("%ld %ld %ld", &P, &Q, &R );

	}

	return 0;
}
