//http://www.spoj.com/problems/ADV04L/

#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

int main(){

	set< unsigned long long int> fibSeries;
	set<unsigned long long int> :: iterator it;
	unsigned long long int prev = 1, present = 2, temp, num, result,testCases;
	
	fibSeries.insert(1);
	int i = 73;

	while( i-- ){
	
		fibSeries.insert(present);
		temp = present;
		present = present + prev;
		prev = temp;
	}

	scanf("%llu", &testCases);

	while(testCases--){
	
		scanf("%llu", &num);
		result = 0;

		while( num != 0){
			
			it = fibSeries.lower_bound(num);
	
			if( *it > num){
				
				result = result + *it; 
				num = num - *(--it);
			}
			else{

				num = num - *it;
				result = result + *(++it); 


			}
		}

		printf("%llu\n",result);
	}
	return 0;
}
