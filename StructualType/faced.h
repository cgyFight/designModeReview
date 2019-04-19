#ifndef FACED_H
#define FACED_H
#include <iostream>
using namespace std;

/*
 * 外观模式
 * 也就是将一系列过程封装起来，对外只暴露一个简单接口
 */
class Cpu
{
public:
    void createCpu() {cout << "construct cpu\n";}
};
class Graphics
{
public:
   void createGrapics() {cout << "construct graphics\n";}
};
class Computer {
public:
    void createComputer() {
        Cpu c;
        c.createCpu();
        Graphics g;
        g.createGrapics();
    }
};

#endif // FACED_H
