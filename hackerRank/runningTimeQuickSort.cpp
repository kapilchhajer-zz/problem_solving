//https://www.hackerrank.com/challenges/quicksort4


#include<iostream>
#include<cstdio>

using namespace std;

int swapQuick = 0, swapInsertion = 0;

int partition(int *Arr, int start, int end){

	int pivot, temp, pivotPosition, j = start, A[end - start + 1];

	pivot = Arr[end];
	
	

	for( int i = start; i <= end; i++){

		if( pivot >= Arr[i] ){
		
			temp = Arr[i];
			Arr[i] = Arr[j]; 
			Arr[j] = temp;
			j++;	
			swapQuick++;
		}
	}

	pivotPosition = j - 1;
	

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

void insertionSort(int *arr, int N){


	int value, pointer;
		for( int i = 1; i < N; i++){

			value = arr[i];
			pointer = i;

			for( int j = i -1; j >= 0; j--){

				if( arr[j] > value){

					arr[pointer] = arr[j];
					pointer--;
					swapInsertion++;
				}
				else
					break;

			} 
			
			arr[pointer] = value;

		}

}
int main(){

	int num;

	scanf("%d", &num);

	int Array[num],arr[num];

	for(int i = 0; i < num; i++){
		scanf("%d",Array + i);
		arr[i] = Array[i];
	}

	quickSort(Array, 0 , num - 1);
	insertionSort(arr, num);

	printf("%d\n",swapInsertion - swapQuick);

	return 0;
}
