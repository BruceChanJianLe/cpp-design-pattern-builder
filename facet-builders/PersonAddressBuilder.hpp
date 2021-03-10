#pragma once

#include "PersonBuilder.hpp"
#include <string>


// Important to specify public (friend purpose)
class PersonAddressBuilder : public PersonBuilder
{
private:
    typedef PersonAddressBuilder Self;
public:
    explicit PersonAddressBuilder(Person & person)
    :   PersonBuilder(person)
    {
        ;
    }

    Self & at(std::string street_address)
    {
        this->person.street_address = street_address;
        return *this;
    }

    Self &  with_postcode(std::string post_code)
    {
        this->person.post_code = post_code;
        return *this;
    }

    Self & in(std::string city)
    {
        this->person.city = city;
        return *this;
    }
};