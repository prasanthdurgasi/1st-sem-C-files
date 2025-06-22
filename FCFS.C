#include <stdio.h>

int a[10][6];
int cawt = 0, ctat = 0, n;

void awt();
void tat();

int main() {
    int i, c = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID: ");
        scanf("%d", &a[i][0]);
        printf("Enter Burst Time: ");
        scanf("%d", &a[i][1]);
        printf("Enter Arrival Time: ");
        scanf("%d", &a[i][2]);
    }

    for (i = 0; i < n; i++) {
        if (i == 0 || a[i][2] > a[i - 1][5]) {
            a[i][5] = (i == 0) ? a[i][2] + a[i][1] : a[i][2] + a[i][1];
        } else {
            a[i][5] = a[i - 1][5] + a[i][1];
        }
    }

    awt();
    tat();

    printf("\nPID\tBT\tAT\tWT\tTAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5]);
    }

    printf("Average Waiting Time: %.2f\n", (float)cawt / n);
    printf("Average Turnaround Time: %.2f\n", (float)ctat / n);

    return 0;
}

void awt() {
    int i;
    for (i = 0; i < n; i++) {
        a[i][3] = a[i][5] - a[i][1] - a[i][2];
        cawt += a[i][3];
    }
}

void tat() {
    int i;
    for (i = 0; i < n; i++) {
        a[i][4] = a[i][5] - a[i][2];
        ctat += a[i][4];
    }
}
