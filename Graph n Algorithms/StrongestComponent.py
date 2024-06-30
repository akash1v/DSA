from collections import defaultdict
class Solution:
    def __init__(self):
        pass

    def dfs(self, node, vis, adj, st):
        vis[node] = 1
        for neighbor in adj[node]:
            if not vis[neighbor]:
                self.dfs(neighbor, vis, adj, st)
        st.append(node)

    def dfs3(self, node, vis, adjT):
        vis[node] = 1
        for neighbor in adjT[node]:
            if not vis[neighbor]:
                self.dfs3(neighbor, vis, adjT)

    def kosaraju(self, V, adj):
        vis = [0] * V
        st = []
        for i in range(V):
            if not vis[i]:
                self.dfs(i, vis, adj, st)
        adjT = defaultdict(list)

        for i in range(V):
            vis[i] = 0
            for neighbor in adj[i]:
                adjT[neighbor].append(i)
        scc = 0
        while st:
            node = st.pop()
            if not vis[node]:
                scc += 1
                self.dfs3(node, vis, adjT)
        return scc


if __name__ == "__main__":
    n = 5
    edges = [
        [1, 0], [0, 2],
        [2, 1], [0, 3],
        [3, 4]
    ]
    adj = defaultdict(list)
    
    for edge in edges:
        adj[edge[0]].append(edge[1])
    
    obj = Solution()
    ans = obj.kosaraju(n, adj)
    print("The number of strongly connected components is:", ans)
