//http://www.spoj.com/problems/XMEN/

#include<iostream>
#include<cstdio>

using namespace std;

void binary( int result[] , int size, int element){

	int start = 0, end = size - 1, mid;

	while( start <= end){

		mid =  (start + end) / 2;
	
		if( result[mid - 1] < element && result[mid] > element){

			result[mid] = element;
			break;
		}
		
		if(result[mid] < element)
			start = mid + 1;
		else
			end = mid - 1;
	}

}

int main(){

	int testCases, N;

	scanf("%d", &testCases);

	while(testCases--){

		scanf("%d", &N);

		int first[N + 1], second[N],result[N], length = 1,temp;

		for(int i = 1; i <= N; i++){
			scanf("%d", &temp);
			first[temp] = i;
		}

		for(int i = 0; i < N; i++)
			scanf("%d", second + i);

		result[0] = first[second[0]];

		for(int i = 1; i < N; i++){
	
			temp = first[second[i]];

			if( result[length - 1] < temp){
			
				result[length] = temp;
				length++;
			}
			else{

				binary(result, length, temp);
			}

		}

		printf("%d\n", length);
		
	}
	return 0;	
}
