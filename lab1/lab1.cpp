// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

unsigned int fileSize(const string filePath) {

    streampos fsize = 0;
    ifstream file(filePath, std::ios::binary);

    fsize = file.tellg();
    file.seekg(0, std::ios::end);
    fsize = file.tellg() - fsize;
    file.close();

    return unsigned int(fsize);
}

int main()
{
    ofstream fout;
    ifstream fin;
    string inputFile, outputFile, data;
    int arraySize, stepCount = 0;
    double summa = 0;
    unsigned int startTime, endTime, fileLen;

    cout << "Input fileName\n";
    cin >> inputFile;
    fin.open(inputFile);
    fileLen = fileSize(inputFile);

    cout << "Output fileName\n";
    cin >> outputFile;
    fout.open(outputFile);

    cout << "Input N:\n";
    cin >> arraySize;


    startTime = clock();

    while(getline(fin, data, ' '))
    {
        summa += stoi(data);
        stepCount++;
        fout << data << " ";
        if (stepCount == arraySize){
            fout << "AVG: " << summa / arraySize << endl;
            stepCount = 0;
            summa = 0;
        }
    }
    endTime = clock();

    fout << "TIME: " << ((float)endTime - startTime) / CLOCKS_PER_SEC << " BYTES_SIZE: " << fileLen;
    fin.close();
    fout.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
