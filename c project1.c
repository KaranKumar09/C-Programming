#include <stdio.h>
struct Icecream {
    int id;
    char name[50];
    int quantity;
    float price;
    char mf[11];
    char ex[11];
};

void display(struct Icecream ice);
void addIcecream();
void displayAllIcecream();
void updateIcecream();
void searchIcecream();
void deleteIcecream();

int main() {
	printf("\t\t\t\t------------------- ICECREAM PARLOR MANAGEMENT ---------------------\n\n");
    int choice;
    do {
    	printf("\n\n");
        printf("1. Display Icecream Details\n");
        printf("2. Add New Icecream\n");
        printf("3. Delete Icecream Details\n");
        printf("4. Search a Particular Icecream\n");
        printf("5. Update Icecream Details\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            	displayAllIcecream();
                break;
            case 2:
                addIcecream();
                break;
            case 3:
            	deleteIcecream();
                break;
            case 4:
                searchIcecream();
                break;
            case 5:
            	updateIcecream();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}
void display(struct Icecream ice) {
  printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%s\t\t%s\n",ice.id, ice.name, ice.quantity, ice.price, ice.mf, ice.ex);
}
void displayAllIcecream() {
    struct Icecream ice;
    printf("\t\t\t\t\t--- ALL ICECREAM ---\n");
    printf("\n");
    FILE *fp;
    fp = fopen("icecream_db.txt", "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }
    printf("Icecream Id\tIcecream Name\t\tQuantity\tPrice\t\tManufacturing Date\tExpiry Date\n");
    printf("\n");
    while (fscanf(fp, "%d %s %d %f %s %s\n", &ice.id, &ice.name, &ice.quantity, &ice.price, &ice.mf, &ice.ex) != EOF) {
    
        display(ice);
        printf("\n");
    }
    fclose(fp);
}
void addIcecream() {
    struct Icecream ice;
    printf("\n--- ADD ICECREAM ---\n");
    printf("Enter ID: ");
    scanf("%d", &ice.id);
    printf("Enter Name: ");
    scanf("%s", ice.name);
    printf("Enter Quantity: ");
    scanf("%d", &ice.quantity);
    printf("Enter Price: ");
    scanf("%f", &ice.price);
    printf("Enter Manufacturing Date: ");
    scanf("%s", &ice.mf);
    printf("Enter Expiry Date: ");
    scanf("%s", &ice.ex);
    FILE *fp;
    fp = fopen("icecream_db.txt", "a");
    fprintf(fp, "%d %s %d %.2f %s %s\n", ice.id, ice.name, ice.quantity, ice.price, ice.mf, ice.ex);
    fclose(fp);
    printf("Icecream added successfully.\n");
}

void deleteIcecream() {
    char name[50];
    printf("Enter the name of the icecream to delete: ");
    scanf("%s",&name);
	FILE *fp = fopen("icecream_db.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the database file\n");
        return;
    }

    FILE *temp_fp = fopen("temp.txt", "w");
    if (temp_fp == NULL) {
        printf("Failed to create a temporary file\n");
fclose(fp);
        return;
    }

    char temp_name[50],ex[11],mf[11];
    int quantity,id;
    float price;
    int deleted = 0;
    while (fscanf(fp, "%d %s %d %f %s %s",&id, &temp_name, &quantity, &price, &mf, &ex) == 6) {
        if (strcmp(temp_name, name) == 0) {
            deleted = 1;
            continue;
        }

        fprintf(temp_fp, "%d %s %d %.2f %s %s\n",id,temp_name, quantity, price, mf, ex);
    }

    fclose(fp);
    fclose(temp_fp);

    if (!deleted) {
		printf("Record not found\n");
        remove("temp.txt");
    } else {
        remove("icecream_db.txt");
 rename("temp.txt", "icecream_db.txt");
        printf("Record deleted successfully\n");
    }
}
void updateIcecream() {
    char name[50];
    printf("Enter the name of the icecream to update: ");
    scanf("%s",&name);

    FILE *fp = fopen("icecream_db.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the database file\n");
        return;
    }

    FILE *temp_fp = fopen("temp.txt", "w");
    if (temp_fp == NULL) {
        printf("Failed to create a temporary file\n");
        fclose(fp);
        return;
    }

    char temp_name[50],ex[11],mf[11];
    int quantity,id;
	float price;
    int updated = 0;
    while (fscanf(fp, "%d %s %d %f %s %s",&id,&temp_name, &quantity, &price, &mf, &ex) == 6) {
if (strcmp(temp_name, name) == 0) {
            updated = 1;

            printf("Enter the new quantity: ");
            scanf("%d", &quantity);

            printf("Enter the new price: ");
            scanf("%f", &price);
            
            printf("Enter new Manafacturing Date: ");
            scanf("%s",&mf);
            
            printf("Enter the new Expiry Date: ");
            scanf("%s",&ex);

            fprintf(temp_fp, "%d %s %d %.2f %s %s\n",id,name, quantity, price, mf, ex);
        } else {
            fprintf(temp_fp, "%d %s %d %.2f %s %s\n",id,temp_name, quantity, price, mf, ex);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    if (!updated) {
 		printf("Record not found\n");
        remove("temp.txt");
    } else {
        remove("icecream_db.txt");
        rename("temp.txt", "icecream_db.txt");
        printf("Record updated successfully\n");
}
}
void searchIcecream() {
    char name[50];
    printf("Enter the name of the icecream to search: ");
    scanf("%s", name);

    FILE *fp = fopen("icecream_db.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the database file\n");
        return;
    }

    int found = 0;
    char temp_name[50],ex[11],mf[11];
    int quantity,id;
    float price;
    while (fscanf(fp, "%d %s %d %f %s %s",&id,&temp_name, &quantity, &price, &mf, &ex) == 6) {
        if (strcmp(temp_name, name) == 0) {
            found = 1;
			printf("Icecream Id\tIcecream Name\t\tQuantity\tPrice\t\tManufacturing Date\tExpiry Date\n");
            printf("\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%s\t\t%s\n",id, name, quantity, price, mf, ex);
            break;
        }
    }
    fclose(fp);
    if (!found)
        printf("Record not found\n");
}

