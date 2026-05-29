#include<stdio.h>
void armstrong(int);
main(){
	int a;
	printf("Enter the number: ");
	scanf("%d",&a);
	armstrong(a);
}
void armstrong(int x)
{
	int y=x;
	int sum=0;
	while (x>0){
		int r=x%10;
		sum=sum+r*r*r;
		x/=10;
	}
	if(y==sum){
		printf("%d is an armstrong number",y);
	}
	else{
		printf("%d is not an armstrong number",y);
	}
}
