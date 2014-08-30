//http://www.spoj.com/problems/SHPATH/

#include<iostream>
#include<cstdio>
#include<map>
#include<climits>
#include<list>
#include<algorithm>

using namespace std;


class Graph{

	public:
		long int vertex, **path, **shortestPath;
		Graph(int V);
	        void addWeight(int V, int W, int weight);		
		int minDistance(int source, bool spath[]);
		long int Dijkstra(int source, int destination);
};


Graph::Graph(int V){

	vertex = V;
	path = new long int *[V + 1];
	shortestPath = new long int*[V + 1];

	for( int i = 0 ; i <= V; i++){
		path[i] = new long int[V + 1];
		shortestPath[i] = new long int[V + 1];
		fill_n( path[i] , V + 1, LONG_MAX);
		fill_n(shortestPath[i], V + 1, LONG_MAX);
	}
}
	


void Graph::addWeight(int V, int W, int weight){

	path[V][W] = weight;
	
}

int Graph::minDistance(int source, bool spath[]){

	long int min = LONG_MAX, index = -1;
	
	for(int i = 1; i <= vertex; i++){

		if( spath[i] == false  && shortestPath[source][i] < min){
			
			min = shortestPath[source][i];
			index = i;
		} 
	}

	return index;
}

long int Graph::Dijkstra(int source, int destination){
	
	if(shortestPath[source][destination] != LONG_MAX)
		return shortestPath[source][destination];

	bool spath[vertex + 1];
	int  changer[vertex + 1];

	int j = 0;

	for( int i = 1; i <= vertex; i++){

		if(shortestPath[source][i] != LONG_MAX){
			spath[i] = true; 
			changer[i] = 0; 
		}
		else{
			changer[i] = source;
			spath[i] = false;
			j++;
		}
	}

	for( int j = 1; j <= vertex; j++){

		if( spath[j]){

			long int weight = shortestPath[source][j];
			for( int i = 1; i <= vertex; i++){
				if(path[j][i] != LONG_MAX && weight + path[j][i] < shortestPath[source][i]){
						shortestPath[source][i] = weight + path[j][i];
						changer[i] = j;
				}

			}
		}
	}
	changer[source] = 0;
	shortestPath[source][source] = 0;
	list<long int> :: iterator it;

	for( int k = 0; k <  j; k++){
		
		int u = minDistance(source, spath);
		
		if( u == -1)
			continue;

		long int weight = shortestPath[source][u];	
		spath[u] = true;

		for( int i = 1; i <= vertex; i++){

			if(spath[i] == false && path[u][i] != LONG_MAX && weight + path[u][i] < shortestPath[source][i]){
					shortestPath[source][i] = weight + path[u][i];
					changer[i] = u;
			}
		}
	}
/*	
	for( int j = 1; j <= vertex; j++)
		printf("%d ",changer[j]);

	printf("\n");
	for( int j = 1; j <= vertex; j++)
		printf("%ld ",shortestPath[source][j]);

	printf("\n");
*/
	for( int j = 1; j <= vertex; j++){
		if( changer[j] == -1)
			continue;

		int k;
		k = changer[j];

		while( k != 0){
			
			shortestPath[j][k] = shortestPath[source][j] - shortestPath[source][k];
			shortestPath[k][j] = shortestPath[j][k];
			//printf("source : %d destination : %d %ld\n",j,k,shortestPath[j][k]);
			k = changer[k];
		}

		shortestPath[j][source] = shortestPath[source][j];	
	}
	
	return shortestPath[source][destination];
}

int main(){

	int StestCases, RtestCases, cities, neighbourCities, endCity, cost, source, destination;
	string name, src, dest;
	map<string, int> cityMapping;
	map<string, int> :: iterator it;

	scanf("%d", &StestCases);

	while( StestCases-- ){
		scanf("%d", &cities);
		Graph *g = new Graph(cities);
	
		for( int i = 1; i <= cities; i++){

			cin>>name;
			cityMapping[name] = i;

			scanf("%d", &neighbourCities);

			for( int j = 0; j < neighbourCities; j++){
		
				scanf("%d %d", &endCity, &cost);
				g->addWeight( i , endCity, cost);	
			
			}
		}

		scanf("%d", &RtestCases);

		for( int i = 0; i < RtestCases; i++){

			cin>>src;
			cin>>dest;
			it = cityMapping.find(src);	
			source = it->second;
			it = cityMapping.find(dest);	
			destination = it->second;

			printf("%ld\n", g->Dijkstra(source , destination));
		}
		
		cityMapping.clear();
	}

	return 0;
}
