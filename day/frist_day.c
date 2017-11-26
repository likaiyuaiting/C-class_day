#include<iostream>
using namespace std;
class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	Date& operator=(const Date& d)
	{
		Date temp(*this);
		temp._day = d._day;
		temp._month = d._month;
		temp._year = d._year;
		return temp;
	}


	// 计算当前日期day天之后日期
	/*
	
	
	Date& operator+(int day)
	{
		Date temp(*this);
		if (day == 0||day<0)
			return *this;
		temp._day += day;
		if (temp._day > 31)
		{
			temp._month = temp._month + temp._day / 31;
			temp._day =temp._day+ temp._day%31;
			if (temp._day > 31)
			{
				temp._month++;
				temp._day = temp._day - 31;
			}
		}
		if (temp._month > 12)
		{
			temp._year =temp._year + temp._month /12;
			temp._month =temp._month + temp._month%12;
			if (temp._month > 12)
			{
				temp._year++;
				temp._month = temp._month - 12;
			}
		}
		return temp;
	}
*/
	// 计算当前日期day天之前日期
	Date& operator+(int day)
	{
		Date temp(*this);
		if (day == 0 || day>0)
			return *this;
		while (day++)
		{
			if (temp._day > 0)
			{
				temp._day --;
			}
			else if (temp._day == 0 && temp._month > 0)
			{
				temp._day = 31;
				temp._month--;
			}
			else (temp._day == 0 && temp._month == 0 && temp._year > 0)
			{
				temp._year--;
				temp._month = 12;
				temp._day = 31;
			}
		}
		return temp;
	}

	// 计算两个日期之间差距
	Date& operator-(const Date& d)
	{
		Date temp(*this);
		if (this->_year > d._year)
		{
			if (this->_month > d._month)
			{
				if (this->_day > d._day)
				{
					temp._day = this->_day - d._day;
					temp._month = this->_month -d._month ;
					temp._year = this->_year - d._year;
				}
				else
				{
					temp._day = this->_day + 31 - d._day;
					temp._month = this->_month -1-d._month ;
					temp._year = this->_year - d._year;
				}
			}
			else
			{
				if (this->_day > d._day)
				{
					temp._day = this->_day - d._day;
					temp._month = this->_month+12 - d._month;
					temp._year = this->_year-1 - d._year;
				}
				else
				{
					temp._day = this->_day + 31 - d._day;
					temp._month = this->_month + 12 - 1 - d._month;
					temp._year = this->_year - 1 - d._year;
				}
			}
		}
		else
		{
			if (d._month > this->_day)// d._month
			{
				if (d._month > this->_day)
				{
					temp._day = d._month - this->_day;
					temp._month = d._month - this->_day;
					temp._year = d._month - this->_day;
				}
				else
				{
					temp._day = d._month + 31 - d._day;
					temp._month = d._month - 1 - d._month;
					temp._year = d._month - d._year;
				}
			}
			else
			{
				if (d._day > this->_day)
				{
					temp._day = d._month - this->_day;
					temp._month = d._month + 12 - this->_day;
					temp._year = d._month - 1 - this->_day;
				}
				else
				{
					temp._day = d._month + 31 - this->_day;
					temp._month = d._month + 12 - 1 - this->_day;
					temp._year = d._month - 1 - this->_day;
				}
			}
		}
		return temp;
	}


	//前置++
	Date& operator++()
	{
		this->_day += 1;
		if (this->_day > 31)
		{
			this->_day = 1;
			this->_month += 1;
		}
		if (this->_month > 12)
		{
			this->_month = 1;
			this->_year += 1;
		}
		return *this;
	}
		// 后置++
	Date operator++(int d)
	{
		Date temp(*this);
		this->_day += 1;
		if (this->_day > 31)
		{
			this->_day = 1;
			this->_month += 1;
		}
		if (this->_month > 12)
		{
			this->_month = 1;
			this->_year += 1;
		}
		return temp;
	}

	Date& operator--()
	{
		
		if (this->_day > 1)
		{
			this->_day -= 1;
		}
		if (this->_day==1 && this->_month > 1)
		{
			this->_day = 31;
			this->_month -= 1;
		}
		if (this->_day == 1 && this->_month == 1)
		{
			this->_day = 31;
			this->_month = 12;
			this->_year -= 1;
		}
		return *this;
	}
	Date operator--(int)
	{
		Date temp(*this);
		if (this->_day > 1)
		{
			this->_day -= 1;
		}
		if (this->_day == 1 && this->_month > 1)
		{
			this->_day = 31;
			this->_month -= 1;
		}
		if (this->_day == 1 && this->_month == 1)
		{
			this->_day = 31;
			this->_month = 12;
			this->_year -= 1;
		}
		return temp;
	}

		// 一般情况下不会重载成类的成员函数，因为不符合输出习惯
		// void operator<<(ostream& _cout)
		// {
		// _cout<<_year<<"-"<<_month<<"-"<<_day;
		// }

		//bool operator>(const Date& d);
	//bool operator<(const Date& d);
	bool operator==(const Date& d)
	{
		return this-d;
	}
	bool operator!=(const Date& d)
	{
		return !(this - d);
	}
	// 重载输出运算符

};
int main(void)
{
	Date d1(2017, 2, 12);
	Date d2(2015, 1, 11);
	Date d3 = d1 - d2;
	return 0;
}
