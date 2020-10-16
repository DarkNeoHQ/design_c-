//
// Created by qhc on 2020/10/16.
//

#include "dai_li.h"
#include "iostream"

using namespace std;


class school_girl
{
public:
    void SetName(const string str)
    {
        this->name = str;
    }

    string GetName()
    {
        return this->name;
    }

private:
    string name;
};


class IGiveGift
{
    virtual void GiveDolls() = 0;

    virtual void GiveFlowers() = 0;

    virtual void GiveChocolate() = 0;
};

class Pursult : public IGiveGift
{
public:
    explicit Pursult(school_girl *mm)
    {
        this->mm = mm;
    }

    void GiveDolls() override
    {
        cout << "GiveDolls" << endl;
    }

    void GiveFlowers() override
    {
        cout << "GiveFlowers" << endl;
    }

    void GiveChocolate() override
    {
        cout << "GiveChocolate" << endl;
    }

private:
    school_girl *mm;
};

class Proxy : public IGiveGift
{
public:
    Proxy(school_girl *mm)
    {
        this->gg = new Pursult(mm);
    }

    void GiveDolls() override
    {
        this->gg->GiveDolls();
    }

    void GiveFlowers() override
    {
        this->gg->GiveFlowers();
    }

    void GiveChocolate() override
    {
        this->gg->GiveChocolate();
    }

private:
    Pursult *gg;

};


int main()
{
    school_girl* jj = new school_girl;
    jj->SetName("jj");

    Proxy *pp = new Proxy(jj);

    pp->GiveChocolate();
    pp->GiveFlowers();
    pp->GiveDolls();
}