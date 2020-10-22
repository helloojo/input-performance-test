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