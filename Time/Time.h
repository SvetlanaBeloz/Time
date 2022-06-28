#include <iostream>
#include <windows.h>
class Time
{
	int hour;
	int minutes;
	int seconds;

public:
	Time();
	Time(int hour, int minutes, int seconds);

	void SetHour(int hour);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);
	int GetHour() const;
	int GetMinutes() const;
	int GetSeconds() const;
	void Print();

	Time& operator ++();
	Time operator ++(int);
	Time& operator --();
	Time operator --(int);

	friend Time operator+(const Time& original, int sec);
	friend bool operator < (const Time& left, const Time& right);
	friend bool operator > (const Time& left, const Time& right);
	friend bool operator == (const Time& left, const Time& right);
	friend bool operator != (const Time& left, const Time& right);
	friend std::istream& operator >> (std::istream& is, Time& original);
	friend std::ostream& operator << (std::ostream& os, const Time& original);
};

