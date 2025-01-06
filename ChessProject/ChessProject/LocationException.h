#pragma once
#include <exception>

class LocationException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "This is an location exception!\n";
    }
};
