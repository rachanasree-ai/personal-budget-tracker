#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float income;
} BudgetTracker;

// Function to add a transaction
void addTransaction(BudgetTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_TRANSACTIONS) {
        strcpy(tracker->transactions[tracker->count].description, description);
        tracker->transactions[tracker->count].amount = amount;
        tracker->count++;
    } else {
        printf("Transaction limit reached! Cannot add more transactions.\n");
    }
}

// Function to calculate total expenses
float getTotalExpenses(const BudgetTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->transactions[i].amount;
    }
    return total;
}

// Function to display the budget summary
void displaySummary(const BudgetTracker *tracker) {
    printf("\n--- Budget Summary ---\n");
    printf("Total Income: $%.2f\n", tracker->income);
    printf("Total Expenses: $%.2f\n", getTotalExpenses(tracker));
    printf("Remaining Budget: $%.2f\n", tracker->income - getTotalExpenses(tracker));
    printf("\nTransactions:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s: $%.2f\n", tracker->transactions[i].description, tracker->transactions[i].amount);
    }
}

int main() {
    BudgetTracker tracker;
    tracker.count = 0;
    tracker.income = 0.0;

    printf("Welcome to the Personal Budget Tracker!\n");

    // Input income
    printf("Enter your total income: $");
    scanf("%f", &tracker.income);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. View Summary\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char description[50];
                float amount;

                printf("Enter expense description: ");
                scanf(" %[^\n]", description); // Read string with spaces
                printf("Enter expense amount: $");
                scanf("%f", &amount);

                addTransaction(&tracker, description, amount);
                break;
            }
            case 2:
                displaySummary(&tracker);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}