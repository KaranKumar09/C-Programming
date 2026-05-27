#include<stdio.h>
main(){
	char choice;
		float r,a;
	printf("press C to calculate area of circle \n");
	printf("press R to calculate area of rectangle\n");
	printf("press T to calculate area of triangle\n");
	printf("Enter your choice \n");
	scanf("%c", &choice);
	switch(choice){
		case 'C': ;
		
			printf("enter the value of radius: ");
			scanf("%f",&r);
			a=3.14*r*r;
			printf("%f",a);
			break;
		case 'R': 
			float k,l,m;
			printf("enter the value of length and breath: ");
			scanf("%f %f", &l, &k);
			m=l*k;
			printf("%f",m);
			break;
		case 'T': 
			float p,q,s;
			printf("enter the value of sides: ");
			scanf("%f %f", &p, &q);
			s=0.5*p*q;
			printf("%f",s);
			break;
		default:
			printf("invalid area");
	}
}
