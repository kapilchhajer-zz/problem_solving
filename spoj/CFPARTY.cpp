//http://www.spoj.com/problems/CFPARTY/


#include<iostream>
#include<cstdio>

using namespace std;


int main(){

	int testCases, N;


	scanf("%d", &testCases);


	while(testCases--){
		
		scanf("%d", &N);
		
		if( N < 3)
			printf("0\n");
		else
		printf("%d\n", N - 2);

	}

	return 0;
}
