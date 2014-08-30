//https://www.hackerrank.com/challenges/tutorial-intro

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int V, N, index, temp;

	scanf("%d %d", &V, &N);

	for(int i = 0; i < N; i++){

		scanf("%d", &temp);
	
		if( temp == V)
			index = i;
	}

	printf("%d\n", index);
	return 0;

}
