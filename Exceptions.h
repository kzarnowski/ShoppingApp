//
// Created by krzysztof on 16.01.2021.
//

#ifndef ZARNOWSKIKRZYSZTOF_ETAP3_EXCEPTIONS_H
#define ZARNOWSKIKRZYSZTOF_ETAP3_EXCEPTIONS_H

#include <iostream>
#include <utility>
#include <exception>

class WrongArgumentError : public std::out_of_range {
public:
    explicit WrongArgumentError(const std::string&  message = "Wrong argument.") : std::out_of_range(message) {}
};

class ListOutOfRange : public WrongArgumentError {
public:
    explicit ListOutOfRange(const std::string& message =
            "List at this index does not exist.") : WrongArgumentError(message) {};
};

class ProductOutOfRange : public WrongArgumentError {
public:
    explicit ProductOutOfRange(const std::string& message =
            "Product at this index does not exist.") : WrongArgumentError(message) {};
};

class ActionOutOfRange : public WrongArgumentError {
public:
    explicit ActionOutOfRange(const std::string& message =
            "This option is not available.") : WrongArgumentError(message) {};
};

class ShoppingListOverflow : public std::length_error {
public:
    explicit ShoppingListOverflow(const std::string & message = "List is full.") : std::length_error(message) {};
};

class ObjectNotFound : public std::logic_error {
public:
    explicit ObjectNotFound(const std::string & message =
            "Object not found or too few objects to perform this operation.") : std::logic_error(message) {};
};
#endif //ZARNOWSKIKRZYSZTOF_ETAP3_EXCEPTIONS_H
