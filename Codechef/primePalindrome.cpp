//http://www.codechef.com/problems/PRPALIN

#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){

	long int N,k,root;
	bool palindromeFlag = false,flag = false;
	vector<long int> prime;
	vector<long int>::iterator  it;

	scanf("%ld",&N);
	
	if( N <= 2){
		printf("2\n");	
		return 0;
	}

	if(N % 2 == 0)
		N = N + 1;

	prime.push_back(2);
	k = 3;

	int t = (int)sqrt(N);
	
	while(k <= t){
		
		flag = false;
		root = sqrt(k);
		
		for(it = prime.begin(); *it <= root && it != prime.end(); it++){
			if( k % (*it) == 0){
				flag = true;
				break;
			}
		}
		
		if(flag){
			k = k + 2;
			continue;
		}

		prime.push_back(k);
		k = k + 2;
	}

	while(!palindromeFlag){
	
		flag = false;	
		root = sqrt(N);

		for(it = prime.begin(); *it <= root && it != prime.end() ; it++){
			if( N % (*it) == 0 ){
				flag = true;
				break;
			}		
		}

		if(flag){
			N = N + 2;
			continue;
		}
		prime.push_back(N);

		long int temp = N, num = 0,rem;
	
		while(temp != 0){
					
			rem = temp % 10;
			temp = (temp - rem) / 10;
			num = num * 10 + rem;
		}
				
		if( num == N){
			palindromeFlag = true;
			printf("%ld\n",N);
		}
		
		N = N + 2;
	}
	return 0;
}
