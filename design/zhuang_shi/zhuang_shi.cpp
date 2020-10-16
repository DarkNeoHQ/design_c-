//
// Created by qhc on 2020/10/16.
//

#include "zhuang_shi.h"
#include <iostream>
#include <string>
using namespace std;
//Person类 ConcreteComponent
class Person
{
public:
    Person()
    {
    }
    Person(string str)
    {
        this->name = str;
    }
    virtual void Show()
    {
        cout << "装扮的: " << this->name << endl;
    }

private:
    string name;
};

class Finery : public Person
{
public:
    void Decorate(Person* pPerson)
    {
        this->component = pPerson;
    }
    void Show() override
    {
        if (this->component != nullptr)
        {
            this->component->Show();
        }
    }
protected:
    Person* component;
};

//具体服饰类 ConcreteDecorator
class TShirts : public Finery
{
public:
    void Show() override
    {
        cout << "大T恤" << endl;
        Finery::Show();
    }
};

class BigTrouser : public Finery
{
public:
    void Show() override
    {
        cout << "垮裤" << endl;
        Finery::Show();
    }
};

class Sneakers : public Finery
{
public:
    void Show() override
    {
        cout << "破球鞋" << endl;
        Finery::Show();
    }
};

class Suit : public Finery
{
public:
    void Show() override
    {
        cout << "西装" << endl;
        Finery::Show();
    }
};

class Tie : public Finery
{
public:
    void Show() override
    {
        cout << "领带" << endl;
        Finery::Show();
    }
};

class LeatherShoes : public Finery
{
public:
    void Show() override
    {
        cout << "皮鞋" << endl;
        Finery::Show();
    }
};

int main()
{
    Person* xc = new Person("小菜");
    Person buffer[10];

    cout << "\n第一种装扮：\n";

    Sneakers* pqx = new Sneakers;
    BigTrouser* kk = new BigTrouser;
    TShirts* dtx = new TShirts;

    pqx->Decorate(xc);
    pqx->Show();
    kk->Decorate(pqx);
    kk->Show();
    dtx->Decorate(kk);
    dtx->Show();

    return 0;
}
