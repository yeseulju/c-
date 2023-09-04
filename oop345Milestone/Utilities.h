
/*
OOP345 SUMMER2023
student name : yeseul ju
student id : yju9@myseneca.ca
student number : 154673198
course : NRA
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{

	class Utilities
	{
	private:
		size_t m_widthField{ 1 };
	public:
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	};
}
#endif