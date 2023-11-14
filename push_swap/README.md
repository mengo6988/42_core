# Push_Swap
## Because Swap_push isn't as natural

Writing a sorting algorithm is always a very important first step in a developer's journey. This is usually where we first encounter the concept of complexity.

The 42 push_swap program will take in a list of numbers and provides the smallest set of operations (see below) that will sort the stack going from lowest to the highest.
---

### Rules
1. You have 2 stacks (a & b)
   1. a: random amount of non duplicating +ve/-ve numbers.
   2. b: empty
2. Goal is to sort in ascending order numbers to a
3. Available operations at your disposal.
   1. sa (swap a): Swap first 2 elements at top of stack a
   2. sb (swap b): Swap first 2 elements at top of stack b
   3. ss (swap both)
   4. pa (push a): Push first element top of stack b to top of stack a.
   5. pb (push b): Push first element top of stack a to top of stack b.
   6. ra (rotate a): Shift up all elements of stack a by 1
   7. rb (rotate b): Shift up all elements of stack b by 1
   8. rr (rotate both)
   9. rra (reverse rotate a) Shift down all elements of stack a by 1
   10. rrb (reverse rotate b) Shift down all elements of stack b by 1
   11. rrr (reverse rotate both)

### My algorithm

First phase:

Determine the median of stack A. Call the set of values that are less than that median X, and the set of the remaining values Y.
Determine the median of X.
Move all values in X that are less than the second median to the bottom of stack B and all values in X that are greater than that median to the top of stack B. Values in Y should just rotate to the bottom of stack A.
Now stack A has half its original size, and stack B has two partitions: its top half has values that are all greater than its bottom values
Repeat the above until A is only left with 3 values. Sort those three values. Stack B will end up with several partitions of varying size. The outermost partitions will have the greatest values, and the innermost will have the lesser values.
Second phase:

In this phase stack A will always be circularly sorted, i.e. it only needs rotations to be sorted.

Repeatedly take a value from stack B and insert it into the sorted index in stack A, i.e. at the single position where the above invariant is not broken. Calculate which one of the possible candidate values in Stack B requires the least operations to do that. Both stacks may need rotations: B rotates the chosen value to its top, and A rotates to bring the desired insert position at its top. If either stack was rotated to retrieve and accept the value, these rotations don't need to be reversed after the push. Make use of the combined operators (rr, rrr) when possible.
Repeat the above until stack B is empty.
Rotate stack A so that its greatest value is at the bottom.
To extend this to undefined larger inputs, you would need to apply the split into partitions multiple times, switching stacks to repeat a similar phase as the first one, and acting on large partitions to split them up into smaller ones. Acceptable sizes for partitions are up to about 450. When partitions get much larger than that you need to add a partitioning from stack B to A, ...etc. I will not dwell on this, as your question seems to target inputs of up to 500 values, but it is an essential step to achieve an acceptable asymptotic complexity.

Note that this challenge does not look for an optimal time complexity of the algorithm, but of the output size. So in theory you can spend as much time as you want to try different methods/parameters to get the input sorted and finally take the one that turns out best.
