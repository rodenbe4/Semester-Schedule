//Header file timeInterval.h: This is the INTERFACE for the class TimeInterval.
//startTime must be less than or equal to endTime

#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

#include "dtime.h"
#include <iostream>
using namespace std;


    class TimeInterval
{
    public:
        TimeInterval( );
        //Initializes the interval to [0:00, 0:00].

        TimeInterval(const DigitalTime& a, const DigitalTime& b);
        //Initializes the interval to [a, b], if a <= b. Otherwise intialize to [0:00, 0:00] 

        void setInterval(const DigitalTime& a, const DigitalTime& b);
        //Initializes the interval to [a, b], if a <= b. Otherwise leave host unchanged

        DigitalTime getStart() const;
        DigitalTime getEnd() const;

        void output(ostream& outs) const;
        //Outputs the interval in the form a - b. For example, 9:30 - 10:45
        //Precondition: If outs is a file output stream, then outs has already been 
        //connected to a file.
    private:
        DigitalTime startTime;
        DigitalTime endTime;
    };

    bool operator&&(const TimeInterval& a, const TimeInterval& b);
    //Returns true if a and b overlap, false otherwise

    ostream& operator<<(ostream& outs, const TimeInterval& d);
    //Use the output member funtion to implement stream insertion for TimeInterval

#endif //TIMEINTERVAL_H


              
