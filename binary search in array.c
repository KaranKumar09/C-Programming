#include<stdio.h>
main(){
	int loc=-1,i,last=9,mid,beg=0,key;
	int a[10]={2,4,6,8,10,12,37,45,68,89};
	printf(" array element are: ");
	for(i=0;i<10;i++)
	printf("\n%d",a[i]);
	printf("\nEnter the integer value to searched: ");
	scanf("%d",&key);
	while(beg<=last){
		mid=(beg+last)/2;
		if(a[mid]==key){
			loc=mid+1;
			break;
		}
		else if(a[mid]>key){
			last=mid-1;
		}
		else if(a[mid]<key){
			beg=mid+1;
		}
	}
		if (loc!=-1){
			printf("element found at %d",loc);
		}
		else{
			printf("element not found");
		}
	
}
