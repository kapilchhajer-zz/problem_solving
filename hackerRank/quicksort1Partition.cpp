//https://www.hackerrank.com/challenges/quicksort1

#include<iostream>
#include<cstdio>

using namespace std;

void partition(int *Arr, int start, int end){

	int pivot, j = start, A[end - start + 1];

	pivot = Arr[start];


	for( int i = start + 1 ; i <= end ; i++){

		if( pivot >= Arr[i] ){
		
			A[j] = Arr[i];
			j++;
		}
	}

	A[j] = pivot;

	for( int i = start + 1 ; i <= end ; i++){

		if( pivot < Arr[i]){

			j++;
			A[j] = Arr[i];
		}
	}	


	
	for( int i = 0; i <= end; i++)
		printf("%d ",A[i]);

	printf("\n");

}


int main(){

	int num;

	scanf("%d", &num);

	int Array[num];

	for(int i = 0; i < num; i++)
		scanf("%d",Array + i);
	
	partition(Array, 0 , num - 1);
	return 0;
}
