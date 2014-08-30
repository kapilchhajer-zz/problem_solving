//http://www.spoj.com/problems/CANDY2/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

struct record
{
	int index;
	long long int value;
};

bool myFunction(struct record first, struct record second){

	return first.value < second.value ;
}


int main(){

	int N;
	long long int totalChocolate = 0, totalStrawberry = 0, totalBanana = 0;
	scanf("%d", &N);

	struct record chocolate[N], strawberry[N], banana[N];

	for(int i = 0; i < N; i++){

		scanf("%lld%lld%lld", &chocolate[i].value, &strawberry[i].value, &banana[i].value);
		chocolate[i].index = strawberry[i].index = banana[i].index = i;
		
		totalChocolate += chocolate[i].value;
		totalStrawberry += strawberry[i].value;
		totalBanana += banana[i].value;
	}

	for( int i = 0; i < N; i++){

		chocolate[i].value = totalChocolate - chocolate[i].value;
		strawberry[i].value = totalStrawberry - strawberry[i].value;
		banana[i].value = totalBanana - banana[i].value;
	}

	sort(chocolate, chocolate + N, myFunction);
	sort(strawberry, strawberry + N, myFunction);
	sort(banana, banana + N, myFunction);



	int p = 0, q = 0, r = 0;

	long long int sum, min = LLONG_MAX;

	for( int i = 0; i < 3; i++){

		for( int j = 0; j < 3; j++){


			for( int k = 0; k < 3; k++){
				
				sum = chocolate[i].value + strawberry[j].value + banana[k].value;

			if(sum < min && chocolate[i].index != strawberry[j].index && strawberry[j].index != banana[k].index && banana[k].index != chocolate[i].index){
					min = sum;
					p = i;
					q = j;
					r = k;
				}
			}
		
		}
	}

	printf("%d\n%d\n%d\n", chocolate[p].index, strawberry[q].index, banana[r].index);
	return 0;
}
