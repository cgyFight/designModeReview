#ifndef DECORATE_H
#define DECORATE_H
/*
 * 也就是动态的给一些对象添加一些额外的功能
 * 比如 基类饺子A: dumplings，
 * 现在实现一个我的饺子 B mydumplings
 * 现在需要往饺子里面加各种配料
 *
 * 1. 首先定义一个装饰类C，继承A,并传入一个A基类, 这个可以是我的某种饺子, 实际调用这个showmyDumplings是调用这个的
 * 2. 定义具体的装饰内容 继承C ，并在showDumpings时增加自己的内容，最后调用父类的showDumplings
 *
 */
#include <iostream>
using namespace std;

class Dumplings
{
public:
    Dumplings() {}
    virtual void showMyDumplings() = 0;
};

class MyDumplings : public Dumplings
{
public:
    virtual void showMyDumplings() override {
        cout << "my dumplings\n";
    }
};

// 装饰类
class DecorateDumpling:public Dumplings
{
public:
    DecorateDumpling(Dumplings *d):dd(d){}

    virtual void showMyDumplings() override {
        dd->showMyDumplings();
    }
private:
    Dumplings *dd;
};

// 继承装饰类加料
class SaltDecorator:public DecorateDumpling
{
public:
    SaltDecorator(Dumplings *d) :DecorateDumpling(d) {}

    virtual void showMyDumplings() override{
        addSalt();
        DecorateDumpling::showMyDumplings();
    }

private:
    void addSalt()
    {
        cout << "Add salt\n";
    }
};

// 加肉
class MeatDumpings : public DecorateDumpling
{
public:
    MeatDumpings(Dumplings *d) :DecorateDumpling(d) {}
    virtual void showMyDumplings() override {
        addMeat();
        DecorateDumpling::showMyDumplings();
    }

private:
    void addMeat() {
        cout << "add meat\n";
    }
};


class TestDecoder
{
public:
    void testDecoder() {
        Dumplings *d = new SaltDecorator(new MeatDumpings(new DecorateDumpling(new MyDumplings())));
        d->showMyDumplings();
    }
};

#endif // DECORATE_H
