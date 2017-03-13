//
//  Product.cpp
//  store-simulator-cpp
//
//  Created by Tyler Silva on 3/12/17.
//  Copyright © 2017 Tyler McSilva. All rights reserved.
//

#include "Product.hpp"
#include <string>

using namespace std;

Product::Product(string id, string t, string d, double p, int qa){
    idCode = id;
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
}

string Product::getIdCode(){
    return idCode;
}

string Product::getTitle(){
    return title;
}

string Product::getDescription(){
    return description;
}

double Product::getPrice(){
    return price;
}

int Product::getQuantityAvailable(){
    return quantityAvailable;
}

void Product::decreaseQuantity(){
    quantityAvailable--;
}
