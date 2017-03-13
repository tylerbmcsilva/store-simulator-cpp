/*
 Title: Produce Class
 Date: 03/12/17
 Descrition: Is a class utilized in the Store class. Stores the
 account id, their name, and whether they're a premium meber or not
*/

#include "Product.hpp"
#include <string>

using namespace std;

/*
 Contructor
 Takes the id, title, description, price, and quantity and sets the 
 private variables accordingly
*/

Product::Product(string id, string t, string d, double p, int qa){
    idCode = id;
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
}

/*
 getIdCode
 Returns the id of the product
 */

string Product::getIdCode(){
    return idCode;
}

/*
 getTitle
 Returns the Title of the Product
*/

string Product::getTitle(){
    return title;
}

/*
 getDescription
 Returns the description of the Product
*/

string Product::getDescription(){
    return description;
}

/*
 getPrice
 Returns the price of the Product
 */

double Product::getPrice(){
    return price;
}

/*
 getQuantityAvailable
 Returns the quantity available for the Product
*/

int Product::getQuantityAvailable(){
    return quantityAvailable;
}

/*
 decreaseQuantity
 Decrements the quantity available by one
*/

void Product::decreaseQuantity(){
    quantityAvailable--;
}
