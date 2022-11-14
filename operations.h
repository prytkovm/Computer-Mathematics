#ifndef COMPUTERMATHEMATICS_OPERATIONS_H
#define COMPUTERMATHEMATICS_OPERATIONS_H
#include "hashtable/table.h"
#include <string>
#include "tools/exceptions.h"
#include <gmpxx.h>

mpz_class discrete_log(mpz_class, mpz_class, mpz_class);
mpz_class newton_sqrt(const mpz_class&);
mpz_class bits_count(mpz_class);
mpz_class binary_pow(mpz_class, mpz_class);

mpz_class discrete_log(mpz_class a, mpz_class b, mpz_class p)
{
    mpz_class H = newton_sqrt(p) + 1;
    mpz_class current_val, temp, c = 1, d = 1;
    size_t converted_H;
    try
    {
       converted_H = mpz_to_ull(H);
    }
    catch (ValTooLong& err)
    {
        throw err;
    }
    for (mpz_class i = 0; i < H; i++)
    {
        c *= a;
        c %= p;
    }
    auto table = new HashTable(converted_H);
    if (b < 0)
    {
        b = p + (b % p);
    }
    for (mpz_class i = 1; i <= H; i++)
    {
        d *= a;
        current_val = (b * d) % p;
        table->add_item(current_val, i);
    }
    current_val = c;
    for (mpz_class i = 1; i <= H; i++)
    {
        if (table->contains(current_val, temp))
        {
            delete table;
            return H * i - temp;
        }
        current_val = (current_val * c) % p;
    }
    delete table;
    return -1;
}

mpz_class binary_pow(mpz_class base, mpz_class exponent)
{
    mpz_class result = 1;
    while (exponent)
    {
        if ((exponent & 1) != 0)
            result *= base;
        base *= base;
        exponent >>= 1;
    }
    return result;
}

mpz_class bits_count(mpz_class val)
{
    mpz_class count = 0;
    while (val)
    {
        val >>= 1;
        count += 1;
    }
    return count;
}

mpz_class newton_sqrt(const mpz_class& val)
{
    bool decrease_flag = false;
    mpz_class x_0 = binary_pow(2, bits_count(val) >> 1);
    mpz_class x_i;
    while (true)
    {
        x_i = (x_0 + val / x_0) >> 1;
        if (x_0 == x_i || x_i > x_0 && decrease_flag)
            break;
        decrease_flag = (x_i < x_0);
        x_0 = x_i;
    }
    return x_0;
}

#endif
