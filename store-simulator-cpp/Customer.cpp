/*
 Title: Customer Class
 Date: 03/12/17
 Descrition: Is a class utilized in the Store class. Stores the 
 account id, their name, and whether they're a premium meber or not
*/
#include <string>
#include <vector>
#include "Customer.hpp"
#include "Product.hpp"

using namespace std;

/*
 Contructor
 Takes the name, account ID, and status of premium member and sets
 the private variables accordingly
*/

Customer::Customer(string n, string a, bool pm){
    name = n;
    accountID = a;
    premiumMember = pm;
}

/*
 getAccountID
 Returns Account ID of Customer
*/

string Customer::getAccountID(){
    return accountID;
}

/*
 getCart
 Returns vecor of product ids in the customer's cart
*/

vector<string> Customer::getCart(){
    return cart;
}

/*
 addProductToCart
 Pushes the id of a product to the vector 'cart'
*/

void Customer::addProductToCart(string id){
    cart.push_back(id);
}

/*
 isPremiumMember
 Returns if the customer is a premium member or not
*/

bool Customer::isPremiumMember(){
    return premiumMember;
}

/*
 emptyCart
 Clears the cart of all contents
*/

void Customer::emptyCart(){
    cart.clear();
}
