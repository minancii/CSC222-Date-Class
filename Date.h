#ifndef DATE_H
#define DATE_H

#include <string>

/*
    Date represents one valid calendar date.

    Class invariant:
    - month is between 1 and 12.
    - year is 1 or greater.
    - day is between 1 and the last day of that month and year.

    Any invalid date supplied to the constructor or setDate()
    causes the object to store January 1, 1900.
*/
class Date
{
private:
    int month;
    int day;
    int year;

    // Checks whether all three values form a valid calendar date.
    bool isValidDate(int m, int d, int y) const;

public:
    // Purpose: Create a Date object.
    // Input: Month, day, and year (or default values).
    // Precondition: None; invalid dates are handled by the class.
    // Postcondition: A valid date is stored, or the default date is used.
    // Output: Initialized Date object.
    Date(int m = 1, int d = 1, int y = 1900);

    // Purpose: Change the complete date.
    // Input: New month, day, and year.
    // Precondition: None.
    // Postcondition: Stores the supplied valid date, or January 1, 1900.
    // Output: None.
    void setDate(int m, int d, int y);

    // Purpose: Read one part of the current date.
    // Input: None.
    // Precondition: Object has a valid date.
    // Postcondition: Object is unchanged.
    // Output: Current month, day, or year.
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Purpose: Check if a year is a leap year.
    // Input: Either the object's year or a supplied year.
    // Precondition: None; years below 1 return false.
    // Postcondition: Object is unchanged.
    // Output: true if leap year, otherwise false.
    bool isLeapYear() const;
    bool isLeapYear(int y) const;

    // Purpose: Find the last valid day of a month.
    // Input: Either the object's month/year or supplied month/year.
    // Precondition: None; invalid month/year returns 0.
    // Postcondition: Object is unchanged.
    // Output: 28, 29, 30, 31, or 0 for invalid input.
    int lastDay() const;
    int lastDay(int m, int y) const;

    // Purpose: Return the date as month/day/year.
    // Input: None. Precondition: Object is valid.
    // Postcondition: Object is unchanged.
    // Output: String like 12/25/2021.
    std::string formatNumeric() const;

    // Purpose: Return the date with the month name first.
    // Input: None. Precondition: Object is valid.
    // Postcondition: Object is unchanged.
    // Output: String like December 25, 2021.
    std::string formatMonthFirst() const;

    // Purpose: Return the date with the day first.
    // Input: None. Precondition: Object is valid.
    // Postcondition: Object is unchanged.
    // Output: String like 25 December 2021.
    std::string formatDayFirst() const;
};

#endif
