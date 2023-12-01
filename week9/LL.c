#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The struct for a node - contains a value, and a pointer to the next node.
 * 
 */
typedef struct node
{
    int value;
    struct node *next;
} node;



/**
 * @brief Ask the user for the new value of the node, and add it to the end of the linked list.
 *
 * @param linked_list pass in the linked list (the first node)
 */
void add_new_node(node* linked_list)
{
    // write me
}


/**
 * @brief Remove the linked list item at the given position, or give some helpful error message if there is no node there.
 *
 * @param linked_list pass in the linked list (the first node)
 * @param pos The position to be removed (0-indexed)
 */
void remove_node(node* linked_list, int pos)
{
    // write me
    // be extra careful about removing the first and the last item :)
}



/**
 * @brief Print the linked list in a neatly formatted way
 * 
 * @param linked_list the linked list.
 */
void print_linked_list(node* linked_list) 
{
    // write me
}

/**
 * @brief Returns the length of the linked list - this one is provided as it might be useful for you :)
 * 
 * @param linked_list the linked list
 * @return int the length of the linked list
 */
int length(node* linked_list)
{
    int counter = 1;
    node* current = linked_list;
    while(current->next != NULL)
    {
        current = current->next;
        counter++;
    }
    return counter;

}

int main()
{

    // creating a first node to get us started...
    node first;
    first.value = 20;
    first.next = NULL;

    // this will be our linked list from now on.
    node* linked_list = &first;

    printf("%d\n", length(linked_list));
}