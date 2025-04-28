
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10
#define MAX_NAME_LENGTH 50
#define MAX_EVENTS 20
#define MAX_EVENT_LENGTH 100
#define MAX_SUPPLIES 25
#define MAX_SUPPLY_LENGTH 50

// Contact structure: stores name and phone number for each emergency contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[20];
} Contact;

// Array of events (calendar), starts empty
char events[MAX_EVENTS][MAX_EVENT_LENGTH];
int event_count = 0; // Initial number of events

// Array of emergency contacts, initialized with some sample contacts
 Contact contacts[MAX_CONTACTS];

//Array of emergency supplies
char supplies[MAX_SUPPLIES][MAX_SUPPLY_LENGTH];
int supply_count = 0;
int contact_count = 0; // Initial number of contacts




//first 3 fucntions load event, contact, and supply list info from filesystem
void loadContactsFile(){
  FILE* fileptr = fopen("contacts.txt", "r");
  if(fileptr == NULL){
    printf("contacts file failed to open!\n");
  }
  while(fscanf(fileptr, "%49[^,],%19[^\n]\n", contacts[contact_count].name, contacts[contact_count].number) ==2){
    contact_count++;
  if(contact_count >= MAX_CONTACTS)
  {
    break;
  }
}
fclose(fileptr);
}

void loadEvents(){
    FILE* fileptr = fopen("events.txt", "r");
    if(fileptr == NULL){
        printf("Events File not found!\n");
        return;
    }
    char line[MAX_EVENT_LENGTH];
    event_count = 0;
    while(fgets(line, sizeof(line), fileptr) && event_count < MAX_EVENTS){
        // errors if there a newline character
        line[strcspn(line, "\n")] = '\0';

        strncpy(events[event_count], line, MAX_EVENT_LENGTH - 1);
        events[event_count][MAX_EVENT_LENGTH - 1] = '\0';
        event_count++;
    }
    fclose(fileptr);
    }

void loadSupplies(){
    FILE* fileptr = fopen("supplies.txt", "r");
    if(fileptr == NULL){
        printf("Supplies file not found!\n");
        return;
    }
    char line[MAX_SUPPLY_LENGTH];
    supply_count = 0;
    while(fgets(line, sizeof(line), fileptr) && supply_count < MAX_SUPPLIES){
        //errors if there is a newline character
        line[strcspn(line, "\n")] = '\0';

        strncpy(supplies[supply_count], line, MAX_SUPPLY_LENGTH - 1);
        supplies[supply_count][MAX_SUPPLY_LENGTH-1] = '\0';
        supply_count++;
    }
    fclose(fileptr);
}







//The next 3 functions save events, supply list info, and contacts to filesystem 
void saveEventsFile(){
    FILE* fileptr = fopen("events.txt", "w");
    if(fileptr == NULL){
        printf("Failed to find Events file.\n");
        return;
    }
    for(int i = 0;i< event_count;i++){
        fprintf(fileptr, "%s\n", events[i]);
    }
    fclose(fileptr);
}

void saveSupplies(){
    FILE* fileptr = fopen("supplies.txt", "r");
    if(fileptr == NULL){
        printf("Error supplies file not found.\n");
        return;
    }
    for(int i=0;i<supply_count;i++){
        fprintf(fileptr, "%s\n", supplies[i]);
    }
    fclose(fileptr);
}

void saveContactFile(){
       FILE *fileptr = fopen("contacts.txt", "w");
    if (fileptr == NULL) {
        printf("Failed to find contacts file.\n");
        return;
    }
    for (int i = 0; i < contact_count; i++) {
        fprintf(fileptr, "%s,%s\n", contacts[i].name, contacts[i].number);
    }
    fclose(fileptr);
}




// Next 3 fucntions handle manipulation of supply list array
// Function to display a list of emergency supplies to have on hand
void show_supplies() {
    printf("\nEmergency Supply List:\n");
       if(supply_count == 0){
        printf("No supplies added yet.\n");
    } else {
        for(int i=0;i<supply_count;i++){
            printf("%d. %s\n", i+1, supplies[i]);
        }
    }
}

void add_supplies(){
    if(supply_count >= MAX_SUPPLIES){
        printf("Supply List Full. Cannot add more events.\n");
        return;
    }
    getchar();
    char new_supply[MAX_SUPPLY_LENGTH];
    printf("Enter a new item: ");
    scanf("%[^\n]", new_supply); // allows spaces in name of supply.

    //Add new item to supply array
    strcpy(supplies[supply_count], new_supply);
    supply_count++;
    saveSupplies();
    printf("Item saved to supply list successfully!\n");
}

void delete_supply(){
    int index;
    show_supplies();
    printf("Enter the number of item to delete(0 to cancel): ");
    scanf("%d", &index);

    if(index < 1 || index > supply_count){
        printf("Canceled or invalid choice.\n");
        return;
    }
    // shift supply array after deleted item
    for(int i = index - 1; i < supply_count; i++){
        strcpy(events[i], events[i+1]);
    }
    supply_count--;
    printf("Item deleted.\n");
    saveSupplies();
}





 
// Function to display the emergency guide with basic instructions
void guide() {
    printf("\nEmergency Guide:\n");
    printf("- Earthquake: Drop, Cover, and Hold On.\n");
    printf("- Fire: Stop, Drop, and Roll.\n");
    printf("- Flood: Move to higher ground immediately.\n");
}



// The next 3 functions are for manipulating the events array
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
    getchar();
    char new_event[MAX_EVENT_LENGTH];
    printf("Enter new event: ");
    scanf("%[^\n]", new_event);  // allows spaces in the event description

    // Add the new event to the events array
    strcpy(events[event_count], new_event);
    event_count++; // Increment the event count
    printf("Event added successfully.\n");
    saveEventsFile();
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
    saveEventsFile();
}






// The next 3 functions are for manipulating the contacts array
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
    scanf(" %[^\n]", name);  // Read input with spaces
    printf("Enter phone number: ");
    scanf(" %s[^]", number);  // Read input for the phone number

    // Add new contact to the contacts array
    strcpy(contacts[contact_count].name, name);
    strcpy(contacts[contact_count].number, number);
    contact_count++; // Increment the contact count
    printf("Contact added successfully.\n");
    saveContactFile();
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
    saveContactFile();
}







//The next 3 functions are the menu system for UI
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

// Menu to handle supply list, adding, removing, and displaying
void supply_menu(){
    int choice;
    while(1){
        printf("\nSupply Menu:\n");
        printf("1. View Supplies\n");
        printf("2. Add an Item\n");
        printf("3. Delete an Item\n");
        printf("4. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: show_supplies(); break;
            case 2: add_supplies(); break;
            case 3: delete_supply(); break;
            case 4: return; //Go back to main menu
            default: printf("Invalid choice\n"); //Handle invalid input
        }
    }
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

// ---------------------------------------------------------------------------------------
// Main function to display the initial prompt and provide the main menu
int main() {
    int choice;
    loadContactsFile();
    loadEvents();
    loadSupplies();

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
        printf("2. View Supply Menu\n");
        printf("3. Community Calendar\n");
        printf("4. Emergency Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get the user's choice

        switch (choice) {
            case 1: guide(); break; // View the emergency guide
            case 2: supply_menu(); break; // View the supply list
            case 3: calendar_menu(); break; // Manage the calendar
            case 4: contact_menu(); break; // Manage emergency contacts
            case 5: printf("Exiting. Stay safe!\n"); return 0; // Exit the program
            default: printf("Invalid choice.\n"); // Handle invalid input
        }
    }
}
