//Moises Gonzalez
//2/18/2025
//3350
//
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
//look up flags
//uniq, sort, sorted_names.txt 
using namespace std;
int i = 0;
int counter = 0;
char arr[400]= {0};
map<string, int> nameCount;
map<int, int> Count;
ifstream in;

int main(int argc, char *argv[])
{
#ifdef WHO_TEST
  system("who > file.txt");
#else  
    system("PROCPS_USERLEN=15 w -h > file.txt");
#endif
    ifstream fin("file.txt");
#ifdef UNIT_TEST
    in.open("live_data.txt");
#else
    in.open("test_data.txt");
#endif
    char line[400];

    while (fin.getline(line,400)) {
        counter++;
        i = 0;

        while(line[i] != ' '){
            arr[i] = line[i];
            i++;
        }
        arr[i] = '\0';
        string username(arr);

        nameCount[username]++;
        i = 0;
    }
    fin.close(); 

    for (const auto& entry : nameCount){
        Count[entry.second]++;
    }

printf("Odin current login statistics\n");
time_t T;
time(&T);
printf("time: %s\n", ctime(&T));
for (const auto& entry : Count) {
    if(entry.second == 1){
        cout << "0" << entry.second << " login:  " << entry.first << " times." << endl;
    } else if (entry.second < 10){
        cout << "0" << entry.second << " logins: " << entry.first << " times." << endl;
    } 
    else {
    cout << entry.second << " logins: " << entry.first << " times." << endl;
    }
}

return 0;
}
