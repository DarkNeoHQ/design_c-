//
// Created by qhc on 2020/10/16.
//

#include "ce_lue.h"
#include <iostream>

using namespace std;

// 抽象类
class Strategy
{
public:
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout << "I am from ConcreteStrategyA." << endl;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout << "I am from ConcreteStrategyB." << endl;
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout << "I am from ConcreteStrategyC." << endl;
    }
};

class Context
{
public:
    Context(Strategy *pStrategyArg) : pStrategy(pStrategyArg)
    {
    }

    void ContextInterface()
    {
        pStrategy->AlgorithmInterface();
    }

private:
    Strategy *pStrategy;
};

int main()
{
    // Create the Strategy
    Strategy *pStrategyA = new ConcreteStrategyA;
    Strategy *pStrategyB = new ConcreteStrategyB;
    Strategy *pStrategyC = new ConcreteStrategyC;
    Context *pContextA = new Context(pStrategyA);
    Context *pContextB = new Context(pStrategyB);
    Context *pContextC = new Context(pStrategyC);
    pContextA->ContextInterface();
    pContextB->ContextInterface();
    pContextC->ContextInterface();

    if (pContextA) delete pContextA;
    if (pContextB) delete pContextB;
    if (pContextC) delete pContextC;
}