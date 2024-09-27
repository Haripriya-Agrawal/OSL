#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

void printState(int frames[], int n, int page) {
    printf("%d\t", page);
    for (int i = n - 1; i >= 0; i--) {
        if (frames[i] != -1) {
            printf("%d", frames[i]);
        } else {
            printf(" ");
        }
        if (i > 0) printf("\t");
    }
}

int fifo(int pages[], int m, int frames[], int n) {
    int fault = 0, current = 0;
    char result[10];

    printf("\nFIFO Page Replacement:\n");
    printf("!\t");
    for (int i = n; i > 0; i--) {
        printf("F%d", i);
        if (i > 1) printf("\t");
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            frames[current] = pages[i];
            current = (current + 1) % n;
            fault++;
            strcpy(result, "Miss");
        } else {
            strcpy(result, "Hit");
        }

        printState(frames, n, pages[i]);
        printf("\t%s\n", result);
    }

    return fault;
}

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int lru(int pages[], int m, int frames[], int n) {
    int fault = 0, time[MAX_FRAMES] = {0};
    char result[10];

    printf("\nLRU Page Replacement:\n");
    printf("!\t");
    for (int i = n; i > 0; i--) {
        printf("Frame %d", i);
        if (i > 1) printf("\t");
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                time[j] = i + 1;
                break;
            }
        }

        if (flag == 0) {
            int pos = (fault < n) ? fault : findLRU(time, n);
            frames[pos] = pages[i];
            time[pos] = i + 1;
            fault++;
            strcpy(result, "Miss");
        } else {
            strcpy(result, "Hit");
        }

        printState(frames, n, pages[i]);
        printf("\t%s\n", result);
    }

    return fault;
}

int findOptimal(int pages[], int m, int frames[], int n, int index) {
    int pos = -1, farthest = index;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = index; j < m; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == m)
            return i;
    }
    return (pos == -1) ? 0 : pos;
}

int optimal(int pages[], int m, int frames[], int n) {
    int fault = 0;
    char result[10];

    printf("\nOptimal Page Replacement:\n");
    printf("!\t");
    for (int i = n; i > 0; i--) {
        printf("Frame %d", i);
        if (i > 1) printf("\t");
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            int pos = (fault < n) ? fault : findOptimal(pages, m, frames, n, i + 1);
            frames[pos] = pages[i];
            fault++;
            strcpy(result, "Miss");
        } else {
            strcpy(result, "Hit");
        }

        printState(frames, n, pages[i]);
        printf("\t%s\n", result);
    }

    return fault;
}

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int n, m, i, choice;
    int fifo_faults, lru_faults, optimal_faults;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter number of pages: ");
    scanf("%d", &m);

    printf("Enter page reference string: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nPage reference string: ");
    for (i = 0; i < m; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    do {
        printf("\nChoose algorithm:\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. Optimal\n");
        printf("4. Compare all\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) frames[i] = -1;
                fifo_faults = fifo(pages, m, frames, n);
                printf("\nTotal Page Faults (FIFO) = %d\n", fifo_faults);
                break;
            case 2:
                for (i = 0; i < n; i++) frames[i] = -1;
                lru_faults = lru(pages, m, frames, n);
                printf("\nTotal Page Faults (LRU) = %d\n", lru_faults);
                break;
            case 3:
                for (i = 0; i < n; i++) frames[i] = -1;
                optimal_faults = optimal(pages, m, frames, n);
                printf("\nTotal Page Faults (Optimal) = %d\n", optimal_faults);
                break;
            case 4:
                for (i = 0; i < n; i++) frames[i] = -1;
                fifo_faults = fifo(pages, m, frames, n);
                for (i = 0; i < n; i++) frames[i] = -1;
                lru_faults = lru(pages, m, frames, n);
                for (i = 0; i < n; i++) frames[i] = -1;
                optimal_faults = optimal(pages, m, frames, n);

                printf("\nComparison Table:\n");
                printf("Algorithm | Page Faults\n");
                printf("----------+------------\n");
                printf("FIFO      | %d\n", fifo_faults);
                printf("LRU       | %d\n", lru_faults);
                printf("Optimal   | %d\n", optimal_faults);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
