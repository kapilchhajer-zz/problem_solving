//http://www.codechef.com/problems/PCYCLE

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){

	int num,*value,*flag;

	scanf("%d",&num);

	value = (int *) calloc(num+1 , sizeof(int));
	flag  = (int *) calloc(num+1 , sizeof(int));
	
	for(int i = 1; i <= num;i++)
		scanf("%d",value+i);


	int result[8000];
	int j = 0,count = 0,k;
	for(int i = 1; i <= num; i++){

		if( flag[i] == 0){
			count++;
			result[j++] = i;
			k = i;
			flag[i] = 1;

			while(value[k] != i){	
				k = value[k];
				flag[k] = 1;
				result[j++] = k;
			}

			result[j++] = i;
			result[j++] = 0;
		}
	}
	
	result[j++] = -1;
	printf("%d\n",count);
	
	j = 0;
	
	while(result[j] != -1){
		if(result[j] != 0)
			printf("%d ",result[j]);
		else
			printf("\n");
		
		j++;
	}	
	return 0;
}
