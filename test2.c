
// create a struct parrellelogram
// with height and base members
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void create(struct Node** head){
    int size, temp;
    printf("Enter amount of elements you plan on entering: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        struct Node* new_node = malloc(sizeof(struct Node));
        printf("Enter an integer: ");
        scanf("%d", &temp);
        new_node->data = temp;
        new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    } else{
        struct Node* ptr3 = *head;
        while(ptr3->next!=NULL){
            ptr3 = ptr3->next;
        }
        ptr3->next = new_node;
    }
}
}

void delet(struct Node** head){
    if(*head==NULL || (*head)->next == NULL){
        return;
    }
    
    struct Node* ptr = *head;
    while(ptr->next != NULL){
        struct Node* ptr2 = ptr->next;
        ptr->next = ptr2->next;
        free(ptr2);
        ptr = ptr->next;
    }
}

void print(struct Node** head){
    if(*head == NULL){
        printf("errror\n");
        return;
    }
    struct Node* ptr = *head;
    while(ptr != NULL){
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node* head = NULL;
    create(&head);
    print(&head);
// starting at 2nd node delete every other node
    delet(&head);
    printf("\n");
    print(&head);
    

    return 0;
}
