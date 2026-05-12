#include<stdio.h>
main()
{
	int a[10],i,loc=0,key;
	printf("Enter array elements :");
	for (i=0;i<10;i++)
	scanf("%d",&a[i]);
	printf("Array elements are:");
	for(i=0;i<10;i++)
	printf("%d",a[i]);
	printf("\nEnter integer value to search in array");
	scanf("%d",&key);
	for(i=0;i<10;i++)
	{
	if (a[i]==key)
	{
	loc=i+1;
	break;
	}
	
	if(loc!=-1)
	{
		printf("Element found at %d",loc);
	}
	else
	{
		printf("Elements not found");
	
	}
	}
}
