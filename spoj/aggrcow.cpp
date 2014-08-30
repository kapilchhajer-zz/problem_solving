//http://www.spoj.com/problems/AGGRCOW/

#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	int testCases, N, C;
	
	scanf("%d", &testCases);

	while( testCases-- ){

		scanf("%d %d", &N, &C);

		long int arr[N], avg;

		for(int i = 0 ; i < N ; i++)
			scanf("%ld", arr + i);

		sort(arr , arr + N);
		C--;
		avg = (arr[N - 1] - arr[0]) / C;

		for( int i = 0; i < N ; i++)
			arr[i] = arr[i + 1] - arr[i];

		N--;

		long int start = 1, end = avg, sum,largestMin = 1, partition;

		while( start < end ){


			long int mid = (start + end) / 2;
			
			partition = sum = 0;

			for( int j = 0 ; j < N ; j++){
					
				sum = sum + arr[j];
		
				if( sum >=  mid){
				
					partition++;
					sum = 0;
				}
			}

			if(partition >= C){
				largestMin = mid;
				start = mid + 1;
			} 
			else{

				end = mid;
			}			

		}


		printf("%ld\n", largestMin);
	}	

	return 0;
}
