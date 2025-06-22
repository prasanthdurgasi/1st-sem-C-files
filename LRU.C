#include <stdio.h>

int main() {
    int sec[20], pri[20], recent[20];
    int smp, pmf;
    int i, j, hits = 0, misses = 0, count = 0, pos;

    printf("Enter number of pages: ");
    scanf("%d", &smp);

    printf("Enter number of frames: ");
    scanf("%d", &pmf);

    printf("Enter the page reference string:\n");
    for(i = 0; i < smp; i++) {
        scanf("%d", &sec[i]);
    }

    // Initialize all frames and recent usage times
    for(i = 0; i < pmf; i++) {
        pri[i] = -1;
        recent[i] = 0;
    }

    for(i = 0; i < smp; i++) {
        int found = 0;

        // Check for page hit
        for(j = 0; j < pmf; j++) {
            if(sec[i] == pri[j]) {
                found = 1;
                hits++;
                recent[j] = ++count; // Update last used time
                break;
            }
        }

        // Page fault (miss)
        if(!found) {
            pos = 0;

            // Find the least recently used page
            for(j = 1; j < pmf; j++) {
                if(recent[j] < recent[pos]) {
                    pos = j;
                }
            }

            pri[pos] = sec[i];       // Replace the LRU page
            recent[pos] = ++count;   // Update last used time
            misses++;
        }
    }

    printf("Total Page Hits: %d\n", hits);
    printf("Total Page Misses: %d\n", misses);

    return 0;
}
