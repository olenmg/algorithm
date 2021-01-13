# CCW(counterclockwise) algorithm CCW 알고리즘

## Summary 요약
CCW algorithm finds the relation between two vectors in two dimensional coordinate space.  
It can also find if two lines intersect.  
In fact, this just finds the cross product of two vectors.  

  
CCW 알고리즘은 2차원 좌표공간에서 두 벡터간의 위치관계를 찾는데에 사용한다.  
좀 덧붙이자면, 두 벡터간의 각도 중 작은 각도를 기준으로 시계반대방향으로 어느 것이 먼저 놓이는지 찾는다.  
이 알고리즘을 응용하면 두 선분이 교차하는지도 확인할 수 있다.  
사실 이 알고리즘은 그냥 두 벡터간 외적을 구하는 알고리즘이다.  


## Algorithm 알고리즘
Find the cross product of two vectors. Set the z coordinates of two vectors as 0 and find cofactor expansion for z direction (C_13).  
We can also find this value as using shoelace formula.  
Also their results are same. Shoelace formula is just the easy way to find C_13.  

    
두 벡터간의 외적을 찾는다. z좌표를 0으로 두고 두 벡터 간의 z방향 라플라스 전개(cofactor expansion)을 구해도 되고(C_13), 신발끈 공식을 전개해도 된다.  
신발끈 공식은 라플라스 전개를 보다 보기 쉽게 표현한 것이고, 사실 두 방법의 결과는 완벽히 일치한다.  


## Proof of correctness 정당성
It is well known that the cross product of two vectors can determine the vertical direction(...).  


벡터의 외적이 두 벡터의 수직방향을 결정할 수 있다는 것은 잘 알려져있다.   


## Ohter 그 외
We can check if two lines intersect by using CCW for 4 times.  
Suppose that two vectors are L1(a, b), L2(c, d). a, b, c, d are all end points of each line.  
Make new vectors ac and ad by connection a with c, d. And find the cross product(CCW) between L1 and ac, L1 and ad. Check if their sign is different.  
Repeat same process with L2. (L2 and ca, cb) We can find whether lines are intersect by check the sign of 4 CCWs.  
If some CCW is 0, it means that some three points of a, b, c, d lie on a same straight line. Then we have to check if some point is lie on other line.  
We can easily understand this process by drawing picture.  



두 선분이 교차하는지는 총 4번의 CCW 수행으로 구할 수 있다.  
점 a와 점 b를 이어 만든 선분 L1, 점 c와 점 d를 이어 만든 선분 L2가 있다고 가정하자.  
점 a와 점 c, d를 각각 이어 새로운 벡터 ac, ad를 만들고 해당 벡터를 L1과 외적하여(CCW) 두 외적값(CCW)의 부호가 서로 다른지를 확인한다.  
같은 과정을 L2에 대하여서도 반복하면(L2와 ca, cd) 총 4번의 CCW를 수행하게 되며, 부호를 체크함으로써 두 선분이 교차하는지를 알 수 있다.  
CCW값이 0인 경우가 나타나면 각 선분을 구성하는 점들 중 세 점이 한 직선에 놓인다는 뜻이므로 이 때는 선분의 양 끝점 중 하나가 다른 선분의 위에 놓여있는지를 확인해야한다.  
선분 교차 알고리즘의 경우 원리는 간단한데 글로 설명하기는 복잡하여 여기에 자세히 쓰지는 않는다. 다만 그림을 그려보면 쉽게 파악할 수 있다.  
  