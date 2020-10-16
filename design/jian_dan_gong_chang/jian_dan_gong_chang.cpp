//
// Created by qhc on 2020/10/16.
//

#include "jian_dan_gong_chang.h"
#include <iostream>

using namespace std;

class operation
{
public:
    double GetNumberA() const
    {
        return this->numA;
    }

    double GetNumberB() const
    {
        return this->numB;
    }

    void SetNumA(const double A)
    {
        this->numA = A;
    }

    void SetNumB(const double B)
    {
        this->numB = B;
    }

    virtual double GetResult()
    {
        double result = 0;
        return result;
    }

protected:
    double numA{};
    double numB{};
};


class operation_sub : public operation
{
public:
    double GetResult() override
    {
        double result = 0;
        result = this->numA - this->numB;
        return result;
    }
};

class operation_add : public operation
{
public:
    double GetResult() override
    {
        double result = 0;
        result = this->numA + this->numB;
        return result;
    }
};

class operation_mul : public operation
{
public:
    double GetResult() override
    {
        double result = 0;
        result = this->numA * this->numB;
        return result;
    }
};

class operation_div : public operation
{
public:
    double GetResult() override
    {
        double result = 0;
        result = this->numA / this->numB;
        return result;
    }
};

class operationFactory
{
public:
    static  operation *createoperate(char type)
    {
        operation *operation = nullptr;

        switch (type)
        {
            case '+':
                operation = new operation_add();
                break;
            case '-':
                operation = new operation_sub();
                break;
            case '*':
                operation = new operation_mul();
                break;
            case '/':
                operation = new operation_div();
                break;
            default:
                break;
        }
        return operation;
    }
};


int main()
{
    operation *operation;
    double A, B;
    cin >> A >> B;

    operation = operationFactory::createoperate('+');

    operation->SetNumA(A);
    operation->SetNumB(B);
    cout << "=" << operation->GetResult();
}

