//https://www.hackerrank.com/challenges/service-lane/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int segments, testCases, start, end, min;

	scanf("%d %d", &segments, &testCases);

	int width[segments];

	for(int i = 0; i < segments; i++)
		scanf("%d", width + i);

	while( testCases-- ){

		min = 4;

		scanf("%d %d", &start, &end);

		for( int i = start; i <= end; i++)
			if( min > width[i])
				min = width[i];

		printf("%d\n", min);
	}
	return 0;
}
