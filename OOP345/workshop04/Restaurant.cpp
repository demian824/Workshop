#include <iostream>
#include"Restaurant.h"
namespace sdds {
	typedef Restaurant RS;
	using namespace std;

	RS::Restaurant() : m_resPtr(nullptr), m_size(0){}
	RS::Restaurant(const Reservation* reservations[], size_t cnt) {
		m_size = cnt;
		m_resPtr = new Reservation[m_size];

		if (!m_resPtr) cout << "Failed to memory allocation" << endl;
		else {
			for (size_t i = 0ull; i < cnt; i++) {
				m_resPtr[i] = *reservations[i];
			}
		}
		
	}
	RS::Restaurant(const Restaurant& res) {  *this = res; }
	RS::Restaurant(Restaurant&& res) noexcept {	*this = std::move(res);	}
	Restaurant& RS::operator=(const Restaurant& res) {
		if (this != &res) {
			m_size = res.m_size;
			if (res.m_resPtr != nullptr) {
				delete[] m_resPtr;
				m_resPtr = new Reservation[m_size];
				for (size_t i = 0ull; i < m_size; i++)
					m_resPtr[i] = res.m_resPtr[i];
			}
		}
		return *this;
	}
	Restaurant& RS::operator = (Restaurant&& res) noexcept {
		if (this != &res) {
			m_size = res.m_size;
			res.m_size = 0ull;
			delete[] m_resPtr;
			m_resPtr = res.m_resPtr;
			res.m_resPtr = nullptr;
			
		}
		return *this;
	}
	size_t RS::size() const {	return m_size;	}

	void RS::display(ostream& os) const {
		for (size_t i = 0; i < m_size; i++)
			os << m_resPtr[i];
	}

	ostream& operator << (ostream& os, const Restaurant& res) {
		static int num = 1;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << num++ << ")" << endl;
		os << "--------------------------" << endl;
		if (res.m_resPtr != nullptr)	res.display(os);
		else os << "This restaurant is empty!" << endl << "--------------------------" << endl;
		return os;
	}
	RS::~Restaurant() {
		delete[] m_resPtr;
	}
}