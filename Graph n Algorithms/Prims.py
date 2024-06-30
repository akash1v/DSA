def Prims(graph, no_of_vertices):
    """
    Prims gives the minimum spanning tree

    Parameters:
    Graph : Name of the vertices should be of integer, 
            greater than -1 and
            less than no_of_vertices
    
    no_of_vertices : must be an integer
    """
    
    
    visited = set()
    spanning_tree = {}

    start_node = graph[0][0][0]
    visited.add(start_node)

    while len(spanning_tree) < no_of_vertices-1:
        min_edge_cost = None
        min_cost = float('inf')

        for edge, cost in graph:

            if ((edge[0] in visited and edge[1] not in visited) or
                (edge[1] in visited and edge[0] not in visited)):
                if cost < min_cost:
                    min_cost = cost
                    min_edge_cost = (edge, cost)

        if min_edge_cost:
            spanning_tree[min_edge_cost[0]] = min_edge_cost[1]
            visited.add(min_edge_cost[0][0])
            visited.add(min_edge_cost[0][1])

    return spanning_tree
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

    print(Prims(graph, 7))
