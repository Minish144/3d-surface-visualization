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

figure_t setSurface(vector<vector<string>> &zAxisMatrix, float step)
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
                surface.edges.push_back(getEdges(i, j, zAxisMatrix.size()));
                qDebug() << "point: " << point.x << point.y << point.z << surface.edges[i];
            } catch (...) {
                qDebug() << "error point: " << j << QString::fromStdString(zAxisMatrix[i][j]) << i;
            }
        }
    return surface;
}

vector<int> getEdges(int i, int j, size_t count)
{
    int rows = count - 1;
    int columns = rows;

    // обработка точек не лежащих на крайних "прямых"
    if (i != 0 and j != 0 and i != rows and j != columns)
        return {i*j, (i+1)*j-1, (i+1)*j+1, (i+2)*j};

    // обработка краевых точек
    if (i == 0 && j == 0)
        return {1, columns+1};
    else if (i == 0 and j == columns)
        return {columns-1, 2*columns};
    else if (i == rows and j == 0)
        return {(rows-1)*columns+1, rows*columns+1+1};
    else if (i == rows and j == columns)
        return {(rows+1)*columns-1, rows+1*columns};

    // обработка точек лежащих на крайних "прямых" матрицы, но не краевых точках
    else if (i == 0 and j != 0 and j != columns)
        return {j-1, j+1, columns+1+j};
    else if (i == rows and j != 0 and j != columns)
        return {rows*columns+j, rows*columns+j+2, (rows-1)*columns+1+j};
    else if (j == 0 and i != 0 and i != rows)
        return {i*columns+2, (i-1)*columns+1, (i+1)*columns+1};
    else if (j == columns and i != 0 and i != rows)
        return {i*columns, (i+1)*columns-1, (i+2)*columns};
}

void setEdges(figure_t &surface, vector<vector<string>> &zAxisMatrix)
{
    for (size_t i = 0; i < zAxisMatrix.size(); i++)
        for (size_t j = 0; j < zAxisMatrix.size(); j++)
        {
            surface.edges.push_back(getEdges(i, j, zAxisMatrix.size()));
        }
}

float findExtremums(figure_t &surface, float &min, float &max)
{
    min = max = surface.points[0].y;
    for (int i = 1; i < surface.Count(); i++)
    {
        if ( surface.points[i].y <= min )
            min = surface.points[i].y;
        else
            max = surface.points[i].y;
    }
    return min;
}

void normalize(figure_t &surface, float a, float b)
{
    float min, max;
    findExtremums(surface, min, max);
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].y = a + (surface.points[i].y - min) * (b - a) / (max - min);
    }
}

