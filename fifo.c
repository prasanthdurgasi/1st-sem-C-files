#include <stdio.h>

int sec[20], pri[10];
int smp, pmf, hits = 0, misses = 0;

void fifo();

int main() {
    int i;
    printf("Enter the number of pages: ");
    scanf("%d", &smp);
    printf("Enter the number of frames: ");
    scanf("%d", &pmf);
    printf("Enter the page reference string:\n");
    for (i = 0; i < smp; i++) {
        scanf("%d", &sec[i]);
    }
    fifo();
    return 0;
}

void fifo() {
    int rear = 0, i, j, flag;
    for (i = 0; i < pmf; i++) {
        pri[i] = -1;
    }
    for (i = 0; i < smp; i++) {
        flag = 0;
        for (j = 0; j < pmf; j++) {
            if (sec[i] == pri[j]) {
                flag = 1;
                hits++;
                break;
            }
        }
        if (flag == 0) {
            pri[rear] = sec[i];
            rear = (rear + 1) % pmf;
            misses++;
        }
    }
    printf("Total Hits: %d\n", hits);
    printf("Total Misses: %d\n", misses);
}
