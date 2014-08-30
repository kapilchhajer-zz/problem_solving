//https://www.hackerrank.com/challenges/countingsort3

#include<iostream>
#include<cstdio>

using namespace std;



int main(){

	int N, num, arr[100] = {0};
	char s[1000];

	scanf("%d", &N);

	while(N--){

		scanf("%d %s", &num, s);
		arr[num]++;
	}	

	printf("%d ",arr[0]);
	for(int i = 1; i < 100; i++){
		arr[i] = arr[i - 1] + arr[i];
		printf("%d ",arr[i]);
	}

	printf("\n");

	return 0;
}
