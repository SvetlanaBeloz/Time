#include "Time.h"

Time::Time()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	hour = st.wHour;
	minutes = st.wMinute;
	seconds = st.wSecond;
}

Time::Time(int hour, int minutes, int seconds)
{
	SetHour(hour);
	SetMinutes(minutes);
	SetSeconds(seconds);
}

void Time::SetHour(int hour)
{
	if (hour >= 0 && hour <= 23)
		this->hour = hour;
	else {
		std::cout << "Incorrect time\n";
		return;
	}
}

void Time::SetMinutes(int minutes)
{
	if (minutes >= 0 && minutes < 60)
		this->minutes = minutes;
	else {
		std::cout << "Incorrect time\n";
		return;
	}
}

void Time::SetSeconds(int seconds)
{
	if (seconds >= 0 && seconds < 60)
		this->seconds = seconds;
	else {
		std::cout << "Incorrect time\n";
		return;
	}
}

int Time::GetHour() const
{
	return hour;
}

int Time::GetMinutes() const
{
	return minutes;
}

int Time::GetSeconds() const
{
	return seconds;
}

void Time::Print()
{
	std::cout << "Time is: " << hour << " hours, " << minutes << " minutes, " << seconds << " seconds.\n";
}

Time operator + (const Time& original, int sec)
{
	int time = original.hour * 3600 + original.minutes * 60 + original.seconds + sec;
	int hour = time / 3600;
	if (hour >= 24)
		hour = hour - (24 * (hour / 24));
	time = time % 3600;
	int minutes = time / 60;
	time = time % 60;
	int seconds = time;
	Time  changed(hour, minutes, seconds);
	return changed;
}

bool operator < (const Time& left, const Time& right)
{
	if (left.hour < right.hour)
		return true;
	else if (left.hour == right.hour && left.minutes < right.minutes)
		return true;
	else if (left.hour == right.hour && left.minutes == right.minutes && left.seconds < right.seconds)
		return true;
	else return false;
}

bool operator > (const Time& left, const Time& right)
{
	if (left.hour > right.hour)
		return true;
	else if (left.hour == right.hour && left.minutes > right.minutes)
		return true;
	else if (left.hour == right.hour && left.minutes == right.minutes && left.seconds > right.seconds)
		return true;
	else return false;
}

bool operator == (const Time& left, const Time& right)
{
	return left.hour == right.hour && left.minutes == right.minutes && left.seconds == right.seconds;
}

bool operator != (const Time& left, const Time& right)
{
	return left.hour != right.hour || left.minutes != right.minutes || left.seconds != right.seconds;
}

std::istream& operator >> (std::istream& is, Time& original)
{
	std::cout << "Please enter hours: ";
	is >> original.hour;
	std::cout << "Please enter minutes: ";
	is >> original.minutes;
	std::cout << "Please enter seconds: ";
	is >> original.seconds;
	return is;
}

std::ostream& operator << (std::ostream& os, const Time& original)
{
	std::cout << original.hour << " " << original.minutes << " " << original.seconds << "\n";
	return os;
}


