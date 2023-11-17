# static_cast

```cpp
static_cast <dest_type> (source);
```

## 용도

- 상속으로 관련된 유형 변환(업캐스팅 또는 다운캐스팅)
    - 업캐스팅의 경우 항상 안전하다.
    - 다운캐스팅의 경우 안전하지 않을 수 있다.(dynamic_cast 사용)
- C++에서의 비 다형성 타입의 변환
    - int -> float, int -> double, double -> int 등
    - 열거형(enum) -> int, int -> 열거형(enum) 등
    - void* -> int*, int* -> void* 등
    - int 레퍼런스 -> double 레퍼런스 등
    - 상속관계가 아닌 클래스 간의 변환

## 예시

```cpp
float floatNumber = 3.5;
 
int a = (int)floatNumber;
cout << "The Value of a: " << a << std::endl;

int b = static_cast<int>(floatNumber);
cout << "The Value of b: " << b << std::endl;
```

```bash
The Value of a: 3
The Value of b: 3
```

### C 스타일 캐스팅
- 안전성에 대한 자세한 검사를 제공하지 않으므로 때때로 안전하지 않거나 의도하지 않은 동작이 발생할 수 있다.
- static_cast, const_cast, 심지어 reinterpret_cast의 조합을 `(int)floatNumber`와 같은 하나의 스타일로 표현하기에 명시성이 떨어진다. 

### static_cast
- 엄격한 컴파일 타임 타입 검사를 제공
- C++ 타입 시스템 내에서 안전하고 유효한 것으로 정의된 변환만 수행한다. 호환되지 않는 포인터 유형 간의 변환과 같이 본질적으로 안전하지 않은 변환은 컴파일되지 않음.
- static_cast 이외에도 dynamic_cast, const_cast, reinterpret_cast가 있기에 명시성이 높다.

<br>

# dynamic_cast

```cpp
dynamic_cast <dest_type> (source);
```

## 용도

- 베이스 클래스에서 파생 클래스로의 안전한 다운캐스팅(업캐스팅도 가능)
  - RTTI(Run-Time Type Information)를 사용하여 런타임에 유형 안전성을 검사한다.
  - 때문에 성능이 느리지만 안전하다. 
- 베이스 포인터/레퍼런스로 참조된 객체의 정확한 유형을 알 수 없고 런타임에 결정해야 하는 상황에서 사용된다.
- 반드시 하나 이상의 가상 함수를 가진 클래스에서만 사용할 수 있다.

## 예시

```cpp
class Base { virtual void foo() {} };
class Derived : public Base {};

Base *b = new Derived;
Derived *d = dynamic_cast<Derived*>(b);
```

### 예외 발생 시
- dynamic_cast는 포인터 타입에 대해 NULL을 반환하고 레퍼런스 타입에 대해 std::bad_cast 예외를 발생시킨다.

```cpp
class Base { virtual void foo() {} };
class DerivedA : public Base {};
class DerivedB : public Base {};

Base *b = new DerivedA;
DerivedB *d = dynamic_cast<DerivedB*>(b);
```

<br>

# reinterpret_cast

```cpp
reinterpret_cast <dest_type> (source);
```

## 용도
- 값은 그대로 유지하면서 포인터 간의 변환을 수행한다.(재해석, 형식만 바꿈)
- 포인터 간의 변환
- C++의 reinterpret_cast는 한 포인터 또는 참조 유형을 다른 유형으로 변환하는 데 사용되는 일종의 캐스팅 연산자로, 프로그래머가 가리키는 객체의 비트 패턴을 재해석할 수 있도록 해줍니다. 이러한 유형의 형변환은 값의 실제 내용을 변경하지 않습니다. 대신 컴파일러가 표현식의 비트 패턴을 다른 유형인 것처럼 취급하도록 지시할 뿐입니다.

## 예시

```cpp
int* ip = new int(42);  // Integer with value 42

// Reinterpreting the int pointer as a char pointer
char* cp = reinterpret_cast<char*>(ip);

std::cout << "*cp: " << *cp << std::endl;
std::cout << std::bitset<8>(*cp) << std::endl;

std::cout << "*ip: " << *ip << std::endl;
std::cout << std::bitset<32>(*ip) << std::endl;
```

```bash
*cp: *
00101010
*ip: 42
00000000000000000000000000101010
```
