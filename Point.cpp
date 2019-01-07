//
// Created by roy on 07/01/19.
//

#include "Point.h"

void Point::setRight(int right) {
    this->right = right;
}

void Point::setLeft(int left) {
    this->left = left;
}

int Point::getLeft() const {
    return left;
}

int Point::getRight() const {
    return right;
}

const bool Point::operator==(const Point &second) {
    if (this->left == second.getLeft() && this->right == second.getRight()){
        return true;
    }
    return false;
}
