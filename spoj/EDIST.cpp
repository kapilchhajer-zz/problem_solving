//www.spoj.com/problems/EDIST

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
//http://www.spoj.com/problems/EDIST/

#include<iostream>
#include<cstdio>

using namespace std;

int  mem[2001][2001];


int min( int A , int B, int C){

		if( A <= B && A <= C)
			return A;
		else if( B <= C && B <= A)
			return B;
		else
			return C;

}

int main(){

	int testCases, lengthA, lengthB;
	char A[2001], B[2001];

	scanf("%d", &testCases);

	while(testCases--){

		scanf("%s", A);
		scanf("%s", B);

		lengthA = strlen(A);
		lengthB = strlen(B);
		

		mem[0][0] = 0;

		for( int i = 1; i <= lengthA; i++)
			mem[i][0] = i;
	
		for( int i = 1; i <= lengthB; i++)
			mem[0][i] = i;

		
		int temp;

		for( int i = 1; i <= lengthA; i++){
					
			for( int j = 1; j <= lengthB; j++){
	
				temp = mem[i - 1][j - 1] + 1;	
				
				if( A[i - 1] == B[j - 1])
					temp--;

							
				mem[i][j] = min(temp , mem[i][j - 1] + 1, mem[i - 1][j] + 1); 

			} 

		}

		printf("%d\n", mem[lengthA][lengthB]);	
		
	}
	return 0;
}	
