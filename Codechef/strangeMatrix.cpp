#include<iostream>
#include<map>
#include<cstdio>
#define gc() getchar_unlocked();

using namespace std;

unsigned long long int read_int() {
	register char c = gc();
	unsigned long long int ret = 0;
	
	while(c<'0' || c>'9') c = gc();
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = gc();
	}	
	
	return  ret;
}

int main()
{

	unsigned long long int M,N,p,row,column,temp;
	map<unsigned long long int ,unsigned long long int> myMap;
	map<unsigned long long int,unsigned long long int>::iterator it;
	
	M = read_int();
	N = read_int();
	p = read_int();

	while(p--){

		row = read_int();
		column = read_int();
		temp = (row - 1) * N  + column ;
		it = myMap.find(temp);
 
		if( it != myMap.end() )
			myMap.at(temp) += 1;
		else
			myMap[temp] = 1;

	}
	
	it = myMap.begin();

	unsigned long long int start,end,result,inc,incKey;
	bool flag;

	for(unsigned long long int i = 1; i <= M; i++){
		flag = false;
		start = (i - 1) * N + 1;
		end   = (i - 1) * N + N;
		result = N - 1;
		inc = 1;

		for( ; it != myMap.end(); it++){
			
			if(flag && it->first <= end)
				continue;

			if(it->first > end){
				if( !(inc == 1 || incKey == end) )
					flag = true;
				break;
			}
		
			if(it->first == start){
				result = result - it->second;
				inc    = it->second;
				incKey = it->first;
				continue;
			}
		
			if( (it->first == incKey+1 && it->second >= inc-1) || inc == 1 ){
				inc = it->second;
				incKey = it->first;
			}
			else{
				flag = true;
			}		

			if(it->first == end)
				result = result + it->second;
		}
		
		if( !(inc == 1 || incKey == end) )
			flag = true;
		
		if(flag)
			printf("-1\n");
		else
			printf("%llu\n",result);

	}

	return 0;
}
