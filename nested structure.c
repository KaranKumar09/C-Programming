#include<stdio.h>
struct account{
	int acc_no;
	float balance;
};
struct customer {
	char name[10];
	char add[10];
	struct account ac;
};
main(){
	struct customer cust;
	printf("enter customer name:");
	scanf("%s",cust.name);
	printf("enter customer address: ");
	scanf("%s",cust.add);
	printf("enter account number:");
	scanf("%d",&cust.ac.acc_no);
	printf("enter balance: ");
	scanf("%f",&cust.ac.balance);
	printf("customer name: %s\n address: %s\n",cust.name,cust.add);
	printf("account number: %d\n balance: %f\n",cust.ac.acc_no,cust.ac.balance);
}
