//http://www.spoj.com/problems/CRAN02/

#include<cstdio>
#include<algorithm>
#include<climits>

#define SIZE 1000001

using namespace std;


int main(){

	int testCases;
	long long int N, num[SIZE], sum, temp, count;

	scanf("%d", &testCases);

	while( testCases-- ){

		sum = 0;
		scanf("%lld", &N);

		for(int i = 0; i < N; i++){
			scanf("%lld", &temp);
			sum = sum + temp;
			num[i] =  sum;
		} 
		
		sort(num, num + N);

		temp = LONG_MAX;
		count = sum = 0;

		for(int i = 0; i < N; i++){
	
			if( temp != num[i]){

				if(temp == 0)
					count++;

				sum = sum + count * (count + 1) / 2;
				temp = num[i];
				count = 0;
			
			}
			else{

				count++;
			}
			
		}
		
		if(temp == 0)
			count++;

		sum = sum + count * (count + 1) / 2;

		printf("%lld\n", sum);
	}

	return 0;
}
