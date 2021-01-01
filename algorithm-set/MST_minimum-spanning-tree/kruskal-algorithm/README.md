# Kruskal's algorithm 크루스칼 알고리즘

## Summary 요약
Kruskal's algorithm finds a minimum spanning tree on undirected edge-weighted graph.  
It is necessary to keep track of whether cycle exists in the MST made so far, so this algorithm use union-find data structure.  
Time complexity: O(|E|log|E|) (= O(|E|log|V|))  

무향 가중 그래프의 최소 신장 트리 탐색 알고리즘.  
지금까지 만든 MST에 사이클이 존재하는지 지속적으로 추적해야하기 때문에, 유니온 파인드(상호 배타적 집합) 자료구조를 함께 사용한다.  
시간복잡도: O(|E|log|E|) (= O(|E|log|V|)) (|E|는 최대 |V|^2이며 log|V|^2은 시간복잡도에서 logV로 간주 가능)  


## Algorithm 알고리즘
Find the minimum weighted edge on unsearched edge set which does not make cycle on the tree, and add it to the MST.  
The number of edge in the tree is at most |V| - 1, therefore we have to repeat above process for |V| - 1 times.  
Exactly we can repeat above process until the queue is empty.  


아직 탐색하지 않는 간선들 중 사이클을 만들지 않는 가중치 최소의 간선만을 그리디하게 선택하여 MST에 붙인다. (이 과정에서 정점들이 처음에는 연결되어있지 않을 수 있다)  
트리를 구성하는 간선의 갯수는 반드시 |V| - 1개이므로 간선을 |V| - 1개 선택할 때까지 반복한다.  
다만 보통의 경우 간선이 선택될 때마다 해당 간선이 사이클을 형성하면 건너뛰기 때문에, 편의상 큐가 빌 때까지 반복해줘도 무관하다.   


## Proof of correctness 정당성
Suppose that at now stage, edge L which connect vertices u and v is chosen. And this edge is not on MST, even it dose not make any cycle.  
Then there is some other paths which connect u and v, but length of some edge on that path must be less than or equal to L.  
Because if all of edges on that path is shorter than L, they have to be chosen before L being chosen. (If so, u and v should have already been connected)  
Therefore, there is no path from u to v shorter than L.


어떤 두 정점 u와 v를 연결하는 간선 L이 이번 단계에서 선택되었을 때, 이 간선이 사이클을 만들지 않음에도 MST에 포함되는 간선이 아니라고 가정해보자.  
그러면 u와 v를 연결하는 다른 경로가 존재할텐데 이 경로에 있는 간선 중 최소 한 개는 L보다 길거나 같아야 한다.  
만약 u - v경로에 있는 간선의 길이가 모두 L보다 짧았으면 L보다 일찍 선택되었어야 하고, 그랬으면 L이 선택된 단계에서 사이클을 이루므로 L은 무시되었어야 하기 때문이다.  
따라서 u와 v를 연결하는 L보다 짧은 경로는 존재하지 않는다.  