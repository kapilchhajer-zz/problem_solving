//https://www.hackerrank.com/challenges/gem-stones

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	
	int N, alphaCount[26], count = 0;
	
	scanf("%d", &N);

	char str[N][100];

	for( int i = 0; i < 26; i++)
		alphaCount[i] = -1;

	for( int i = 0; i < N; i++){

		scanf("%s", str[i]);
		
		for(int j = 0; str[i][j] != '\0'; j++)
			if( alphaCount[str[i][j] - 'a'] == i - 1)		
				alphaCount[str[i][j] - 'a'] = i;		
	
	}

	N--;

	for( int i = 0; i < 26; i++)
		if( alphaCount[i] == N)
			count++;
	
	printf("%d\n",count);

	return 0;
}
