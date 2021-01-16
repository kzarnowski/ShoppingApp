//
// Created by krzysztof on 28.12.2020.
//

#ifndef ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYWEIGHT_H
#define ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYWEIGHT_H

#include "Product.h"

class ProductByWeight : public Product {
    // grams

public:
    explicit ProductByWeight(const std::string & name, int weight = 1000);
    ProductByWeight();
    std::string quantityToString() const override;
};


#endif //ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYWEIGHT_H
