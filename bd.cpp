/* 
    База данных горелок. Поля: Марка, тип соединения (текст), вес, мощность, наличие пьезоподжига.
*/


#include <string>
#include <iostream>
#include <vector>

#include "Gorelki.h"

using namespace std;



int main()
{
    bool ext = false;
    string s = "";
    do
    {
        cout << ">"; cin >> s;
        if     (s == "!add") { add_gorelka(); }
        else if(s == "!delete") { del_gorelka(); }
        else if(s == "!change") { change_Gorelka(); }
        else if(s == "!print") { print_all(); }
        else if(s == "!fileread") { readfile();}
        else if(s == "!filewrite") { savefile();}
        else if(s == "!help") { show_help();}
        else if(s == "!exit") { ext = true;}
        else {cout << "Wrong argement" << endl;}
    }
    while(!ext);
    
    free_memory();
    
    return 0;
}
