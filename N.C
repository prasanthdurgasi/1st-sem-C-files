#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void add();
void display();
void search();

int main() {
    int choice;
    while (1) {
        printf("\n1. Add\n");
        printf("2. Display\n");
        printf("3. Search by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void add() {
    struct Employee emp;
    FILE *file = fopen("employee.dat", "ab");
    if (!file) {
        printf("Unable to open file\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    fwrite(&emp, sizeof(emp), 1, file);
    fclose(file);
    printf("Record added successfully.\n");
}

void display() {
    struct Employee emp;
    FILE *file = fopen("employee.dat", "rb");
    if (!file) {
        printf("Unable to open file\n");
        return;
    }
    printf("\n--- Employee Records ---\n");
    while (fread(&emp, sizeof(emp), 1, file)) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(file);
}

void search() {
    struct Employee emp;
    int found = 0, searchid;
    FILE *file = fopen("employee.dat", "rb");
    if (!file) {
        printf("Unable to open file\n");
        return;
    }
    printf("Enter search ID: ");
    scanf("%d", &searchid);
    while (fread(&emp, sizeof(emp), 1, file)) {
        if (emp.id == searchid) {
            printf("Record Found - ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record with ID %d not found.\n", searchid);
    }
    fclose(file);
}
