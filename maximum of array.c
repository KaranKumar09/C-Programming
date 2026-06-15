#include <stdio.h>
//main(){
	//int i,max;
	//int arr[10];
	//printf("enter the array elements");
	//for (i=0;i<=10;i++){
		//scanf("%d",&arr[i]);
	//}
	//max=arr[0];
	//for (i=0;i<10;i++){
		//if(max<arr[i])
		//max=arr[i];
	//}
	//printf("largest element=%d",max);
//}
main(){
	int i,min,max;
	int arr[10];
	printf("enter the array elements");
	for (i=0;i<=10;i++){
		scanf("%d",&arr[i]);
	}
	min=arr[0];
	for (i=0;i<10;i++){
		if(min>arr[i])
		min=arr[i];
	}
	max=arr[0];
	for (i=0;i<10;i++){
		if(max<arr[i])
		max=arr[i];
	}
	printf("smallest element=%d & largest element=%d",min,max);
}
