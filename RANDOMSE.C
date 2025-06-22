#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

struct Employee {
    int id;
    char name[50];
    float salary;
    int isFilled;
};

int hash(int id);
void initializeFile();
void add();
void display();
void search();

int main() {
    int choice;
    printf("Initializing file (only once)...\n");
    initializeFile();

    printf("\n1. Add\n2. Display\n3. Search\n4. Exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

int hash(int id) {
    return id % SIZE;
}

void initializeFile() {
    int i;
    FILE *file = fopen("emp.dat", "wb");
    struct Employee empty = {0, "", 0.0, 0};
    if (!file) {
        printf("file not found\n");
        return;
    }
    for (i = 0; i < SIZE; i++) {
        fwrite(&empty, sizeof(struct Employee), 1, file);
    }
    fclose(file);
}

void add() {
    struct Employee e, temp;
    int pos;
    FILE *file = fopen("emp.dat", "rb+");
    if (!file) {
        printf("file not found\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", e.name);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);
    e.isFilled = 1;
    pos = hash(e.id);
    fseek(file, pos * sizeof(struct Employee), SEEK_SET);
    fread(&temp, sizeof(struct Employee), 1, file);
    if (temp.isFilled) {
        printf("Slot already filled. Cannot add employee with ID %d.\n", e.id);
    } else {
        fseek(file, pos * sizeof(struct Employee), SEEK_SET);
        fwrite(&e, sizeof(struct Employee), 1, file);
        printf("Record added at position %d.\n", pos);
    }
    fclose(file);
}

void display() {
    struct Employee e;
    int i;
    FILE *file = fopen("emp.dat", "rb");
    if (!file) {
        printf("file not found\n");
        return;
    }
    printf("\n--- Employee Records ---\n");
    for (i = 0; i < SIZE; i++) {
        fseek(file, i * sizeof(struct Employee), SEEK_SET);
        fread(&e, sizeof(struct Employee), 1, file);
        if (e.isFilled) {
            printf("Position %d: ID=%d, Name=%s, Salary=%.2f\n", i, e.id, e.name, e.salary);
        }
    }
    fclose(file);
}

void search() {
    struct Employee e;
    int id, pos;
    FILE *file = fopen("emp.dat", "rb");
    if (!file) {
        printf("file not found\n");
        return;
    }
    printf("Enter ID to search: ");
    scanf("%d", &id);
    pos = hash(id);
    fseek(file, pos * sizeof(struct Employee), SEEK_SET);
    fread(&e, sizeof(struct Employee), 1, file);
    if (e.isFilled && e.id == id) {
        printf("Found: ID=%d, Name=%s, Salary=%.2f\n", e.id, e.name, e.salary);
    } else {
        printf("Record not found at position %d.\n", pos);
    }
    fclose(file);
}
