//http://www.spoj.com/problems/BUGLIFE/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int main(){

	long int testCases, noOfBugs, noOfInteraction, first, second, scenario = 1;
	
	scanf("%ld", &testCases);

	while(testCases--){
		
		char connection[2001][2001] = {0};
		bool flag = false;
		queue<long int> myqueue;
		int arr[2001] = {0}, st = 1, front, now ;

		scanf("%ld %ld", &noOfBugs, &noOfInteraction);

		while(noOfInteraction--){

			scanf("%ld %ld", &first, &second);
			
			connection[first][second] = 'c';
			connection[second][first] = 'c';
		}

		printf("Scenario #%ld:\n",scenario);
		scenario++;

		for(int i = 1; i < noOfBugs; i++){

			for(int j = i + 1; j <= noOfBugs; j++){ 
		
				if(connection[i][j] != 'c')
					continue;

				myqueue.push(i);
				arr[i] = st;

				st = st + 2;
				while(!myqueue.empty()){

					front = myqueue.front();
					myqueue.pop();
					
					if(arr[front] % 2 == 0)	
						now = arr[front] - 1;
					else
						now = arr[front] + 1;

					for(int k = 1; k <= noOfBugs; k++){

						if(connection[front][k] == 'c'){
				
							connection[k][front] = connection[front][k] = 's';
							myqueue.push(k);
							
							if(arr[k] == 0 )
								arr[k] = now;
							else if(arr[k] != now){
								
								flag = true;
								break;
							}
						}
					}
					
					if(flag)
						break;
				}
			
				if(flag)
					break;
				
			}

			if(flag)
				break;

		}

		if(flag)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
			
	}


	return 0;
}
