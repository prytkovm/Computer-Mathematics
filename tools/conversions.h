#ifndef COMPUTERMATHEMATICS_CONVERSIONS_H
#define COMPUTERMATHEMATICS_CONVERSIONS_H
#include <cstddef>
#include <gmpxx.h>

size_t mpz_to_ull(mpz_class&);
bool mpz_fits_ull(mpz_class);

#endif
