#include<stdio.h>
main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++){
		if(a[i]<35){
		printf("%d\n",a[i]);
		}
		else{
			printf("not found\n");
		}
	}
	
}
