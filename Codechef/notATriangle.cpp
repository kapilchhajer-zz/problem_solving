//http://www.codechef.com/problems/NOTATRI

#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){

	int N, start, end;;
	long int arr[2002],value;
	long long int count;

	scanf("%d",&N);

	while(N != 0){

		count = 0;

		for(int i = 0; i < N; i++)
			scanf("%ld",arr+i);

		sort(arr,arr+N);

		for(int i = N - 1; i >= 2; i--){

			start = 0;
			end = i - 1;
			value = arr[i];

			while(start < end){
			
				if( arr[start] + arr[end] < value){
					
					count  = count + end - start;
					start++;
				}	
				else{
					end--;
				}

			}	
		}

		printf("%lld\n",count);
		
		scanf("%d",&N);
	}

	return 0;

}
