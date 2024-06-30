def krushkal(Graph, No_of_vertices):
    """
    Krushkal gives the minimum spanning tree

    Parameters:
    Graph : Name of the vertices should be of integer, 
            greater than -1 and
            less than no_of_vertices
    
    no_of_vertices : must be an integer
    """
    
    
    nodes = {}
    
    for i in range(0, No_of_vertices):
        nodes[i] = -1

    span_tree = {}
    new_set = 0

    while len(span_tree) < No_of_vertices - 1:
        Graph = sorted(Graph, key=lambda x:x[1])
        edge, cost = Graph.pop(0)
        
        if nodes[edge[0]] == -1 and nodes[edge[1]] == -1:
            span_tree[edge] = cost
            nodes[edge[0]] = new_set
            nodes[edge[1]] = new_set
            new_set += 1

        elif nodes[edge[0]] == -1:
            span_tree[edge] = cost
            nodes[edge[0]] = nodes[edge[1]]
        elif nodes[edge[1]] == -1:
            span_tree[edge] = cost
            nodes[edge[1]] = nodes[edge[0]]

        elif nodes[edge[0]] != nodes[edge[1]]:
            span_tree[edge] = cost
            old = nodes[edge[1]]
            new = nodes[edge[0]]
            for key, value in nodes.items():
                if value == old:
                    nodes[key] = new
    return span_tree

if __name__ == "__main__":
    graph = [
        ((0, 1), 28),
        ((1, 2), 16),
        ((1, 6), 14),
        ((2, 3), 12),
        ((3, 4), 22),
        ((3, 6), 18),
        ((4, 5), 25),
        ((4, 6), 24),
        ((5, 0), 10),
    ]

    print(krushkal(graph,7))
