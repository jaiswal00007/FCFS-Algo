#include <stdio.h>

int main() {
    int frames;

    // Get user input for the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Check if the number of frames is valid
    if (frames <= 0) {
        printf("Invalid number of frames. Exiting...\n");
        return 1; // Exit with an error code if frames is not a positive integer
    }

    int pageCount;

    // Get user input for the number of pages in the incoming sequence
    printf("Enter the number of pages in the incoming sequence: ");
    scanf("%d", &pageCount);

    int pages[pageCount];

    // Get user input for the incoming page sequence
    printf("Enter the incoming page sequence (separated by spaces): ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    int pageFaults = 0;

    // Print the header for the table
    printf("Page \t Frames\n");

    int temp[frames];

    // Initialize frames with -1 indicating an empty slot
    for (int i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    for (int i = 0; i < pageCount; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        // Check if the current page is already in a frame
        for (int j = 0; j < frames; j++) {
            if (temp[j] == currentPage) {
                pageFound = 1;
                pageFaults--;
            }
        }

        pageFaults++;

        // Replace a page if it's not in a frame
        if (pageFaults <= frames && !pageFound) {
            temp[i] = currentPage;
        } else if (!pageFound) {
            temp[(pageFaults - 1) % frames] = currentPage;
        }

        // Print the current state of frames
        printf("%d\t", currentPage);
        for (int j = 0; j < frames; j++) {
            if (temp[j] != -1)
                printf("%d ", temp[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    // Print the total number of page faults
    printf("\nTotal Page Faults: %d", pageFaults);
    printf("\tTotal Page Hit:%d\n",pageCount-pageFaults);

    return 0;
}
