#ifndef ADAPTER_H
#define ADAPTER_H

/*
 * 适配器模式
 * 1. 对象适配器
 * 2. 类适配器
 *
 */
//主要就是已经实现有A接口 ，但是客户需要B接口，因此用一个适配类，继承B，内部调用A的接口
// 场景，充电用两个孔的插口，但是这里只有三口的插口，所以通过一个适配器，使得可以使用三孔的插口
// 适配器继承目标三口插口，传入二孔插口，

class ChaKou
{
public:
    virtual void powerWithTow() = 0;

};

class TowChaKou:public ChaKou
{
public:
    virtual void powerWithTow() override {
        cout << "tow cha kou power\n";
    }
};

class ThreeChaKou{
public:
    void powerWithThree() {cout << "power with three\n";}
};

class AdapterChakou:public ChaKou
{
public:
    AdapterChakou(ThreeChaKou *intree):threeChaKou(intree) {}

    virtual void powerWithTow(){threeChaKou->powerWithThree();}


private:
    ThreeChaKou *threeChaKou;
};

class Hotel
{
public:
    Hotel(ChaKou *c):chkou(c) {}

    void chongdian() {
        chkou->powerWithTow();
    }

private:
    ChaKou *chkou;
};

class TestAdpter
{
public:
    TestAdpter() {
        Hotel hotel(new AdapterChakou(new ThreeChaKou));
        hotel.chongdian();
    }
};
#endif // ADAPTER_H
