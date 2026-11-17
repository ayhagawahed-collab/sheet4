#include <stdio.h>
#include "global.h"
#include "stack.h"
#include "queue.h"

static void PrintCustomer(element_type c) {
    printf("  Name: %-20s ID: %d\n", c.name, c.id);
}

static void AddCustomer(Queue *q) {
    element_type c;
    if (QueueFull(q)) {
        printf("The workshop is full, cannot add more customers.\n");
        return;
    }
    printf("Enter customer name: ");
    scanf(" %49[^\n]", c.name);
    printf("Enter customer ID: ");
    scanf("%d", &c.id);
    Enqueue(c, q);
    printf("Customer added.\n");
}

static void ServeCustomer(Queue *q) {
    element_type c;
    if (!Dequeue(&c, q)) {
        printf("No customers waiting.\n");
        return;
    }
    printf("Serving customer:\n");
    PrintCustomer(c);
}

static void DisplayCustomers(Queue *q) {
    int i, n = QueueSize(q);
    element_type c;
    if (n == 0) {
        printf("No customers waiting.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        Dequeue(&c, q);
        PrintCustomer(c);
        Enqueue(c, q);
    }
}

static void DisplayMostRecent(Queue *q) {
    Stack s;
    element_type c;
    int i, n = QueueSize(q);

    if (n == 0) {
        printf("No customers waiting.\n");
        return;
    }
    CreateStack(&s);
11
    for (i = 0; i < n; i++) {
        Dequeue(&c, q);
        Push(c, &s);
        Enqueue(c, q);
    }
    while (Pop(&c, &s))
        PrintCustomer(c);
}

int main(void) {
    Queue q;
    int choice;

    CreateQueue(&q);

    do {
        printf("\n===== Car Workshop =====\n");
        printf("1. Add a New Customer.\n");
        printf("2. Serve a customer.\n");
        printf("3. Display Customers Information.\n");
        printf("4. Display Customers information in the \"most-recent\" Order.\n");
        printf("5. Exit menu\n");
        printf("Your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: AddCustomer(&q);          break;
            case 2: ServeCustomer(&q);        break;
            case 3: DisplayCustomers(&q);     break;
            case 4: DisplayMostRecent(&q);    break;
            case 5: printf("Goodbye!\n");     break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);

    return 0;
}
