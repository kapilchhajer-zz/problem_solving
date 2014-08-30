//https://www.hackerrank.com/challenges/utopian-tree/

#include<cstdio>

using namespace std;

int main(){

	int testCases, initial, cycles;

	scanf("%d", &testCases);

	while( testCases-- ){

		initial = 1;
		scanf("%d", &cycles);

		for( int i = 0; i < cycles; i++)
			initial = i % 2 ? initial + 1 : 2 * initial ;

		printf("%d\n",initial);
	
	}
	return 0;
}
