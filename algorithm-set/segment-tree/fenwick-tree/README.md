# Fenwick tree (Data Structure) 펜윅 트리

## Summary 요약
Fenwick tree acts similar with the sum segment tree.  
Fenwick tree is useful to find prefix sum, also we can find arbitary segment sum by using two prefix sums. (subtract one to the other)  
Even their time complexity is same, Fenwick tree is more simple to implement and has less space complexity(O(n)) then segment tree(O(4n)).  
Time complexity: O(logN) for update, O(logN) for query  
  

펜윅트리는 구간합 세그먼트 트리와 비슷한 용도로 쓰인다.  
펜윅트리는 prefix sum을 구하는데 유용하며, prefix sum 2번을 구하여 원하는 구간의 합도 쉽게 구해낼 수 있다.    
세그먼트 트리와 쿼리 및 업데이트에 대한 시간 복잡도가 같으나, 구현이 더 간단하고 메모리를 더 적게 사용한다는 점에서(n, 4n) 장점을 가진다.  
시간 복잡도: 업데이트 및 쿼리에 모두 O(logN)  


## Algorithm 알고리즘
Fenwick tree use bit operation.  
Here, the 'LSB' means the LSB(least significant bit) of k.  
     
The value stored in index k is sum from (k - 2^LSB + 1)-th element to k-th element. (total number is 2^LSB)  
Therefore, we can perform update and query by using LSB.

- Update  
  1. Now we want to update k-th element. Represent k in binary.  
  2. Until k exceed the size of array, while add LSB to k, update all the element that has index of encountered number.  

- Query
  1. Now we want to get sum up to the kth number. Represent k in binary.  
  2. Until k becomes 0, while erase the LSB(i.e., subtracting the LSB), sum all the element that has index of encountered number and return it.  


    
펜윅 트리는 비트연산을 이용하여 쿼리 및 업데이트를 수행한다.  
앞으로 'LSB'는 현재 k의 최하위 비트(LSB)를 의미한다.  
    
k번째 인덱스에 저장되는 값은 (k - 2^LSB + 1)번째 값부터 k번째 값까지의 합이다. (총 2^LSB 개)  
따라서 우리는 LSB를 이용하여 업데이트와 쿼리를 수행할 수 있다.  

- 업데이트  
  1. k번째 수를 업데이트하려고 한다. k를 이진수로 나타낸다.  
  2. 수열의 크기를 초과하기 전까지 LSB를 k에 더해가며, 만나는 모든 수를 인덱스로 하는 배열 값에 업데이트를 수행한다.  

- 쿼리  
  1. k번째 수까지의 합을 구하려고 한다. k를 이진수로 나타낸다.  
  2. k가 0이 되기 전까지 LSB를 지워나가면서(즉, LSB를 빼면서) 만나는 모든 수를 인덱스로 하는 배열 값을 모두 더하여 반환한다.  


## Proof of correctness 정당성
How updates and queries work can be easily understood by drawing a picture with it.  
The point is, i & -i represent LSB.  
Suppose that i = 101000 in binary, let's see -i in binary. -i = ~i + 1 = 010111 + 1 = 011000  
Realize that left bits of LSB has a bit opposite to i, and the right bits of LSB has a bit of 0.  
Therefore i & -i = 000000.....1(LSB position)....0000.  


업데이트와 쿼리의 원리는 사실 펜윅트리의 구조를 직접 그림으로 그려보면 쉽게 이해할 수 있다.  
요지는, i & -i가 정말 i의 LSB를 나타내느냐이다.  
i에 2의 보수를 취한 값을 살펴보자.  i가 이진수 101000일 때, -i = ~i + 1 = 010111 + 1 = 011000이다.  
관찰해보면, i에서 LSB를 기준으로 왼쪽의 값들은 i의 bit와 반대이고, i에서 LSB의 오른쪽 값들은 반드시 0이다.  
즉, i & i & -i = 000000.....1(LSB)....0000 이다.  