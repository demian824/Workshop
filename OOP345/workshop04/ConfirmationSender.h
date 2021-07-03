
#pragma once
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** m_res;
		size_t m_capacity;
		size_t m_size;
	public:
		~ConfirmationSender();
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& cf);
		ConfirmationSender(ConfirmationSender&& cf) noexcept;
		ConfirmationSender& operator = (const ConfirmationSender& cf);
		ConfirmationSender& operator = (ConfirmationSender&& cf) noexcept;
		bool searchData(const Reservation& res) const ;		
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& cf);
	};
}