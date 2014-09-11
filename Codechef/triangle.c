#include<stdio.h>
#include<stdlib.h>
#define gc() getchar_unlocked();

int read_int() {
    register char c = gc();
    while(c<'0' || c>'9') c = gc();
    int ret = 0;
    while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
    }
        return  ret;
}
int main()
{
        int testCases,i,j,size,*arr,temp,k,prev,cur;
        testCases=read_int();

        while(testCases--)
        {
                temp=0;
                size=read_int();
                arr = (int *) calloc((size),sizeof(int));


                for(i=0;i<size;i++)
                {
			cur=k=0;
                        temp++;
                        while(k<temp)
                        {
                                j=read_int();
				prev=cur;
				cur=arr[k];
                                if(prev>cur)
                                        arr[k]=j+prev;
                                else
                                        arr[k]=j+cur;

                                k++;

                        }

                }
		temp=0;
                for(i=0;i<size;i++)
                        if(temp<arr[i])
                                temp=arr[i];

                printf("%d\n",temp);
        }

        return 0;
}

