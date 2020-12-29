# Algorithms

- Computer can only look at the array step by step (like opening one locker at a
  time, no birds eye view)

- Linear Search: Searching in order from left to right
  - Correct but not efficient
  - Pseudocode:
    ```
    For i from i to n-1
      if i'th element is 50
        return true
    return false (element doesn't exist)
    ```
  - Time complexity: n (straight line), time to solve is equal to the size of
    the problem
    - Time complexity n/2: Considering two elements (Skip one page of the phone
      book, then go back if you pass the needed element [assumes sorting], or
      consider two elements at the same time like opening two lockers at once)
- Binary Search: Divide the problem by 2 each time
  - Start in the middle and determine which direction to go, divide the problem
    again until you have an answer
  - Pseudocode:
    ```
    If no items
      return false
    If middle item is 50
      return true
    else if 50 < middle item
      search left half
    else if 50 > middle item
      search right half
    ```
  - Time complexity: log₂n (Curved shape, time to solve gets shorter the longer
    you take to solve it because the problem gets smaller as you divide it)

### Big O Notation

- On the order of: What is the efficiency of your code? Meant to be an
  approximation of the upper bound (worst case scenario)

  - O(n)
  - O(n/2)
    - Often considered the same as O(n) because the complexity is almost the
      same
      - If the problem gets big enough they become almost the same
  - O(log n)
    - Discard the base 2 (not important when the problem gets bigger)

- Common/popular time complexities (lower means better time complexity):

  - O(n²) --> Bubble sort, selection sort
  - O(n log n) --> Merge sort
  - O(n) --> Linear search
  - O(log n) --> Binary search
  - O(1) --> 1 step

- Ω is used to describe best case of time complexity (how few steps it could
  take)
  - Ω(n²) --> selection sort (no improvement in best case because all elements
    still need to be considered each run regardless of whether sorted or not)
  - Ω(n log n) --> merge sort
  - Ω(n) --> bubble sort
  - Ω(log n)
  - Ω(1) --> 1 step to solve (linear and binary search can fall into this in
    best case)

### Sorting Algorithms

- Is it worth the time to sort the numbers before searching or better to just
  start searching?
- Bubble Sort:

  - Consider pairs left to right, swap if left is larger than right. Eventually
    right side will have larger numbers and array is sorted.
  - This takes a substantial amount of time especially with larger arrays:
    ```
    (n -1) x (n -1)
    n² - 1n - 1n + 1
    n² - 2n + 1
    O(n²) time complexity which is literally the worst method in our list above e.g sorting is a loss not a gain, it's better to just search linearly
    ```
  - Pseudocode:

  ```
  repeat n - 1 times --> repeat until no swaps to stop early and improve the time complexity for omega
    for i from 0 to n - 2
      if i'th and i +1'th elements are out of order
        swap
  ```

- Selection Sort:
  - On each iteration select the smallest element and swap it with whatever is
    at the beginning of the array. Those elements don't need to be considered on
    further iterations
  - Pseudocode:
  ```
  For i from 0 to n - 1
    find smallest item between i'th item and last item
    swap smallest item with i'th item
  ```
- This is the same time complexity as bubble sort even though it's a very
  different algorithm:

```
n(n + 1)/2
(n² + n)/2
n²/2 + n/2
O(n²)
```

- Recursion:

  - A program that calls itself
  - See recursion.c

- Merge Sort:

  - Pseudocode:

  ```
  If only one item
    return (nothing to sort, this is base case)
  Else
    Sort left half of items
    Sort right half of items
    Merge sorted halves
  ```

  - E.g if we have an array of 8 items, we divide into left and right (4 each),
    divide again (2 each), and divide again (1 each) --> These can then be
    merged
    - Continue like this until left and right of original array can be merged
  - Time complexity is much better at O(n log n) --> this comes in before bubble
    sort and selection sort, but after linear and binary search
    - Best case scenario is however worse than bubble sort, it's a tradeoff

- If upper bound (O) and lower bound (Ω) are exactly the same (best and worst
  case outcome are the same) they can be described using Θ:
  - Θ(n²) --> Selection sort
  - Θ(n log n) --> Merge sort
  - Θ(n)
  - Θ(log n)
  - Θ(1)
