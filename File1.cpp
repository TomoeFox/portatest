#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <fstream.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>

class FindUser {
public:
void find(){
ifstream file1("d:\\test\\file1");
ifstream file2("d:\\test\\file2");
ofstream result("d:\\test\\res.txt");
static string data;
char user1[255];
char user2[255];
string us1;
string us2;
if (file1.is_open() && file2.is_open()) {
while (!file1.eof()) {
file1.getline(user1,255,',');
us1=user1;
if (us1.find("user: ")!=-1) {
us1 = us1.substr(us1.find_last_of(": ")+1, us1.size());
while (!file2.eof())
{
file2.getline(user2,255,',');
us2=user2;

if (us2.find("user: ")!=-1) {
us2 = us2.substr(us2.find_last_of(": ")+1, us2.size());
data.append(us2);
}
}
if (data.find(us1)+1==0) {

result << us1.c_str() << endl;
cout << us1.c_str() << endl;
}
}
}
}
result.close();
file1.close();
file2.close();
}
};
int _tmain(int argc, _TCHAR* argv[])
{
  FindUser u;
  u.find();
  getch();
	return 0;
}
