//
//  main.cpp
//  лаба5
//
//  Created by Виктория Веселкова on 23.11.2021.
//

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#include <iomanip>

#include <vector>
#include <cctype>
#include <map>

using namespace std;

string up(string s){
    for (int i = 0; i < s.length(); i++){
        s[i] = toupper(s[i]);
    }
    return s;
}

void read(string s){
    int len = s.length();

    string temp; //строчка для того чтобы делить слова
    vector<string> words; //словарь всех слов
    map<string, int> counter; // словарь слов и количество их вхожедний в строку
    vector<string> similar; // вектор (дин.массив) ПОВТОРЯЮЩИХСЯ слов
    map<string, vector<int>> pointers; //словарь указателей

    //считываем всю строчку и если у нас есть пробел или завершение строки '\0', то прибавляем количество вхождений этого слова и кидаем само слово
    for (int i = 0; i <= len; i++){
        if (s[i] == ' ' || s[i] == '\0'){
            counter[temp] += 1;
            words.push_back(temp);
            temp = "";
        }
        else{
            temp += s[i];
        }
    }

    //пробегаемся по словарю, где i.first = слово, i.second = кол-во вхождений этого слова
    for (auto i: counter){
        if (i.second > 1){
            similar.push_back(i.first);
        }
    }

    //пробегаемся по вектору и считаем позиции вхождений слова
    for (auto i: similar){
        cout << "Элемент " << i << " встречается в:";
        vector<int> positions;
        int pos = s.find(i, 0);

        while(pos != -1)
        {
            positions.push_back(pos);
            pos = s.find(i,pos+1);
        }

        pointers[i] = positions; // теперь для какого-то повторяющегося слова есть массив с его индексами

        for (int p = 0; p < positions.size(); p++){
            cout << " " << positions[p] << " ";
            s.replace(positions[p], i.length(), up(i));
            //выводим эти индексы и КАПСим слова
        }

        cout << endl;
    }
    cout << endl;

    //пробегаемся по словарю указателей, обращаемся к словарю по ПОВТОРЯЮЩЕМУСЯ слову, получая индексы вхождений, печатаем указатели на первые буквы
    for (auto w : pointers){
        cout << setw(4) << "Для лемента " << w.first << " указателями на первые символы будут:" << endl;
        for (auto i : w.second){
            cout << setw(4) << (int*)(&s[i]) << endl;
        }
        cout << endl;
    }
    cout << "Результат:" << endl;
    cout << s << endl;
}

void bts()
{
 
    
    // 1. Объявление переменных
    string* AS; // массив вводимых строк, это результат
    string* AS2; // дополнительный массив строк
    int count; // количество элементов в массиве
    string s; // дополнительная переменная-строка
    char buf[80]; // буфер для ввода строк
    

    // 2. Цикл ввода строк, конец ввода - пустая строка ""
    cout << "вводите строчкки, вводя слова через 1 пробел на Английском языке. (Если вы введете много пробелов или пустую строку прграмма будет вам давать указатели на пробелы тк это тоже символы. Все одинаковые числа это тоже одинаковые элементы):\n";
    count = 0;
    AS = nullptr;

    do
    {
      
        cout << "=> ";
        cin.getline(buf, 80, '\n'); // строки вводятся с пробелами

       
        s = buf;
        read(s);

        if (strcmp(buf, "no") != 0 )
        {

            count++;

            AS2 = new string[count];

            for (int i = 0; i < count - 1; i++)
                AS2[i] = AS[i];

            AS2[count - 1] = s;

            
            if (AS != nullptr)
                delete[] AS;

          
            AS = AS2;
        }
    } while (strcmp(buf, "no") != 0);

    
    if (count > 0){
        cout << "\nВот они БТС сверху вниз☺️😍:\n";
        for (int i = 0; i < count; i++)
            cout << "В строке №" << i + 1 << " вы вводили: " << AS[i] << ::endl;}
    else
        cout << "НО ВЫ НИЧЕГО НЕ ВВЕЛИ АОАО((";

    // 4. После использования массива AS освободить память, выделенную для него
    delete[] AS;
}

int** sozdanie(int n, int m)
{
    int **A;// Создаю матрицу введенной размерности
    A = new int *[n]; // через массив указателей
    for (int i = 0; i < n; i++) {
       A[i] = new int [m];
    }
    return A;
}


void initialize(int** A, int n, int m)// Функция заполнения
{
    srand(time(0));
    for(int i = 0; i < n; i++ )
    {
        for(int j = 0;  j < m;  j++ )
        {
            A[i][j] = rand()%11 - 5 ;
            
            cout<<setw(8)<<setprecision(3)<<A[i][j]<<' '; //это чтоб выравнивалось красиво
        }
    cout << endl;
    }
}

//ищем кол-во нулей в нужном месте
int num_of_z(int n, int m, int ** Arr) {
    int count = 0;
    for (int i = n/2; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(Arr[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}


//ух

int* f(int n, int m, int noz, int ** Arr) {
    int *Ptr_arr [noz];
    int counter = 0;
    for (int i = n/2; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(Arr[i][j] == 0) {
                Ptr_arr[counter] = &Arr[i][j];
                counter++;
            }
        }
    }
    return *Ptr_arr;
}

void qq(){
    int s=0;
    setlocale(LC_ALL, "Russian");
     
    int n(0), m(0);
    cout << " Введите чётное кол-во строк в массиве" << endl;
    cin >> n;
    s=n;
    if (s%2!=0){
        cout<<"чел ты.."<<"\n";
    }
    else{
        cout << " \nВведите кол-во столбцов в массиве" << endl;
        cin >> m;
        cout << endl;
        int **A;

        A = sozdanie(n,m); // Создаю через функцию
            initialize(A, n, m); // заполняю матрицу



        for ( int i = 0; i < n; i++ )
        {
            delete [] A[ i ];
        }
        delete [] A; // Освобождение памяти
        
        int k = num_of_z(n, m, A);
        int **B = new int*[k];
        *B = f(n,m,k,A);
        for (int i = 0; i < k; i++) {
            cout << B[i] << endl;
        }
    }
}

int main()
{
    cout<<"\n"<<"тут будет первое задание:"<<"\n";
    bts(); //это номер 1
    cout<<"\n"<<"На этом 1 номер закончен(и слава Богу)"<<"\n";
    qq(); //это номер 2
}
