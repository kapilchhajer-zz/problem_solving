//http://www.codechef.com/problems/MARCHA1

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int testCases,N,coin[22],amount,curr,prev;
	bool result[2][20001];
	
	scanf("%d",&testCases);

	while(testCases--){
	
		scanf("%d",&N);
		scanf("%d",&amount);
	
		for(int i = 1; i <= N; i++)
			scanf("%d",coin+i);
		
		curr = 0;
		prev = 1;
		result[prev][0] = true;
		result[curr][0] = true;
  
		for(int i = 1; i <= amount ; i++){
			result[curr][i] = false;
			result[prev][i] = false;
		}
	
		for(int i = 1; i <= N ; i++){
			
			curr = curr ^ 1;
			prev = prev ^ 1;
			
			for(int j = 1; j <= amount; j++){
				
				result[curr][j] = result[prev][j] || ( (j-coin[i] >= 0) && result[prev][ j - coin[i] ] == true );
			}
		}
	
		if( result[curr][amount] == true)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}

