# Segment tree (Data Structure) 세그먼트 트리

## Summary 요약
Segment tree is advantageous in problems with frequent updates of nodes and queries for intervals(or segments).  
This has a complete binary tree structure. Each node stores representative data of section in charge.  
Nodes located more deeper store data of more smaller intervals.  
Each leaf node storse the data of actual data.  
Time complexity: O(logN) for update, O(logN) for query  


세그먼트 트리는 구간에 대한 쿼리가 잦은 문제, 혹은 그러한 구간에 대한 업데이트가 많은 문제에서 유용하게 사용된다.  
완전이진트리의 형태를 지니고 있으며, 각 노드는 자신이 담당하고 있는 구간에 대한 대표 데이터를 저장하고 있게 된다.  
더 깊은 곳에 있는 노드는 더 작은 구간을 담당하게 된다.  
각 리프노드는 실제 데이터를 차례대로 가지고 있게 된다.  
시간 복잡도: 업데이트 및 쿼리에 모두 O(logN)  


## Algorithm 알고리즘
- Update  
    1. If the node to be updated is included in the currently viewed section, update current node and keep this work on child node. (Since this tree is binary tree, we can easily go to child node)  
    * If current node is in range yet, repeat above.  
    * If current node is leaf or not in range, stop searching of this interval.  

- Query  
    1. If currently viewed interval is overlapped with the interval we want to query (even a little bit), go to child node and repeat 1~3.  
    2. If now interval is completely included in the interval we want to query, return the value of current node.  
    3. If now interval doesn't overlap at all, return 0.  


- 업데이트
    1. 현재 보고 있는 구간에 업데이트를 하고자하는 노드가 포함되면 보고 있는 노드를 업데이트를 하고, 자식 노드로 넘어간다. (이진트리이므로 자식노드로 간단하게 넘어갈 수 있다)  
    * 현재 노드가 여전히 범위 내에 있다면 이 노드에 대하여 1번을 반복한다.  
    * 만약 현재 노드가 리프노드이거나 범위 내에 없는 노드라면 이 아래 구간은 탐색하지 않는다.   

- 쿼리
    1. 현재 보고 있는 구간에 쿼리하는 구간이 조금이라도 걸치면 자식노드로 넘어가 다시 1-3번을 반복한다.  
    2. 현재 보고 있는 구간에 쿼리하는 구간이 완전히 포함되면 현재 보고 있는 노드의 값을 반환한다.  
    3. 현재 보고 있는 구간에 쿼리하는 구간이 아예 겹치지 않으면 0을 반환한다.  


## Proof of correctness 정당성
There is nothing to proof.