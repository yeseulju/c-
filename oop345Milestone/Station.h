
/*
OOP345 SUMMER2023
student name : yeseul ju
student id : yju9@myseneca.ca
student number : 154673198
course : NRA
*/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{
	class Station
	{
	private:
		int m_id{};
		std::string m_itemName{};
		std::string m_description{};
		size_t m_nextSerial{};
		size_t m_itemsNum{};

	public:
		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif