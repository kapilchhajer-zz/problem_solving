//https://www.hackerrank.com/challenges/countingsort1

#include<iostream>
#include<cstdio>

using namespace std;



int main(){

	int N, num, arr[100] = {0};


	scanf("%d", &N);

	while(N--){

		scanf("%d", &num);
		arr[num]++;
	}	

	for(int i = 0; i < 100; i++)
		printf("%d ",arr[i]);

	printf("\n");

	return 0;
}
