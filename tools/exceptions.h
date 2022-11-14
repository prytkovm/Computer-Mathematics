#ifndef COMPUTERMATHEMATICS_EXCEPTIONS_H
#define COMPUTERMATHEMATICS_EXCEPTIONS_H
#include <exception>

class ValTooLong: public std::exception
{
    public:
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Your number is too long!";
    }
};

#endif
