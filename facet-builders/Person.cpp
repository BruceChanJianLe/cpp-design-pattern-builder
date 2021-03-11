#include "Person.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"


PersonBuilder Person::create()
{
    return PersonBuilder();
}