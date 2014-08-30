#include<iostream>
#include<cstdio>

using namespace std;


int main(){


	int testCases;
	char in[100007];

	scanf("%d", &testCases);

	while(testCases--){

		long int sum = 0, length = 0, y;
		float 	yFloat;
		scanf("%s", in);
		
		for(int i = 0; in[i] != '\0'; i++){
			sum = sum + in[i] - '0';
			length++;
		}

		yFloat = ((length * 7.0) - sum) / 3.0;
		y = yFloat;

		if( y == yFloat && y <= length && y >= 0)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
