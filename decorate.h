#ifndef DECORATE_H
#define DECORATE_H
/*
 * 也就是动态的给一些对象添加一些额外的功能
 * 比如 基类饺子A，有一个子类肉馅饺子B， 现在需要有一个加盐C，加油的饺子D，则使用装饰类继承基类饺子E，并将B传入，使用C，D继承E，在A的方法中添加自己的特性
 */

class Dumplings
{
public:
    Dumplings() {}
    virtual void showDressing() = 0;
};

class MeatDumpings : public Dumplings
{
public:
    MeatDumpings() {}
    virtual void showDressing() override {
        cout << "add meat\n";
    }
};

// 装饰类
class DecorateDumpling:public Dumplings
{
public:
    DecorateDumpling(Dumplings *d):dd(d){}

    virtual void showDressing() override {
        dd->showDressing();
    }
private:
    Dumplings *dd;
};

// 继承装饰类加料
class SaltDecorator:public DecorateDumpling
{
public:
    SaltDecorator(Dumplings *d) :DecorateDumpling(d) {}

    virtual void showDressing() override{
        DecorateDumpling::showDressing();
        addDressing();
    }

private:
    void addDressing()
    {
        cout << "Add salt\n";
    }
};

#endif // DECORATE_H
