//
// Created by krzysztof on 28.12.2020.
//

#ifndef ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYPIECES_H
#define ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYPIECES_H

#include "Product.h"

class ProductByPieces : public Product {
    // pieces

public:
    explicit ProductByPieces(const std::string & name, int pieces = 1);
    ProductByPieces();
    std::string quantityToString() const override;
};


#endif //ZARNOWSKIKRZYSZTOF_ETAP1_PRODUCTBYPIECES_H
