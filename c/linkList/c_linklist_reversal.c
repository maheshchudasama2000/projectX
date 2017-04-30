#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

//static 
void add_node(struct node **head , int val){
   
    struct node *tmp = *head;
    struct node *new_node ;
    
    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("malloc failed\n");
        return ;
    }
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        //add a new node to last node
        tmp->next = new_node;
    }
}

//static
void print_linkList(struct node *head){
    
    struct node *tmp = head;

    if(head == NULL){
        printf("No elements in the linkList\n");
    } else {

        printf("\nlinkList elements :  \n");
        do{
            printf("%d\t",tmp->val);
            tmp = tmp->next;
        }while(tmp->next != NULL);
        printf("%d\t\n",tmp->val);
    }
}

//static
void linkList_reversal(struct node *node_ptr){

    //Todo

}

//static
void delete_linkList(struct node *head){
    struct node *tmp, *current;
    current = head;

    if(head == NULL)
        return ;
    else if(head->next == NULL){
        free(head);
        return ;
    }

    while (current->next != NULL){
        tmp = current->next;
        free(current);
        current = tmp;
    }

    free(current);
}

int main(void) 
{
    int num;
    struct node *head = NULL;

    printf("Enter number between 1-10 to create linkList, Enter 999 to end the list\n");
    printf("Enter new number ");
    scanf("%d",&num);

    while (num != 999){
        //add new node
        add_node(&head, num);
        printf("Enter new number ");
        scanf("%d",&num);
    }

    print_linkList(head);
    delete_linkList(head);
    return 0;
}
