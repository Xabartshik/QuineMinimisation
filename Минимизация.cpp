#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include "minimisation.h"
//Made by OshlakovD-IVT22

using namespace std;


////Проверка на является ли число степенью 2
//bool isPowerOfTwo(int n) {
//    return (n > 0) && ((n & (n - 1)) == 0);
//}
////Перевод числа в двоичную форму
//vector<unsigned short> toBinaryArray(const unsigned int value, const unsigned int digit)
//{
//    vector<unsigned short> result;
//    bitset<sizeof value * 8> binary(value);
//    for (unsigned i = 0; i < digit; i++)
//    {
//        result.push_back(binary[digit - 1 - i]);
//    }
//    return result;
//}
////Вывод массива
//void printVector(vector<unsigned short> array)
//{
//    for (unsigned i = 0; i < array.size(); i++) {
//        cout << array[i];
//    }
//}
////Вывод матрицы
//void printMatrix(vector<vector<unsigned short>> matrix)
//{
//    for (unsigned i = 0; i < matrix.size(); i++)
//    {
//        for (unsigned j = 0; j < matrix[0].size(); j++)
//        {
//            cout << matrix[i][j];
//        }
//        cout << endl;
//    }
//}
//void printMatrix(const vector<vector<vector<unsigned short>>>& matrix) {
//    for (unsigned i = 0; i < matrix.size(); i++)
//    {
//        for (unsigned j = 0; j < matrix[i].size(); j++) 
//        {
//            for (unsigned k = 0; k < matrix[i].size(); k++)
//            {
//                cout << matrix[i][j][k] << " ";
//            }
//            cout << " | ";
//        }
//        cout << endl;
//    }
//}
////Перевод строки в массив
//vector<unsigned short> stringToArray(const string& str) {
//    vector<unsigned short> array;
//    for (char c : str) {
//        array.push_back(c - '0');
//    }
//    return array;
//}
////Считает value в массиве
//unsigned int count(const vector<unsigned short>& array, unsigned int value) {
//    unsigned int count = 0;
//    for (unsigned int element : array) {
//        if (element == value) {
//            count++;
//        }
//    }
//    return count;
//}
////Сравнивает два массива по числу единичек
//bool compare(const vector<unsigned short>& row1, const vector<unsigned short>& row2) {
//    return count(row1, 1) < count(row2, 1);
//}
////Сортировка по количеству единичек
//void sortMatrixBy1(vector<vector<unsigned short>>& matrix) {
//    sort(matrix.begin(), matrix.end(), compare);
//}
////Добавляет столбец флагов
//void addCheckCol(vector<vector<unsigned short>>& matrix) {
//    for (int i = 0; i < matrix.size(); i++) {
//        matrix[i].push_back(0);
//    }
//}
////Заполнение куба элементов матрицами в зависимости от содержащихся в них строк
//vector<vector<vector<unsigned short>>> fillCube(const vector<vector<unsigned short>> & matrix)
//{
//    vector<vector<vector<unsigned short>>> result;
//    vector<vector<unsigned short>> emptyTab;
//    unsigned onesCount = count(matrix[0], 1);
//    for (unsigned i = 0; i<matrix.size(); i++)
//    {
//        if (onesCount != count(matrix[i],1))
//        {
//            addCheckCol(emptyTab);
//            result.push_back(emptyTab);
//            onesCount= count(matrix[i], 1);
//            emptyTab.clear();
//        }
//        emptyTab.push_back(matrix[i]);
//
//
//    }
//    addCheckCol(emptyTab);
//    result.push_back(emptyTab);
//    return result;
//}
//
////Приведение к СДНФ
//vector<vector<unsigned short>> PNDF(const vector<unsigned short> & resCol)
//{
//    vector<vector<unsigned short>> result;
//    for (unsigned i = 0; i < resCol.size(); i++)
//    {
//        if (1 == resCol[i])
//        {
//            result.push_back(toBinaryArray(i, log2(resCol.size())));
//        }
//    }
//    return result;
//}
//
////unsigned seekFirstWithLast(const vector<vector<unsigned int>>& matrix, unsigned int value)
////{
////    for (unsigned i = 0; i < matrix.size(); i++)
////
////    {
////        if (matrix[i][last] == value)
////        {
////            result.push_back(toBinary(i, log2(resCol.size())));
////        }
////    }
////}
////Склейка массивов
//vector<unsigned short> compareArray(const vector<unsigned short> &array1, const vector<unsigned short> &array2)
//{
//    vector<unsigned short> result = array1;
//
//    for (unsigned i = 0; i < array1.size()-1; i++)
//    {
//        if (array1[i] + array2[i] == 1)
//        {
//            result[i] = 8;
//        }
//    }
//    result[array1.size() - 1] = 0;
//    return result;
//}
////Проверка, что массивы склеются
//bool checkArray(const vector<unsigned short> & array1, const vector<unsigned short>& array2)
//{
//    bool result = false;
//
//    unsigned count = 0;
//    unsigned sum = 0;
//    for (unsigned i = 0; i < array1.size()-1; i++)
//    {
//        sum = array1[i] + array2[i];
//        if (sum == 1)
//        {
//            count++;
//            result = true;
//        }
//        else if (sum>2 &&  sum < 16)
//            {
//                result = false;
//                return result;
//            }
//        if (count > 1)
//        {
//            result = false;
//            return result;
//        }
//        
//    }
//
//    return result;
//}
/////Служебные процедуры для нормальной реализации работы метода Квайна
////Очищает крайнюю правую колонку
//void resetCheckCol(vector<vector<unsigned short>>& matrix) {
//    for (unsigned i = 0; i < matrix.size(); i++) {
//        matrix[i].back() = 0;
//    }
//}
////Удаляет крайнюю правую колонку
//void deleteCheckCol(vector<vector<unsigned short>>& matrix) {
//    for (unsigned i = 0; i < matrix.size(); i++) {
//        matrix[i].pop_back();
//    }
//}
////Убирает повторяющиеся элементы
//void removeDuplicates(vector<unsigned short>& array) {
//    sort(array.begin(), array.end());
//    array.erase(unique(array.begin(), array.end()), array.end());
//}
////Убирает повторяющиеся массивы
//void removeDuplicates(vector<vector<unsigned short>>& matrix) {
//    sort(matrix.begin(), matrix.end());
//    matrix.erase(unique(matrix.begin(), matrix.end()), matrix.end()); 
//}
////Выводит массивы с нулем в конце из куба элементов в матрицу
//void findZero(const vector<vector<vector<unsigned short>>>& matrixOld, vector<vector<unsigned short>>& matrixNew) {
//    
//    for (unsigned i = 0; i < matrixOld.size(); i++) {
//        for (unsigned j = 0; j < matrixOld[i].size(); j++) {
//            if (matrixOld[i][j].back() == 0) {
//                matrixNew.push_back(matrixOld[i][j]);
//            }
//        }
//    }
//}
///// Функция минимизации
//vector<vector<unsigned short>> KVA(const vector<vector<vector<unsigned short>>>& cube)
//{
//    vector<vector<unsigned short>> result;
//    vector<vector<vector<unsigned short>>> cubeNew;
//    vector<vector<vector<unsigned short>>> cubeOld = cube;
//    bool sum = true;
//    //Последний элемент строки матрицы массива матриц
//    unsigned max = cubeOld[0][0].size()-1;
//    while (sum == true)
//    {
//        //Очистка и изменение размеров массива матриц нового
//        cubeNew.clear();
//        cubeNew.resize(cubeOld.size() - 1);
//        sum = false;
//        for (unsigned k = 0; k < cubeOld.size()-1 ; k++)
//        {
//            for (unsigned i = 0; i < cubeOld[k].size(); i++)
//            {
//
//                for (unsigned j = 0; j < cubeOld[k+1].size(); j++)
//                {
//                    //Проверка на возможность склейки
//                    if (checkArray(cubeOld[k][i], cubeOld[k+1][j]))
//                    {
//                        //Склейка была сделана, флаги меняются
//                        cubeNew[k].push_back(compareArray(cubeOld[k][i], cubeOld[k+1][j]));
//                        sum = true;
//                        cubeOld[k][i][max] = 1;
//                        cubeOld[k+1][j][max] = 1;
//                    }
//                }
//
//
//            }
//            //Очистка от повторяющихся массивов
//            removeDuplicates(cubeNew[k]);
//        }
//        //Ищет массивы, последний элемент которых - 0 (они не были задейстоваваны во время склейки). Выводит их в результат
//        findZero(cubeOld, result);
//        //Присваивает значения нового массива матриц старому, повторяя цикл снова
//        cubeOld = cubeNew;
//    }
//    //Удаляем столбец, где хранились метки проверенности
//    deleteCheckCol(result);
//    reverse(result.begin(), result.end());
//    return result;
//}
//
//bool isColumnFilledWithZeros(vector<vector<unsigned short>> matrix, unsigned colNum, unsigned skipRow) {
//    unsigned rows = matrix.size();
//    for (unsigned i = 0; i < rows; i++) {
//        if (i != skipRow) {
//            if (matrix[colNum][i] != 0) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
////Находит строки, которые являются ядром
//vector<unsigned short> findCore(const vector<vector<unsigned short>>& matrix) {
//    unsigned rows = matrix.size();
//    unsigned columns = matrix[0].size();
//    unsigned findCore;
//    vector<unsigned short> result;
//
//    for (unsigned col = 0; col < columns; col++) {
//        bool foundOne = false;
//        for (unsigned row = 0; row < rows; row++) {
//            if (matrix[row][col] == 1) 
//            {
//                //Если до этого уже нашли 1, то сбрасываем флаг
//                if (foundOne) {
//                    foundOne = false;
//                    break;
//                }
//                foundOne = true;
//                findCore = row;
//
//            }
//        }
//        if (foundOne)
//        result.push_back(findCore);
//    }
//    return result;
//}
////Находит столбцы, где только одна единица
//vector<unsigned short> findFillOnlyOneCols(const vector<vector<unsigned short>>& matrix) {
//    unsigned rows = matrix.size();
//    unsigned columns = matrix[0].size();
//
//    vector<unsigned short> result;
//
//    for (unsigned col = 0; col < columns; col++) {
//        bool foundOne = false;
//        for (unsigned row = 0; row < rows; row++) {
//            if (matrix[row][col] == 1)
//            {
//                //Если до этого уже нашли 1, то сбрасываем флаг
//                if (foundOne) {
//                    foundOne = false;
//                    break;
//                }
//                foundOne = true;
//            }
//        }
//        if (foundOne)
//            result.push_back(col);
//    }
//    return result;
//}
//
//
//
//
//
////Вывод числа в двоичной форме
//void printBinary(const int value)
//{
//    cout << bitset<sizeof(value) * 8>(value);
//}
//
////Толмач с новомашинного:
//string matrixToString(const vector<vector<unsigned short>>& matrix) {
//    string result;
//    for (int i = 0; i < matrix.size(); i++) {
//        result += "[";
//        for (int j = 0; j < matrix[i].size(); j++) {
//            if (matrix[i][j] == 1) {
//                result += "X" + to_string(j + 1) + "";
//            }
//            else if (matrix[i][j] == 0) {
//                result += "~X" + to_string(j + 1) + "";
//            }
//            else
//            {
//                result += "";
//            }
//        }
//        result += "]";
//        result += "v";
//    }
//    result.pop_back();
//    return result;
//}
////Толмач с новомашинного:
//string matrixToString(const vector<unsigned short>& matrix) {
//    string result;
//    result += "[";
//        for (int i = 0; i < matrix.size(); i++) {
//            if (matrix[i] == 1) {
//                result += "X" + to_string(i + 1) + "";
//            }
//            else if (matrix[i] == 0) {
//                result += "~X" + to_string(i + 1) + "";
//            }
//            else
//            {
//                result += "";
//            }
//    }
//    result += "]";
//    return result;
//}
////Другой толмач
//string matrixToStringPDNF(const vector<vector<unsigned short>>& matrix) {
//    string result;
//    for (int i = 0; i < matrix.size(); i++) {
//        result += "[";
//        for (int j = 0; j < matrix[i].size(); j++) {
//            if (matrix[i][j] == 1) {
//                result += "X" + to_string(j + 1) + "";
//            }
//            else if (matrix[i][j] == 0) {
//                result += "~X" + to_string(j + 1) + "";
//            }
//            else
//            {
//                result += "";
//            }
//        }
//        result += "]";
//        result += " | ";
//
//    }
//    result.pop_back();
//    return result;
//}
////Проверка подмножества
//bool isSubset(vector<unsigned short> array, vector<unsigned short> subArray)
//{
//    unsigned arraySize = array.size();
//    unsigned subArraySize = subArray.size();
//
//    bool result = true;
//    for (unsigned i = 0; i < arraySize; i++)
//    {
//        if ((subArray[i] != array[i]) && (subArray[i] != 8))
//        {
//            result = false;
//            return result;
//        }
//    }
//    return result;
//}
////Составление матрицы проверки попадания мин.дизъюнктов в сднф
//vector<vector<unsigned short>> checkTab(const vector<vector<unsigned short>>& minArray, const vector<vector<unsigned short>>& PDNFarray)
//{
//    vector<vector<unsigned short>> result (minArray.size());
//    for (unsigned i = 0; i < minArray.size(); i++)
//    {
//        for (unsigned j = 0; j < PDNFarray.size(); j++)
//        {
//            result[i].push_back(isSubset(PDNFarray[j],minArray[i]));
//
//        }
//
//    }
//    return result;
//}
////Удаление из матрицы строк по номерам rows
//vector<vector<unsigned short>> removeRows(vector<vector<unsigned short>> matrix, vector<unsigned short> rows) {
//    vector<vector<unsigned short>> newMatrix;
//    bool test;
//    for (unsigned i = 0; i < matrix.size(); i++) {
//        test = find(rows.begin(), rows.end(), i) == rows.end();
//        if (test) {
//            newMatrix.push_back(matrix[i]);
//        }
//    }
//
//    return newMatrix;
//}
//// Функция для заполнения строки матрицы нулями
//void fillRowWithZeros(vector<vector<unsigned short>>& matrix, unsigned row) 
//{
//    for (unsigned j = 0; j < matrix[0].size(); j++) {
//        matrix[row][j] = 0;
//    }
//}
//
//// Функция для заполнения столбца матрицы нулями
//void fillColumnWithZeros(vector<vector<unsigned short>>& matrix, unsigned column) 
//{
//    for (unsigned i = 0; i < matrix.size(); i++) {
//        matrix[i][column] = 0;
//    }
//}
////Вычеркивание из матрицы по методу Ошлакова
//void crossingOut(vector<vector<unsigned short>>& matrix, unsigned row)
//{
//    for (unsigned j = 0; j < matrix[0].size(); j++) {
//        if (matrix[row][j] == 1)
//        {
//            fillColumnWithZeros(matrix, j);
//        }
//    }
//}
////Поэлементно складывает два массива
//void sumVector(vector<unsigned short>& arr1, const  vector<unsigned short>& arr2)
//{
//    for (int i = 0; i < arr1.size(); i++) {
//        arr1[i] = arr1[i] || arr2[i];
//    }
//}
//
////all_of - все элементы в контейнере удовлетворяют условию лямбда-функции
//bool checkAllOnes(const vector<unsigned short>& arr) {
//    return all_of(arr.begin(), arr.end(), [](int i) { return i == 1; });
//}
////Поиск самого покрывающего массива
//unsigned findMostCompatieble(const vector<vector<unsigned short>>& matrix, const vector<unsigned short>& array)
//{
//    unsigned result = 0, maxZeroCount = count(matrix[0], 0);
//    vector<unsigned short> testLine = array;
//    for (unsigned i = 0; i < matrix.size(); i++)
//    {
//        if (find(array.begin(), array.end(), i) == array.end())
//        {
//            sumVector(testLine, matrix[i]);
//            if ((count(testLine, 0) < maxZeroCount))
//            {
//                maxZeroCount = (count(testLine, 0));
//                result = i;
//            }
//        }
//    }
//    return result;
//}
////Поиск номеров конъюнктов с наибольшим покрытием
//vector<unsigned short> findMostEfficientImplicants(const vector<vector<unsigned short>>& matrix)
//{
//    vector<vector<unsigned short>> processingMatrix = matrix;
//    vector<unsigned short> core = findCore(matrix);
//    vector<unsigned short> result;
//    vector<unsigned short> checkFill(matrix[0].size(), 0);
//    //Обнуление ядра
//    for (unsigned i = 0; i < core.size(); i++)
//    {
//        sumVector(checkFill, processingMatrix[core[i]]);
//        result.push_back(core[i]);
//    }
//    unsigned i = 0;
//    while(!checkAllOnes(checkFill))
//    {
//        if (find(core.begin(), core.end(), i) == core.end())
//        {
//            unsigned temp = 0;
//            temp = findMostCompatieble(matrix, checkFill);
//            result.push_back(temp);
//            sumVector(checkFill, processingMatrix[temp]);
//        }
//        i++;
//    }
//
//
//    return result;
//}
//
////Вычеркивание лишнего из матрциы
//vector<vector<unsigned short>> filterMatrix(const vector<vector<unsigned short>>& matrix, const vector<unsigned short>& core) {
//    vector<vector<unsigned short>> result;
//
//    for (unsigned short i = 0; i < matrix.size(); i++) {
//        if ((find(core.begin(), core.end(), i) != core.end())) {
//            result.push_back(matrix[i]);
//        }
//    }
//
//    return result;
//}
////Заполнение матрицы вывода значений на экран. Красивое
//void fillOutputMatrix(const vector<vector<unsigned short>>& minArray, const vector<vector<unsigned short>>& PDNFarray) {
//        cout << "               " << matrixToStringPDNF(PDNFarray) << endl;
//        unsigned width = PDNFarray[0].size()*2+6;
//        vector<vector<unsigned short>> output = checkTab(minArray, PDNFarray);
//        vector<unsigned short> nonessential;
//        for (unsigned i = 1; i < minArray.size()+1; i++)
//        {
//            for (unsigned j = 0; j < PDNFarray.size()+1; j++)
//            {
//                if (j == 0)
//                {
//                    cout.width(width);
//                    cout << matrixToString(minArray[i-1]);
//                }
//                else
//                {
//                    cout.width(width);
//                    cout << output[i-1][j-1] << " | ";
//                }
//            }
//            cout << endl;
//        }
//}

int main(int argc, char* argv[])
{
    testWork();
    vector<vector<unsigned short>> output;
    string input;
    vector<vector<vector<unsigned short>>> valueCube;
    vector<vector<unsigned short>> PDNFMatrix;
    vector<vector<unsigned short>> minimzationResult;
    vector<unsigned short> test;
    cin >> input;
    PDNFMatrix = PNDF(stringToArray(input));
    sortMatrixBy1(PDNFMatrix);
    valueCube = fillCube(PDNFMatrix);
    minimzationResult = KVA(valueCube);
    cout << endl;
    cout << "Результат минимизации:" << endl;
    cout << matrixToString(minimzationResult);
    cout << endl;
    fillOutputMatrix(minimzationResult, PDNFMatrix);
    cout << endl;
    cout << "Результат уничтожения лишних элементов:" << endl;
    output = checkTab(minimzationResult, PDNFMatrix);
    test = findMostEfficientImplicants(output);
    minimzationResult = filterMatrix(minimzationResult, test);
    cout << matrixToString(minimzationResult);
    cout << endl;
    fillOutputMatrix(minimzationResult, PDNFMatrix);
}