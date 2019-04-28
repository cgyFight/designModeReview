#ifndef PROXY_H
#define PROXY_H
#include <iostream>

/*
 *
 */
using namespace std;
class Subject
{
public:
    Subject() {}

    virtual void request() = 0;
    virtual ~Subject() {
    }

private:
};

class RealSubject : public Subject
{
public:
    RealSubject() {}
    virtual void request() {cout << "this is real subject\n";}
};

class Proxy : public Subject
{
public:
    Proxy() {realSub = new RealSubject();}
    virtual ~Proxy() { }

    void request() { //通过代理实现
        beforRequest();
        realSub->request(); //真正得执行
        afterRequest();
    }
private:

    void beforRequest(){}
    void afterRequest() {}

    RealSubject *realSub;
};

#endif // PROXY_H
