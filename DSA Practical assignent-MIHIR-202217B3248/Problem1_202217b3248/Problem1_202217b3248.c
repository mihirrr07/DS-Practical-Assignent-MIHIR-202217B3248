#include <stdio.h>
#include <stdlib.h> // Include for exit() function
#define MAX 20 // Adjusted the MAX value to match array size

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, p, e, i, pos;

int main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        // Call the appropriate function based on user choice
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); // Exit the program
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g); // Note the space before %c to consume any leftover newline character
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Number of nodes exceeds the maximum allowed (%d)\n", MAX);
        return;
    }
    for (i = 0; i < n; i++) {
        printf("\nEnter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos >= n || pos < 0) {
        printf("\nInvalid Location\n");
        return;
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }
    printf("\nThe Elements after deletion:");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
    printf("\n");
}

void search() {
    printf("\nEnter the Element to be searched: ");
    scanf("%d", &e);
    int found = 0;
    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list\n", e);
    }
}

void insert() {
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);
    if (pos > n || pos < 0 || n >= MAX) {
        printf("\nInvalid Location\n");
        return;
    } else {
        for (i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
    }
    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    printf("\nThe Elements of The list ADT are:");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}
