//https://www.hackerrank.com/challenges/encryption

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int main(){

	char message[82];

	scanf("%s", message);

	int length  = strlen(message), min, max, W, minimum = 200;
	float sqroot;

	sqroot = sqrt(length);
	max= sqroot + 0.99;
	min = sqroot;

	int j;

	for( int i = min; i <= max; i++){

		for(j = min; i * j < length; j++);

		if( i <= j && i * j < minimum && j <= max){
			W = j;
			minimum = i * j;
		}
	}

	for( int i = 0; i < W; i++){

		for( j = i; j < length; j = j + W)
			printf("%c",message[j]);

		printf(" ");	
	}

	printf("\n");
	return 0;
}
