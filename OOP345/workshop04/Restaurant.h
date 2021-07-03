#pragma once
#include "Reservation.h"
namespace sdds {
	class Restaurant {
		Reservation* m_resPtr;
		size_t m_size;		
	public:
		Restaurant();
		~Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& res);
		Restaurant(Restaurant&& res) noexcept;
		Restaurant& operator = (const Restaurant& res);
		Restaurant& operator = (Restaurant&& res) noexcept;
		size_t size() const;
		void display(std::ostream& os)  const;
		friend std::ostream& operator << (std::ostream& os, const Restaurant& res);
	};
}