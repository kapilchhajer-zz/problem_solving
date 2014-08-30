//https://www.hackerrank.com/challenges/maximizing-xor

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int L, R, max = 0, current;

	scanf("%d %d", &L, &R);

	for( int i = L ; i < R; i++){

		for( int j = i + 1 ; j <= R; j++) {
		
			current =  i ^ j;
			if( current > max)
				max = current;
		}
	} 

	printf("%d\n",max);
	

	return 0;
}
