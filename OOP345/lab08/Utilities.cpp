/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week8
*/

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/************************************
	* File Name:			Element.h
	* Included Header/Library
	*	memory
	*	List.h
	*	Element.h
	*	Utilities.h
	* namespace:			sdds
	* preprocessor:
		ifndef
		define
		endif
	************************************/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		Product* ptr = nullptr;
		for (size_t i = 0; i < desc.size(); i++) 
			for (size_t j = 0; j < price.size(); j++) 
				if (desc[i].code == price[j].code) {
					ptr = new Product(desc[i].desc, price[j].price);
					ptr->validate();
					priceList += ptr;
					delete ptr;
					ptr = nullptr;
				}			
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) 
			for (size_t j = 0; j < price.size(); j++) 
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[j].price));
					ptr->validate();
					priceList += ptr;
				}
		return priceList;
	}
}