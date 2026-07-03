from typing import List
from collections import deque

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        graph = [[] for _ in range(n)]
        indegree = [0] * n
        weights = []

        for u, v, w in edges:
            graph[u].append((v, w))
            indegree[v] += 1
            weights.append(w)

        if not weights:
            return -1

        topo = []
        q = deque()

        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        while q:
            u = q.popleft()
            topo.append(u)

            for v, _ in graph[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)

        weights = sorted(set(weights))

        def check(limit):
            INF = 10**30
            dist = [INF] * n
            dist[0] = 0

            for u in topo:
                if dist[u] == INF:
                    continue

                if u != 0 and u != n - 1 and not online[u]:
                    continue

                for v, w in graph[u]:

                    if w < limit:
                        continue

                    if v != n - 1 and not online[v]:
                        continue

                    if dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w

            return dist[n - 1] <= k

        left = 0
        right = len(weights) - 1
        ans = -1

        while left <= right:
            mid = (left + right) // 2

            if check(weights[mid]):
                ans = weights[mid]
                left = mid + 1
            else:
                right = mid - 1

        return ans
        
