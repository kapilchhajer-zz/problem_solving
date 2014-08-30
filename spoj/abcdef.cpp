//http://www.spoj.com/problems/ABCDEF/

#include<cstdio>
#include<algorithm>

#define gc() getchar_unlocked();

using namespace std;

int read_int() {
    register char c = gc();
    bool flag = false;

    while((c<'0' || c>'9') && (c != '-') ) c = gc();

    if(c == '-') { flag = true; c=gc();  }
    int ret = 0;
    while( c>='0' && c<='9' ) {
    ret = 10 * ret + c - 48;
    c = gc();
    }
    
    if(flag) ret = -1 * ret;
	return  ret;
}

long int store[1000001], myMap[1000001]; 

int main(){

	int N;
	scanf("%d", &N);

	int Arr[N]; 
	long long int p = 0, q = 0, temp1, temp2, count = 0;

	for(int i = 0; i < N; i++)
		Arr[i] = read_int();

	for(int i = 0; i < N; i++){
		
		temp1 = Arr[i];

		for(int j = 0; j < N; j++){
			
			temp2 = temp1 * Arr[j];

			for(int k = 0; k < N; k++)
			 	myMap[p++] = temp2 + Arr[k];
		}
	}
	

	for(int i = 0; i < N; i++){
		
		temp1 = Arr[i];

		for(int j = 0; j < N; j++){
			
			temp2 = temp1 + Arr[j];

			for(int k = 0; k < N; k++)
				if( Arr[k] != 0)
					store[q++] = temp2 * Arr[k];
		}
	}

	sort(myMap , myMap + p  );
	sort(store , store + q  );

	long long int count1, count2;

	for( int i = 0, j = 0 ; i < p && j < q ; ){
	
		temp1 = myMap[i];
		temp2 = store[j];

		if( temp1 < temp2){
			i++;
			while(temp1 == myMap[i]) i++;
		}
		else if( temp2 < temp1){
			j++;
			while(temp2 == store[j]) j++;
		}
		else{

			count1 = count2 = 0;

			while(temp1 == myMap[i]){  count1++; i++; } 
			while(temp2 == store[j]){ count2++;  j++; }			
			
			count = count + count1 * count2;

		}
	}
 
	printf("%lld\n",count);
	return 0;

}
