def BFS(grp, root_key):
    queue = []
    visited = []

    queue.append(root_key)       # root key added

    # print(f"Open List : {*queue,},        Close List : {*visited,}")

    while len(queue) != 0:
        key = queue.pop(0)      
        nbr = grp[key]            # neighbours of the exploring key
        
        for i in nbr:
            if i not in visited and i not in queue:
                queue.append(i)  
        
        visited.append(key)
        # print(f"Open List : {*queue,},         Close List : {*visited,}")
    return visited


if __name__ == "__main__":
    graph = {
        'B' : ['C', 'N'],
        'C' : ['A', 'Q'],
        'A' : ['M'],
        'Q' : ['R'],
        'N' : ['S'],
        'S' : ['T', 'Z'],
        'M' : [],
        'R' : [],
        'T' : [],
        'Z' : [],
    }

    print(BFS(graph, 'B'))