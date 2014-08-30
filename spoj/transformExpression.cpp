//http://www.spoj.com/problems/ONP/

#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

/* return 
	priority = 2 if op is +,-
	priority = 3 if op is *,/
	priority = 4 if op is  (,)
*/
int priority(char op){

	if ( op == '(')
		return 0;
	else if ( op == ')')
		return 1;
	else if(op == '+' || op == '-')
		return 2;
	else if(op == '*' || op == '/')
		return 3;
	else if(op == '^')
		return 4;
	else
		return -1;

}


/* return true if we have to insert it into stack otherwise false */
bool precedenceChecker(char stackTop , char op){

	int stackTopPriority,opPriority;
	
	stackTopPriority = priority(stackTop);
	opPriority	= priority(op);

	if(stackTopPriority  < opPriority || opPriority == 0)
		return true;
	else 
		return false;
}

int main(){

	stack<char> operators;
	string input,output;
	int testCases,length;
		

	scanf("%d",&testCases);
	
	while(testCases--){
		operators.push('$');
		cin>>input;
		//scanf("%s",&input);
		length = input.length();

		for(int i=0;i<length;i++){
			
			if( isalpha(input[i]) || isdigit(input[i]) ){
				output.append(1,char(input[i]));
			}
			else{
				
				if( precedenceChecker(operators.top(),input[i])){
					operators.push(input[i]);
				}
				else {
					
					while( !precedenceChecker(operators.top(),input[i])){
						output.append(1,operators.top());
						operators.pop();
					}

					if(input[i]==')')
						operators.pop();
					else
						operators.push(input[i]);
				}
				
				
		
			}

		}
		cout<<output<<endl;
		//printf("%s\n",output);
		output.clear();
		while(!operators.empty())
			operators.pop();
	}
	return 0;
}
