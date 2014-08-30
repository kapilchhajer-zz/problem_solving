//http://www.spoj.com/problems/POUR1/

#include<cstdio>

using namespace std;

int AToB(int A, int B, int C){
	
	//printf("%d %d %d\n",A,B,C);

	int total = 0, pourA = 0, pourB = 0, blank, initial = 0;
	bool initialFlag = true;

	while(true){

		pourA = A;
		total++;
	
		blank = B - pourB;

		while( pourA >= blank ){
	
			pourA = pourA - blank;
			total = total + 2;
			
			//printf("AtoB : %d\n",pourA);

			if( pourA == C )
				return --total;

			
			if(pourA == initial || pourA == 0)
				return -1;
		
			if(initialFlag){
				initial = pourA;
				initialFlag = false;
			}
	
			pourB = 0;		
			blank = B - pourB;
		}


		/*
		
		while( pourA > B){
	
			pourA = pourA - B;
			total = total + 2;	
			
			if( pourA == C )
				return --total;
		}
		*/
		pourB = pourA;
		pourA = 0;

	}

}


int BToA(int A, int B, int C){

	int total = 0, pourA = 0, pourB = 0, blank, initial = 0;
	bool initialFlag = true;

	while(true){

		blank = pourA + B;
	
		while( blank < A ){
			pourA = pourA + B;
			total = total + 2;	
			
			if( pourA == C )
				return total;
				
			blank = pourA + B;
		}

		pourB = blank - A ;
		total = total + 2;

		//printf("BtoA  : %d\n",pourB);
		
		if(pourB == initial)
			return -1;

		if(initialFlag){
			initial = pourB;
			initialFlag = false;
		}
		
		if( pourB == C )
			return total;

		total = total + 2;
		pourA = pourB;

	}
}

int main(){

	int testCases, A, B, C, result1, result2;
	
	scanf("%d", &testCases );

	while( testCases-- ){

		scanf("%d %d %d", &A, &B, &C);
		if( C == 0){
			printf("0\n");
			continue;
		}
		if( A == C || B == C){
			printf("1\n");
			continue;
		}
		else if( A == B && B != C ){
			printf("-1\n");
			continue;
		}
		else if( A < C && B < C ){
			printf("-1\n");
			continue;
		}
		else if( A < B ){
			
			A = A + B;
			B = A - B;
			A = A - B;
		}

		result1 = AToB(A, B, C);
		result2 = BToA(A, B, C);
		
		//printf("%d %d\n",result1,result2);
	
		if(result1 > 0 && result2 > 0){

			if(result1 <= result2)
				printf("%d\n", result1);	
			else
				printf("%d\n", result2);	

			continue;
		}
		
		if(result1 > 0 )
			printf("%d\n",result1);
		else if(result2 > 0)
			printf("%d\n", result2);
		else
			printf("-1\n");
	}

	return 0;
}
