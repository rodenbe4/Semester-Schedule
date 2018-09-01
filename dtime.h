//Header file dtime.h: This is the INTERFACE for the class DigitalTime.
//Values of this type are times of day. The values are input and output in
//24 hour notation as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.

#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using namespace std;


    class DigitalTime
{
    public:
        bool isEqual(const DigitalTime& time1) const;
        //Returns true if time1 and host represent the same time; 
        //otherwise, returns false.

        bool isLess(const DigitalTime& time1) const;
        //Returns true if host is strictly less than time1; 
        //otherwise, returns false.

        DigitalTime(int the_hour, int the_minute);
        //Precondition: 0 <= the_hour <= 23 and 0 <= the_minute <= 59.
        //Initializes the time value to the_hour and the_minute.

        DigitalTime( );
        //Initializes the time value to 0:00 (which is midnight).

        bool input(istream& ins);
        //Reads a white-space delimited token from ins. If the token is of the form
        //hh:mm where hh is an integer from 0 to 23 (inclusive) and mm is an integer
        //from 0 to 59 (inclusive), host is set to these values and the function returns true.
        //Otherwise host is left unchanged and the function returns false.
        //Precondition: If ins is a file input stream, then ins has already been 
        //connected to a file. 

        void output(ostream& outs) const;
        //Outputs digital time in the form hour:minute
        //Precondition: If outs is a file output stream, then outs has already been 
        //connected to a file.

	int getHour() const;
	int getMinute() const;
	void set(int hour, int minute); 
	//If <hour>:<minute> is valid, the digitalTime is set to that value. If either hour
	//or minute is not valid, the host object is unchanged.

    private:
        int hour;
        int minute;
    };

    bool operator<(const DigitalTime& a, const DigitalTime& b);
    bool operator>(const DigitalTime& a, const DigitalTime& b);
    bool operator<=(const DigitalTime& a, const DigitalTime& b);
    bool operator>=(const DigitalTime& a, const DigitalTime& b);
    bool operator==(const DigitalTime& a, const DigitalTime& b);
    bool operator!=(const DigitalTime& a, const DigitalTime& b);
    //Use the member functions isEqual and isLess to implement each of the operators above.

    istream& operator>>(istream& ins, DigitalTime& d);
    //Use the input member funtion to implement stream extraction for DigitalTime
    ostream& operator<<(ostream& outs, const DigitalTime& d);
    //Use the output member funtion to implement stream insertion for DigitalTime


#endif //DTIME_H


              
