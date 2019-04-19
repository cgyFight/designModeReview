#ifndef TEMPLATE_H
#define TEMPLATE_H
/* 模板模式,将通用的算法方法抽象出来，将关键代码在父类中实现，其它步骤到子类中实现，比如游戏类有玩时有三个步骤，初始化，开始，结束
 * 不同的游戏有不同的初始化，开始，结束步骤
 */

class Game {
public:
    void play(){
        initial();
        end();
    }
    virtual void initial() = 0;
    virtual void end() = 0;
};
class FootballGame : public Game
{
public:
    FootballGame() {}
    virtual void initial() override {
        cout << "inital foot bal\n";
    }
    virtual void end() override {
        cout << "end foot bal\n";
    }
};

class BaskteBallGame:public Game
{
public:
    virtual void initial() override {
        cout << "inital basketball bal\n";
    }
    virtual void end() override {
        cout << "end  basketball bal\n";
    }
};

#endif // TEMPLATE_H
