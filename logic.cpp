#include "logic.h"

vector<vector<string>> dataVariable;

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
        qDebug() << tmp[tmp.length()-1];
//        if (tmp[tmp.length()-1] == '\r')
//            tmp = tmp.substr(0, tmp.length()-3);
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
    dataVariable = tempMatrix;
    return tempMatrix;
}

figure_t setFigure(vector<vector<string>> &zAxisMatrix, float step)
{
    point_t point;
    figure_t surface;
    qDebug() << "matrix size: " << zAxisMatrix.size() << "step: " << step;
    for (size_t i = 0; i < zAxisMatrix.size(); i++)
        for (size_t j = 0; j < zAxisMatrix.size(); j++)
        {
            try {
                point.x = j * step;
                point.y = stof(zAxisMatrix[i][j]) * step;
                point.z = i * step;
                surface.points.push_back(point);
                qDebug() << "point: " << point.x << point.y << point.z;
            } catch (...) {
                qDebug() << "error point: " << j << QString::fromStdString(zAxisMatrix[i][j]) << i;
            }
        }
    return surface;
}

void normalize(figure_t &surface)
{

}
