//http://www.spoj.com/problems/BALLOT/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	long int cities, machines, ballot, highest;

	scanf("%ld %ld", &cities, &machines);

	while( cities != -1 && machines != -1){

		long int population[cities],start,end, mid;
	
	
		highest = 0;
		for( int i = 0; i < cities; i++){
			scanf("%ld", population + i);
			if( population[i] > highest)
				highest = population[i];
		}

		start = 0;
		end = highest;

		while( start <=  end){

			ballot = 0;
			
			mid = (start + end) / 2;

			for( int j = 0; j < cities; j++){


					ballot = ballot + population[j] / mid;
				
					if( population[j] % mid)
						ballot++; 
			}

			if( ballot >  machines )
				start = mid + 1;
			
			else
				end = mid - 1;
		}
		

		printf("%ld\n",start);
	
		scanf("%ld %ld", &cities, &machines);
	}

	return 0;
}
