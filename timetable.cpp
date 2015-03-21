#include <iostream>
//#include <cmath>
//#include <cstdlib>
//#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <pwd.h>
#include <unistd.h>
using namespace std;

int generateTimetableFile (string);

int main (int argc, char* argv[]) {
  passwd* pw = getpwuid (getuid());
  string homedir = pw->pw_dir;
  string timetablePath = homedir + "/timetable";
  ifstream ifile (timetablePath.c_str());
  if (!(ifile.good())) {
    cout << "You have no \"timetable\" file in your homedir.\n"
         << "Do you want to generate it? [yn] ";
    char answer;
    cin.get(answer);
    if (answer == 'y') {
      cout << "processing... ";
      generateTimetableFile (timetablePath);
      cout << "done\n";
    }
    else {
      cout << "ok\n";
    }
    ifile.close();
    return 0;
  }

  time_t t = time (0);
  struct tm* now = localtime (&t);
  int dayOfWeek = (now->tm_wday);
  if ((argc > 1) && (argv[1][0] == '-')) {
    switch(argv[1][1]) {
      case 'n':
        dayOfWeek = dayOfWeek % 7 + 1;
        break;
      case 't':
        //already ok
        break;
      default:
        cout << "possible args:\n"
             << "-t  today\n"
             << "-n  next day\n";
    }
  }
  struct days {
    string mo, tu, we, th, fr, sa, su;
  } d;
  d.mo = "[MONDAY]";
  d.tu = "[TUESDAY]";
  d.we = "[WEDNESDAY]";
  d.th = "[THIRSDAY]";
  d.fr = "[FRIDAY]";
  d.sa = "[SATURDAY]";
  d.su = "[SUNDAY]";

  string line;
  while (!ifile.eof()) {
    getline (ifile, line);
    switch (dayOfWeek) {
      case 1:
        if (line == d.mo) {
        cout << line << "\n";
          while ((getline (ifile, line)) && (line != "[end]")) {
            cout << line << "\n";
          }
          return 0;
        }
        break;
      case 2:
        if (line == d.tu) {
        cout << line << "\n";
          while ((getline (ifile, line)) && (line != "[end]")) {
            cout << line << "\n";
          }
          return 0;
        }
        break;
      case 3:
        if (line == d.we) {
        cout << line << "\n";
          while ((getline (ifile, line)) && (line != "[end]")) {
            cout << line << "\n";
          }
          return 0;
        }
        break;
      case 4:
        if (line == d.th) {
        cout << line << "\n";
          while ((getline (ifile, line)) && (line != "[end]")) {
            cout << line << "\n";
          }
          return 0;
        }
        break;
      case 5:
        if (line == d.fr) {
        cout << line << "\n";
          while ((getline (ifile, line)) && (line != "[end]")) {
            cout << line << "\n";
          }
          return 0;
        }
        break;
      case 6:
        if (line == d.sa) {
        cout << line << "\n";
          while ((getline (ifile, line)) && (line != "[end]")) {
            cout << line << "\n";
          }
          return 0;
        }
        break;
      case 7:
        if (line == d.su) {
        cout << line << "\n";
          while ((getline (ifile, line)) && (line != "[end]")) {
            cout << line << "\n";
          }
          return 0;
        }
        break;
    }
  }
  ifile.close();
  return 0;
}

int generateTimetableFile (string path) {
  ofstream ofile (path.c_str());
  ofile << "[MONDAY]\n"
       << "empty\n"
       << "[end]\n"
       << "\n"
       << "[TUESDAY]\n"
       << "empty\n"
       << "[end]\n"
       << "\n"
       << "[WEDNESDAY]\n"
       << "empty\n"
       << "[end]\n"
       << "\n"
       << "[THURSDAY]\n"
       << "empty\n"
       << "[end]\n"
       << "\n"
       << "[FRIDAY]\n"
       << "empty\n"
       << "[end]\n"
       << "\n"
       << "[SATURDAY]\n"
       << "empty\n"
       << "[end]\n"
       << "\n"
       << "[SUNDAY]\n"
       << "empty\n"
       << "[end]\n";
  ofile.close();
  return 0;
}
