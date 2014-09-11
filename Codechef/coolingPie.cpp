#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main(){

	int testCases,N,temp;
	map<int, int> pies, coolingRack;
	map<int, int> :: iterator  itPies,itCoolingRack;

	scanf("%d",&testCases);
	
	while(testCases--){
		
		scanf("%d",&N);
		
		// Next Two For Loops are taking input pie and cooling rack wieght, Inserted into pies and coolingRack map structure
		for(int i = 0; i < N; i++){
			scanf("%d",&temp);
			itPies = pies.find(temp);

			if(itPies == pies.end())
				pies[temp] = 1;
			else
				pies[temp] = pies[temp] + 1;
		}

		for(int i = 0; i < N; i++){
			scanf("%d",&temp);
			itCoolingRack = coolingRack.find(temp);

			if(itCoolingRack == coolingRack.end())
				coolingRack[temp] = 1;
			else
				coolingRack[temp] = coolingRack[temp] + 1;
		}
		
		itPies = pies.begin();
		itCoolingRack = coolingRack.begin();
		int count = 0;

		while(itPies != pies.end() and itCoolingRack != coolingRack.end()){
		
			if(itPies->first <= itCoolingRack->first){
				if(itPies->second <= itCoolingRack->second){
					count = count + itPies->second;
					itCoolingRack->second = itCoolingRack->second - itPies->second;
					itPies++;
				}
				else{
					count = count + itCoolingRack->second;
					itPies->second = itPies->second - itCoolingRack->second;
					itCoolingRack++;
				}
			}
			else{
				itCoolingRack++;
			}

		}
		
		printf("%d\n",count);
		pies.clear();
		coolingRack.clear();
	}
	
	return 0;
}
