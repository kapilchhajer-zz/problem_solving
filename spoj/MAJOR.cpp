//http://www.spoj.com/problems/MAJOR/

#include<iostream>
#include<cstdio>

using namespace std;


bool isMajorityElement(int *Arr, int N, int maj_element){

	int count = 0;
	
	for(int i = 0; i < N; i++)		
		if( maj_element == Arr[i])
			count++;

	if( count > N/2)
		return true;
	else
		return false;

}

int majorityCandidate(int *Arr, int N){


	int maj_index = 0, count = 1;

	for(int i = 1; i < N; i++){

		if(Arr[maj_index] == Arr[i])
			count++;
		else
			count--;

		if(count == 0){
	
			maj_index = i;
			count = 1;
		}
	}

	return Arr[maj_index];
}

void printMajorityElement(int *Arr, int N){

	int maj_element = majorityCandidate(Arr, N);

	if(isMajorityElement(Arr, N, maj_element))
		printf("YES %d\n",maj_element);
	else
		printf("NO\n");
}


int main(){

	int testCases, N;

	scanf("%d", &testCases);


	while(testCases--){

		scanf("%d", &N);
		
		int Arr[N];

		for(int i = 0; i < N; i++)
			scanf("%d", Arr + i);

		printMajorityElement(Arr, N);
	}

	
	return 0;
}
