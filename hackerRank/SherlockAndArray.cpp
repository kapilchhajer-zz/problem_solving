//https://www.hackerrank.com/challenges/sherlock-and-array

#include<iostream>
#include<cstdio>

using namespace std;


int main(){

	long int testCases , num;

	scanf("%ld", &testCases);

	while(testCases--){

		scanf("%ld", &num);

		long int A[num], j = num - 1;
		bool flag = false;

		for(int i = 0; i< num; i++)
			scanf("%ld", &A[i]);
	
		
		for(int i = 0; i < j;){
			
			if(A[j] > A[i]){

				A[j] = A[j] - A[i];
				i++;
			}
			else if( A[j] < A[i]){
		
				A[i] = A[i] - A[j];
				j--;		
			}
			else{
				if( i + 2 == j){
					flag = true;
					break;
				}		

				i++;
				j--;
			}
	  	}

		if(flag || num == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
