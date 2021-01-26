#include <stdio.h>
#include <stdlib.h>

// Create a node data structure
typedef struct node
{
  int number;
  struct node *next;
} node;

int main(void)
{
  // Create a node list with no pointer value
  node *list = NULL;

  // Create space for a node (e.g. an integer and a pointer)
  node *n = malloc(sizeof(node));

  // Safety check to make sure all is well
  if (n == NULL)
  {
    return 1;
  }

  // Assign n to be 1 and have a pointer value of null, then reassign the list (pointer) to the address of n
  n->number = 1;
  n->next = NULL;
  list = n;

  n = malloc(sizeof(node));

  if (n == NULL)
  {
    free(list);
    return 1;
  }

  n->number = 2;
  n->next = NULL;
  list->next = n;

  n = malloc(sizeof(node));

  if (n == NULL)
  {
    free(list->next);
    free(list);
    return 1;
  }

  n->number = 3;
  n->next = NULL;
  list->next->next = n;

  // Go to the address of list, loop as long as tmp is not null, and update tmp to whatever the value of next is after each iteration
  for (node *tmp = list; tmp != NULL; tmp = tmp->next)
  {
    printf("%i\n", tmp->number);
  }

  while (list != NULL)
  {
    // Create variable with address of the next node
    node *tmp = list->next;
    // List is the first node in the list (not the whole list)
    free(list);
    // Reassign tmp variable, continue loop until all nodes are freed
    list = tmp;
  }
}