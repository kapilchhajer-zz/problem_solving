//https://www.hackerrank.com/challenges/countingsort2

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
		for(int j = arr[i]; j > 0; j--)
			printf("%d ",i);


	printf("\n");

	return 0;
}
