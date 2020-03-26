#include "logic.h"

int checkFile(string filepath)
{
    ifstream file(filepath);
    if (file.is_open())
    {
        qDebug() << "Все ОК! Файл удалось открыть!\n" << endl;
        return 1;
    }
    else
    {
        qDebug() << "Файл не удалось открыть!\n" << endl;
        return 0;
    }
}

vector<string> readCSV(string filepath)
{
    checkFile(filepath);
    ifstream file(filepath);
    string tmp;
    vector<string> sArray;
    int count = 0;
    for (int i = 0; getline(file, tmp); i++)
    {
        sArray.push_back(tmp);
        count++;
    }
    for (int i = 0; i  < count; i++)
    {
        qDebug() << QString::fromStdString(sArray[i]);
    }
    return sArray;
}


vector<string> splitString(string str, string sep)
{
    vector<string> arr;
    size_t prev = 0;
    size_t next;
    size_t delta = 1;
    while ((next = str.find(sep, prev)) != string::npos)
    {
        arr.push_back(str.substr(prev, next - prev));
        prev = next + delta;
    }
    arr.push_back(str.substr(prev));
    return arr;
}

vector<vector<string>> getStringMatrix(vector<string> array)
{
    vector<vector<string>> tempMatrix;
    vector<string> tempArray;
    for (size_t i = 0; i < array.size(); i++)
    {
        tempArray = splitString(array[i], ",");
        tempMatrix.push_back(tempArray);
    }
    return tempMatrix;
}
