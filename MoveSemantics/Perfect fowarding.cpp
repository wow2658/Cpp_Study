// [forwarding]
// func(int x)
// func(int& x)
// func(const int& x)
// func(int&& x)
// 위 같은 형태에 따라 각각 lvalue, rvalue가 허용되고 안되고를 저번에 판별할 수 있었다.
// 또한 그에따라 x에 대해서 Modifiable 한지, const로 인해 Immutable한지, Move version 알 수 있었다.
// 이렇게 완성한 x를 활용해서 본인이 감싸고 있는 함수나 클래스를 call할 때 인수로 활용하는 것을 forwarding이라고 한다.

// [Nested References]
// int seoul = 42; 를 통해 seoul이라는 lvalue를 얻어보자.
// int& ref = seoul 를 통해 lvalue reference도 얻어보자.
// 그다음 Nested(중첩)하게 42라는 prvalue를 담은 seoul이라는 lvalue를 refernce한 red라는 lvalue reference를 reference....하면 어떻게 될까?
// 일부러 어지럽게 길게 써봤다. 간단하게 표현하면 
// int& & nested_ref = ref;로 나타낼 수 있다. 어떻게 될까?
// 컴파일 오류가 난다. ref는 lvalue로 이미 identity를 가지고 있는데 그거 수명연장해서 rvalue reference로 삼으려고하다니 무슨짓이냐! 하고 컴파일러가 막아버린다.
// using 키워드를 사용하면 컴파일러가 reference collapsing해버려서 통과시켜준다.
// using int_ref = int&; int_ref& nested_ref = ref; 라고 쓰면 오류가 안나는 것을 아래 main에서 확인할 수 있었다.
// 그럼 이렇게 까지해서 얻은 nested_ref의 정체는 lvalue reference일까 rvalue reference일까?

// nested_func(nested_ref);를 통해 lvalue reference라는 것을 알 수 있었다. 왜 그런걸까?
// 컴파일러가 reference collapsing할 때 답이 있다.
// using lval_ref = int&;
// using rval_ref = int&&;
// 라고 정했을 때 컴파일러는 아래와 같이 collaps해서 해석해버린다.
// lval_ref &         => int& (nested_ref는 여기였나보다.)
// lval_ref &&        => int&
// rval_ref &         => int& 
// rval_ref &&        => int&&
// 위의 것의 의의는 컴파일러가 답을 한쪽으로만 내리는 것 아니라 int&인지 int&&인지 양쪽으로 나름의 해석을 통해 나눌줄 안다는 것이다.
// 이러한 가능성을 가지고 template을 이용하면 아주 유용해진다.
// template <class T>
// Test make_test(T&& x); 
// 이렇게 해두면 컴파일러가 알아서 들어온 x를 보고 lvalue가 왔는지 rvalue가 왔는지 판단도 해주고
// 그걸 토대로 copy를 이용할지 move를 할지도 알아서 정하고 인스턴스화 한다.
// 이걸 알아서 해준다면 일일히 모든 경우의 수에 대비해서 오버로드할 필요 없어서
// 매우 편할 것이다! 대단하다. 덕분에 라이브버리를 개발할때 많이 사용된다고 한다.

// [Perfect Forwarding]
// template <class T>와 (T&& x) 콤보를 사용해도 약점이 있다.
// 들어오는 것은 똑똑하게 어찌저찌 알아서 잘 구별해도 그것을 내부에서 Perfect forwarding할때는 다시 바보가 되어 구별을 못한다.
// 
//template <class T>
//void f(T&& x)
//{
//    gf(x);                  // 이렇게 해두면 rvalue가 들어와도 Modifiable version을 부른다. 
//                            // 이걸 해결하고 싶어서
//    gf(std::move(x));       // 으로 바꾸면  rvalue가 들어왔을때 정상적으로 Move version을 부르기는 하는데...
//                            // 이번에는 또 lvalue가 들어왔을때도 Move version을 불러버려서 빵꾸를 내버린다. 무슨 시소도 아니고 이러지도 저러지도 못하게 한다.
//    gf(std::forward<T>(x)); // 이때 이것을 사용해서 해결할 수 있다. 완전 만능 구세주 반가운 친구다.
//                            // std::forward(x)로만 쓰면 오류가 난다. <T>를 붙여줘야한다.
//}
// 이렇게 해서 모든 경우의 수에 잘 대비가 된 상태로 Perfect Forwarding을 구현 할 수 있었다.
// 
// 
// 공부시작하기 전에 어떤 블로그에서는 Perfect Forwarding를 문제현상이고 그 자체가 오류라는듯이 설명해서 
// Perfect하면 좋은거 아닌가 뭐가 문제지? 궁금하기도 했고 
// Move Semantics 공부한 타이밍에서 연계하면 매우 좋을 것 같아서 공부하게 되었다.

 

#include <iostream>

using namespace std;

void nested_func(int& x)
{
    std::cout << "\nnested_func called with argument int&\n";
}

class PF_TEST { };

void gf(PF_TEST& x)
{
    std::cout << "Modifiable version of gf called\n";
}

void gf(const PF_TEST& x)
{
    std::cout << "Immutable version of gf called\n";
}

void gf(PF_TEST&& x)
{
    std::cout << "Move version of gf called\n";
}

template <class T>
void f(T&& x)
{
    //gf(x);
    //gf(std::move(x));
    gf(std::forward<T>(x));
}



class Test
{
    string m_str;
public:
    Test(const string& str) : m_str(str)
    {
        cout << "const string& constructor called\n";
    }
    Test(string&& str) : m_str(std::move(str))
    {
        cout << "string&& constructor called\n";
    }
};

void g(string& x)
{
    std::cout << "Modifiable version of g called\n";
}

void g(string&& x)
{
    std::cout << "Move version of g called\n";
}

template <class T>
Test make_test(T&& x)
{
    g(std::forward<T>(x));
    return Test(std::forward<T>(x));
}

int main()
{

    //Nested References 실험
    int seoul = 42;
    int& ref = seoul;
    //int&& nested_ref = ref; // rvalue 참조를 lvalue에 바인딩할 수 없습니다.
    using int_ref = int&;
    int_ref& nested_ref = ref; // 통과
    nested_func(nested_ref);    // nested_ref는 int&으로 lvalue reference 취급을 받았다.


    PF_TEST x;
    const PF_TEST cx;


    cout << "\nCalling f() with lvalue argument\n";
    f(x);
    cout << "\nCalling f() with const lvalue argument\n";
    f(cx);
    cout << "\nCalling f() with rvalue argument\n";
    f(std::move(x));

    string hello{ "Hello" };

    cout << "\nCalling make_test() with lvalue argument\n";
    Test t1 = make_test(hello);

    cout << "\nCalling make_test() with rvalue argument\n";
    Test t2 = make_test(std::move(hello));
}