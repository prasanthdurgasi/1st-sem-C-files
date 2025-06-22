#include <stdio.h>

int main() {
    int n, i, j, temp;
    int process[10], bt[10], wt[10], tat[10];
    int totalwt = 0, totaltat = 0;
    float averagewt, averagetat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        totalwt += wt[i];
        totaltat += tat[i];
    }

    printf("\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n");
    printf("----------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("    %d      |     %d     |      %d      |       %d\n",
               process[i], bt[i], wt[i], tat[i]);
    }

    averagewt = (float)totalwt / n;
    averagetat = (float)totaltat / n;

    printf("\nAverage Waiting Time: %.2f\n", averagewt);
    printf("Average Turnaround Time: %.2f\n", averagetat);

    return 0;
}
