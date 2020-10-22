# C++ Input Performance Test

## 사용법
`./input_test ...[OPTION]`
#### `-i`
입력 성능 테스트를 수행
#### `-o`
입력 성능 테스트를 위한 파일을 생성
#### `-s [sample size]`
테스트 위한 파일에 생성할 라인 개수
#### `-t [MODE]`
테스트 모드
##### 1
`scanf` 테스트
##### 2
`cin, sync_with_stdio(true)` 테스트
##### 3
`cin, sync_with_stdio(false)` 테스트
##### 4
`cin, sync_with_stdio(false), cin.tie(nullptr)` 테스트

### 예시
#### 테스트용 파일 생성
![image](https://user-images.githubusercontent.com/28619559/96888121-404d0d80-14c0-11eb-9929-c080f1cdad40.png)
#### 테스트
![image](https://user-images.githubusercontent.com/28619559/96887995-1bf13100-14c0-11eb-85ba-e67cd29987d3.png)
