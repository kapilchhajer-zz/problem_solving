//http://www.spoj.com/problems/SANTA1/

#include<utility>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>

#define sllu(j) scanf("%llu",&j)
typedef unsigned long long int llu;
using namespace std;

int main(){

	char ch,name[1000];
	llu entries,productivity, seniority, result = 0, add, sub,prev,curr,next;
	map<string, pair<llu , llu> > strmap;
	map<string, pair<llu , llu> > :: iterator mapIt;
	multiset< pair<llu, llu> > store;
	multiset< pair<llu , llu> >::iterator itCurr, itPrev, itNext;

	sllu(entries);
	result = 0;

	while(entries--){


		scanf(" %c",&ch);
		scanf("%s",name);

		if( ch == 'A'){
	
			sllu(seniority);
			sllu(productivity);
	
			strmap[name] = pair<llu , llu> (seniority , productivity);
			store.insert( pair<llu, llu>( seniority , productivity));
				
			itCurr = itPrev = store.lower_bound(pair<llu , llu>(seniority , productivity));
			itNext = store.upper_bound(pair<llu , llu>(seniority , productivity));
		
			curr = itCurr->second;

			if( itNext == store.end())
				next = 0;
			else
				next = itNext->second;

			if( itPrev == store.begin())
				prev = 0;
			else 
				prev = (--itPrev)->second;
		
			add = (prev + next) *curr; 
			sub =  prev * next;
			result = result + add - sub;
		}
		else{
			mapIt = strmap.find(name);	
			itCurr = itPrev = store.lower_bound(mapIt->second);
			itNext = store.upper_bound(mapIt->second);
			
			curr = itCurr->second;

			if( itNext == store.end())
				next = 0;
			else
				next = itNext->second;

			if( itPrev == store.begin())
				prev = 0;
			else 
				prev = (--itPrev)->second;
			
			add = prev * next;
			sub = curr * (prev + next);	
			result = result + add - sub;

			strmap.erase(mapIt);
			store.erase(itCurr);
		}

		printf("%lld\n",result);
	}		

	return 0;
}
