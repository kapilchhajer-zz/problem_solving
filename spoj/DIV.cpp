//http://www.spoj.com/problems/DIV/

#include<iostream>
#include<cstdio>

#define MAX 1000000

using namespace std;

bool cube[MAX] = {0};

int main(){

	int div[MAX] = {0}, k = 0,temp;
	
	for( int i = 1; i < 101; i++){
		temp = i * i * i;
		cube[temp] =  true;
	}
	div[1] = 1;
	for( int i = 2; i < MAX; i++){
		div[i]++;

		for( int j = i; j < MAX; j = j + i)
			div[j]++;


		temp = div[i];
		if(div[temp] == 4 && !cube[temp]){
				k++;
				if(k ==  9){
					printf("%d\n",i);
					k = 0;	
				}
	
		}
		
	}

	return 0;
}
