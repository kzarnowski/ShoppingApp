//
// Created by krzysztof on 28.12.2020.
//

#ifndef ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYCAPACITY_H
#define ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYCAPACITY_H

#include "Product.h"

class ProductByCapacity : public Product {
    // milliliters

public:
    explicit ProductByCapacity(const std::string & name, int capacity = 1000);
    ProductByCapacity();
    std::string quantityToString() const override;
};

#endif //ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYCAPACITY_H
