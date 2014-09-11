//http://www.codechef.com/problems/LEPERMUT/


#include<iostream>
#include<cstdio>
#include<climits>
#include<cstdlib>

using namespace std;
int merge(int *A, int begin, int mid, int end){

    int length1,length2,i,j,k;
	int inversions = 0, *left, *right;
	
	length1 = mid - begin + 1;
	length2 = end - mid;
	left = (int *) malloc(sizeof(int) * (length1 ));
	right = (int *) malloc(sizeof(int) * (length2 ));

	for(i = 0; i < length1 ; i++)
		left[i] = A[begin + i];
  
	for(j=0; j < length2 ; j++)
		right[j] = A[mid + 1 + j];
	
	i = j = 0;

	for(k = begin; k <= end; k++){

		if(left[i] > right[j]){
			A[k] = right[j];
			inversions += length1 - i;
          	   	j++;
		}
		else{
			A[k] = left[i];
			i++;
		}	
        
        if(i == length1)
            break;
        if(j == length2)
            break;
	}
    
     while(i != length1){
         k++;
         A[k] = left[i];
         i++;
    }
    
    while(j!=length2){
        k++;
        A[k] = right[j];
        j++;
    }
    
	return inversions;
}
int mergeSort(int *Arr , int begin , int end){

    int N = end - begin + 1;

	if(N == 1) 
		return 0;
	else if(N == 2){
    	if(Arr[begin] <=  Arr[end])
			return 0;
		else{
    	   		 int temp = Arr[begin];
           		 Arr[begin] = Arr[end];
            		 Arr[end] = temp;
           		 return 1;
            
		}
	}
	else{

		int mid = (begin + end) / 2, leftInversion, rightInversion, splitInversion;
	
		leftInversion = mergeSort(Arr, begin, mid);
		rightInversion = mergeSort(Arr, mid + 1, end);
		splitInversion = merge(Arr, begin, mid, end);
		
		return leftInversion + rightInversion + splitInversion;
    } 
}



int main(){

	int testCases;
	scanf("%d",&testCases);

	while(testCases--){
	
		int num,*array,inversion,localInversion = 0;
		scanf("%d",&num);
		
		array = (int *) malloc(sizeof(int) * num);
	
		for(int i = 0; i < num; i++)
			scanf("%d",&array[i]);
		
		for(int i =0; i < num - 1; i++)
			if(array[i+1] < array[i])
				localInversion++;

		inversion = mergeSort(array,0,num-1);

		if(inversion == localInversion)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}

