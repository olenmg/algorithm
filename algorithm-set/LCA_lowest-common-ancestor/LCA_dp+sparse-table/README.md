# LCA finding (with sparse table)

## Summary 요약
In tree structure, this algorithm can find the lowest common ancestor of some two vertices in a short time(log time).  
This algorithm uses the concept of DP and sparse table.  
Time complexity: O(|V|log|V|) for pre-processing, O(log|V|) for query.  


트리 구조에서, 이 알고리즘은 로그 시간 내에 어떤 두 정점의 최소 공통 조상(LCA)을 찾아낼 수 있다.  
구간 최소 세그먼트 트리를 활용하는 알고리즘도 있으나, 여기서는 DP와 희소 테이블(sparse table)을 활용한 방법을 기술하였다.  
시간 복잡도: 전처리 O(|V|log|V|), 쿼리 O(log|V|)  


## Algorithm 알고리즘
Make array in which store the 2^k-th ancestor of each vertex at k-th index. (sparse table)  
Find the LCA of two vertices using above table.  
1. Pulled up lower-level vertex so that the level of two vertices become same. (If already same, skip this step.)  
2. Find the lowest height where the same ancestor appears.  


트리 내에 있는 모든 정점의 2^k 번째 조상을 저장하는 sparse table을 구성한다. (전처리)  
이후 쿼리로 들어온 두 개의 정점에 대하여 미리 구성한 테이블을 이용하여 LCA를 찾는다.  
1. 두 정점의 레벨이 같아지도록 더 높은 레벨을 가진 정점을 위로 끌어올린다. (이미 같다면, 이 과정은 생략한다)  
2. 이후 두 정점의 조상이 같아지기 위해 올라가야하는 최소 높이를 찾는다.  


## Proof of correctness 정당성
Since binary number can represent all of decimal number, we can progress this algorithm by using sparse table and bit operation.  


이진수로 모든 십진수를 표현할 수 있기 때문에, 비트 연산을 통해 위에 기술한 알고리즘의 1번, 2번 과정을 수행할 수 있다.  


## Other 그 외
We can simply find the LCA using DFS, but it is effective for only one query. (time complexity: O(|V|) for one query, no pre-processing)  
p.s. DFS in tree has time complexity O(|V|), since |E| = |V| - 1)  


DFS를 이용하여 간단하게 LCA를 찾을 수 있으나, 쿼리가 한 개 정도로 매우 적을 때만 효과적이다. (시간복잡도: 쿼리당 O|V|, 전처리 필요 없음)  
p.s. 트리에서 |E| = |V| - 1이므로 DFS의 시간복잡도는 O(|V|)이다.