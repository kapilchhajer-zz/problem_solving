//http://www.spoj.com/problems/GCPC11C/

#include<iostream>
#include<cstdio>
#include<stack>
#include<list>

using namespace std;

class Graph{

	public :

		int V, *inDegree;
		list<int> *adj;

		Graph( int v){
	
			this->V = v;
			inDegree =  new int[V + 1];
			adj = new list<int>[V + 1];

			for( int i = 0; i <= V; i++)
				inDegree[i] = 0;
		}

		void addEdge( int tail, int head);
		int topologicalUtil( int v, bool visited[], stack<int> &stck);
		int topologicalSort( stack<int> &stck);
			
};


void Graph :: addEdge( int tail, int head){

	adj[tail].push_back(head);
}

int Graph :: topologicalUtil(int v, bool visited[], stack<int> &stck){

	visited[v] = true;
	int cycle = 0,temp = 0;

	list<int> :: iterator  it;

	for( it = adj[v].begin(); it != adj[v].end(); it++)
		inDegree[*it]--;
	
	for( it = adj[v].begin(); it != adj[v].end(); it++){	

		//printf(" visited : %d node: %d indegree : %d\n",visited[*it], *it, inDegree[*it]);
		if( visited[*it] == false && inDegree[*it] == 0){
			cycle = topologicalUtil( *it , visited , stck);
			temp++;

		}
			
	}
	stck.push(v);


	if( temp >= 2){
		cycle = 2;
	}
	return cycle;
}

int Graph :: topologicalSort(stack<int> &stck){

	bool *visited = new bool[V + 1];
	int j = 1, status = 0;

	for( int i = 0; i <= this->V ; i++)
		visited[i] = false;

	for( int i = 1; i <= this->V; i++){

		
		if( visited[i] == false && this->inDegree[i] == 0){
			
			int cycle = topologicalUtil( i , visited , stck);
			
			if( j == 2 || cycle == 2){
				status = 1;
			}
			j++;

		}
	}

	for(int i = 1; i <= this->V; i++)
		if(visited[i] == false){
			status = 2;	
		}	
	return status;
}

int main(){

	int testCases, vertices , edges, end, start;

	scanf("%d", &testCases);

	while( testCases-- ){

		scanf("%d %d", &vertices, &edges);
		
		Graph g = Graph(vertices);

		for( int i = 0; i < edges; i++){

			scanf("%d %d", &end, &start);
			g.addEdge(end, start);
			g.inDegree[start]++;
		}
		
		if( vertices == 1){

			printf("1\n");
			continue;
		}
		stack<int> Stack;
		
		int status =  g.topologicalSort(Stack); 

		if( status == 2 ){
			printf("recheck hints\n");
			continue;
		} 
		else if( status == 1){
			printf("missing hints\n");
			continue;
		}

		while( !Stack.empty() ){
			
			printf("%d ",Stack.top());
			Stack.pop();
		}
	
		printf("\n");
	}

	return 0;
}
