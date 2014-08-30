//http://www.spoj.com/SPOJ/problems/BWIDOW/

#include<cstdio>

typedef long long ll;


int main(){

	int testCases, num, index, counter;

	scanf("%d", &testCases);

	while(testCases--){

		register ll maxInner, maxOuter, secondMaxOuter, inRadius, outRadius;

		maxInner = maxOuter = secondMaxOuter = index = counter = 0;

		scanf("%d", &num);
	
		while(num--){

			index++;
			scanf("%lld %lld", &inRadius, &outRadius);

			if( maxInner < inRadius){
				maxInner = inRadius;
				counter = index;
			}

			if(maxOuter <= outRadius){
		
				secondMaxOuter = maxOuter;
				maxOuter = outRadius;
			}
			else if( secondMaxOuter < outRadius){

				secondMaxOuter = outRadius;
			}

		}

		if( maxInner > secondMaxOuter)
			printf("%d\n",counter);
		else
			printf("-1\n");

	}

	return 0;
}
