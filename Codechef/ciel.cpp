//http://www.codechef.com/problems/CIELAB

#include<cstdio>

int main(){

	int A,B;
	scanf("%d %d",&A,&B);
	A = A - B;
	if( A != 1)
		printf("%d\n",A ^1);
	else
		printf("3\n");

	return 0;
}
