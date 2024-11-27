#include <iostream>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getStartDayOfYear(int year) {
    int q = 1; 
    int m = 1; 
    if (m < 3) {
        m += 12; 
        year--;
    }
    int K = year % 100; 
    int J = year / 100; 
    int h = (q + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    return (h + 5) % 7; 
}

void printGregorianCalendar(int year) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    cout << "Календарь " << year << " года" << endl;
    cout << "-------------------------------------" << endl;

    const char* monthNames[] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    int startDay = getStartDayOfYear(year);

    for (int month = 0; month < 12; ++month) {
        cout << setw(20) << monthNames[month] << endl;
        cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;

        for (int i = 0; i < startDay; ++i) {
            cout << "   ";
        }

        for (int day = 1; day <= daysInMonth[month]; ++day) {
            cout << setw(2) << day << " ";
            startDay++;

            if (startDay % 7 == 0) {
                cout << endl;
            }
        }

        cout << endl << endl;

        startDay %= 7;
    }
}

int main() {
    int year;

    cout << "Введите год: ";
    cin >> year;

    printGregorianCalendar(year);

    return 0;
}
