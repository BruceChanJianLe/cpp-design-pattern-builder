#pragma once

#include "Person.hpp"


// Forward declaration
class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilder
{
    private:
        Person p;

    protected:
        Person & person;
        // Explicit Constructor
        explicit PersonBuilder(Person & person)
        :   person(person)
        {
            ;
        }

    public:
        // Constructor
        PersonBuilder()
        :   person(p)
        {
            ;
        }

        operator Person()
        {
            return std::move(person);
        }

        // Builder facets
        PersonAddressBuilder lives();
        PersonJobBuilder works();
};