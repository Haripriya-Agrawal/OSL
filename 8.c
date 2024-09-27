#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// SSTF Disk Scheduling Algorithm
void SSTF(int requests[], int n, int head) {
    int completed[n], seek_sequence[n], seek_count = 0;
    for (int i = 0; i < n; i++) completed[i] = 0;

    for (int i = 0; i < n; i++) {
        int min_distance = 100000, idx = -1;
        for (int j = 0; j < n; j++) {
            if (!completed[j] && abs(requests[j] - head) < min_distance) {
                min_distance = abs(requests[j] - head);
                idx = j;
            }
        }
        seek_sequence[i] = requests[idx];
        seek_count += abs(head - requests[idx]);
        head = requests[idx];
        completed[idx] = 1;
    }

    printf("SSTF Seek Sequence: ");
    for (int i = 0; i < n; i++) printf("%d ", seek_sequence[i]);
    printf("\nTotal Seek Operations: %d\n\n", seek_count);
}

// SCAN Disk Scheduling Algorithm
void SCAN(int requests[], int n, int head, int disk_size) {
    int seek_count = 0, direction, idx = 0;
    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    sort(requests, n);
    int seek_sequence[n + 1];
    
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            idx = i;
            break;
        }
    }

    if (direction == 1) {
        for (int i = idx; i < n; i++) {
            seek_sequence[seek_count++] = requests[i];
        }
        seek_sequence[seek_count++] = disk_size - 1;
        for (int i = idx - 1; i >= 0; i--) {
            seek_sequence[seek_count++] = requests[i];
        }
    } else {
        for (int i = idx - 1; i >= 0; i--) {
            seek_sequence[seek_count++] = requests[i];
        }
        seek_sequence[seek_count++] = 0;
        for (int i = idx; i < n; i++) {
            seek_sequence[seek_count++] = requests[i];
        }
    }

    printf("SCAN Seek Sequence: ");
    for (int i = 0; i < seek_count; i++) printf("%d ", seek_sequence[i]);
    printf("\nTotal Seek Operations: %d\n\n", abs(head - seek_sequence[0]) + abs(seek_sequence[0] - seek_sequence[seek_count - 1]));
}

// C-LOOK Disk Scheduling Algorithm
void C_LOOK(int requests[], int n, int head) {
    int seek_count = 0, idx = 0;
    sort(requests, n);
    int seek_sequence[n + 1];
    
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            idx = i;
            break;
        }
    }

    for (int i = idx; i < n; i++) {
        seek_sequence[seek_count++] = requests[i];
    }
    for (int i = 0; i < idx; i++) {
        seek_sequence[seek_count++] = requests[i];
    }

    printf("C-LOOK Seek Sequence: ");
    for (int i = 0; i < seek_count; i++) printf("%d ", seek_sequence[i]);
    printf("\nTotal Seek Operations: %d\n\n", abs(head - seek_sequence[0]) + abs(seek_sequence[seek_count - 1] - seek_sequence[0]));
}

int main() {
    int choice, n, head, disk_size;
    
    // Take inputs once at the beginning
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int requests[n];
    
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    // Loop to let the user choose multiple algorithms
    do {
        printf("\nChoose Disk Scheduling Algorithm:\n");
        printf("1. SSTF\n2. SCAN\n3. C-LOOK\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                SSTF(requests, n, head);
                break;
            case 2:
                SCAN(requests, n, head, disk_size);
                break;
            case 3:
                C_LOOK(requests, n, head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
