//http://www.spoj.com/problems/BLINNET/

#include<iostream>
#include<cstdio>
#include<utility>
#include<set>
#include<vector>
#include<cstring>

#define si(a) scanf("%d", &a);
#define sdi(a,b) scanf("%d %lld", &a, &b);

using namespace std;

struct util{

	int rank,parent;
} mem[10001];


int findParent(int index){

	while( index != mem[index].parent)
		index = mem[index].parent;

	return index;
}

void Union(int x, int y){


	int xRoot, yRoot;

	xRoot = findParent(x);
	yRoot = findParent(y);

	if( mem[xRoot].rank < mem[yRoot].rank ){

		mem[xRoot].parent = yRoot;
		mem[yRoot].rank++;
	}
	else{ /* in case of xRoot greater same as before and equal u need to make parent of other here we will make xRoot as parent */

		mem[yRoot].parent = xRoot;
		mem[xRoot].rank++;
	}

}


int main(){

	int testCases, noOfCities, dest, entries;
	long long wt;
	char name[100];

	si(testCases);

	while(testCases--){

		si(noOfCities);
		set< pair<long long int, pair<int,int>  > > graph;
		pair<long long int, pair<int, int> > element;
		pair<int,int> inter;
		
		for(int i = 0; i < 10001; i++){
			
			mem[i].rank = 0;
			mem[i].parent = i;	
		}

		for( int i = 1; i <= noOfCities; i++){
			
			scanf("%s", name);
			si(entries);
			for( int j = 0; j < entries; j++){
			
				sdi(dest, wt);
			
				if(dest > i ){

					inter.first = i;
					inter.second = dest;
					element.first = wt;
					element.second = inter;
					graph.insert(element);
				}
					
			}
		}


		set< pair<long long int, pair<int,int> > >::iterator it;
		pair<int,int> myPair;
		long long int total = 0, count = 1;
		int x, y;

		for( it = graph.begin(); it != graph.end(); it++){

			myPair = it->second;
		
			 
			x = findParent(myPair.first);
			y = findParent(myPair.second);

			if(x == y)
				continue;

			total = it->first + total;
			count++;
			Union(myPair.first , myPair.second);
			
			if(count == noOfCities)
				break;
		}

		cout<<total<<endl;
	}

	return 0;
}
