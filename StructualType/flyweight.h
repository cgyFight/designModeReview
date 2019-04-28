#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H
/*
 * 享元模式
 *
 * 即实现对象得共享
*/

class FlyWeighut
{
public:
    FlyWeighut() {}
    virtual ~FlyWeighut();
};

class FlyWeight2 : public FlyWeighut
{
public:
    FlyWeight2() {}
};

#endif // FLYWEIGHT_H
