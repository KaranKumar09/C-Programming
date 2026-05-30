#include<stdio.h>
main(){
	int sum=0;
	int n,r;
	scanf("%d",&n);
	int temp=n;
	while(n>0){
		r=n%10;
		sum=sum+r*r*r;
		n=n/10;	
	}
	if (sum==temp){
		printf("Armstrong no.");
	}
	else{
		printf("Not a armstrong no.");
	}
	
}
