# Trie (Data Structure) 트라이 자료구조 

## Summary 요약
Trie is tree for searching associative array. (usually for string)  
Each node is tree stores the pieces of complete array that are divided into small size in order.  
This tree is very powerful for finding some keys in short time.  
However, this has a critical drawback in spatial complexity because all nodes are stored their child pointer.  
Time complexity: O(N) for finding key where N is the length of search key(string)  
++ O(NM) for preprocessing(making tree) where M  is the number of keys.  


트라이는 앞뒤요소가 서로 연관되어있는 리스트 값을 저장하고 찾는데에 유용하다. (보통 문자열을 저장하고 찾는데에 많이 이용한다.)  
문자열을 예로 들면 전형적인 트라이의 경우, 각 노드는 문자열의 글자 하나하나를 순서대로 표현한다.  
+다만 줄일 수 있다면 트라이의 노드 하나하나가 글자 여러 개를 저장하는 등의 방식으로 최적화하는 방법도 존재한다.  
이 자료구조는 찾고 싶은 키가 있을 때 빠른 시간 내에 찾을 수 있다는 점에서 강점을 가진다.  
그러나 각 노드가 자식 노드 포인터를 자식 노드가 될 수 있는 후보군의 갯수만큼 저장하고 있어야 하므로 공간복잡도에서 단점을 보인다.  
시간 복잡도: N이 찾고자하는 키값의 길이일 때 쿼리에 O(N), N이 가지고 있는 키값의 길이 중 최댓값이고 M이 가지고 있는 키값의 갯수일 때 전처리에 O(NM)  


## Algorithm 알고리즘
1. Pre-processing  
- Each node has as many Trie node pointers(child node) as the number of possible candidates next.  
- If new key is inserted, if needs, dynamically allocating the child node, stretch out the branches.  
- For example, ordinary English word has 26 candidates for next child(a ~ z). So each node has to have 26 Trie node pointers.  

2. Searching  
- If we want to search some key, we have to go down the Trie while checking if node of next key is whether NULL or not.  
- And if next key is null character('\0), check if Trie has the key that finish on this node.  
- For this checking, each Trie node has to remember if there is word that finish on it. So each node has another boolean variable for remembering it.    
  


1. 각 노드는 다음에 올 수 있는 후보군의 갯수만큼 트라이 노드 포인터를 가지고 있게 된다.  
새로운 키값이 삽입되면, 필요에 따라 자식 노드를 동적할당하여 트라이의 가지를 뻗어나가면 된다.  
예를 들어, 일반적인 영어 문자열의 경우 자식의 후보군이 26개이므로 미리 26개의 Trie 포인터를 가지고 있는 것이다.  

2. 키값을 찾을 때는 다음 키값을 담는 노드가 NULL인지 확인하면서 다음 가지로 내려가면 된다.  
만약 다음 키값이 널문자('\0')이면 여기서 단어가 끝나는 경우가 있었는지 확인해주면 된다.  
이를 위해 각 트라이 노드는 여기서 끝나는 단어가 있는지 기억해주기 위해 1번에서 언급한 노드 포인터와 함께 boolean 변수를 가지고있게 된다.  


## Proof of correctness 정당성
There is nothing to proof.

증명할 것이 없다. 일단 이게 알고리즘이 아니고 자료구조라서 보이는 그대로 받아들이면 된다(...)


## Other 그 외
Hash table can be faster than Trie. Therefore this should be used in the right place.  
If possible, use hash table. We should use Trie in problems that cannot be solved with hash tables.  
And of course, it is impossible to store the Korean word.  


C++ 표준 라이브러리에서 제공하는 set, map등은 당연히 Trie보다 빠르다. (O(logN))  
당연하게도 이 알고리즘을 사용하여 푼 BOJ 14425번 역시 해시테이블을 이용하는 것이 훨씬 간편하고 시간/공간복잡도 면에서도 유리하다.  
따라서 트라이는 일반적인 해시테이블을 적용할 수 없는 문제들에 대하여 적재적소에 사용해야한다.  
또한 당연하게도, 한글을 Trie에 담는 것은 거의 불가능하다.  