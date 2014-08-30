//https://www.hackerrank.com/challenges/countingsort4

#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct element{

	int id,  value;
	char name[12];

};

void insertionSort(struct element  *arr, int N){


	int value, pointer;
	struct element temp;

		for( int i = 1; i < N; i++){

			value = arr[i].value;
			pointer = i;
			temp = arr[i];
		
			for( int j = i -1; j >= 0; j--){

				if( arr[j].value > value){

					arr[pointer] = arr[j];
					pointer--;
				}
				else
					break;

			} 
			
			arr[pointer] = temp;

		}

}

bool compare( struct element first , struct element second){

	return first.value < second.value;
}
	

int main(){

	int N;

	scanf("%d", &N);

	struct element Arr[N];

	for(int i = 0 ; i < N; i++){

		scanf("%d%s", &Arr[i].value, Arr[i].name);
		Arr[i].id = i + 1;
	}

	insertionSort(Arr, N);

	for(int i = 0; i < N; i++){


		if( Arr[i].id <= N/2)
			printf("- ");
		else
			printf("%s ",Arr[i].name);
		

	}

	printf("\n");
	

}
