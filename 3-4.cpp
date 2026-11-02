#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>

long long date_to_days(int y, int m, int d) {
    int lengths[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int mo = 0;
    for (int i = 1; i <= m; i++) {
        mo += lengths[i];
    }
    return 365LL * y + y / 4 - y / 100 + y / 400 + mo + d;
}

long long days_between(int y1, int m1, int d1, int y2, int m2, int d2) {
    return std::abs(date_to_days(y2, m2, d2) - date_to_days(y1, m1, d1));
}

std::string get_day_of_week(int y, int m, int d) {
    std::string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    long long days_from_epoch = date_to_days(y, m, d) - date_to_days(1970, 1, 1);
    int day_index = (days_from_epoch + 4) % 7;
    if (day_index < 0) day_index += 7;
    return days[day_index];
}

void printCalendar(int year, int month) {
    if (month < 1 || month > 12 || year < 1) {
        std::cout << "invalid month or year\n";
        return;
    }

    std::tm time_in = {};
    time_in.tm_year = year - 1900;
    time_in.tm_mon = month - 1;
    time_in.tm_mday = 1;
    std::mktime(&time_in);

    int startday = time_in.tm_wday;
    int daysInMonth;

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        daysInMonth = isLeap ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }
    else {
        daysInMonth = 31;
    }

    const std::string month_names[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    std::cout << "\n--- " << month_names[month] << " " << year << " ---\n";
    std::cout << "Su Mo Tu We Th Fr Sa\n";

    for (int i = 0; i < startday; i++) {
        std::cout << "   ";
    }

    for (int day = 1; day <= daysInMonth; day++) {
        std::cout << std::setw(2) << day << " ";
        startday++;
        if (startday % 7 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n\n";
}




int main() {
    // Test Days Between
    std::cout << "Days between 2023-01-01 and 2026-10-30: (answer: 1398)"
        << days_between(2023, 1, 1, 2026, 10, 30) << " days\n";

    // Test Day of the Week
    std::cout << "Day of the week on Oct 30, 2026: (answer: friday) "
        << get_day_of_week(2026, 10, 30) << "\n";

    // Test Print Calendar
    printCalendar(2026, 10);

    return 0;
}
