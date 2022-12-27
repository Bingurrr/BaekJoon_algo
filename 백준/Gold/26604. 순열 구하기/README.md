# [Gold III] 순열 구하기 - 26604 

[문제 링크](https://www.acmicpc.net/problem/26604) 

### 성능 요약

메모리: 2100 KB, 시간: 92 ms

### 분류

구성적(constructive), 구현(implementation), 시뮬레이션(simulation)

### 문제 설명

<p>$1$부터 $N$까지의 정수로 이루어진 길이 $N$의 순열 $P$가 있다. 배열 $A_{i}$는 $P$의 처음 $i(1≤i≤N)$개의 원소를 정렬시킨 길이 $i$의 배열로 정의한다. 배열 $B$는 $A_{1} \oplus A_{2} \oplus \cdots \oplus A_{N-1} \oplus A_{N} \oplus P$ 연산을 수행한 새로운 배열로 정의한다. 두 배열의 xor 연산은 아래의 절차로 이루어진다.</p>

<p>1. 두 배열의 길이가 같다면 다음과 같이 연산한다.</p>

<p style="text-align: center;">$ A \oplus B = [ A_{1} \oplus B_{1}, A_{2} \oplus B_{2}, \cdots , A_{N-1} \oplus B_{N-1}, A_{N} \oplus B_{N} ] $</p>

<p>2. 길이가 $N$인 배열 $A$와 길이가 $M$인 배열 $B$가 있는 경우 다음과 같이 연산한다. ( $N < M$ )</p>

<p style="text-align: center;">$A \oplus B = [ A_{1} \oplus B_{1}, A_{2} \oplus B_{2}, \cdots , A_{N-1} \oplus B_{N-1}, A_{N} \oplus B_{N}, B_{N+1} , \cdots , B_{M-1}, B_{M} ] $</p>

<p>배열 $B$가 주어졌을 때 원래 순열 $P$를 구하는 프로그램을 작성하시오.</p>

<p>여기서 $\oplus$는 bitwise xor 연산을 의미한다. bitwise xor 연산의 정의는 하단 힌트 탭에 있다.</p>

### 입력 

 <p>첫째 줄에 순열의 길이 $N$이 주어진다. $ \left( 1 \leq N \leq 5\,000 \right) $</p>

<p>둘째 줄에 배열의 원소 $B_{i}$가 공백으로 구분되어 주어진다.</p>

<p>순열 $P$로 복원할 수 있는 배열 $B$만 주어지며 $B_{i}$는 항상 $2^{31}$보다 작은 음이 아닌 정수다.</p>

### 출력 

 <p>첫째 줄에 순열 $P$의 원소를 공백으로 구분해 출력한다.</p>

