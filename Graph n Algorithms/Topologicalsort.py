def topological_sort(graph):
    indegree = {v: 0 for edge in graph for v in edge}
    for edge in graph:
        indegree[edge[1]] += 1

    queue = [vertex for vertex in indegree if indegree[vertex] == 0]
    result = []

    while queue:
        current_vertex = queue.pop(0)
        result.append(current_vertex)
        for edge in graph:
            if edge[0] == current_vertex:
                indegree[edge[1]] -= 1
                if indegree[edge[1]] == 0:
                    queue.append(edge[1])

    if len(result) != len(indegree):
        return None
    return result

if __name__ == "__main__":
    graph = {
        (1, 0): 28,
        (1, 4): 20,
        (0, 2): 16,
        (0, 4): 14,
        (2, 4): 12,
        (4, 3): 22,
    }
    print(topological_sort(graph))
