Every graph problem has three layers two it. Ask the below questions:
1. Where is the graph? -> graph formulation (can be as simple as "You are given a graph" or can be complex with no hint of graph usage, but we must model it as a graph problem in order to solve it)
2. Which graph algo? -> there is a fixed number of classical graph algorithms which are made to solve specific kind of graph problems -> you need to be able to identify that its a graph problem, then understand the problem and finally use one of the algos to solve it
3. Best way to code -> specific coding strategy to help you code graph algos fast!



#### Types/Classes of Problems in Graphs

- Reachability
    - can you reach a particular node in a graph starting from one node?
    - need to use DFS, BFS

- DFS variants
    - coloring components
    - numbering components
    - Articulation point and bridges
    - etc...

- Topological ordering
    - lexicographically smallest topological ordering - Kohn's algorithm

- Shortest path (very important)
    - given starting and ending node, find the shortest path
    - withing shortest path
        - single source shortest path -----| BFS, 0-1 BFS, Djikstra
        - multi source shortest path  -----| Bellman Ford
        - all pair shortest path ---->  Floyd Warshal

- Minimum Spanning Tree (MST) & Union Find (UF)
    - Krushkal's Algo
    - Prim's Algo

- Trees
    - DFS/BFS
    - Diameter 
    - Centre/Centroid
    - Longest/Shortest path
    - Subtree
    - DP on tree

- Eulerian (Fleury's algo, Heirholzer's) and Hamiltonian tour (DP + bitmask)

- SCC (Tarjan's algo)

- MaxFlow and Min Cost Max Flow

- Data structures on trees
    - Euler tour on tree
    - HLD
    - centroid decomposition
    - block-cut tree
    - dominator tree




    