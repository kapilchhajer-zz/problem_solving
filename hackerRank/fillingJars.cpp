//https://www.hackerrank.com/challenges/filling-jars

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	
	long int size, num;
	long long int sum = 0, A, B, K;

	scanf("%ld %ld", &size, &num);

	for( long int i = 0; i < num; i++){

		scanf("%lld %lld %lld", &A, &B, &K);

		sum = sum + (B - A + 1) * K;
	}

	printf("%lld\n", sum / size);
	return 0;
}
