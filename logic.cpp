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
                point.y = i * step; //stof(zAxisMatrix[i][j]) * step;
                point.z = 0; //i * step;
                surface.points.push_back(point);
                surface.edges.push_back(getEdges(i, j, zAxisMatrix.size()));
//                qDebug() << "point: " << "x, j:" << point.x << "y, i :" << point.y;
//                qDebug() << surface.edges[i];
            } catch (...) {
                qDebug() << "error point: " << j << QString::fromStdString(zAxisMatrix[i][j]) << i;
            }
        }
    return surface;
}

vector<int> getEdges(int i, int j, int count)
{
    // обработка угловых точек
    if (i == 0 and j == 0)
        return {1, count};
    else if (i == 0 and j == count-1)
        return {count-2, 2*count-1};
    else if (i==count-1 and j == 0)
        return {(i-1)*count, i*count+1};
    else if (i == count-1 and j == count-1)
        return {(i+1)*count-2, i*count-1};

    // обработка крайних матричных точек
    else if (i == 0 and j != 0)
        return {j-1, j+1, count+j};
    else if (i == count-1 and j != 0)
        return {i*(count)+j-1, i*(count)+j+1, i*(count-1)+j-1};
    else if (j == 0 and i != 0)
        return {i*count+1, (i-1)*count, (i+1)*count};
    else if (j == count-1 and i != 0)
        return {i*count-1, i*count+j-1, (i+1)*count+j};

    else return {};
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

