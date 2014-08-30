//http://www.spoj.com/problems/APS/

#include<cstdio>
#define MAX 10000001

using namespace std;


long long int result[MAX] = {0};

void fun(){

	result[0] = result[1] = 0;
	result[2] = 2;

	for(long long int i = 3; i < MAX; i = i + 2){
		
		if( result[i] == 0 ){
	
			for( long long int j = i; j < MAX; j = j + i){
				
				if( result[j] == 0)	
					result[j] = i;
			}
			
		}
		
		result[i] = result[i - 1] + result[i];
		result[i + 1] = 2 + result[i];
	}

} 

int main(){

	fun();

	int testCases;
	long int N;

	scanf("%d",&testCases);

	while(testCases--){

		scanf("%ld",&N);
		printf("%lld\n",result[N]);
	}
	return 0;
}
