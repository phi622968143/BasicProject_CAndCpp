#include <stdio.h>
void ss(int*,int);//FindMin&Swap With Head
void swap(int*,int*);

int main(void) {
	int a[]={34,4324,235,42,324,556},a1=3,b=5;
	int n=sizeof(a)/sizeof(int);

	ss(a,n);

	for(int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}

void ss(int*a,int n){

    for(int i=0;i<n-1;i++){//SwapTimes
		int min=i;

		for(int j=i+1;j<n;j++){//FindMinIndex

			if(a[min]>a[j]) {
           min=j;
			}
		}

		if(min!=i){//IfItselfNoMin
          swap(&a[i],&a[min]);
		}
	}
}
void swap(int*f,int*l){//ChangeValue
	int t=*l;
    *l=*f;
	*f=t;
}
