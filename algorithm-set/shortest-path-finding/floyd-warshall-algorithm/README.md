# Floyd-Warshall algorithm 플로이드-워셜 알고리즘

## Summary 요약
For finding the shortest paths between vertices in a graph.  
This can be used both positive and negative weights.  
This also provide the shortest path from any to any. (all paths between each pairs of vertices)  
Time complexity : O(|V|^3)   


최단경로 탐색 알고리즘. 간선의 가중치가 양수든 음수든 사용 가능  
그래프에 존재하는 모든 두 정점 짝(V * (V - 1) 개)의 최단경로 길이를 전부 찾아낼 수 있다.  
시간복잡도: O(|V|^3)  


## Algorithm 알고리즘
If a path from A to B through K is shorter than old path from A to B, update it. Repeat this process with changing of stopover(vertex) every time.  


출발 정점 A에서 어떤 한 정점 K를 경유하여 도착 정점 B까지 가는 거리가 기존에 알고있던 A->B 최단경로의 길이보다 짧다면 최단경로를 갱신해준다. 경유 정점을 매번 바꾸어주며(1~V) 이 작업을 반복한다.  


## Proof of correctness 정당성
This algorithm is based on concept of dynamic programming.
Suppose that we set 'stopover vertex' sequentially from the first vertex, and now we look k-th vertex. Recurrence equation is as follows.  
C_k(u, v) = min(C_k-1(u, k) + C_k-1(k, v), C_k-1(u,v))  
In other words, the shortest distance is min(distance(u - k) + distance(k - v), (old)distance(u - v)).  
Of course, the above three paths does not include k-th node.  
1. If there is no negative-cycle in graph, former case can not include k on the shortest path.
2. In the latter case, it was searched before we touch k-th vertex. So k-th vertex is not included in the old path.  


다이나믹 프로그래밍 컨셉의 알고리즘이다.  
경유지는 1번 정점부터 차례로 설정하며, 현재 k번째 정점을 탐색하고 있다고 가정할 때, 점화식은 다음과 같다.  
C_k(u, v) = min(C_k-1(u, k) + C_k-1(k, v), C_k-1(u,v))  
즉, k까지의 정점을 경유할 수 있을 때 최단거리는 (u에서 k까지의 최단거리) + (k에서 v까지의 최단거리) 와 (이전에 탐색했던 u에서 v까지의 최단거리) 중 작은 값이다.  
당연히, 이 과정에 들어가는 3개의 최단거리 길에는 k가 포함되지 않는다.  
전자의 경우 음수 사이클이 없다면 k에서 출발하거나 k에 도착하는 최단거리에 k가 포함될 리 없으며, 후자의 경우 이전에 탐색했던 값이므로 해당 경로에는 k가 포함되지 않는다. 


## Other 그 외
+ We can check whether there is(are) path(s) of negative-infinity distance by checking the distance of path from some vertex i to i after all processing.  
+ If distance(i to i) is negative(=not zero), negative infinity path will exist.  



* 만약 알고리즘을 수행한 후 정점 i에서 정점 i로 가는 최단거리가 0이 아닌 음수값으로 갱신되어있다면 음수 사이클이 존재한다는 것을 알 수 있다.