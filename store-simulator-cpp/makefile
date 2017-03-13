all: store

store: storeMain.cpp Store.o Customer.o Product.o
	g++ -g storeMain.cpp Store.o Customer.o Product.o -o store

Store.o: Store.cpp Store.hpp Customer.hpp Product.hpp
	g++ -c Store.cpp

Customer.o: Customer.cpp Customer.hpp Product.hpp
	g++ -c Customer.cpp

Product.o: Product.cpp Product.hpp
	g++ -c Product.cpp

clean:
	rm -f *.o
