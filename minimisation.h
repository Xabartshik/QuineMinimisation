#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>

using namespace std;

//Проверка на является ли число степенью 2
bool isPowerOfTwo(int n);
//Перевод числа в двоичную форму
vector<unsigned short> toBinaryArray(const unsigned int value, const unsigned int digit);
//Вывод массива
void printVector(vector<unsigned short> array);
//Вывод матрицы
void printMatrix(vector<vector<unsigned short>> matrix);
//Вывод матрицы
void printMatrix(const vector<vector<vector<unsigned short>>>& matrix);
//Перевод строки в массив
vector<unsigned short> stringToArray(const string& str);
//Считает value в массиве
unsigned int count(const vector<unsigned short>& array, unsigned int value);
//Сравнивает два массива по числу единичек
bool compare(const vector<unsigned short>& row1, const vector<unsigned short>& row2);
//Сортировка по количеству единичек
void sortMatrixBy1(vector<vector<unsigned short>>& matrix);
//Добавляет столбец флагов
void addCheckCol(vector<vector<unsigned short>>& matrix);
//Заполнение куба элементов матрицами в зависимости от содержащихся в них строк
vector<vector<vector<unsigned short>>> fillCube(const vector<vector<unsigned short>>& matrix);
//Приведение к СДНФ
vector<vector<unsigned short>> PNDF(const vector<unsigned short>& resCol);
//Склейка массивов
vector<unsigned short> compareArray(const vector<unsigned short>& array1, const vector<unsigned short>& array2);
//Проверка, что массивы склеются
bool checkArray(const vector<unsigned short>& array1, const vector<unsigned short>& array2);
//Очищает крайнюю правую колонку
void resetCheckCol(vector<vector<unsigned short>>& matrix);
//Удаляет крайнюю правую колонку
void deleteCheckCol(vector<vector<unsigned short>>& matrix);
//Убирает повторяющиеся элементы
void removeDuplicates(vector<unsigned short>& array);
//Убирает повторяющиеся массивы
void removeDuplicates(vector<vector<unsigned short>>& matrix);
//Выводит массивы с нулем в конце из куба элементов в матрицу
void findZero(const vector<vector<vector<unsigned short>>>& matrixOld, vector<vector<unsigned short>>& matrixNew);
/// Функция минимизации
vector<vector<unsigned short>> KVA(const vector<vector<vector<unsigned short>>>& cube);
//Проверка на заполненость нулями столбца
bool isColumnFilledWithZeros(vector<vector<unsigned short>> matrix, unsigned colNum, unsigned skipRow);
//Находит строки, которые являются ядром
vector<unsigned short> findCore(const vector<vector<unsigned short>>& matrix);
//Находит столбцы, где только одна единица
vector<unsigned short> findFillOnlyOneCols(const vector<vector<unsigned short>>& matrix);
//Вывод числа в двоичной форме
void printBinary(const int value);
//Толмач с новомашинного: (Перевод кода массива в циферки и буковки)
string matrixToString(const vector<vector<unsigned short>>& matrix);
//Толмач с новомашинного: (Перевод кода массива в циферки и буковки)
string matrixToString(const vector<unsigned short>& matrix);
//Другой толмач (Перевод кода массива в циферки и буковки)
string matrixToStringPDNF(const vector<vector<unsigned short>>& matrix);
//Проверка подмножества
bool isSubset(vector<unsigned short> array, vector<unsigned short> subArray);
//Составление матрицы проверки попадания мин.дизъюнктов в сднф
vector<vector<unsigned short>> checkTab(const vector<vector<unsigned short>>& minArray, const vector<vector<unsigned short>>& PDNFarray);
//Удаление из матрицы строк по номерам rows
vector<vector<unsigned short>> removeRows(vector<vector<unsigned short>> matrix, vector<unsigned short> rows);
// Функция для заполнения строки матрицы нулями
void fillRowWithZeros(vector<vector<unsigned short>>& matrix, unsigned row);
// Функция для заполнения столбца матрицы нулями
void fillColumnWithZeros(vector<vector<unsigned short>>& matrix, unsigned column);
//Вычеркивание из матрицы 
void crossingOut(vector<vector<unsigned short>>& matrix, unsigned row);
//Поэлементно складывает два массива
void sumVector(vector<unsigned short>& arr1, const  vector<unsigned short>& arr2);
//all_of - все элементы в контейнере удовлетворяют условию лямбда-функции
bool checkAllOnes(const vector<unsigned short>& arr);
//Поиск самого покрывающего массива
unsigned findMostCompatieble(const vector<vector<unsigned short>>& matrix, const vector<unsigned short>& array);
//Поиск номеров конъюнктов с наибольшим покрытием
vector<unsigned short> findMostEfficientImplicants(const vector<vector<unsigned short>>& matrix);
//Вычеркивание лишнего из матрциы
vector<vector<unsigned short>> filterMatrix(const vector<vector<unsigned short>>& matrix, const vector<unsigned short>& core);
//Заполнение матрицы вывода значений на экран. Красивое
void fillOutputMatrix(const vector<vector<unsigned short>>& minArray, const vector<vector<unsigned short>>& PDNFarray);
//Проверка работоспособности
void testWork();
