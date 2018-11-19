#include <iostream>

using namespace std;

//基本：
//1.将构造函数放到private，
//2.static一个函数获取一个static指针

// first
// static似有变量，并提供一个静态方法作为单例的接口。让构造成为私有的，即该对象不能通过类外进行实例化
class Singleton
{
public:
    void myInfo();
    static Singleton * getInstance() {
        if (!m_sgton) {
            m_sgton = new Singleton(); 
        }
        return m_sgton;
    }

private:
    Singleton(){};
    ~Singleton(){};
    static Singleton * m_sgton;
};

Singleton * Singleton::m_sgton = NULL; // 初始化在主线程之前

// second
// 返回静态局部对象的指针
// 为了防止拷贝构造和赋值构造将这两个也放入到私有函数中
class Singleton2
{
public:
    static Singleton2 * getInstance() {
        static Singleton2 sigton;
        return &sigton;
    }

private:
    Singleton2();

    //防止拷贝构造和赋值构造
    Singleton2(const Singleton2 &);
    Singleton2 &operator = (const Singleton2 &);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
