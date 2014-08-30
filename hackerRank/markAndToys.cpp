//https://www.hackerrank.com/challenges/mark-and-toys

#include<iostream>
#include<cstdio>

using namespace std;

int partition(int *Arr, int start, int end){

	int pivot,pivotPosition, j = 0, A[end - start + 1];

	pivot = Arr[start];
	
	

	for( int i = start + 1 ; i <= end ; i++){

		if( pivot >= Arr[i] ){
		
			A[j] = Arr[i];
			j++;
		}
	}

	A[j] = pivot;
	pivotPosition = start + j;

	for( int i = start + 1 ; i <= end ; i++){

		if( pivot < Arr[i]){

			j++;
			A[j] = Arr[i];
		}
	}	


	j = 0;

	for( int i = start; i <= end; i++){
		Arr[i] = A[j];
		j++;
	}

	return pivotPosition;
}


void quickSort(int * Arr , int start , int end){

	if(start >= end)
		return ;
	
	int  position;
	
	position = partition(Arr, start, end);

	quickSort(Arr,start, position - 1);	 
	quickSort(Arr,position + 1 , end);
	
	return ;
}

int main(){

	int num, money, sum = 0;

	scanf("%d %d", &num, &money);

	int Array[num];

	for(int i = 0; i < num; i++)
		scanf("%d",Array + i);

	quickSort(Array, 0 , num - 1);

	for(int i = 0; i < num; i++){
		
		sum = sum + Array[i];

		if( sum > money){
			
			sum = i;
			break;
		}

	}

	printf("%d\n",sum);
	return 0;
}
