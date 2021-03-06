#include <iostream>
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
         << "Generate? [yn] ";
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
        //nothing
        break;
      case 'd':
        if (argc > 2) {
          dayOfWeek = (argv[2][0] - '0') % 7;
        }
        else {
          cerr << "Specify the day number after \"-d\"\n";
          return 1;
        }
        break;
      default:
        cerr << "possible args:\n"
             << "-t           this day\n"
             << "-n           next day\n"
             << "-d <number>  specify the day number\n";
        return 1;
        break;
    }
  }
  string day[] = { "[SUNDAY]",
                   "[MONDAY]",
                   "[TUESDAY]",
                   "[WEDNESDAY]",
                   "[THURSDAY]",
                   "[FRIDAY]",
                   "[SATURDAY]"
 };
                     
  string line;
  while (!ifile.eof()) {
    getline (ifile, line);
    if (line == day[dayOfWeek]) {
        cout << line << "\n";
        while ((getline( ifile, line )) && ( line != "[end]")) {
            cout << line << "\n";
        }
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
