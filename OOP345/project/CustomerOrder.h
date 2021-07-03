
#pragma once


#include "Station.h"
#include "Utilities.h"

namespace sdds {
	
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name = {};
		std::string m_product = {};
		size_t m_cntItem = 0;
		Item** m_lstItem = nullptr;
		static size_t m_widthField;
	public:
		~CustomerOrder();
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& origin);
		CustomerOrder& operator=(const CustomerOrder& origin) = delete;
		CustomerOrder(CustomerOrder&& origin) noexcept;
		CustomerOrder& operator=(CustomerOrder&& origin) noexcept;
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
		int countItemNum(const std::string& str);
		bool isItemOnList(const std::string& str);
	};
}