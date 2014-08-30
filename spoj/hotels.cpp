//http://www.spoj.com/problems/HOTELS/

#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main(){

	long int N, value, temp, max = 0, count = 0;
	queue<long int> myqueue;

	scanf("%ld %ld", &N, &value);

	for(int i = 0; i < N; i++){

		scanf("%ld", &temp);
		
		count = count + temp;
		
		myqueue.push(temp);	
		
		while(!myqueue.empty() && count > value){
		
			count = count - myqueue.front();
			myqueue.pop();
		}

		if(count > max)
			max = count;


		
	}

	printf("%ld\n",max);
	return 0;
}
