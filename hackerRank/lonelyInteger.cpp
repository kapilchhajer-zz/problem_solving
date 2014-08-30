//https://www.hackerrank.com/challenges/lonely-integer

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	bool  status[101] = {0};
	int N, temp;
	
	scanf("%d", &N);

	for( int i = 0; i < N; i++){

		scanf("%d", &temp);
		status[temp] = status[temp] ^ true;
	}	

	for( int i = 0; i < 101; i++){

		if( status[i] == true ){
		
			cout<<i<<endl;	
			break;
		}
	}

	return 0;
}
