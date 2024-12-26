#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to hold contact details
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

#define MAX_CONTACTS 100
Contact contacts[MAX_CONTACTS];
int contact_count = 0;

// Function prototypes
void add_contact();
void list_contacts();
void search_contact();
void delete_contact();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_contact(); break;
            case 2: list_contacts(); break;
            case 3: search_contact(); break;
            case 4: delete_contact(); break;
            case 5: printf("Exiting program...\n"); exit(0); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n=== Contact Management System ===\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    Contact new_contact;
    printf("Enter name: ");
    getchar(); // Clear the input buffer
    fgets(new_contact.name, 50, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0'; // Remove newline
    printf("Enter phone: ");
    fgets(new_contact.phone, 15, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = '\0'; // Remove newline
    printf("Enter email: ");
    fgets(new_contact.email, 50, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = '\0'; // Remove newline

    contacts[contact_count++] = new_contact;
    printf("Contact added successfully!\n");
}

void list_contacts() {
    if (contact_count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n=== Contact List ===\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Contact %d\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("---------------------\n");
    }
}

void search_contact() {
    if (contact_count == 0) {
        printf("No contacts available to search.\n");
        return;
    }
    char name[50];
    printf("Enter the name to search: ");
    getchar(); // Clear the input buffer
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            printf("\nContact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact() {
    if (contact_count == 0) {
        printf("No contacts available to delete.\n");
        return;
    }
    char name[50];
    printf("Enter the name to delete: ");
    getchar(); // Clear the input buffer
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contact_count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}
