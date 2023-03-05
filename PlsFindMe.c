#include <stdio.h>
//bsort and bsearch
int main(void) {	
	int a[]={21,57,39,23,26,123,1324,2324,213,68,76};
	int n=sizeof(a)/sizeof(int),k;
	scanf("%d",&k);
	bsort(a,n);

	for(int j=0;j<n;j++){
			printf("%d ",a[j]);
	}
	if(b_search(a,n,k))
		printf("\n%d is the %d th min ",k,b_search(a,n,k)+1);
	else
		printf("\nboka");
}

void bsort(int*a,int n){
	for(int j=0;j<n-1;j++){// for SortingTimes
		for(int i=0;i<n-j-1;i++)//for SwapingTimes
		{		
				if(a[i]>a[i+1]){
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
}
int b_search(int*a,int size,int n){
	int low=0,high=size-1;

	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==n){
			return mid;
		}
		else if(a[mid]>n){
			high=mid-1;//left
		}
		else{
			low=mid+1;//right
		}
	}
	return 0;
}
	
