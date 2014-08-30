//https://www.hackerrank.com/challenges/runningtime

#include<iostream>
#include<cstdio>

#define SIZE 10000

using namespace std;

int main(){

	int N, arr[SIZE], count = 0, pointer, value;

	scanf("%d", &N);

	for(int i = 0; i < N; i++)	
		scanf("%d", arr + i);

	for( int i = 1; i < N; i++){

		value = arr[i];
		pointer = i;

		for( int j = i -1; j >= 0; j--){

			if( arr[j] > value){

				arr[pointer] = arr[j];
				pointer--;
				count++;
			}
			else
				break;

			arr[pointer] = value;
		}

		for(int k = 0; k < N; k++)
			printf("%d ",arr[k]);
	
		printf("\n");
	}
	

	return 0;
}
