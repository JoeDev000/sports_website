#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct stDate {
  short year, month, day;
};

struct stResult {
  float years;
  unsigned short days;
  unsigned int hours, mins;
  unsigned long secs; 
  string dayUwerePornAt;
};

short readYear() {
bool wrongInput = 0;
short y;
  do {
    if(wrongInput) cout << "Wrong Input Year, try again\n";
    cout << "Entre your birth Year: ";
    cin >> y;
    cout << endl;
    wrongInput = 1;
  } while (y <= 0);
  return y; 
} 

short readMonth() {
bool wrongInput = 0;
short m;
  do {
    if(wrongInput) cout << "Wrong Input Month, try again\n";
    cout << "Entre your birth Month: ";
    cin >> m;
    cout << endl;
    wrongInput = 1;
  } while (m < 1 || m > 12);
  return m; 
}

short readDay() {
bool wrongInput = 0;
short d;
  do {
    if(wrongInput) cout << "Wrong Input Day, try again\n";
    cout << "Entre your birth Day: ";
    cin >> d;
    cout << endl;
    wrongInput = 1;
  } while (d < 1 || d > 31);
  return d; 
}

bool isLeapYear(short year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short getNumberOfDaysInMonth(short month, short year) {
short daysInMonths[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  // return month == 2 ? (isLeapYear(year) ? 29 : 28) : daysInMonths[month-1];
  return isLeapYear(year) && month == 2 ? 29 : daysInMonths[month-1];
}

stDate readFullDate() {
stDate date;
  date.day = readDay();
  date.month = readMonth();
  date.year = readYear();
  return date;
}

bool isLastMonthInTheYear(short month) {
  return month == 12;
}

bool isLastDayInTheMonth(short day, short month, short year) {
  return day == getNumberOfDaysInMonth(month, year);
}

stDate increaseDateByOneDay(stDate date) {
  if (isLastDayInTheMonth(date.day, date.month, date.year)) {
    if (isLastMonthInTheYear(date.month)) {
      date.year ++;
      date.month = 1;
      date.day = 1;
    }
    else {
      date.month ++;
      date.day = 1;
    }
  } 
  else {
    date.day ++;
  }
  return date;
}

bool dateOfBirth_CameBefore_currentDate(stDate dateOfBirth, stDate currentDate) {
  return (dateOfBirth.year < currentDate.year) ? true : ((dateOfBirth.year == currentDate.year) ? ((dateOfBirth.month < currentDate.month) ? true : ((dateOfBirth.month == currentDate.month) ? (dateOfBirth.day < currentDate.day) : false)) : false);
}

unsigned short getAgeInDays(stDate dateOfBirth, stDate currentDate) {
unsigned short counter = 0;
  while (dateOfBirth_CameBefore_currentDate(dateOfBirth, currentDate)) {
    counter ++;
    dateOfBirth = increaseDateByOneDay(dateOfBirth);
  }
  return counter;
}

short caclulate_ordre(short year, short month, short day) {
int a, m, y;
  a = (14 - month) / 12;
  y = year - a;
  m = month + 12*a - 2;
  return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string getDayUwerePornAt(short year, short month, short day) {
string days[] {"Sunday", "Monday", "Tusday", "Wednesday", "Thurthday", "Friday", "Saturday"};
  return days[caclulate_ordre(year, month, day)];
}

void getSystemDate(stDate &currentDate) {
time_t t = time(NULL);
struct tm* now = localtime(&t);
  currentDate.year = now -> tm_year + 1900;
  currentDate.month = now -> tm_mon + 1;
  currentDate.day = now -> tm_mday;
}

stDate readDateOfBirth() {
stDate dateOfBirth;
  cout << "---- Entre Your Date Of Birth ----\n";
  dateOfBirth = readFullDate();
  return dateOfBirth;
}

stResult getResult(stDate dateOfBirth, stDate currentDate) {
stResult result;
  result.dayUwerePornAt = getDayUwerePornAt(dateOfBirth.year, dateOfBirth.month, dateOfBirth.day);
  unsigned short ageInDays = getAgeInDays(dateOfBirth, currentDate);
  result.years = (float) ageInDays / 365.25;
  result.days = ageInDays;
  result.hours = ageInDays * 24;
  result.mins = result.hours * 60;
  result.secs = result.mins * 60;
  return result;
}

void printResult(stResult result) {
  cout << endl;
  cout << "\t  --- Your Age ---\n";
  cout << " ----------------------------------\n";
  cout << "|    You Have | " << left << setw(10) << result.years << " | Years |\n";
  cout << "| OR You Have | " << left << setw(10) << result.days << " | Days  |\n";
  cout << "| OR You Have | " << left << setw(10) << result.hours << " | Hours |\n";
  cout << "| OR You Have | " << left << setw(10) << result.mins << " | Mins  |\n";
  cout << "| OR You Have | " << left << setw(10) << result.mins << " | Mins  |\n";
  cout << " ----------------------------------\n";
  cout << "| You Were Porn At " << left << setw(9) << result.dayUwerePornAt << " :)\t   |\n";
  cout << " ----------------------------------\n";
}

int main() {
stDate currentDate, dateOfBirth;
  dateOfBirth = readDateOfBirth();
  getSystemDate(currentDate);
  printResult(getResult(dateOfBirth, currentDate));
return 0;
}
