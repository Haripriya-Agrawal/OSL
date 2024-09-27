#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

void sstf(int requests[], int n, int head) {
    int done[MAX] = {0};
    int total_seek = 0;
    int current = head;

    printf("Sequence: %d", head);

    for (int i = 0; i < n; i++) {
        int min = INT_MAX;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (!done[j]) {
                int distance = abs(requests[j] - current);
                if (distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        done[index] = 1;
        total_seek += min;
        current = requests[index];
        printf(" -> %d", current);
    }

    printf("\nTotal seek time: %d\n", total_seek);
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void scan(int requests[], int n, int head, int direction, int disk_size) {
    int seek_sequence[MAX];
    int seek_count = 0;
    int distance, cur_track;
    int left[MAX], right[MAX];
    int left_size = 0, right_size = 0;

    left[left_size++] = 0;
    right[right_size++] = disk_size - 1;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[left_size++] = requests[i];
        if (requests[i] > head)
            right[right_size++] = requests[i];
    }

    sort(left, left_size);
    sort(right, right_size);

    int run = 2;
    while (run--) {
        if (direction == 0) {
            for (int i = left_size - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence[seek_count++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = 1;
        }
        else if (direction == 1) {
            for (int i = 0; i < right_size; i++) {
                cur_track = right[i];
                seek_sequence[seek_count++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = 0;
        }
    }

    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is: ");
    for (int i = 0; i < seek_count; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}

void c_look(int requests[], int n, int head, int disk_size) {
    int seek_sequence[MAX];
    int seek_count = 0;
    int distance, cur_track;
    int left[MAX], right[MAX];
    int left_size = 0, right_size = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[left_size++] = requests[i];
        if (requests[i] > head)
            right[right_size++] = requests[i];
    }

    sort(left, left_size);
    sort(right, right_size);

    for (int i = 0; i < right_size; i++) {
        cur_track = right[i];
        seek_sequence[seek_count++] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    for (int i = 0; i < left_size; i++) {
        cur_track = left[i];
        seek_sequence[seek_count++] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is: ");
    for (int i = 0; i < seek_count; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}



int main() {
    int requests[MAX], n, head, choice, disk_size, direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the total disk size: ");
    scanf("%d", &disk_size);

    while (1) {
        printf("\nDisk Scheduling Algorithms:\n");
        printf("1. SSTF\n");
        printf("2. SCAN\n");
        printf("3. C-LOOK\n");
      
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sstf(requests, n, head);
                break;
            case 2:
                printf("Enter the direction (0 for left, 1 for right): ");
                scanf("%d", &direction);
                scan(requests, n, head, direction, disk_size);
                break;
            case 3:
                c_look(requests, n, head, disk_size);
                break;
            
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
