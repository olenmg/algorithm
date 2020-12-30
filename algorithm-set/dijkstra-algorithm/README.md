# Dijkstra's algorithm 다익스트라 알고리즘

## Summary 요약
For finding the shortest paths between vertices in a graph.  
This can be used when all of the weights of edges in graph are positive integers or real numbers.  
It can find all of the shortest paths from start vertice to other vertices.  
Time complexity : O((|V| + |E|)log|V|) (with priority queue), O(V^2) (with naive array) (This code was written on priority queue basis.)   
  
최단경로 탐색 알고리즘. 간선의 가중치가 음수가 아닐 때 사용 가능  
출발점에서 그 외 모든 다른 정점까지의 최단경로 추적 가능  
시간복잡도: O((|V| + |E|)log|V|) (우선순위 큐 기반), O(V^2) (배열 기반, 간선이 없는 부분도 탐색하므로 시간복잡도가 높음)  
(이 코드는 우선순위큐 기반으로 작성되었음)  


## Algorithm 알고리즘
Repeat the operation below.  
Find the vertice with the minimum <code>dist</code> value among the vertices whose <code>dist</code> has been updated so far, and update the <code>dist</code> value of vertices around that vertice.  

현재까지 <code>dist</code>가 갱신된 정점들 중 <code>dist</code>값이 가장 작은 정점을 찾아, 다시 해당 정점 주위 정점들의 최단거리값(<code>dist</code>)를 갱신하는 작업을 반복한다.   


## Proof of correctness 정당성
We have to prove that the <code>dist</code> chosen on every step must be the minimum distance from starting vertice.  
Suppose that the minimum route from starting point to vertice <code>p</code> included vertice <code>q</code> which is not visited yet.  
(<code>q</code> is the first vertice not belonging to visited vertice set)  
Then, distance(start ~ <code>q</code>) + distance(<code>q</code> ~ <code>p</code>) < distance(start ~ <code>p</code>) must be true.  
In other words, distance(start ~ <code>q</code>) < distance(start ~ <code>p</code>) must be true.  
But <code>p</code> is guaranteed that it has the minimum <code>dist</code> value among other vertices, contradiction.  
Therefore, minimum route from starting point to <code>p</code> only include the vertice that has been visited.  

방문하지 않은 정점 중 <code>dist</code>값이 가장 작은 정점을 찾았을 때 그 <code>dist</code>가 실제 그 정점까지의 최단거리임을 증명하면 된다.  
즉, 지금까지 방문한 정점 집합(<code>V</code>)만으로 이루어진 경로로 새로 찾은 정점(<code>p</code>)까지의 최단거리를 만들 수 있음을 보이면 된다.  
아직 방문하지 않은 정점(<code>q</code>)이 포함된 경로의 길이가 최단거리라고 가정해보자. (단, 출발점으로부터 <code>p</code>까지의 경로상에서 <code>q</code>는 <code>V</code>에 속하지 않는 첫 번째 정점)  
이 때, (시작점 ~ <code>q</code> 거리) + (<code>q</code> ~ <code>p</code> 거리) < (시작점 ~ <code>p</code> 거리) 가 성립하여야 한다.  
즉, (시작점 ~ <code>q</code> 거리) < (시작점 ~ <code>p</code> 거리)라는 것인데, 그렇다면 애초에 정점 <code>p</code>가 방문하지 않은 정점 중 <code>dist</code>값이 가장 작은 정점(첫줄)라는 가정에 위배된다.  
따라서 <code>p</code>까지의 최단거리 경로에는 반드시 <code>V</code>에 포함된 정점만 존재한다.  
