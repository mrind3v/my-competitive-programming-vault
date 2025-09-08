## Level 1 and 2

- graph can be represented by a set of vertices and edges as G(V,E) where E={(1,2),(1,3)} and V={1,2,3}
- node = vertices
- graphs can be directed/undirected, weighted/non-weighted
- they can be sparse or dense
- If there are a total of N nodes - there could be a max of ${}^nC_2$ $\approx \frac{n(n-1)}{2}$ $\approx n^2$ number of edges
    - A graph is called sparse if it has $< N^{3/2}$ number of edges and dense if greater. Almost all algorithms run properly on sparse graphs, but takes a lot of time in dense graph
- $\sum_{i=1}^N (degree \; of \; all \; vertices) = 2E$ where E - number of edges in the graph. This is because, each edge contributes 2 degrees (1 to each of the connected vertices)
- if X - sum of in-degree of all vertices and Y - sum of out-degree of all vertices then X+Y=2E. Also, sum of in-degree in a graph is equal to sum of out-degree so X=Y. Each edge contributes 1 in-degree in a node and 1 out-degree to another node

---

## Level 3 and 4

- a simple cycle is a cycle where no edge repeats
- a simple graph is where there can't be any self-loop or edge repetation (meaning, at most one edge between any two vertices)
- multigraph is the exact opposite - both self-loops and multiple edges allowed 
- node y is reachable from x if there is a path between x and y
- if graph has n components (not connected), to make all the componenets connected, we need to add n-1 edges between the components
- strongly connected component is the one where for each node x,y R(x,y) => R(y,x) where R(x,y) means x is reachable from y
