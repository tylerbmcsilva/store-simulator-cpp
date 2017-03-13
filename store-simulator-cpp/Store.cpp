//
//  Store.cpp
//  store-simulator-cpp
//
//  Created by Tyler Silva on 3/12/17.
//  Copyright © 2017 Tyler McSilva. All rights reserved.
//

#include <string>
#include <iostream>
#include <iomanip>
#include "Store.hpp"
#include "Customer.hpp"
#include "Product.hpp"

using namespace std;

void Store::addProduct(Product * p){
    inventory.push_back(p);
}

void Store::addMember(Customer * c){
    members.push_back(c);
}

Product* Store::getProductFromID(string id){
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i]->getIdCode().compare(id) >= 0){
            return inventory[i];
        }
    }
    return NULL;
}

Customer* Store::getMemberFromID(string id){
    for(int i = 0; i < members.size(); i++){
        if(members[i]->getAccountID().compare(id) >= 0){
            return members[i];
        }
    }
    return NULL;
}

void Store::productSearch(string str){
    cout << fixed;
    cout << setprecision(2);
    for(int i = 0; i < inventory.size(); ++i){
        if( (inventory[i]->getTitle()).find(str) != string::npos ||
            (inventory[i]->getDescription()).find(str) != string::npos ){
            cout << " Item: " << inventory[i]->getTitle() << endl;
            cout << "   ID: " << inventory[i]->getIdCode() << endl;
            cout << "Price: $" << inventory[i]->getPrice() << endl;
            cout << " Desc: " << inventory[i]->getDescription() << endl << endl;
        }
    }
}

void Store::addProductToMemberCart(string pID, string mID){
    Customer * c = getMemberFromID(mID);
    Product * p = getProductFromID(pID);
    if( c == NULL ) {
        cout << "Member #" << pID << " not found." << endl;
    } else if ( p == NULL ) {
        cout << "Product #" << pID << " not found." << endl;
    } else {
        if( p->getQuantityAvailable() > 0 ){
            c->addProductToCart(p->getIdCode());
        } else {
            cout << "Sorry, product #" << pID << " is currently out of stock." << endl;
        }
    }
}

void Store::checkOutMember(string mID){
    double total = 0.0;
    double shipping = 0.0;
    cout << fixed;
    cout << setprecision(2);
    
    if(getMemberFromID(mID) == NULL){
        cout << "Member #" << mID << " not found." << endl;
    } else {
        vector<string> cart = getMemberFromID(mID)->getCart();
        if(cart.size() > 0){
            for(int i = 0; i < cart.size(); i++){
                if(getProductFromID(cart[i])->getQuantityAvailable() > 0){
                    cout << getProductFromID(cart[i])->getTitle() << " - $" << getProductFromID(cart[i])->getPrice() << endl;
                    total += getProductFromID(cart[i])->getPrice();
                    getProductFromID(cart[i])->decreaseQuantity();
                } else {
                    cout << "Sorry, product #" << getProductFromID(cart[i])->getIdCode() << " is no longer available" << endl;
                }
            }
            if(getMemberFromID(mID)->isPremiumMember()){
                shipping = 0.0;
            } else {
                shipping = total * 0.07;
            }
            cout << "Subtotal: $" << total << endl;
            cout << "Shipping: $" << shipping << endl;
            cout << "Total:    $" << (total + shipping) << endl << endl;
            getMemberFromID(mID)->emptyCart();
        } else {
            cout << "There are no items in the cart!" << endl;
        }
    }
}







