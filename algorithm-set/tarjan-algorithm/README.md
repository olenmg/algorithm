# Tarjan's algorithm 타잔 알고리즘 (for SCC)

## Summary 요약
This algorithm finds all of SCCs in graph. (other, kosaraju's algorithm exists)  
Time complexity : O(|V| + |E|) (this algorithm based on DFS)  
  
SCC 탐색 알고리즘 중 하나. (그 외 코사라주 알고리즘으로도 SCC 탐색이 가능함)  
시간복잡도: O(|V| + |E|) (DFS 기반 알고리즘으로, 시간 복잡도가 DFS와 같다)  


## Algorithm 알고리즘
During DFS, if we find a cycle at some vertices, bind them together as same SCC.  
Repeat until all vertices are allocated to some SCC. (Also, one SCC may consist of one vertex).  


DFS를 수행하면서, 정점들간 사이클이 탐색되면 해당 정점들을 같은 SCC로 묶는다.  
모든 정점들이 어떤 하나의 SCC에 할당될 때까지 탐색을 반복한다.  


## Proof of correctness 정당성
vertices arriving later must have a larger <code>dfsn</code> value.  
Therefore, there must be cycle if next <code>dfsn</code> value is smaller than now one.  
Meanwhile, <code>result</code> value and <code>dfsn</code> value of the vertices that do not form a cycle are same, they pop only their own in stack.  


알고리즘 동작 구조상, 나중에 도달하는 정점의 <code>dfsn</code> 값은 반드시 크다.  
즉, <code>dfsn</code> 값이 작아지려면 반드시 사이클이 존재해야 하는 것이다.  
한편 사이클을 이루지 않는 정점들은 <code>result</code>값이 갱신되지 않으므로 반드시 <code>result</code>값과 <code>dfsn</code>값이 동일하며 스택에서 바로 자기 자신이 <code>pop</code>된다.  


## Other 그 외
+ If we find all of SCCs, it is obvious that they do not form any cycle. In other words, newly formed SCC graph is DAG.  
    * IN DAG, we can find topological sort of vertices by using DFS. (exit order of these vertices provide topological sort)  
    * Since tarjan algorithm is based on DFS, we can get **topological sort of SCCs** (also as exit order).  
+ Likewise, Kosaraju's algorithm provides topological sort of SCCs.  

---

+ 모든 SCC를 찾으면 SCC끼리는 사이클을 이루지 않는다. 즉, 완성된 SCC 그래프는 비순환 유향 그래프이다.  
    * 비순환 유향 그래프에서 DFS를 적용하면 DFS 적용 역순으로 위상정렬이 된다.  
    * 이 알고리즘은 DFS 기반이므로 마찬가지로 **SCC들간의 위상정렬 결과**를 얻을 수 있다.  
+ 헷갈렸던 점: DFS의 시작점이 반드시 루트 정점여야 위상정렬된 결과를 얻을 수 있는 것 아닌지 의문이 있었는데,
어차피 어디서 시작하든 맨 마지막 도착점에 붙이는 번호가 가장 작다.  
+ 코사라주 알고리즘을 적용해도 마찬가지로 위상정렬된 결과를 얻을 수 있다.  