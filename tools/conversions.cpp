#include <gmpxx.h>
#include <sstream>
#include "exceptions.h"

bool mpz_fits_ull(mpz_class val)
{
    mpz_class MAX(std::to_string(ULONG_LONG_MAX));
    if (val <= MAX)
        return true;
    else
        return false;
}

size_t mpz_to_ull(mpz_class& val)
{
    if (!mpz_fits_ull(val))
        throw ValTooLong();
    std::stringstream str(val.get_str());
    size_t ull;
    str >> ull;
    return ull;
}
