#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>


// Forward declaration
struct HtmlBuilder;

struct HtmlElement
{
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;

    const size_t indent_size = 2;

    // Default constructor
    HtmlElement() {}

    // Constructor
    HtmlElement(const std::string & name, const std::string & text)
    :   name(name), text(text)
    {
        ;
    }

    // Return std::string
    std::string str(int indent = 0) const
    {
        // Temp o stream string
        std::ostringstream oss;
        // Prepare indent size
        std::string i(indent_size * indent, ' ');

        // Opening
        oss << i << "<" << name << ">" << std::endl;

        // Body
        if(text.size() > 0)
            oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;
        
        for(const auto & e : elements)
            oss << e.str(indent + 1);

        // Closing
        oss << i << "</" << name << ">" << std::endl;

        return oss.str();
    }

    // Unique pointer to Htmlbuilder
    static std::unique_ptr<HtmlBuilder> build(std::string root_name)
    {
        return std::make_unique<HtmlBuilder>(root_name);
    }
};


struct HtmlBuilder
{
    // Attributes
    HtmlElement root;

    // Constructor
    HtmlBuilder(std::string root_name)
    {
        root.name = root_name;
    }

    // Void to start with
    HtmlBuilder & add_child(std::string child_name, std::string child_text)
    {
        HtmlElement e(child_name, child_text);
        root.elements.emplace_back(e);
        return *this;
    }

    // Return std::string
    std::string str()
    {
        return root.str();
    }

    operator HtmlElement() const
    {
        return root;
    }
};


int main(int argc, char ** argv)
{
    // <p>hello</p>
    std::cout << "ordinary method 1" << "\n=================" << std::endl;
    auto text = "hello";
    std::string output;
    output += "<p>";
    output += text;
    output += "</p>";
    std::cout << output << std::endl;

    // <ul><li>hello</li><li>world</li></ul>
    std::cout << "\nordinary method 2" << "\n=================" << std::endl;
    std::string words[] = {"hello", "world"};   // Passing in initializer list {}
    std::ostringstream oss;
    // Opening
    oss << "<ul>";
    // Body
    for(auto w : words)
        oss << " <li>" << w << "</li>";
    // Closing
    oss << " </ul>";
    std::cout << oss.str() << std::endl;

    // Builder Design Pattern
    std::cout << "\nBuilder Design Pattern 1" << "\n========================" << std::endl;
    HtmlBuilder builder("ui");
    builder.add_child("li", "hello").add_child("li", "world");
    std::cout << builder.str() << std::endl;

    std::cout << "\nBuilder Design Pattern 2" << "\n========================" << std::endl;
    HtmlElement e = HtmlElement::build("ui")->add_child("li", "hello").add_child("li", "world");
    std::cout << e.str() << std::endl;

    return 0;
}