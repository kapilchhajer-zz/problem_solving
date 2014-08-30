//http://www.spoj.com/problems/TRICOUNT/

#include<iostream>
#include<cstdio>

using namespace std;


int main(){

	int testCases;
	unsigned long long int num, sum;

	scanf("%d", &testCases);

	while( testCases-- ){

		scanf("%llu", &num);
	
		if(num % 2 == 0)
			sum = ( num * ( num + 2 ) * ( ( 2 * num ) + 1 ) ) / 8;
        	else
			sum = ( ( num * ( num + 2 ) * ( ( 2 * num ) + 1 ) ) - 1 ) / 8;	
		
		printf("%llu\n",sum);
	}

	return 0;
}
