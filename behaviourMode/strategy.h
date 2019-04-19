#ifndef STRATEGY_H
#define STRATEGY_H


/* 策略模式
 * 概述：定义一些列的算法，将他们封装，让他们可以互相替换，使得算法可以独立于客户而变化
 * 即功能一样接口一样，但实现算法不一样
 *
 * 1. 定义抽象策略角色（为策略对象定义一个公共接口）
 * 2. 编写具体策略角色（子类继承实现接口）
 * 3. 定义环境角色，内部持有一个策略的引用
 *
 * 总结：和工厂模式类似，不同的是这个封装的是方法，工厂模式封装的类
 *
 */

/*
 * 方式1 普通重写
 */
class HurtStrategy
{
public:
    virtual void hurt() = 0 {}

private:
};

class ADCHurt:public HurtStrategy
{
public:
    virtual void hurt() override {cout << "adchurt\n";}
};

class APHurt:public HurtStrategy
{
public:
    virtual void hurt() override {cout << "aphurt\n";}
};

typedef enum { adc, apc } HurtType;
/*
 * 传入调用和tag调用
 */
class NormorEnvironment
{
public:
    NormorEnvironment(HurtStrategy *inStrage) : strage(inStrage) {  }
    NormorEnvironment(HurtType type) {
        switch (type) {
        case adc:
            strage = new ADCHurt;
            break;
        case apc:
            strage = new APHurt;
            break;
        default:
            break;
        }
    }

    void callHurt() {
        strage->hurt();
    }

private:
    HurtStrategy *strage;
};

/*
 * 方式三使用模板类
 */
template <class T>
class Rou
{
public:
//    Rou() {cout << "Rou\n";}
    void  beHurt() {
        cout << "begin be hurt\n";
        somRol.hurt();
    }
private:
    T somRol;
};

class Test
{
public:
    Test() {
        cout << "nor mal call\n";
        NormorEnvironment e(new ADCHurt);
        e.callHurt();
        cout << "use tag call\n";
    }
};

/*
 * 方式4 使用函数指针或者 std::function
 */


#endif // STRATEGY_H
