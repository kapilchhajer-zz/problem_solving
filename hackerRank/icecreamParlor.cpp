//https://www.hackerrank.com/challenges/icecream-parlor

#include<iostream>
#include<cstdio>

using namespace std;


int main(){

	int testCases, temp;
	int M, N;

	scanf("%d", &testCases);

	while(testCases--){		
		
		scanf("%d %d", &M, &N);
		
		int index[10001] = {0}, ind, result;

		for(int i = 1; i <= N; i++){

			scanf("%d", &temp);
			if(index[temp] != 0){
				result = temp;
				ind = i;
			}
			if( M > temp && index [ M - temp] == 0)
				index[ M - temp] = i;
		}

		printf("%d %d\n", index[result], ind);
	}

	return 0;
}
