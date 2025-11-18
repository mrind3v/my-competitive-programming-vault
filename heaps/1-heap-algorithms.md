### Extract Max/Min
> need to remove the max/min node after storing it

Steps:
1. store Max/Min from root.
2. swap root and last node / or can just copy last node to root
3. remove the last node (which now is the root node)
4. heapify down root (which now is the last node) 

### Increase Key
> need to increase the value of a given node. But after doing it, the heap property might be disrupted, so we may need to percolate the node

Steps:
1. update the node value
2. percolate the node up till:
    - index of current node > 0
    - parent > current


### Decrease Key
> Dual of increase key

Steps:
1. update the node value
2. maxHeapify node down (notice that percolate up is opposite of heapify)
   - we are doing this bcuz, decreasing the value of a node will disrupt the max heap property by making it smaller than its children.
> In heap problems, you need to decide wheather you need to percolate up or down. In max-heap, to bring a node up, use the percolate up algo and to bring a node down, use the maxHeapify down algo. In min-heap, to bring a node up, again use percolate up algo and to bring down, use minHeapify


> Both percolate up and heapify algos have time complexity - O(logN) becuz in both scenarios, the worst case is when we need to percolate a leaf node to root (travelled the entire height (logN) of tree) and heapify root node to leaf. As for space complexity, percolation algo take O(1) space (iterative) and heapify takes O(logN) if used the recursive version and O(1) if iterative 


### Insert Element 
> In complete binary tree, insert elements at last level from left to right

Steps:
1. add ele to last level
2. percolate up till:
   - current node index > 0
   - parent > current