#include <iostream>

#include <mutex>
using namespace std;

//基本：
//1.将构造函数放到private，
//2.static一个函数获取一个static指针

// 通常有两种实现方式，分别为饿汉式和懒汉式

// 1. 饿汉式，在静态区初始化, 也就是还没用就初始化
// 2. 懒汉式， 在运行时进行初始化, 也就是需要时在用

// first

// static似有变量，并提供一个静态方法作为单例的接口。让构造成为私有的，即该对象不能通过类外进行实例化
extern mutex mt;
mutex mt;
class Singleton
{
public:
    void myInfo();
    static Singleton * getInstance() {
        if (!m_sgton) {
            mt.lock();
            if (!m_sgton) {
                m_sgton = new Singleton();
            }
            mt.unlock();
        }
        return m_sgton;
    }

private:
    Singleton(){}
    ~Singleton(){}
    static Singleton * m_sgton;
};

Singleton * Singleton::m_sgton = nullptr; // 初始化在主线程之前

// 饿汉式
// 返回静态局部对象的指针
// 为了防止拷贝构造和赋值构造将这两个也放入到私有函数中
class Singleton2
{
public:
    static Singleton2 * getInstance() {
        static Singleton2 sigton; // 饿汉式，在静态区进行初始化，并将其返回,或者static成员变量， 并在初始化时候进行初始哈
        return &sigton;
    }

private:
    Singleton2();

    //防止拷贝构造和赋值构造
    Singleton2(const Singleton2 &);
    Singleton2 &operator = (const Singleton2 &);
};

#if 1
class Signaleton3
{
public:
    static Signaleton3 * getInstance() {
        return instance;
    }

private:
    Signaleton3(){}
    static  Signaleton3 *instance;
};

Signaleton3 * Signaleton3::instance = new Signaleton3(); // 只要是静态区的初始化都是饿汉式

#endif



















