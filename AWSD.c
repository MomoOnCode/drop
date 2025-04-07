// Include necessary library
#include <stdio.h>
// Include necessary library
#include <string.h>

// Define the maximum number of guides
#define MAX_GUIDES 5
// Define the maximum number of events
#define MAX_EVENTS 5
// Define the maximum number of contacts
#define MAX_CONTACTS 5

// Structure to store guide information
struct Guide {
    char title[100];
    char content[500];
};

// Structure to store event details
struct Event {
    char eventName[100];
    char eventDetails[200];
};

// Structure to store contact details
struct Contact {
    char name[100];
    char phoneNumber[20];
};

// Structure to store guide information
struct Guide guides[MAX_GUIDES];
// Structure to store event details
struct Event events[MAX_EVENTS];
// Structure to store contact details
struct Contact contacts[MAX_CONTACTS];

int guideCount = 0;
int eventCount = 0;
int contactCount = 0;

void displayMenu() {

    printf("\n--- Main Menu ---\n");

    printf("1. View Tips\n");

    printf("2. View Guides\n");

    printf("3. View Events\n");
// Print output to the console
    printf("4. View Contacts\n");
// Print output to the console
    printf("5. Save Emergency Guide\n");
// Print output to the console
    printf("6. Save Community Event\n");
// Print output to the console
    printf("7. Save Emergency Contact\n");
// Print output to the console
    printf("8. Show Arlington Emergency Preparedness Locations\n");
// Print output to the console
    printf("9. Exit\n");
// Print output to the console
    printf("Enter your choice: ");
}

void emergencyPrompt() {
// Print output to the console
    printf("\n******************************************************\n");
// Print output to the console
    printf("   ALERT: In case of an emergency, please dial 911.\n");
// Print output to the console
    printf("******************************************************\n");
// Print output to the console
    printf("Press Enter to continue to the main menu...\n");
    getchar();
}

void showArlingtonEmergencyPreparedness() {
// Print output to the console
    printf("\nEmergency Preparedness Locations in Arlington, TX:\n");
// Print output to the console
    printf("1. City of Arlington Emergency Preparedness: Provides hazard and disaster preparedness information.\n");
// Print output to the console
    printf("   Website: https://www.arlingtontx.gov/city_hall/departments/fire/emergency_preparedness\n");
// Print output to the console
    printf("2. North Central Texas Council of Governments (NCTCOG): Regional emergency preparedness services.\n");
// Print output to the console
    printf("   Website: https://www.nctcog.org/ep\n");
// Print output to the console
    printf("Press Enter to return to the main menu...\n");
    getchar();
}

void saveGuide() {
    if (guideCount < MAX_GUIDES) {
// Print output to the console
        printf("Enter Guide Title: ");
        fgets(guides[guideCount].title, sizeof(guides[guideCount].title), stdin);
        guides[guideCount].title[strcspn(guides[guideCount].title, "\n")] = '\0';

// Print output to the console
        printf("Enter Guide Content: ");
        fgets(guides[guideCount].content, sizeof(guides[guideCount].content), stdin);
        guides[guideCount].content[strcspn(guides[guideCount].content, "\n")] = '\0';

        guideCount++;
// Print output to the console
        printf("Guide saved!\n");
    } else {
// Print output to the console
        printf("Guide list is full.\n");
    }
}

void viewGuides() {
    if (guideCount == 0) {
// Print output to the console
        printf("\nNo emergency guides available.\n");
        return;
    }

// Print output to the console
    printf("\nSaved Guides:\n");
    for (int i = 0; i < guideCount; i++) {
// Print output to the console
        printf("Title: %s\n", guides[i].title);
// Print output to the console
        printf("Content: %s\n", guides[i].content);
// Print output to the console
        printf("-------------------------\n");
    }
}

void saveEvent() {
    if (eventCount < MAX_EVENTS) {
// Print output to the console
        printf("Enter Event Name: ");
        fgets(events[eventCount].eventName, sizeof(events[eventCount].eventName), stdin);
        events[eventCount].eventName[strcspn(events[eventCount].eventName, "\n")] = '\0';

// Print output to the console
        printf("Enter Event Details: ");
        fgets(events[eventCount].eventDetails, sizeof(events[eventCount].eventDetails), stdin);
        events[eventCount].eventDetails[strcspn(events[eventCount].eventDetails, "\n")] = '\0';

        eventCount++;
// Print output to the console
        printf("Event saved!\n");
    } else {
// Print output to the console
        printf("Event list is full.\n");
    }
}

void viewEvents() {
    if (eventCount == 0) {
// Print output to the console
        printf("No events saved yet.\n");
        return;
    }

// Print output to the console
    printf("\nSaved Events:\n");
    for (int i = 0; i < eventCount; i++) {
// Print output to the console
        printf("Event: %s\n", events[i].eventName);
// Print output to the console
        printf("Details: %s\n", events[i].eventDetails);
// Print output to the console
        printf("-------------------------\n");
    }
}

void saveContact() {
    if (contactCount < MAX_CONTACTS) {
// Print output to the console
        printf("Enter Contact Name: ");
        fgets(contacts[contactCount].name, sizeof(contacts[contactCount].name), stdin);
        contacts[contactCount].name[strcspn(contacts[contactCount].name, "\n")] = '\0';

// Print output to the console
        printf("Enter Contact Phone Number: ");
        fgets(contacts[contactCount].phoneNumber, sizeof(contacts[contactCount].phoneNumber), stdin);
        contacts[contactCount].phoneNumber[strcspn(contacts[contactCount].phoneNumber, "\n")] = '\0';

        contactCount++;
// Print output to the console
        printf("Contact saved!\n");
    } else {
// Print output to the console
        printf("Contact list is full.\n");
    }
}

void viewContacts() {
    if (contactCount == 0) {
// Print output to the console
        printf("No contacts saved yet.\n");
        return;
    }

// Print output to the console
    printf("\nSaved Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
// Print output to the console
        printf("Name: %s\n", contacts[i].name);
// Print output to the console
        printf("Phone Number: %s\n", contacts[i].phoneNumber);
// Print output to the console
        printf("-------------------------\n");
    }
}

void displaySampleTips() {
// Print output to the console
    printf("\nSample Disaster Preparedness Tips:\n");
// Print output to the console
    printf("1. CPR: Perform CPR if the person is not breathing.\n");
// Print output to the console
    printf("2. Bleeding: Apply pressure to stop bleeding.\n");
// Print output to the console
    printf("3. Burns: Cool the burn with cold water.\n");
// Print output to the console
    printf("Press Enter to return to the main menu...\n");
    getchar();
}

// Main function: Entry point of the program
int main() {
    emergencyPrompt();

    int choice;
    
    do {
        displayMenu();
// Take input from the user
        scanf("%d", &choice);
// Take input from the user
        getchar(); // Clear newline after scanf
        
        switch (choice) {
            case 1: displaySampleTips(); break;
            case 2: viewGuides(); break;
            case 3: viewEvents(); break;
            case 4: viewContacts(); break;
            case 5: saveGuide(); break;
            case 6: saveEvent(); break;
            case 7: saveContact(); break;
            case 8: showArlingtonEmergencyPreparedness(); break;
// Print output to the console
            case 9: printf("Exiting...\n"); break;
// Print output to the console
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 9);

    return 0;
}