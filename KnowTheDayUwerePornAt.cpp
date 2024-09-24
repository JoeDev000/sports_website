#include <iostream>
using namespace std;

short readYear() {
bool wrongInput = 0;
short y;
  do {
    if(wrongInput) cout << "Wrong Input Year, try again\n";
    cout << "Entre your birth Year: ";
    cin >> y;
    cout << endl;
    wrongInput = 1;
  } while (!y > 0);
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

int main() {
  cout << "--------------------------------\n";
  cout << "Konw The Day You Were Porn At :3\n";
  cout << "--------------------------------\n";
  cout << "Entre Your date of birth\n";
short year = readYear();
short month = readMonth();
short day = readDay();
  cout << "You were porn at "  << getDayUwerePornAt(year, month, day) << ", Welcome To Life :)\n";
return 0;
}
