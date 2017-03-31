#include <vector>
#include <iostream>
#include <fstream>

#include "Structure.h"
#include "Interface.h"

vector <Gorelky> SpisokGorelok;  

int next_id = 0; // ИД следующего при добавлении


void free_memory() // Дописано
{
    SpisokGorelok.clear();
}

void savefile() // дописан
{
    string path = "./Privet.txt";
    
    ofstream file;
    file.open(path);
    
    if (file.is_open())
    {
        for (Gorelky one : SpisokGorelok) 
        {
            file << one.id << endl;
            file << one.mark << endl;
            file << one.type_of_con << endl;
            file << one.ves << endl;
            file << one.power << endl;
            if (one.piezopodjig == true)
                file << "1" << endl;
            else file << "0" << endl;
            
            if (!file) 
            {
                cout << "Error writing to file '" << path << "'" << endl;
                return;
            }
        }
        
        file.close();
        if (!file) 
        {
            cout << "Error writing to file '" << path << "'" << endl;
            return;
        }
        else
        {
            cout << "Writing to file - ready" << endl;
            
        }
    }
    else
    {
        cout << "Error writing to file '" << path << "'" << endl;
    }
    return;
}

void nullGorelka(Gorelky* one) // дописан
{
    one->id = 0;
    one->mark = "";
    one->type_of_con = "";
    one->ves = 0;
    one->power = 0;
    one->piezopodjig = false;
}

void readfile() //дописан
{
    SpisokGorelok.clear();
    Gorelky buf;
    string path = "./Privet.txt";
    ifstream file;
    string s;
    file.open(path);
    if (file.is_open())
    {
        do
        {
            file >> buf.id;
            file >> buf.mark;
            file >> buf.type_of_con;
            file >> buf.ves;
            file >> buf.power;
            file >> s;
            if (s == "1")
                buf.piezopodjig = true;
            else buf.piezopodjig = false;
            if (buf.id != 0) 
                SpisokGorelok.push_back(buf);
            
            nullGorelka(&buf);
            
            
        }while (!file.eof() || buf.id!=0);
        file.close();
        cout << "Чтения из файла - готово" << endl;
    }
    else
    {
        cout << "Ошибка чтения из файла '" << path << "'" << endl;
    }
    
}


bool read_gorelka(Gorelky* new_gorelka) // дописано
{
    new_gorelka->mark = give_meaning("Марка: ");
    new_gorelka->type_of_con = give_meaning("Тип соединения: ");
    new_gorelka->ves = read_int("Вес: ", 0, 200);
    new_gorelka->power = read_int("Мощность: ", 0, 500);
    new_gorelka->piezopodjig = read_boolean();
    
    string in = give_meaning("Верно? (y/n)");
    return (in == "y" || in == "yes");
}

void add_gorelka()  // Дописано.
{
    Gorelky new_gorelka;
    
    bool confirmed = read_gorelka(&new_gorelka);
    
    if (confirmed) {
        new_gorelka.id = ++next_id;
        SpisokGorelok.push_back(new_gorelka);
        cout << "Горелка с id " << new_gorelka.id << " добавлена." << endl;
    } else {
        cout << "Отмена." << endl;
    }
}

bool check_id(int id)  // Дописано. Проверяет наличие ИД в списке горелок
{
    if(id>0 && id <= next_id)
    {
        for (Gorelky one : SpisokGorelok) 
        {
            
            if (one.id == id)
            {
                return true;
            }
        }
    }
    return false;
}

void del_gorelka()  // Дописано
{
    int id = read_gorelka_id();
    if (check_id(id)) {
        int number = 0;
        
        for (Gorelky one : SpisokGorelok) 
        {
            if (one.id == id)
            {
                SpisokGorelok.erase(SpisokGorelok.begin() + number);
                break;
            }
            number++;
        }
        
        cout << "Удалено." << endl;
    } else {
        cout << "Ошибка. ID: " << id << endl;
    }
}

void print_Gorelka(Gorelky* one) // Дописано 
{
    cout << "Марка: " ;
    cout << one->mark << endl;
    cout << "Тип соединения: " ;
    cout << one->type_of_con << endl;
    cout << "Вес: " ;
    cout << one->ves << endl;
    cout << "Мощность: " ;
    cout << one->power << endl;
    
    if (one->piezopodjig == true) 
        cout << "Есть пьезоподжиг" << endl;
    else cout << "Нет пьезоподжига" << endl;
}



void show_help() // Дописано.
{
    cout << endl
         << "Добро пожаловать в базу данных горелок" << endl
         << "add        -   Создать новую запись" << endl
         << "delete     -   Удалить запись"     << endl
         << "change     -   Изменить информацию" << endl
         << "print      -   Показать всё" << endl
         << "help       -   Справка" << endl 
         << "fileread   -   Прочитать из файла" << endl
         << "filewrite  -   Записать в файл" << endl
         << "exit       -   Выход" << endl;
}

void print_all()  // Дописано. 
{
    int i = 1;
    for (Gorelky one : SpisokGorelok)
    {
        cout << i++ << ". ";
        print_Gorelka(&one);
        cout << endl;
    }
}

void change_Gorelka() // Дописано
{
    int id = read_gorelka_id();
    if (check_id(id)) {
        int number = 0;
        Gorelky new_gorelka;
        if(read_gorelka(&new_gorelka) == true)
        {
            for (Gorelky one : SpisokGorelok) 
            {
                if (one.id == id)
                {
                    new_gorelka.id = one.id;
                    SpisokGorelok.at(number) = new_gorelka;
                }
                number++;
            }
        }
        cout << "Готово." << endl;
    } else {
        cout << "Ошибка." << endl;
    }
}