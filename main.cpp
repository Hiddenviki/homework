#include <iostream>
#include <iomanip>
//#include <windows.h>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#include "StreamTable.h"
using namespace std;

int sti(char *s,int num){
    if(!*s)
        return num;
    return sti(s+1,num*10+*s-'0');
} //важная функция для набора имен и фамилий

double getMark()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Оценка письма(в формате double от 0.0 до 10.0): ";
        double a;
        cin >> a;

        if (cin.fail() or (a <= 0.0) or (a > 10.0) ) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
} //важная функция для double mark
int getIndexFrom()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Индекс отправителя: ";
        int a;
        cin >> a;

        if (cin.fail() or (a <= 0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
} //важная функция для int Index
int getIndexTo()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Индекс получателя: ";
        int a;
        cin >> a;

        if (cin.fail() or (a <= 0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
} //важная функция для int Index
int getNumber()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Индивидуальный идентификационный номер: ";
        int a;
        cin >> a;

        if (cin.fail() or (a <= 0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
} //важная функция для int individualNumber

char * getSurNameFrom(){
    int i;
    char *str;
    str = new char[15];
    char *Obj = new char[15];
    do{
        cout<<"Введите фамилию отправителя: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Введены не буквы("<<endl<<"Повтори ввод"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
} //важная функция для char surNameFrom
char * getNameFrom(){
    int i;
    char *str;
    str = new char[15];
    char *Obj = new char[15];
    do{
        cout<<"Введите имя отправителя: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Введены не буквы("<<endl<<"Повтори ввод"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
} //важная функция для charNameFrom
char * getSurnameTo(){
    int i;
    char *str;
    str = new char[15];
    char *Obj = new char[15];
    do{
        cout<<"Введите фамилию получателя: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Введены не буквы("<<endl<<"Повтори ввод"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
} //важная функция для char surnameTo
char * getNameTo(){
    int i;
    char *str;
    str = new char[15];
    char *Obj = new char[15];
    do{
        cout<<"Введите имя получателя: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Введены не буквы("<<endl<<"Повтори ввод"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
} //важная функция для char nameTo

struct Letter
{
    double mark;
    int indexFrom;
    int individualNumber;
    char* surnameFrom;
    char* nameFrom;
    int indexTo;
    char* surnameTo;
    char* nameTo;
};

Letter* AddStruct(Letter* Obj, int amount);
void setData(Letter* Obj, int amount);
void showData(Letter* Obj, int amount);
void showMenu(int* a)
{
    cout << "Диалоговое окно:" << endl;
    cout << "1)Вывести таблицу" << endl;
    cout << "2)Добавить новое письмо" << endl;
    cout << "3)Распечатать информацию о письме по индивидуальному идентификационному номеру" << endl;
    cout << "4)Найти все письма заданного отправителя" << endl;
    cout << "5)найти все письма с оценкой большей заданного" << endl;
    cout << "6)Завершить работу" << endl;
    cout << "Введите число от 1 до 6" << endl;
    cin >> *(a);
}

void showInfo(Letter* Obj, int amount)
{
    int s;
    cout << "Введите индивидуальный идентификационный номер:" << endl;
    cin>>s;

    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].individualNumber == s)
        {
            cout <<  setw(10) << setprecision(3) << "Оценка письма" << setw(10) << setprecision(3)  << "Индекс отправителя\t" <<setw(10) << setprecision(3)  << "Фамилия отправителя\t" << setw(10) << setprecision(3) << "Имя отправителя\t" <<setw(10) << setprecision(3) << "Индекс получателя\t" <<setw(10) << setprecision(3) << "Фамилия получателя\t" <<setw(10) << setprecision(3) << "Имя получател\t" <<setw(10) << setprecision(3) << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout <<  setw(10) << setprecision(3) << Obj[i].mark << '\t' << setw(11) << setprecision(3) << Obj[i].indexFrom << '\t' << setw(10) << setprecision(3) <<Obj[i].surnameFrom << '\t' << setw(10) << setprecision(3) << Obj[i].nameFrom <<setw(10) << setprecision(3) <<setw(10) << setprecision(3) <<Obj[i].indexTo<<setw(10) << setprecision(3) <<Obj[i].surnameTo<<setw(10) << setprecision(3) <<Obj[i].nameTo<< setw(10) << setprecision(3)  << endl;
        }
    }
}


void FindThem(Letter* Obj, int amount)
{
    char s[32];
    cout << "Введите фамилию отправителя:" << endl;
    cin.get();
    cin.getline(s, 32, '\n');
    char n[32];
    cout << "Введите имя отправителя:" << endl;
    cin.getline(n, 32, '\n');
    cout << "ОЦЕНКА ПИСЬМА" << "ИНДЕКС ОТПРАВИТЕЛЯ" << "ФАМИЛИЯ ОТПРАВИТЕЛЯ" << "ИМЯ ОТПРАВИТЕЛЯ" << "ИНДЕКС ПОЛУЧАТЕЛЯ" << "ФАМИЛИЯ ПОЛУЧАТЕЛЯ" << "ИМЯ ПОЛУЧАТЕЛЯ" << "ИНДИВИДУАЛЬНЫЙ ИДЕНТИФИКАЦИОННЫЙ НОМЕР";
    for (int i = 0; i < amount; i++)
    {
        if ((strcmp(Obj[i].surnameFrom, s) == 0) and (strcmp(Obj[i].nameFrom, n) == 0))
        {
            cout <<  Obj[i].mark << '\t' << setw(11) << setprecision(3) << Obj[i].indexFrom << '\t' << setw(10) << setprecision(3) <<Obj[i].surnameFrom << '\t' << setw(10) << setprecision(3) << Obj[i].nameFrom <<setw(10) << setprecision(3) <<setw(10) << setprecision(3) <<Obj[i].indexTo<<setw(10) << setprecision(3) <<Obj[i].surnameTo<<setw(10) << setprecision(3) <<Obj[i].nameTo<< setw(10) << setprecision(3) <<Obj[i].individualNumber<<endl;
            //printf("")
        }
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Last(Letter* Obj, int amount)
{
    double n=getMark();
    cin.get();

    int counter = 0;
    cout << setw(10) << setprecision(3) << "Оценка письма" << setw(10) << setprecision(3)  << "Индекс отправителя\t" <<setw(10) << setprecision(3)  << "Фамилия отправителя\t" << setw(10) << setprecision(3) << "Имя отправителя\t" <<setw(10) << setprecision(3) << "Индекс получателя\t" <<setw(10) << setprecision(3) << "Фамилия получателя\t" <<setw(10) << setprecision(3) << "Имя получател\t" <<setw(10) << setprecision(3) <<"Индивидуальный идентификационный номер"<< endl;
    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].mark>n)
        {
            counter++;

        }
    }

    string* array = new string[counter];
    multiset <string> all; //индекс сет это слово чтоб по алфавиту
    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].mark>n)
        {
            all.insert(Obj[i].surnameTo);
        }
    }


    cout << "Отсортированный вариант:"<<"\n";
    for (auto w : all) {
        cout<<" получатель: "<<w<<"\n";
        cout<< "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }

}

int main()
{
    //SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    Letter* MyLittleLetters = 0;
    int sponsorAmount = 0;
    int YesOrNot = 0; //  продолжить или остановить ввод данных

    do
    {
        MyLittleLetters = AddStruct(MyLittleLetters, sponsorAmount);
        setData(MyLittleLetters, sponsorAmount);
        sponsorAmount++;
        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
        cin.get();
    } while (YesOrNot != 0);

    showData(MyLittleLetters, sponsorAmount);
    int a;
    do {
        showMenu(&a);
        switch (a)
        {
            case 1:
                showData(MyLittleLetters, sponsorAmount);
                break;
            case 2:
                MyLittleLetters = AddStruct(MyLittleLetters, sponsorAmount);
                setData(MyLittleLetters, sponsorAmount);
                sponsorAmount++;
                break;
            case 3:
                showInfo(MyLittleLetters, sponsorAmount);
                break;
            case 4:
                FindThem(MyLittleLetters, sponsorAmount);
                break;
            case 5:
                Last(MyLittleLetters, sponsorAmount);
                break;
        }
        //if (c != 6)
            //system("pause");
    } while (a != 6);

    return 0;
}

Letter* AddStruct(Letter* Obj, int amount)
{
    if (amount == 0)
    {
        Obj = new Letter[amount + 1]; // выделение памяти для первой структуры
    }
    else
    {
        Letter* tempObj = new Letter[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete[] Obj;

        Obj = tempObj;
    }
    return Obj;
}

void setData(Letter* Obj, int amount)

{

    Obj[amount].mark=getMark();
    cin.get();

    Obj[amount].indexFrom=getIndexFrom();
    cin.get();

    Obj[amount].individualNumber=getNumber();
    cin.get();

    Obj[amount].surnameFrom = new char[15];
    Obj[amount].surnameFrom = getSurNameFrom(); //here


    Obj[amount].nameFrom = new char[15];
    Obj[amount].nameFrom = getNameFrom();


    Obj[amount].indexTo=getIndexTo();
    cin.get();

    Obj[amount].surnameTo = new char[15];
    Obj[amount].surnameTo = getSurnameTo();

    Obj[amount].nameTo = new char[15];
    Obj[amount].nameTo = getNameTo();


    cout << endl;
}



void showData(Letter* Obj, int amount)
{
    //system("cls");

    StreamTable st(std::cout);
    st.AddCol(20);
    st.AddCol(20);
    st.AddCol(20);
    st.AddCol(20);
    st.AddCol(20);
    st.AddCol(20);
    st.AddCol(20);
    st.AddCol(20);
    st.AddCol(20);
    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    //st.SetDelimRow(false); //без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк
    //заголовок и значения выводятся одинаково


    for (int i = 0; i < amount; i++) {
        //cout << "№ПИСЬМА " <<setw(10)<< "ОЦЕНКА ПИСЬМА" << "ИНДЕКС ОТПРАВИТЕЛЯ" << "ФАМИЛИЯ ОТПРАВИТЕЛЯ" << "ИМЯ ОТПРАВИТЕЛЯ" << "ИНДЕКС ПОЛУЧАТЕЛЯ" << "ФАМИЛИЯ ПОЛУЧАТЕЛЯ" << "ИМЯ ПОЛУЧАТЕЛЯ" << "ИНДИВИДУАЛЬНЫЙ ИДЕНТИФИКАЦИОННЫЙ НОМЕР";
        st << "№ПИСЬМА " << "ОЦЕНКА ПИСЬМА" << "ИНДЕКС ОТПРАВИТЕЛЯ" << "ФАМИЛИЯ ОТПРАВИТЕЛЯ" << "ИМЯ ОТПРАВИТЕЛЯ" << "ИНДЕКС ПОЛУЧАТЕЛЯ" << "ФАМИЛИЯ ПОЛУЧАТЕЛЯ" << "ИМЯ ПОЛУЧАТЕЛЯ" << "ИНДИВИДУАЛЬНЫЙ ИДЕНТИФИКАЦИОННЫЙ НОМЕР";
        st << i + 1 << Obj[i].mark << Obj[i].indexFrom << Obj[i].surnameFrom << Obj[i].nameFrom<<Obj[i].indexTo<<Obj[i].surnameTo<<Obj[i].nameTo<<Obj[i].individualNumber;
    }

}