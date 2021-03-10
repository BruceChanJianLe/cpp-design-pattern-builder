#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>


class String
{
    public:
        std::string s;

        String(const std::string & s) : s(s)
        {
            ;
        }

        ~String() {}

        String to_lower_copy() const
        {
            // Return lower case copy of String
            return {boost::to_lower_copy(s)};
        }

        std::vector<String> split(const std::string & delimeter = " ") const
        {
            // Temp variable to store parts of string
            std::vector<std::string> parts;
            // Use boost library to split string
            boost::split(parts, s, boost::is_any_of(delimeter), boost::token_compress_on);
            // Return split result
            return std::vector<String>(parts.begin(), parts.end());
        }

        size_t get_length() const
        {
            return s.length();
        }

        std::string str()
        {
            return s;
        }
};

int main()
{
    std::string s{"Hello  World"};

    // Standard library is not enough, hence, we need to use Boost library.

    std::string s1 = boost::to_lower_copy(s);
    std::vector<std::string> parts;
    boost::split(parts, s1, boost::is_any_of(" "), boost::token_compress_on);

    // Display result
    for(auto & p : parts)
        std::cout << p << " " << p.length() << std::endl;
    
    // Our own adapter
    String s2 {"Hello  World"};

    // Display result on the fly
    for(auto & p : s2.to_lower_copy().split())
        std::cout << p.str() << " " << p.get_length() << std::endl;

    return 0;
}