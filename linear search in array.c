#include <stdio.h>

int main() {
    int n, key, i, found = 0;

    // Read the size of the array
    scanf("%d", &n);

    int arr[n];

    // Read n elements of the array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the element to search for
    scanf("%d", &key);

    // Linear search
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("found at position %d\n", i);
            found = 1;
            break;
        }
    }

    // If element not found
    if(!found) {
        printf("%d not found\n", key);
    }

    return 0;
}
