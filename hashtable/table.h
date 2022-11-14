#ifndef HASHTABLE_TABLE_H
#define HASHTABLE_TABLE_H

#include <cstddef>
#include <gmpxx.h>
#include <vector>
#include <list>
#include "../tools/conversions.h"

class HashTable
{
    public:
    size_t size;
    explicit HashTable(size_t size);
    ~HashTable();
    void add_item(mpz_class value, mpz_class exponent);
    bool contains(mpz_class value, mpz_class& result);

    private:
    struct data;
    std::hash<std::string> hasher;
    size_t hashify(mpz_class&);
    std::vector<std::list<data*>> *items;

};

#endif
