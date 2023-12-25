# CPP_MODULE_08

## General
- STL 쓸 수 있음 (vector / list / map / and so on)
- Algorithm 쓸 수 있음
- template 구현부 .tpp 파일로 분리 또는 분리 안해도 됨

## EX00
- T와 integer 두 개의 인자를 받는 easyfind()라는 템플릿 함수를 만들어라
- T는 정수들을 담아둘 수 있는 컨테이너이다

- 템플릿 함수는 T에 있는 요소들 중에서 두번째 인자로 받은 정수를 찾아야 한다. (레퍼런스 반환?)
- 만약 찾지 못했다면 예외를 던지거나, error value를 반환해라(STL 레퍼런스 참고)

- main.cpp를 만들어서 easyfind()를 테스트해라

- vector / deque / list 만 핸들링 하면 됨