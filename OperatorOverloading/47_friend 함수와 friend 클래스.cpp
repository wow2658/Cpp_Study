//friend 함수 : 객체지향 언어의 중요한 원칙인 캡슐화, 은닉화를 무시하는 무법자
//접근 지정자인 private public 등의 영향을 받지 않는다. -> 좀 특이한 녀석이니까 주의하라고 class {블럭}의 상위라인에 올려놔서 경각심을 주자.
//friend라고 허가를 내준 집주인의 멤버함수로 취급받지도 않는다. -> 헤더파일에서 외부구현하거나 사용처에서 호출시 범위 연산자 ::를 붙이지 않는다.
//ex) friend void func1() 같은 원형을 띈다.

