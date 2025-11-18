#include <stdio.h>
#include <stdlib.h>


typedef struct __NODE__
{
    int val;
    struct __NODE__* next;

}node;

//  add_new_node to match function call in main
node* add_new_node(int val)
{
    // Use calloc to initialize memory to 0 (NULL/0) is often safer
    node* output = (node*)calloc(1, sizeof(node)); 
    if (output == NULL) {
        perror("Failed to allocate node");
        exit(EXIT_FAILURE);
    }
    output->val = val;
    output->next = NULL;

    return output;
}



void addEnd(node* head, node* newNode)
{
    node* current;

    // traverse the list untill we reach the node we want
    for(current = head; current->next != NULL; current = current->next);

    current->next = newNode;
}


void addHead(node** head, node* newHead)
{
    newHead->next = *head;
    *head = newHead;
}

// Dedicated function to safely get the length of the list
int get_length(node* head)
{
    int length = 0;
    node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void bubble_sort(node* head)
{
    int i, j, hold;
    node *curr_i, *curr_j;

    for(curr_i = head, i = 0; i < get_length(head); i++, curr_i = curr_i->next)
    {
        for(curr_j = curr_i->next, j = i + 1; j < get_length(head); j++, curr_j = curr_j->next)
        {
            if(curr_j->val < curr_i->val)
            {
                hold = curr_i->val;
                curr_i->val = curr_j->val;
                curr_j->val = hold;
            }
        } 
    } 

}

void insert_node(node** head_ref, node* new_node, int index)
{   
    node* current = *head_ref;
    int length = get_length(current);
    
    // 1. Handle Insertion at Head (Index 0)
    if (index == 0) {
        addHead(head_ref, new_node);
        return;
    }

    // 2. Handle Invalid Index (Past the end)
    if (index > length || index < 0) {
        printf("Error: Index %d is out of bounds (Length is %d).\n", index, length);
        return;
    }

    // 3. Handle Insertion in the Middle or at the End
    // We stop at the node *before* the insertion point (index - 1)
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    // Now 'current' points to the node *before* where we want to insert.
    new_node->next = current->next;
    current->next = new_node;
}


int delete_node_by_index(node** head, int index)
{
    int length = get_length(* head);
    if(index > length || index < 0)
        return -1;

    node* hold;

    if(index == 0)
    {
        hold = (*head)->next;
        (*head) = (*head) ->next;
        free(hold);
        return 0;
    }

    int i;
    node* current;

    for(current = *head, i = 0; i < index - 1; i++, current = current->next);
    
    hold = current->next;
    current->next = current->next->next;
    printf("Deleted number % d\n", hold->val);
    free(hold);
    return 0;
}


int print_nodes(node* head)
{   
    int index = 0;
    node* current = head; // Start with the head node
    
    while(current != NULL)
    {
        printf("Index %d: Value = %d\n", index, current->val);
        current = current->next;
        index += 1;
    }
    return index;
}


int main()
{
    // Create the initial head node
    node* head = add_new_node(1);

    // Add nodes to the end
    addEnd(head, add_new_node(10));
    addEnd(head, add_new_node(3));
    addEnd(head, add_new_node(4));
    addEnd(head, add_new_node(45));
    addEnd(head, add_new_node(6));
    addEnd(head, add_new_node(17)); // Changed value for clarity

    // Add a node to the head (Index 0)
    addHead(&head, add_new_node(-1));

    printf("--- List Before Insertion ---\n");
    print_nodes(head);
    printf("Length: %d\n\n", get_length(head));

    // Insert 99 at Index 3 and delete second node after insert and then sort the list using bubble sort  
    insert_node(&head, add_new_node(99), 3);
    delete_node_by_index(&head, 2);
    printf("--- List After inserting 99 at index 3, deleting the second node and sort it using bubble sort ---\n");
    bubble_sort(head);
    print_nodes(head);
    printf("Length: %d\n", get_length(head));
    
    
    return 0;
}
