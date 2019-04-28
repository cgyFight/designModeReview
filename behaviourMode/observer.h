#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <set>
using namespace std;



/* 观察者模式
 * 主要解决就是一个目标更新，所有目标更新,比如qt种的信号槽，model/view等
 *
 * 通过一个数据结构保存要更新的目标对象，
 */


// dataModel

// /view 观察者, 当数据更新时，观察者更新
class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer(){};
};

class Observer1:public Observer
{
public:
    Observer1() {static int c = 0; k = c++;}

    virtual void update() override {
        cout << "observer " << k << " get it\n";
    }
private:
    int k;
};

class DateModel
{
public:
    virtual  void add(Observer *) = 0;
    virtual void remove(Observer *) = 0;
    virtual void notify() = 0;
    virtual ~DateModel() = 0{};// {}
};



class IntDataModel : public DateModel
{
public:
    virtual ~IntDataModel() override {}
    virtual  void add(Observer *ob) {setOfObserver.insert(ob);};
    virtual void remove(Observer *ob) {setOfObserver.erase(ob);};
    virtual void notify() {
        for(auto t : setOfObserver) {
            t->update();
        }};
    set<Observer *> setOfObserver;
};

class TestObserver  {
public:
    void testObserver() {
        Observer1 o1, o2, o3;
        IntDataModel m;
        m.add(&o1);
        m.add(&o2);
        m.add(&o2);
        m.add(&o2);
        m.add(&o3);
        m.remove(&o2);
        m.notify();
    }
};



#endif // OBSERVER_H
