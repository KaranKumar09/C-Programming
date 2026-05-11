#include<stdio.h>
main(){
	int a[2][2],i,j,sum=0;
	printf("enter the array\n");
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		scanf("%d",&a[i][j]);
		printf("Array are ");
		for(i=0;i<2;i++){
			printf("\n");
		
		for(j=0;j<2;j++)
		printf("\t%d",a[i][j]);
	}
	for (i=0;i<2;i++)
	for (j=0;j<2;j++)
	if(a[i][j]%2==0)
	sum=sum+a[i][j];
	printf("\nsum of all elements of array: %d",sum);
	
} 
