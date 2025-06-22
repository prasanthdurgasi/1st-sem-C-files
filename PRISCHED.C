#include <stdio.h>

int a[10][7], n, c = 0;
float cawt = 0, ctat = 0;

void sort();
void awt();
void tat();

int main() {
    int i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID: ");
        scanf("%d", &a[i][0]);
        printf("Enter Burst Time: ");
        scanf("%d", &a[i][1]);
        printf("Enter Arrival Time: ");
        scanf("%d", &a[i][2]);
        printf("Enter Priority (Lower number = Higher priority): ");
        scanf("%d", &a[i][3]);
    }

    sort();

    for (i = 0; i < n; i++) {
        c += a[i][1];
        a[i][6] = c;
    }

    awt();
    tat();

    printf("\nPID\tBT\tAT\tPRI\tWT\tTAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], a[i][6]);
    }

    printf("Average Waiting Time: %.2f\n", cawt / n);
    printf("Average Turnaround Time: %.2f\n", ctat / n);

    return 0;
}

void awt() {
    int i;
    a[0][4] = 0;
    cawt += a[0][4];
    for (i = 1; i < n; i++) {
        a[i][4] = a[i - 1][4] + a[i - 1][1];
        cawt += a[i][4];
    }
}

void tat() {
    int i;
    for (i = 0; i < n; i++) {
        a[i][5] = a[i][1] + a[i][4];
        ctat += a[i][5];
    }
}

void sort() {
    int i, j, k, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i][2] > a[j][2] || (a[i][2] == a[j][2] && a[i][3] > a[j][3])) {
                for (k = 0; k < 7; k++) {
                    temp = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = temp;
                }
            }
        }
    }
}
