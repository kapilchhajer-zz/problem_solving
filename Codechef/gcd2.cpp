//http://www.codechef.com/problems/GCD2	

#include<cstdio>

int rem(int A, char *B){

	int rem = 0, i =0;

	while(B[i] != '\0'){

		rem = rem * 10 + B[i++] - '0';
		rem = rem % A;

	}

	return rem; 

}


int gcd(int A, int B){
	
	if(B == 0)
		return A;
	
	return gcd(B , A % B);

} 

int main(){

	int testCases;
	int A;
	char B[252];

	scanf("%d",&testCases);

	while( testCases-- ){
		
		scanf("%d %s",&A,B);
		
		if(A == 0)
			printf("%s\n",B);
		else
			printf("%d\n",gcd(A,rem(A,B)));
	
	}
	return 0;
}
