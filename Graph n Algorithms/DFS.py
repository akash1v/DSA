def DFS(grp, root_key):
    stack = []
    visited = []

    stack.append(root_key)       # root key added

    # print(f"Open List : {*stack,},        Close List : {*visited,}")

    while len(stack) != 0:
        key = stack.pop()       
        nbr = grp[key]            # neighbours of the exploring key
        
        for i in nbr:
            if i not in visited and i not in stack:
                stack.append(i) 
        
        visited.append(key)
        # print(f"Open List : {*stack,},         Close List : {*visited,}")
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

    print(DFS(graph, 'B'))