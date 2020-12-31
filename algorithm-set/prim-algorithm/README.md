# Prim's algorithm 프림 알고리즘

## Summary 요약
Prim's algorithm finds a minimum spanning tree of undirected edge-weighted graph.  
Unlike Kruskal's algorithm, this algorithm keep all vertics connected during process working.  
Time complexity: O(|E|log|V|)  


무향 가중 그래프의 최소 신장 트리 탐색 알고리즘.  
크루스칼 알고리즘과 다르게, MST를 만들어가는 과정에서도 항상 모든 정점이 연결된 상태를 유지한다.  
시간복잡도: O(|E|log|V|)  


## Algorithm 알고리즘
Find the minimum weighted edge among surrounding edges(connected with current tree), and add it to the MST. (commonly using priority queue for this task)  
(Of course, added edge does not make any cycle.)  
MST of course have |V| vertex. Thus repeat above process for |V| times.  
Exactly we can repeat above process until the queue is empty.  

현재까지 형성한 트리 주변에 있는(트리와 연결되어있는) 간선들 중 그 가중치가 최소인 것을 찾아 연결한다. (당연히 이 간선은 사이클을 만들지 않아야 한다)  
MST는(뿐만 아니라 일반적인 트리를 형성하여도) |V|개의 정점을 가지므로 위 과정을 |V|번 반복한다.  
이 과정에서 우선순위 큐를 보통 사용하는데, 따라서 큐가 빌 때까지 위 작업을 반복해도 무관하다.  


## Proof of correctness 정당성
Same with Kruskal's one.  
For two different edges connecting the same two vertices, there is no possibility that an edge to be selected in the future will form an MST over a preselected edge.  

크루스칼 알고리즘에서의 증명과 동일하다.  
동일 정점들을 연결하는 두 간선에 대하여 이전에 선택된 간선보다 나중에 선택되는 간선에 의해 MST가 형성될 가능성은 없다.  


## Other 그 외
+ If the number of edge is very large, Prim's algorithm is more effective, otherwise Kruskal's algorithm is more advantageous.  
+ The structure of this algorithm is very similar with Dijkstra's algorithm.  

* 간선의 수가 많을 경우 프림 알고리즘이 유리하며, 그렇지 않을 경우 크루스칼 알고리즘이 더 유리하다. (시간복잡도 면에서)  
+ 알고리즘의 구조가 다익스트라 알고리즘과 매우 유사하다.  