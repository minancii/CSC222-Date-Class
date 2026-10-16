#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

// Prints the expected and actual results for each test.
void checkTest(const string& name, const string& expected,
               const string& actual, int& passed, int& total)
{
    total++;
    bool success = (expected == actual);
    if (success)
        passed++;

    cout << "Test " << total << ": " << name << endl;
    cout << "  Expected: " << expected << endl;
    cout << "  Actual:   " << actual << endl;
    cout << "  Result:   " << (success ? "PASS" : "FAIL") << "\n\n";
}

string boolText(bool value)
{
    return value ? "true" : "false";
}

int main()
{
    int passed = 0;
    int total = 0;

    Date defaultDate;
    checkTest("Default constructor", "1/1/1900", defaultDate.formatNumeric(), passed, total);

    Date christmas(12, 25, 2021);
    checkTest("Normal valid date", "12/25/2021", christmas.formatNumeric(), passed, total);
    checkTest("Numeric formatting", "12/25/2021", christmas.formatNumeric(), passed, total);
    checkTest("Month-first formatting", "December 25, 2021", christmas.formatMonthFirst(), passed, total);
    checkTest("Day-first formatting", "25 December 2021", christmas.formatDayFirst(), passed, total);

    checkTest("getMonth", "12", to_string(christmas.getMonth()), passed, total);
    checkTest("getDay", "25", to_string(christmas.getDay()), passed, total);
    checkTest("getYear", "2021", to_string(christmas.getYear()), passed, total);

    Date leapDay(2, 29, 2024);
    checkTest("February 29 in a leap year", "2/29/2024", leapDay.formatNumeric(), passed, total);
    checkTest("isLeapYear() current year", "true", boolText(leapDay.isLeapYear()), passed, total);
    checkTest("lastDay() current February", "29", to_string(leapDay.lastDay()), passed, total);

    checkTest("isLeapYear(2000)", "true", boolText(christmas.isLeapYear(2000)), passed, total);
    checkTest("isLeapYear(1900)", "false", boolText(christmas.isLeapYear(1900)), passed, total);
    checkTest("isLeapYear(2023)", "false", boolText(christmas.isLeapYear(2023)), passed, total);
    checkTest("lastDay(2, 2023)", "28", to_string(christmas.lastDay(2, 2023)), passed, total);
    checkTest("lastDay(4, 2026)", "30", to_string(christmas.lastDay(4, 2026)), passed, total);
    checkTest("lastDay(13, 2026) invalid month", "0", to_string(christmas.lastDay(13, 2026)), passed, total);

    Date badFeb(2, 29, 2023);
    checkTest("Invalid February 29", "1/1/1900", badFeb.formatNumeric(), passed, total);

    Date badApril(4, 31, 2026);
    checkTest("Invalid April 31", "1/1/1900", badApril.formatNumeric(), passed, total);

    Date badMonth(13, 10, 2026);
    checkTest("Invalid month 13", "1/1/1900", badMonth.formatNumeric(), passed, total);

    Date badYear(1, 1, 0);
    checkTest("Invalid year 0", "1/1/1900", badYear.formatNumeric(), passed, total);

    Date changed(1, 1, 2026);
    changed.setDate(12, 31, 2026);
    checkTest("setDate with valid values", "12/31/2026", changed.formatNumeric(), passed, total);

    // Good place for a breakpoint: inspect the validation of April 31.
    changed.setDate(4, 31, 2026);
    checkTest("setDate with invalid values", "1/1/1900", changed.formatNumeric(), passed, total);

    cout << "------------------------------\n";
    cout << "Tests passed: " << passed << " / " << total << endl;
    return (passed == total) ? 0 : 1;
}
