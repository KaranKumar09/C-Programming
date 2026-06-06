#include<stdio.h>
void increment(void);
main(){
	increment();
	increment();
	increment();
	
}
void increment()
{
	int i=1;
	printf("\n %d",i);
	i=i+1;
}
