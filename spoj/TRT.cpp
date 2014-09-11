//http://www.spoj.com/SPOJ/problems/TRT/

#include<iostream>
#include<cstdio>
#define ARR_SIZE 2000

using namespace std;

int main(){

	long long int N, Arr[ARR_SIZE];
	long long int sum_array[ARR_SIZE], dp_array[ARR_SIZE], limit;
	
	scanf("%lld", &N);
	scanf("%lld", &Arr[0]);

	dp_array[0] = sum_array[0] = Arr[0];
	
	for(int i = 1; i < N; i++){
		scanf("%lld", Arr + i);
		sum_array[i] =  Arr[i] + sum_array[i - 1];
		dp_array[i] = Arr[i];
	}

	long long int max1, max2;

	for(int i = 1; i < N; i++){

		limit = N - i;
		
		for( int j = 0; j < limit; j++){

			if( j == 0){
				max1 = dp_array[j] + Arr[j + i] + sum_array[j + i - 1];
				max2 = dp_array[j + 1] + Arr[j] + sum_array[j + i] - sum_array[j]; 
			}
			else{

				max1 = dp_array[j] + Arr[j + i] + sum_array[j + i - 1] - sum_array[j - 1];
				max2 = dp_array[j + 1] + Arr[j] + sum_array[j + i] - sum_array[j]; 
			}

			if(max1 > max2)
				dp_array[j] = max1;
			else
				dp_array[j] = max2;
		}
	}

	printf("%lld\n",dp_array[0]);	
	
	return 0;
}
