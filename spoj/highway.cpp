//http://www.spoj.com/problems/HIGHWAYS/

#include<queue>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>

#define MAX 100001

using namespace std;

struct Edge{
	long int vertex, cost;
	
} ;

bool Compare(struct Edge a, struct Edge b) {

	return a.cost < b.cost;
}





int main(){

	int testCases, N, M, S, E, X, Y;
	long int C;

	
	scanf("%d", &testCases);

	while(testCases--){

 		vector <Edge>  map[MAX];
	
		scanf("%d %d %d %d", &N, &M, &S, &E);

		for(int i = 0; i < M; i++){
		
			scanf("%d %d %ld", &X, &Y, &C);
			map[X].push_back( (Edge) { Y , C } );
			map[Y].push_back( (Edge) { X , C } );
		}
		
		queue< Edge > priority_queue;
		struct Edge node, temp;
		int V, vectorLength;
		long int minCost[MAX] = {0};
		minCost[S] = 1;
		priority_queue.push( (Edge) {S,1} );	 		
 			
		while( !priority_queue.empty() ){

			node = priority_queue.front();
			V = node.vertex;
			C = minCost[V];

			priority_queue.pop();

			vectorLength = map[V].size();

			for(int i = 0; i < vectorLength ; i++){		
	
				temp = map[V][i];
				temp.cost = temp.cost + C;
				
				if( temp.cost < minCost[temp.vertex] || minCost[temp.vertex] == 0 ){
				
					minCost[temp.vertex] = temp.cost;
					priority_queue.push(temp);
				} 
	
			}	

		}

		if(minCost[E] != 0)
			printf("%ld\n", minCost[E] - 1 );
				
		else
			printf("NONE\n");
	}
	return 0;
}
