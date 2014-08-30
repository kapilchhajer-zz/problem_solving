//https://www.hackerrank.com/challenges/find-median

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int partition( int *A, int start, int end, int pivot){

	int temp = A[pivot],  index = start;
	
	A[pivot] = A[start];
	A[start] = pivot = temp;
	
	
	for(int i = start + 1; i <= end; i++){
	
		if( pivot >= A[i]){

			index++;
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
		}
	}

	A[start] = A[index];
	A[index] = pivot;

	return index;
}

int main(){

	int N;

	scanf("%d", &N);

	int A[N];

	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int start = 0, end = N -1, pivot, point = -1, index = (N - 1) / 2;
	while( point != index){
		
		pivot = rand() % ( end - start + 1) + start;
		point = partition(A , start, end, pivot);

		if( point < index)
			start = point + 1;
		else
			end = point - 1; 

	}

	printf("%d\n",A[index]);
	return 0;
}
