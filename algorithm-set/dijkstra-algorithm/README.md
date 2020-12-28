# Dijkstra's algorithm 다익스트라 알고리즘

## Summary 요약
For finding the shortest paths between nodes in a graph.  
This can be used when all of the weights of edges in graph are positive integers or real numbers.  
It can find all of the shortest paths from start node to other nodes.  
Time complexity : O((|V| + |E|)log|V|) (with priority queue), O(V^2) (with naive array) (This code was written on priority queue basis.)    
  
최단경로 탐색 알고리즘. 간선의 가중치가 음수가 아닐 때 사용 가능  
출발점에서 그 외 모든 다른 노드까지의 최단경로 추적 가능  
시간복잡도: O((|V| + |E|)log|V|) (우선순위 큐 기반), O(V^2) (배열 기반, 간선이 없는 부분도 탐색하므로 시간복잡도가 높음)  
(이 코드는 우선순위큐 기반으로 작성되었음)  


## Algorithm 알고리즘
Repeat the operation below.  
Find the node with the minimum dist value among the nodes whose dist has been updated so far, and update the dist value of nodes around that node.  

현재까지 dist가 갱신된 노드들 중 dist값이 가장 작은 노드를 찾아, 다시 해당 노드의 주위 노드들의 최단거리값(dist)를 갱신하는 작업을 반복한다.   


## Proof of correctness 정당성
We have to prove that the dist chosen on every step must be the minimum distance from starting node.  
Suppose that the minimum route from starting point to node 'p' included node 'q' which is not visited yet.  
(node 'q' is the first node not belonging to visited node set)  
Then, distance(spoint ~ q) + distance(q ~ p) < distance(spoint ~ p) must be true.  
In other words, distance(spoint ~ q) < distance(spoint ~ p) must be true.  
But p is guaranteed that it has the minimum dist value among other nodes, contradiction.  
Therefore, minimum route from starting point to p only include the node that has been visited.  

방문하지 않은 노드 중 dist값이 가장 작은 노드를 찾았을 때 그 dist가 실제 그 노드까지의 최단거리임을 증명하면 된다.  
즉, 지금까지 방문한 노드 집합(V)만으로 이루어진 경로로 새로 찾은 노드(p)까지의 최단거리를 만들 수 있음을 보이면 된다.  
아직 방문하지 않은 노드(q)가 포함된 경로의 길이가 최단거리라고 가정해보자. (단, 출발점으로부터 p까지의 경로상에서 q는 V에 속하지 않는 첫 번째 노드)  
이 때, (시작점 ~ q까지의 거리) + (q ~ p 거리) < (시작점 ~ p까지의 거리) 가 성립하여야 한다.  
즉, (시작점 ~ q까지의 거리) < (시작점 ~ p까지의 거리)라는 것인데, 그렇다면 애초에 노드 p가 방문하지 않은 노드 중 dist값이 가장 작은 노드(첫줄)라는 가정에 위배된다.  
따라서 p까지의 최단거리 경로에는 반드시 V에 포함된 노드만 존재한다.  
