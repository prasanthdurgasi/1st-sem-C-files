#include <stdio.h>

int i, j;

void firstFit(int b[], int m, int p[], int n);
void bestFit(int b[], int m, int p[], int n);
void worstFit(int b[], int m, int p[], int n);

int main() {
    int m, n;
    int b[10], p[10], original[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of memory blocks:\n");
    for (i = 0; i < m; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &p[i]);
    }

    for (i = 0; i < m; i++)
        original[i] = b[i];
    printf("\nFirst Fit:\n");
    firstFit(b, m, p, n);

    for (i = 0; i < m; i++)
        b[i] = original[i];
    printf("\nBest Fit:\n");
    bestFit(b, m, p, n);

    for (i = 0; i < m; i++)
        b[i] = original[i];
    printf("\nWorst Fit:\n");
    worstFit(b, m, p, n);

    return 0;
}

void firstFit(int b[], int m, int p[], int n) {
    for (i = 0; i < n; i++) {
        int allocated = 0;
        for (j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                b[j] -= p[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated)
            printf("Process %d not allocated\n", i + 1);
    }
}

void bestFit(int b[], int m, int p[], int n) {
    for (i = 0; i < n; i++) {
        int best = -1;
        for (j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                if (best == -1 || b[j] < b[best]) {
                    best = j;
                }
            }
        }
        if (best != -1) {
            printf("Process %d allocated to Block %d\n", i + 1, best + 1);
            b[best] -= p[i];
        } else {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}

void worstFit(int b[], int m, int p[], int n) {
    for (i = 0; i < n; i++) {
        int worst = -1;
        for (j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                if (worst == -1 || b[j] > b[worst]) {
                    worst = j;
                }
            }
        }
        if (worst != -1) {
            printf("Process %d allocated to Block %d\n", i + 1, worst + 1);
            b[worst] -= p[i];
        } else {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}
