#pragma once

#include "PersonBuilder.hpp"
#include <string>


// Important to specify public (friend purpose)
class PersonJobBuilder : public PersonBuilder
{
private:
    typedef PersonJobBuilder Self;
public:
    // Explicit constructor
    explicit PersonJobBuilder(Person & person)
    :   PersonBuilder(person)
    {
        ;
    }

    Self & at(std::string company)
    {
        this->person.company_name = company;
        return *this;
    }

    Self & as_a(std::string position)
    {
        this->person.position = position;
        return *this;
    }

    Self & earning(int annual_income)
    {
        this->person.annual_income = annual_income;
        return *this;
    }
};