//http://www.spoj.com/problems/IOIPALIN/

#include<iostream>
#include<cstdio>

#define si(N) scanf("%d", &N)
#define ss(K) scanf("%s", K)
#define LENGTH 5001

using namespace std;

int max(int A, int B){
	
	return A > B ? A : B;
}

int main(){

	int length;
	char str[LENGTH + 1];

	si(length);
	ss(str);

	int LCS[2][ length + 1], prev = 1, curr = 0, temp;

	for( int i = 0; i <= length; i++)
		LCS[prev][i] = LCS[curr][i] = 0;
	

	for( int i = 0; i < length; i++){


		for(int j = length - 1, k =1; j >= 0; j--, k++){

			if(str[i] == str[j])
				LCS[curr][k] =  LCS[prev][k - 1] + 1;

			else
				LCS[curr][k] = max( LCS[curr][k - 1] , LCS[prev][k]);
			
		
		}
	

		temp = curr;	
		curr = prev;
		prev = temp;
	}
 
	printf("%d\n",length - LCS[prev][length]);
	return 0;
}
