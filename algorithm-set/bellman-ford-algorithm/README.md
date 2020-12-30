# Bellman-Ford algorithm 벨만-포드 알고리즘

## Summary 요약
For finding the shortest paths between vertices in a graph.  
This can be used both positive and negative weights.  
It can find all of the shortest paths from start vertex to other vertices.  
Time complexity : O(|V||E|) (max of |E| = |V|^2 ... O(|V|^3))  


최단경로 탐색 알고리즘. 간선의 가중치가 양수든 음수든 사용 가능(다익스트라 알고리즘과의 차별점)  
출발점에서 그 외 모든 다른 정점까지의 최단경로 추적 가능  
시간복잡도: O(|V||E|) (max of |E| = |V|^2 ... O(|V|^3))  


## Algorithm 알고리즘
For all edges, if old <code>dist</code> value of connected vertex can be updated, (when <code>dist[next]</code> > <code>dist[now]</code> + weight of edge) update it. Repeat this process for |V| - 1 times.  


모든 간선을 탐색하는데, 만약 도착 정점의 <code>dist</code>값이 갱신될 수 있는 상황이면, (즉 <code>dist[next]</code> > <code>dist[now]</code> + 간선의 가중치 일 때) 해당 <code>dist</code> 값을 갱신한다. 이 과정을 |V| - 1번 반복한다.  


## Proof of correctness 정당성
Suppose that the shortest path from A to B is path (A - x - y - z - B). Then it is clear that paths (A - x), (A - x - y), (A - x - y - z) are also the shortest path from A to x, y, z, respectively. Because if they are not, they can not be included on the shortest path from A to B.  
If we repeat updating process for N times, we can find the shortest path of which maximum length is N from A to other vertices.  
(of course, if no negative cycle exists, ) Length of the shortest path is at most |V| - 1. Therefore we repeat updating process for |V| - 1 times.  


A에서 B로 가는 최단 경로 A - x - y - z - B가 있다고 해보자. 이 때 이 경로에 포함된 (A - x), (A - x - y), (A - x - y - z) 역시 A로부터 각 정점까지의 최단 경로이다. 만약 이 길들이 최단경로가 아니라면 A - B 최단경로에 포함될 수 없기 때문이다.  
<code>dist</code>값을 갱신하는 작업을 N번 반복하면 A에서 다른 정점까지 최대 N개의 간선을 거치는 최단 경로를 구할 수 있다.  
(음수 사이클이 존재하지 않는다면)경로의 길이는 최대 |V| - 1이므로 갱신 작업을 |V| - 1번 반복한다.  


## Other 그 외
+ We can check whether there is(are) path(s) of negative-infinity distance by repeat updating process one more time.  
+ If <code>dist</code> value still updated, negative infinity path will exist.  

---

+ <code>dist</code> 갱신 과정을 마지막에 한번 더 해보면 음수 가중치로 인해 최단거리가 음의 무한대인 경로가 존재하는지 확인할 수 있다.  
+ 만약 <code>dist</code> 값이 마지막에도 갱신되고 있으면, 음의 무한대인 경로가 존재하는 것이다.  