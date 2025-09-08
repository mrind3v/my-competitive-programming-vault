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

## Level 3   