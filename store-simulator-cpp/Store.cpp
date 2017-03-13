/*
 Title: Store Class
 Date: 03/12/17
 Descrition: Works off of the Customer and Product classes. Has a 
 running inventory and list of members. Has ability to search for
 products, add a product to a customer's cart, and also checkout
 a customer
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <locale>
#include "Store.hpp"
#include "Customer.hpp"
#include "Product.hpp"

using namespace std;

/*
 addProduct
 Takes a pointer to a product and adds it the inventory vector
*/

void Store::addProduct(Product * p){
    inventory.push_back(p);
}

/*
 addMember
 Takes a pointer to a customer and addits it to the members vector
*/

void Store::addMember(Customer * c){
    members.push_back(c);
}

/*
 getProductFromID
 Takes an ID of a product and checks if the ID is in the inventory 
 vector, returns it if found, returns NULL if not found.
*/

Product* Store::getProductFromID(string id){
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i]->getIdCode().compare(id) >= 0){
            return inventory[i];
        }
    }
    return NULL;
}

/*
 getMemberFromID
 Takes an ID of a customer and checks if the ID is in the members
 vector, returns it if found, returns NULL if not found.
*/

Customer* Store::getMemberFromID(string id){
    for(int i = 0; i < members.size(); i++){
        if(members[i]->getAccountID().compare(id) >= 0){
            return members[i];
        }
    }
    return NULL;
}

/*
 productSearch
 Takes a string, then searches all of the the products, scanning both
 the title and description. If found, it prints the Title, ID, Price
 and Description to the console.
*/

void Store::productSearch(string str){
    // Force doubles to print 2 decimal places
    cout << fixed;
    cout << setprecision(2);
    
    // make sure the first character is lowercase
    locale loc;
    str[0] = tolower(str[0],loc);
    
    // Loop through all items in the inventory
    for(int i = 0; i < inventory.size(); i++){
        // Initialize temp variables
        string tempTitle = inventory[i]->getTitle();
        string tempDesc = inventory[i]->getDescription();
        
        // Loop through and make all charachers lowercase;
        for(int x = 0; x < tempTitle.length(); x++) {
            tempTitle[x] = tolower(tempTitle[x],loc);
        }
        for(int y = 0; y < tempTitle.length(); y++) {
            tempDesc[y] = tolower(tempDesc[y],loc);
        }
        
        // Checks if the search term is in the temp variables,
        // then prints it to the console if found.
        if( (tempTitle).find(str) != string::npos ||
            (tempDesc).find(str) != string::npos ){
            cout << " Item: " << inventory[i]->getTitle() << endl;
            cout << "   ID: " << inventory[i]->getIdCode() << endl;
            cout << "Price: $" << inventory[i]->getPrice() << endl;
            cout << " Desc: " << inventory[i]->getDescription() << endl << endl;
        }
    }
}

/*
 addProductToMemberCart
 First attemps to find the member and product, if either aren't found,
 it prints to the console that it isn't found and the function ends.
 If both are found, then it will then check the quantity available of
 the product. Will then add to the customers cart.
*/

void Store::addProductToMemberCart(string pID, string mID){
    // Gets the customer and product
    Customer * c = getMemberFromID(mID);
    Product * p = getProductFromID(pID);
    
    //Checks for null
    if( c == NULL ) {
        cout << "Member #" << pID << " not found." << endl;
    } else if ( p == NULL ) {
        cout << "Product #" << pID << " not found." << endl;
    } else {
        // As long at the quantity is over 0
        if( p->getQuantityAvailable() > 0 ){
            // Add to cart
            c->addProductToCart(p->getIdCode());
        } else {
            cout << "Sorry, product #" << pID << " is currently out of stock." << endl;
        }
    }
}

/*
 checkOutMember
 Loops through all of the items in the customers cart, decrements the
 quantity of the product and calculates the subtotal, tax, and total
 of the cart. Then clears the customers cart.
*/

void Store::checkOutMember(string mID){
    // Initialize Variables
    double total = 0.0;
    double shipping = 0.0;
    // Force doubles to print 2 decimals
    cout << fixed;
    cout << setprecision(2);
    
    // checks for Null
    if(getMemberFromID(mID) == NULL){
        cout << "Member #" << mID << " not found." << endl;
    } else {
        // Get the cart
        vector<string> cart = getMemberFromID(mID)->getCart();
        if(cart.size() > 0){
            // Loop through all items in the cart
            for(int i = 0; i < cart.size(); i++){
                
                // If there is a quantity available
                if(getProductFromID(cart[i])->getQuantityAvailable() > 0){
                    // Print to console
                    cout << getProductFromID(cart[i])->getTitle() << " - $" << getProductFromID(cart[i])->getPrice() << endl;
                    // Add to total
                    total += getProductFromID(cart[i])->getPrice();
                    // Decrement quantity
                    getProductFromID(cart[i])->decreaseQuantity();
                } else {
                    // Print that the product is not available
                    cout << "Sorry, product #" << getProductFromID(cart[i])->getIdCode() << " is no longer available" << endl;
                }
            }
            
            if(getMemberFromID(mID)->isPremiumMember()){
                // 0.00 shipping if a premium member
                shipping = 0.0;
            } else {
                // 7% shipping if non-premium member
                shipping = total * 0.07;
            }
            // Print subtotal, shipping, and total
            cout << "Subtotal: $" << total << endl;
            cout << "Shipping: $" << shipping << endl;
            cout << "Total:    $" << (total + shipping) << endl << endl;
            
            // Empty Customer's cart
            getMemberFromID(mID)->emptyCart();
        } else {
            cout << "There are no items in the cart!" << endl;
        }
    }
}







