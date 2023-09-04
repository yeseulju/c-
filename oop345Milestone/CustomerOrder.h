#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <string>
#include <iostream>
#include "Station.h"
namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };
		Item(const std::string& name) : m_itemName(name) {};
	};
	class CustomerOrder
	{
	private:
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};
		static size_t m_widthField;
	public:
		CustomerOrder() = default;
		CustomerOrder(const std::string& order);
		CustomerOrder(const CustomerOrder& rightOperand);
		CustomerOrder& operator=(const CustomerOrder& rightOperand) = delete;
		CustomerOrder(CustomerOrder&& rightOperand) noexcept;
		CustomerOrder& operator=(CustomerOrder&& rightOperand) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif