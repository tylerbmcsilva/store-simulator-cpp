//
//  Customer.cpp
//  store-simulator-cpp
//
//  Created by Tyler Silva on 3/12/17.
//  Copyright © 2017 Tyler McSilva. All rights reserved.
//
#include <string>
#include <vector>
#include "Customer.hpp"
#include "Product.hpp"

using namespace std;

Customer::Customer(string n, string a, bool pm){
    name = n;
    accountID = a;
    premiumMember = pm;
}

string Customer::getAccountID(){
    return accountID;
}

vector<string> Customer::getCart(){
    return cart;
}

void Customer::addProductToCart(string id){
    cart.push_back(id);
}

bool Customer::isPremiumMember(){
    return premiumMember;
}

void Customer::emptyCart(){
    cart.clear();
}
