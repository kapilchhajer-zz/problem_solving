//http://www.spoj.com/problems/BALLOT/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	long int cities, machines, ballot, highest;

	scanf("%ld %ld", &cities, &machines);

	while( cities != -1 && machines != -1){

		long int population[cities],start,end, mid, min;
	
	
		highest = 0;
		for( int i = 0; i < cities; i++){
			scanf("%ld", population + i);
			if( population[i] > highest)
				highest = population[i];
		}

		min = highest;
		start = 0;
		end = highest;

		while( start <  end){

			ballot = 0;
			
			mid = (start + end) / 2;

			for( int j = 0; j < cities; j++){

				if( mid >= population[j] )
					ballot++;
				else{

					ballot = ballot + population[j] / mid;
				
					if( population[j] % mid)
						ballot++; 
				}
			}

			if( ballot == machines && min > mid){
				min = mid;
				end = mid - 1;
			}
			else if( ballot <= machines)
				end = mid - 1;
			else{
				start = mid + 1;
			}
		}

		printf("%ld\n",min);
	
		scanf("%ld %ld", &cities, &machines);
	}

	return 0;
}
