
#include<iostream>
#include<cstdio>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        
        int result = 0;

	for(int i = 0; i < n; i++)
		result = result ^ A[i];

	
	return result;
	
    }
};


int main(){

	int arr[] = {5 , 7 , 6, 1 , 2, 5, 6, 2 ,7};

	Solution s;
	
	cout<<s.singleNumber(arr, 9)<<endl;

	return 0;
}
