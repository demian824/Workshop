
#pragma once
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		Reservation** m_res;
		int m_size;
		int m_capacity;
	public:
		~ConfirmationSender();
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& cf);
		ConfirmationSender(ConfirmationSender&& cf) noexcept;
		bool resize(const int& size);
		bool searchData(const Reservation& res) const ;
		ConfirmationSender& operator = (const ConfirmationSender& cf);
		ConfirmationSender& operator = (ConfirmationSender&& cf) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& cf);
	};
}