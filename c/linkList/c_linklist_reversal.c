#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int val;
    struct node *next;
};

static 
struct node* search_node(struct node *head , int val) {
    struct node *current;
    current = head;
    bool found = 0;

    while(current != NULL){
        if(current->val == val){
            found = true;
            break;
        }
        current = current->next;
    }

    if(found)
        return current;
    else
        return NULL;
}

static 
void add_node(struct node **head , int val){
   
    struct node *tmp = *head;
    struct node *new_node ;
    
    new_node = search_node(*head , val);
    if ( new_node != NULL ){
        printf("Node %d already exist in linkListi\n",val);
        return ;
    }

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

static 
void insert_node(struct node **head , int val){
    
    //ToDo

}

static 
void delete_node(struct node **head , int val) {
    struct node *current;
    struct node *next;
    //bool found = false;

    // linkList is empty
    if ( *head == NULL )
        return ;
    
    current = *head;
    next = current->next;

    //Check 1st node 
    if ( current->val == val){
        *head = current->next;
        free(current);
        //found = true;
        return ;
    }

    while( next != NULL ){
        if( next->val == val ){
            current->next = next->next;
            free(next);
            //found = true;
            break;
        }
        current = next;
        next = next->next;
    }
        
    return ;

}

static
void print_linkList(struct node *head){
    
    struct node *tmp = head;

    if(head == NULL){
        printf("No elements in the linkList\n");
    } else {

        printf("\nlinkList elements : ");
        do{
            printf("%d ",tmp->val);
            tmp = tmp->next;
        }while(tmp != NULL);
        printf("\n");
        //}while(tmp->next != NULL);
        //printf("%d\t\n",tmp->val);
    }
}

static
void linkList_reversal(struct node **head_ptr){

    //Todo
    struct node *current;
    struct node *next;
    struct node *head = *head_ptr;

	if( head == NULL || head->next == NULL)
		return;

	current = head;
	next = current->next;

	head = current;
	head->next = NULL;
    current = next;
	next = current->next;

	while ( current->next != NULL) {
		current->next = head;
		head = current;
		current = next;
		next = current->next;	
	}
	
	current->next = head;
	head = current;
	*head_ptr = head;
}

static
void delete_linkList(struct node **head){
    struct node *tmp, *current;
    current = *head;

    if(current == NULL)
        return ;
    else if( current->next == NULL){
        free(current);
        current = NULL;
        return ;
    }

    while (current->next != NULL){
        tmp = current->next;
        free(current);
        current = tmp;
    }

    free(current);
    *head = NULL;
}

/*
int main(void) 
{
    int num;
    struct node *head = NULL;
    struct node *tmp;
    int vals = 3;
    bool ret = false;

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

	linkList_reversal(&head);
    print_linkList(head);

    tmp = search_node(head , vals );
    if ( tmp != NULL )
        printf("Found Node %d in linkList\n", vals );
    else 
        printf("Node %d not found in linkList\n");

    ret = delete_node(&head, vals );
    if (ret){
        print_linkList(head);
        printf("Node %d is deleted from linkList\n", vals);
    } else
        printf("Node %d is not present in linkList, hence not deleted",vals);

    delete_linkList(head);
    return 0;
}
*/

static 
void create_linkList(struct node **head){

    int num = 0;

    printf("\nEnter any integer to create a linkList, Enter =>999<= to end the list\n");
    printf("Enter new number ");
    scanf("%d",&num);

    while (num != 999){
        //add new node
        add_node(head, num);
        printf("Enter new number ");
        scanf("%d",&num);
    }

}

static 
int print_menu(void){
    
    int num = 0;

    printf("\n 0 : Exist Program\n");
    printf(" 1 : Create linkList\n");
    printf(" 2 : Print  linkList\n");
    printf(" 3 : Reverse linkList\n");
    printf(" 4 : Destroy linkList\n");
    printf(" 5 : Add Node\n");
    printf(" 6 : Insert Node\n");
    printf(" 7 : Delete Node\n");
    printf(" 8 : Search Node\n");
    printf(" Enter Number : ");

    scanf("%d", &num);
    return num;
}

int main(void) 
{
    int num = -1;
    struct node *head = NULL;
    struct node *tmp;
    int val = 0;
    //bool ret = false;

while( num != 0 ) {

    num = print_menu();
    switch( num ){
        case 0 :
            //exit program
            delete_linkList(&head);
            printf("Exit Program");
            break;
        case 1 :
            //create linkList
            delete_linkList(&head);
            create_linkList(&head);
            break;
        case 2 :
            //print linkList
            print_linkList(head);
            break;
        case 3 :
            //reverse linkList
	        linkList_reversal(&head);
            break;
        case 4 :
            //destroy linkList
            delete_linkList(&head);
            break;
        case 5 :
            //add node
            printf("Enter new number : ");
            scanf("%d", &val);
            add_node(&head, val);
            break;
        case 6 :
            //insert node
            printf("Enter new number : ");
            scanf("%d", &val);
            insert_node(&head, val);
            break;
        case 7 :
            //delete node
            printf("Enter new number : ");
            scanf("%d", &val);
            delete_node(&head, val);
            break;
        case 8 :
            //search node
            printf("Enter new number : ");
            scanf("%d", &val);

            tmp = search_node(head , val );
            if ( tmp != NULL )
                printf("Found value %d in linkList\n", val );
            else 
                printf("Value %d not found in linkList\n", val );

            break;
        default :
            printf("Enter Valid number\n");
            break;
    } //end switch

}//end while

    return 0;
}
