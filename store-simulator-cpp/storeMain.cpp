/*
 Title: Main
 Date: 03/12/17
 Descrition: Main file used for testing
 */

#include <iostream>
#include "Store.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Store store;
    
    Customer *mem1 = new Customer("Tyler", "123", true);
    Customer *mem2 = new Customer("Jesse", "456", false);
    Customer *mem3 = new Customer("Luna", "789", true);
    store.addMember(mem1);
    store.addMember(mem2);
    store.addMember(mem3);

    Product *p1 = new Product("111","Hat","A red, yellow or blue hat",20.99,2);
    Product *p2 = new Product("222", "Glasses", "A red, yellow or blue pair of glasses", 39.99, 1);
    Product *p3 = new Product("333", "Beer", "A Green beer", 2.00, 6);
    store.addProduct(p1);
    store.addProduct(p2);
    store.addProduct(p3);
    
    store.productSearch("red");
    store.productSearch("Green");
    store.productSearch("hazel");
    
    store.addProductToMemberCart(p1->getIdCode(), mem1->getAccountID());
    store.addProductToMemberCart(p1->getIdCode(), mem1->getAccountID());
    
    store.addProductToMemberCart(p2->getIdCode(), mem2->getAccountID());
    store.addProductToMemberCart(p1->getIdCode(), mem2->getAccountID());
    
    store.addProductToMemberCart(p3->getIdCode(), mem3->getAccountID());
    store.addProductToMemberCart(p3->getIdCode(), mem3->getAccountID());
    store.addProductToMemberCart(p3->getIdCode(), mem3->getAccountID());
    store.addProductToMemberCart(p3->getIdCode(), mem3->getAccountID());
    store.addProductToMemberCart(p3->getIdCode(), mem3->getAccountID());
    store.addProductToMemberCart(p3->getIdCode(), mem3->getAccountID());
    
    
    store.checkOutMember(mem1->getAccountID());
    store.checkOutMember(mem2->getAccountID());
    store.checkOutMember(mem3->getAccountID());
    
    return 0;
}
