set(FILES facet-builders.cpp
    Person.cpp Person.hpp
    PersonBuilder.cpp PersonBuilder.hpp
    PersonAddressBuilder.hpp PersonJobBuilder.hpp
)

add_executable(FacetBuilders ${FILES})