#pragma once

#include <string>
#include <memory>

#include <boost/lexical_cast.hpp>

// Forward declaration
class PersonBuilder;

class Person
{
    private:
        // Address
        std::string street_address, post_code, city;
        // Employment
        std::string company_name, position;
        int annual_income;

        Person() {}

    public:
        static PersonBuilder create();

        // Constructor
        Person(Person && other)
        :   street_address(std::move(other.street_address)),
            post_code(std::move(other.post_code)),
            city(std::move(other.city)),
            company_name(std::move(other.company_name)),
            position(std::move(other.position)),
            annual_income(std::move(other.annual_income))
        {
            ;
        }

        // Overload equal operator
        Person & operator = (Person && other)
        {
            if(this == &other)
                return *this;

            street_address = std::move(other.street_address);
            post_code = std::move(other.post_code);
            city = std::move(other.city);
            company_name = std::move(other.company_name);
            position = std::move(other.position);
            annual_income = std::move(other.annual_income);
        }

        // Overload ostream operator
        friend std::ostream & operator << (std::ostream & os, const Person & obj)
        {
            return os
                << "street address: " << obj.street_address
                << " post code: " << obj.post_code
                << " city: " << obj.city
                << " company name: " << obj.company_name
                << " position: " << obj.position
                << " annual income: " << boost::lexical_cast<std::string>(obj.annual_income);
        }

        // Friend class
        friend class PersonBuilder;
        friend class PersonAddressBuilder;
        friend class PersonJobBuilder;
};