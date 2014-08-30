//http://www.spoj.com/problems/GCPC11J/

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

class Tree{

	public:
		int V,*visited, *inDegree, far, time;
		vector<int> *connected;


		Tree(int V);
		void farthest();		
		void visit(int vertex, int ttl, int visitCount);
};

Tree::Tree(int V){
	this->V = V;
	visited = new int[V];
	inDegree = new int[V];
	time = 0;		
	connected = new  vector<int>[V];
	for(int i = 0; i < V; i++)
		visited[i] = inDegree[i] = 0;
}

void Tree::visit(int vertex, int ttl, int visitCount){

	visited[vertex]++;
	ttl++;
	int size = connected[vertex].size();
	
	for( int i = 0; i < size; i++){		
		if(visited[connected[vertex][i]] == visitCount)
			visit( connected[vertex][i], ttl, visitCount);
	}

	if(ttl > time){

		time = ttl;
		far = vertex;
	}

			
}

void Tree::farthest(){

	int startNode;

	for( int i = 0; i < V; i++)
		if(inDegree[i] == 1){
			startNode = i;
			break;
		}

	
	visit(startNode, -1 , 0);
	time = 0;	
	visit(far, -1, 1);
	
}

int main(){

	int testCases, N, start, end;

	scanf("%d", &testCases);

	while(testCases--){

		scanf("%d", &N);
		Tree *t = new Tree(N);
		N--;

		while(N--){

			scanf("%d %d", &start, &end);		
			t->connected[start].push_back(end);
			t->connected[end].push_back(start);
			(t->inDegree[end])++;
			(t->inDegree[start])++;
	
		}
		t->farthest();

		printf("%d\n", (t->time + 1)/2);
	}
	return 0;
}
