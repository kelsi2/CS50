# Data Structures

- An array is a data structure but we need to decide ahead of time how much memory to set aside for it, we can't just resize it

  - That array is surrounded by other things in memory, not free space
  - What we can do is copy the array to a new space in memory with more space available, this also frees space in the original memory
    - We can't just put the value anywhere on its own, the array needs to be moved
    - This however takes a lot of time to run, O(n) (inserting a value in an array), lower bound (best case) of run time is Ω(1) if the array only has one element and we can just put the number in place

- We can build custom data structures better than arrays to store memory using the following:
  - struct: Define a structure in memory
  - . Go inside a structure
  - \* Go to a spot in memory
  - -> A combination of . and \*, a pointer

## Linked Lists

- Dynamic data structure that can grow or shrink without moving to a new location and considering each entry every time
  - We can store indices anywhere in memory and link to them, they don't need to be located together
  - Each index takes up double the space, basically metadata to track the address (pointer) of the next index, the last one stores 0x0 (NULL) so we know there are no further values
  - Linked list is a collection of nodes connected by pointers
- Drawback is that this takes a lot of extra memory, we need to consider if space or time is more important

```c
typedef struct node
{
  int number;
  struct node *next;
}
node;
```

- C doesn't understand anything it hasn't seen before so we can't use node as a pointer (it doesn't know what it is until the typedef is finished)

  - We fix this problem by including node in the initial definition and placing struct when referring to it within the typedef

- When we add a new node we are using malloc to create space for that node

```c
// This represents an empty linked list, not pointing at any values
node *list = NULL;

// This allocates memory for whatever size the node is and returns the address of the first index
// Currently nothing in the node n is pointing at, it contains garbage values
node *n = malloc(sizeof(node));

// If there is a pointer ALWAYS check if it's null before assigning anything, this checks if it's a valid address
// This says if it exists, assign the number 1 at that address
// Also setting the next pointer to NULL because it isn't going anywhere but we need to know it exists
// Arrow notation is the same as *.
if (n != NULL)
{
  (*n).number = 1;
  n->next = NULL;
}

// This allows us to remember that n is a node in the linked list, without this code list doesn't know they're connected. n is temporary and can now be disposed of (we now have a pointer from list to the first node)
list = n;

// We are now creating another node and assigning it to n again (since it is no longer in use)
// Assigning number 2 and saying the pointer has no address
node *n = malloc(sizeof(node));
if (n != NULL)
{
  n->number = 2;
  n->next = NULL;
}

// Again, without this line 2 is not part of the linked list, we need this to say point from 1 next to 2 node
// We now have a linked list of size 2
list->next = n;

// Run the same process again, the only thing that changes is the value of n
node *n = malloc(sizeof(node));
if (n != NULL)
{
  n->number = 3;
  n->next = NULL;
}

// Follow the pointers from list through the 2 next addresses to the new node and assign it to be part of the linked list
// We now have a linked list of size 3
list->next->next = n;
```

- Running time of searching a linked list is still O(n) because you still need to look through all indices before finding the one you need (we only have the address of the linked list, not everything in it)
- Running time of INSERTING to a linked list is O(1) because we can place it anywhere in memory, if it doesn't need to be in sorted order (we can literally insert it as the first value), it is a constant time with the same amount of steps

* If we are inserting new values to a list and we need it to be sorted things get a bit complicated. We need to make sure we don't lose the addresses of the other variables in the list (need to assign the address of the next node first before assigning the variable)

```c
n->next = list;
list = n;
```

- Linked lists are better but not great, there is still a lot of traversing of nodes so performance is low...we need a second dimension

## Trees

- Binary Search Trees:
  - Arrays can have width and length but also height using pointers
  - Numbers need to be placed in order not random (middle number gets pulled up and placed above the others, left child is less than it's value and right child is greater than it's value)
    - Recursive data structure (the children of the tree are trees themselves)
  - Start searching at the root of the tree (top node), if the value we are seeking is less than the root we know to search the left, or right if higher (we can immediately ignore half of the tree)

```c
typedef struct node
{
  int number;
  struct node *left;
  struct node *right;
}
node;
```

- We have pointers to each half of the tree (this applies to all child nodes too)

```c
// Return true or false (is the number present in the tree or not), takes two args: the address of the tree to search and the number we are looking for
bool search(node *tree, int number)
{
  // Always check if the tree exists
  // After we have finished searching the tree and there is nothing left it will return false
  if (tree == NULL)
  {
    return false;
  }
  // If the number being searched for is less than the number at the address, go left to look for the number
  else if (number < tree->number)
  {
    // Use recursion to search the left tree for the number (the original tree has been cut in half)
    return search(tree->left, number);
  }
  // If number is greater than the number at the address, go right to look for the number
  else if (number > tree->number)
  {
    // Use recursion again to search the right tree for the number
    return search(tree->right, number);
  }
  // Return true if/when we find the number (we can also just use else here, no need for if)
  else if (number == tree->number)
  {
    return true;
  }
}
```

- Downside of trees is that insertion isn't constant time (instead it is O(log n)) because we rely on trees being sorted to allow for searching (we need to traverse the tree until we reach the point it should be inserted at)
  - We also need twice the number of pointers of a linked list which costs more space
  - We need to make sure tree is being rotated to stay balanced (change the root node to reflect the values that are present so it doesn't just become a linked list)

## Hash Tables

- Hash table is an array of linked lists
  - Constant time for insertion because array indices can be inserted anywhere without traversing
  - e.g if inserting values alphabetically we can store values in an a-z array, each index is a linked list so we can store multiple values at the same index
    - Drawback is we need to traverse through the linked list at that index to find the value we are looking for
  - Problem is that linked lists can get very long if we are inserting a lot of values (we can create smaller buckets [more array indices to store values] but this takes more memory so we need to consider the best balance of time vs. memory)
    - Regardless this allows us to look at a smaller input size compared to a regular array
- Hash function takes as input a string and returns a number output which matches the array index that value lives at
- Running time for searching a hash table is O(n) -> As the amount of input grows the time it takes to search gets longer
  - This will still take less time than searching an array or a linked list alone, this is a net positive (we need to search less input than we would otherwise)

## Tries

- A tree made up of arrays (rather than numbers)
  - e.g. Each letter in a name will have an array of pointers to other nodes (1 node for H points to 1 node for A points to 1 node for G, etc. We are storing the full array of the alphabet at each node but we follow the pointer to the appropriate letter in that array)
  - Running time is O(1) constant time (it always takes the time required by the length of their name, regardless of the number of names stored)
- The cost of this is how much memory this takes, this takes a huge amount of pointers and arrays

## Abstract Data Structures

- Mental structure that is implemented at a higher level (simplifying these structures for the purpose of problem solving)

### Queues

- First in, first out (FIFO)
  - Enqueue: Get in line
  - Dequeue: Get out of line
- Downside of using an array to implement a queue would be the lack of dynamic manipulation (If we take out the first indices we have spaces at the beginning of the array but not at the end, we basically have to copy the values over to move them up, O(n) time for this operation)
- Linked list might work better for this because we can continue appending and changing the values and locations of the data points

### Stacks

- Last in, first out (LIFO)
  - Think of a stack of trays (the last one placed on top is the first one to be taken off), always removing the one on top
  - Push: Add a value to the top
  - Pop: Remove a value from the top

### Dictionaries

- Associate keys with values (like an object in JS)
  - Like a real world dictionary (word: definition)
  - Find values based on keys
  - Problem is if 2 things have the same key or similar keys
