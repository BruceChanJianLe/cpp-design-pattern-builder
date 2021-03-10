#include <iostream>
#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"


int main()
{
    Person p = Person::create()
                .lives().at("clementi avenue 4").with_postcode("120303").in("Singapore")
                .works().at("ASTAR").as_a("research engineer").earning(2500);

    std::cout << p << std::endl;

    return 0;
}