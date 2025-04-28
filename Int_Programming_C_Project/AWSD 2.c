
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10
#define MAX_NAME_LENGTH 50
#define MAX_EVENTS 20
#define MAX_EVENT_LENGTH 100

// Contact structure: stores name and phone number for each emergency contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[20];
} Contact;

// Array of emergency contacts, initialized with some sample contacts
Contact contacts[MAX_CONTACTS] = {
    {"Police Department", "911"},
    {"Fire Department", "922"},
    {"Local Hospital", "933"}
};
int contact_count = 3; // Initial number of contacts

// Array of events (calendar), starts empty
char events[MAX_EVENTS][MAX_EVENT_LENGTH];
int event_count = 0; // Initial number of events

// Function to display the emergency guide with basic instructions
void guide() {
    printf("\nEmergency Guide:\n");
    printf("- Earthquake: Drop, Cover, and Hold On.\n");
    printf("- Fire: Stop, Drop, and Roll.\n");
    printf("- Flood: Move to higher ground immediately.\n");
}

// Function to display a list of emergency supplies to have on hand
void supply_list() {
    printf("\nEmergency Supply List:\n");
    printf("- Water (1 gallon per person per day)\n");
    printf("- Non-perishable food\n");
    printf("- Flashlight and extra batteries\n");
    printf("- First aid kit\n");
    printf("- Medications\n");
}

// Function to show the current calendar events
void show_calendar() {
    printf("\nCommunity Event Calendar:\n");
    if (event_count == 0) {
        printf("- No events added yet.\n"); // If there are no events, display this message
    } else {
        // If there are events, display each one
        for (int i = 0; i < event_count; i++) {
            printf("%d. %s\n", i + 1, events[i]);
        }
    }
}

// Function to add a new event to the calendar
void add_event() {
    if (event_count >= MAX_EVENTS) {
        printf("Event list is full. Cannot add more events.\n"); // Check if the calendar is full
        return;
    }

    char new_event[MAX_EVENT_LENGTH];
    printf("Enter new event: ");
    scanf(" %[^
]", new_event);  // allows spaces in the event description

    // Add the new event to the events array
    strcpy(events[event_count], new_event);
    event_count++; // Increment the event count
    printf("Event added successfully.\n");
}

// Function to delete an event by its number in the list
void delete_event() {
    int index;
    show_calendar(); // Show current events before deletion
    printf("Enter the number of the event to delete (0 to cancel): ");
    scanf("%d", &index); // Ask user for the event number to delete

    if (index < 1 || index > event_count) {
        printf("Cancelled or invalid choice.\n"); // Invalid choice or cancellation
        return;
    }

    // Shift events after the deleted one
    for (int i = index - 1; i < event_count - 1; i++) {
        strcpy(events[i], events[i + 1]);
    }
    event_count--; // Decrease the event count after deletion
    printf("Event deleted.\n");
}

// Menu to handle calendar-related choices: viewing, adding, and deleting events
void calendar_menu() {
    int choice;
    while (1) {
        printf("\nCalendar Menu:\n");
        printf("1. View Events\n");
        printf("2. Add an Event\n");
        printf("3. Delete an Event\n");
        printf("4. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice); // Get the user's menu choice

        switch (choice) {
            case 1: show_calendar(); break; // Show events
            case 2: add_event(); break; // Add an event
            case 3: delete_event(); break; // Delete an event
            case 4: return; // Go back to the main menu
            default: printf("Invalid choice.\n"); // Handle invalid input
        }
    }
}

// Function to display all emergency contacts
void show_contacts() {
    printf("\nEmergency Contacts:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].number); // Print contact info
    }
}

// Function to add a new contact to the emergency contact list
void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full. Cannot add more contacts.\n"); // Check if the contact list is full
        return;
    }

    char name[MAX_NAME_LENGTH];
    char number[20];

    printf("Enter contact name: ");
    scanf(" %[^
]", name);  // Read input with spaces
    printf("Enter phone number: ");
    scanf(" %[^
]", number);  // Read input for the phone number

    // Add new contact to the contacts array
    strcpy(contacts[contact_count].name, name);
    strcpy(contacts[contact_count].number, number);
    contact_count++; // Increment the contact count
    printf("Contact added successfully.\n");
}

// Function to delete a contact by number
void delete_contact() {
    int index;
    show_contacts(); // Show current contacts before deletion
    printf("Enter the number of the contact to delete (0 to cancel): ");
    scanf("%d", &index); // Ask user for the contact number to delete

    if (index < 1 || index > contact_count) {
        printf("Cancelled or invalid choice.\n"); // Invalid choice or cancellation
        return;
    }

    // Shift contacts after the deleted one
    for (int i = index - 1; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contact_count--; // Decrease the contact count after deletion
    printf("Contact deleted.\n");
}

// Menu to handle contact-related choices: viewing, adding, and deleting contacts
void contact_menu() {
    int choice;
    while (1) {
        printf("\nContact Menu:\n");
        printf("1. Show Contacts\n");
        printf("2. Add a Contact\n");
        printf("3. Delete a Contact\n");
        printf("4. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice); // Get the user's menu choice

        switch (choice) {
            case 1: show_contacts(); break; // Show contacts
            case 2: add_contact(); break; // Add a contact
            case 3: delete_contact(); break; // Delete a contact
            case 4: return; // Go back to the main menu
            default: printf("Invalid choice.\n"); // Handle invalid input
        }
    }
}

// Main function to display the initial prompt and provide the main menu
int main() {
    int choice;

    // Emergency prompt displayed when the program starts
    printf("=====================================\n");
    printf("  Disaster Preparedness Resource Hub \n");
    printf("=====================================\n");
    printf("** If this is a real emergency, please dial 911. **\n");
    printf("Press Enter to continue to the main menu...");
    getchar(); // Clear leftover newline
    getchar(); // Wait for Enter

    // Main menu loop
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. View Emergency Guide\n");
        printf("2. View Supply List\n");
        printf("3. Community Calendar\n");
        printf("4. Emergency Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get the user's choice

        switch (choice) {
            case 1: guide(); break; // View the emergency guide
            case 2: supply_list(); break; // View the supply list
            case 3: calendar_menu(); break; // Manage the calendar
            case 4: contact_menu(); break; // Manage emergency contacts
            case 5: printf("Exiting. Stay safe!\n"); return 0; // Exit the program
            default: printf("Invalid choice.\n"); // Handle invalid input
        }
    }
}
