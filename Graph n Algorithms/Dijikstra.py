def Dijikstra(Graph, start_node, no_of_vertices):
    distances = {node: float('inf') for node in range(no_of_vertices)}
    distances[start_node] = 0
    visited = set()

    while len(visited) < no_of_vertices-1:
        print(distances)

        vertex, min_value = -1, float('inf')
        for node, distance in distances.items():
            if node not in visited:
                if distance < min_value:
                    vertex = node
                    min_value = distance
        visited.add(vertex)

        for edge, cost in Graph.items():
            if vertex in edge:
                other_node = edge[0] if edge[1] == vertex else edge[1]
                new_cost = distances[vertex] + cost
                if new_cost < distances[other_node]:
                    distances[other_node] = new_cost

    return distances

if __name__ == "__main__":
    graph = {
        (0, 1): 50,
        (0, 2): 45,
        (0, 3): 10,
        (1, 2): 10,
        (1, 3): 15,
        (2, 4): 30,
        (3, 4): 15,
        (4, 1): 20,
        (5, 4): 3,
    }

    start_node = 0
    Dijikstra(graph, start_node, 6)
