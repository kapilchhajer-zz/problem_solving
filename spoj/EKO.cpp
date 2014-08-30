//http://www.spoj.com/problems/EKO/

#include<iostream>
#include<cstdio>
#include<climits>

#define SIZE 1000000

using namespace std;


int main(){

	long int N, height[SIZE], wood;
	long long int sum = 0,start = 0, end = 0, mid, result, t = LONG_MAX;


	scanf("%ld", &N);
	scanf("%ld", &wood);
	

	for(int i = 0; i < N; i++){
		scanf("%ld",height + i);

		if( end < height[i])
			end = height[i];
	}

	register long int temp;
	while(start <= end ){

		mid = (start + end) / 2;
		sum = 0;

		for( int i =  0; i < N; i++){

			temp = height[i] - mid;

			if( temp > 0)
				sum = sum + temp;

		}						
		
		if(sum > wood){
				if( t > sum){
					result = mid;
					t = sum;
				}	
			start = mid + 1;
		}
		else if(sum < wood)
			end = mid - 1;
		else{
			result = mid;
			t = sum;
			break;
		}
	
	}
	printf("%lld\n",result);
	

	return 0;
}
