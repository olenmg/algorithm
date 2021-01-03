# KMP (Knuth-Morris-Pratt) algorithm KMP 알고리즘

## Summary 요약
KMP algorithm is effective when we have search for some string in large string.   
The naive searching takes O(NM) time to find a string of length M from a string of length N.  
But if we use failure function with KMP algorithm, O(M) takes to find failure function, O(N) takes to search a string.  
Time complexity: O(N) (since N > M)  


KMP 알고리즘은 긴 문자열에서 특정 문자열을 찾을 때 사용하는 알고리즘이다.  
보통의 naive한 서칭은 길이 N인 문자열에서 길이 M인 문자열을 찾을 때 O(NM)의 시간복잡도를 보인다.  
그러나 KMP 알고리즘의 실패 함수를 활용하면 실패함수를 찾는데 O(M)의 시간, 탐색을 하는데 O(N)의 시간이 걸리므로 빠른 탐색이 가능하다.  
시간 복잡도: O(N) (N > M 이므로)  


## Algorithm 알고리즘
Follows the steps below.
1. Build failure function pi() of the string to be found.  
pi(i) means the max length of the string(... i) that can be both prefix and suffix.  
i.e. ababaab, pi = [0, 0, 1, 2, 3, 1, 2], pi[4] = 3 cause "aba" is the prefix of "ababa" while "aba" also the suffix of "ababa"  
2. Start searching. If the word we looking for is different with current word, just go back as little as possible.  
We know how length of the current string is same with prefix. So we only have to go back that much.    


다음과 같은 과정을 거친다.
1. 우리가 찾고자하는 문자열에 대한 실패함수를 만든다.  
pi(i)는 i번째 문자열까지가 접두사이자 접미사인 문자열의 길이를 의미한다.  
만약 ababaab를 찾는다면, pi = [0, 0, 1, 2, 3, 1, 2]이다. 예를 들어, "aba"는 "ababa"의 접두사이자 접미사이므로 pi[4] = 3이다.  
2. 이제 이 문자열을 긴 문자열에서 탐색한다. 만약 문자열이 중간까지만 일치하고 끊겼다면, 그 위치에서 처음으로 되돌아가지 않고 최소한의 길이만 되돌아간다.  
실패함수를 통해 지금까지 본 문자열을 최대 길이 몇까지 접두사로 간주할 수 있는지 알 수 있으므로, 그만큼만 되돌아가면 된다.  


## Proof of correctness 정당성
Failure function stores the maximum length that can be both a prefix and a suffix.  
Therefore if we go back only the length that failure function provides, string in front of that must match.  


애초에 실패함수에서는 이 문자열이 접두사이자 접미사가 될 수 있는 최대 길이를 저장한다.  
따라서 실패함수의 값만큼만 되돌아가도 반드시 그 앞은 두 문자열이 서로 일치한다.