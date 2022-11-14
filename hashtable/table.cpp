#include "table.h"
#include <gmpxx.h>
#include <string>

struct HashTable::data
{
    mpz_class expression, exponent;
    data(mpz_class expr, mpz_class exp)
    {
        expression = expr;
        exponent = exp;
    }
};

HashTable::HashTable(size_t size)
{
    using std::vector, std::list;
    this->size = size;
    try
    {
        this->items = new vector<list<data*>>(this->size);
    }
    catch (std::bad_alloc& err)
    {
        throw err;
    }
}

HashTable::~HashTable()
{
    for (auto& item: *(this->items))
        for (auto& node: item)
            delete node;
    delete this->items;
}

void HashTable::add_item(mpz_class value, mpz_class exponent)
{
    size_t hash = hashify(value);
    auto new_node = new data(value, exponent);
    this->items->at(hash).push_back(new_node);
}

bool HashTable::contains(mpz_class value, mpz_class &result)
{
    size_t hash = hashify(value);
    if (!this->items->at(hash).empty())
    {
        for (auto& i: this->items->at(hash))
        {
            if (i->expression == value)
            {
                result = i->exponent;
                return true;
            }
        }
    }
    return false;
}

size_t HashTable::hashify(mpz_class& value)
{
    size_t hash = this->hasher(value.get_str()) % this->size;
    return hash;
}

