//https://www.hackerrank.com/challenges/halloween-party

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	long int testCases, cuts, rows, columns;

	scanf("%ld", &testCases);

	while( testCases-- ){	

		scanf("%ld", &cuts);

		rows = cuts / 2;
		columns = cuts - rows;


		printf("%ld\n", rows * columns);
		
	
	}
	return 0;
}
