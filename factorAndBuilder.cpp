// 演示建造者和工厂模式

/* 工厂方法模式注重的是整体对象的创建方法，
而建造者模式注重的是部件构建的过程，
旨在通过一步一步地精确构造创建出一个复杂的对象。
我们举个简单例子来说明两者的差异，如要制造一个超人，
如果使用工厂方法模式，直接产生出来的就是一个力大无穷、能够飞翔、内裤外穿的超人；
而如果使用建造者模式，则需要组装手、头、脚、躯干等部分，然后再把内裤外穿，才能创造一个超人。
*/

#include <iostream>
#include <string>
using namespace std;

// factory
// 开闭原则的体现->抽象父类，比如与运算的，有+ - * / 等等，通过抽象父类
// 抽象->实例子类->工厂根据情况生成子类
// 1. 抽象超人
class CISuperMan
{
public:
    CISuperMan() {}
    virtual  ~CISuperMan() {} // 抽象类的析构函数都需要用virtual，否则Father *child = new Child(); 时析构不会析构父类的
    virtual void mySpecialTalent() const = 0 ;//超能力
};

// 2. 实例化多种子类
class ChildSuperMan:public CISuperMan
{
public:
    ChildSuperMan() {}
    ~ChildSuperMan() override {}
    virtual void mySpecialTalent () const override
    {
        std::cout << "child super man" << std::endl;
    }
};

// 2.1 
class CAdultSuperMan : public CISuperMan
{
public:
    CAdultSuperMan() {}
    ~CAdultSuperMan() override {}

    virtual void mySpecialTalent() const override {
        std::cout << "adult super man" << std::endl;
    }
};

// 3 创建一个工厂,目的是生产超人，具体是成年还是未成年由客户端决定
class SuperManFactory
{
public:
    SuperManFactory() {}
    ~SuperManFactory() {}
    CISuperMan * createSuperMan(string type) {
        if ("adult" == type) {
            return new CAdultSuperMan();
        } else if ("child" == type) {
            return new ChildSuperMan();
        } else {
            return nullptr;
        }
    }
};

// 此例中使用了模板方法的模式,每一个建造者必须返回一个产品，但产品如何制造，则由各个建造者自己负责

// 1. 产品类
// 超人这个产品由三部分组成，躯体，特殊技能，身份标记, 
class SupperMan
{
public:
    SupperMan() {}
    ~ SupperMan() {}

    string getBody() {return body;}
    void setBody( const string &b) {body = b;}

    string getSpecialTalent() {return specialTalent;} 
    void setSpecialTalent(const string &s) {specialTalent = s;}
private:
    string body;
    string specialTalent;
};

// 2. 抽象建造者
class Builder
{
protected:
    Builder() {pSuperMan = new SupperMan();}
    ~Builder() {}

    void setBody(const string &body) {pSuperMan->setBody(body);}
    void setSpecialTalent(const string &s) {pSuperMan->setSpecialTalent(s);}

public:
    virtual SupperMan * getSupperMan() = 0;

protected:
    SupperMan * pSuperMan;
};
