//http://www.spoj.com/problems/NDIV/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;


int main(){
	
	long int A, B, N, temp, fact, sum,count = 0,size;
	
	scanf("%ld %ld %ld", &A, &B, &N);

	if( A > B){
		temp = A;
		A = B;
		B = temp;
	}
	
	int seive[1001] = {0};

	for( long int i = A; i <= B; i++){

		count = 0;
		temp = i / 2;

		for( long int j = 1; j <= temp; j++){

			

		}	
	}

	printf("%ld\n",count);
	return 0;
}
