#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int max_rand = 10;

void arr_read(int*, int);
void arr_ins(int);
void arr_print(int*, int);
void push_back_arr(int*&, int&);
void push_front_arr(int*&, int&);
void delete_back_arr(int*&, int&);
void delete_front_arr(int*&, int&);
void push_k_arr(int*&, int&);
void delete_k_arr(int*&, int&);
void push_value_arr(int*&, int&);
void delete_value_arr(int*&, int&);

int main()
{
    //srand(time(NULL));
    int N;
    int size_arr;
    setlocale(0, "");
    cout << "Введите размер массива: ";
    cin >> size_arr;
    //if (size_arr - (int)size_arr!=0) { cout << "Введите целое число" << endl;}

    int* arr = new int[size_arr];
    arr_ins(size_arr);
    arr_read(arr, size_arr);
    arr_print(arr, size_arr);
    cout << endl;

    do {
        cout << "\n\nВыберите номер задания для выполнения:\n1) добавить элемент в конец массива\n2) добавить элемент в начало массива\n3) добавить элемент на k-ую позицию в массиве";
        cout << "\n4) удалить последний элемент массива\n5) удалить первый элемент массива\n6) удалить k-ый элемент массива\n7) добавить элемент массива после первого встреченного элемента с заданным значением\n8) удалить все элементы массива с заданным значением\
            \nЗадание: "; cin >> N; cout << "\n";

        if (N == 1) push_back_arr(arr, size_arr);
        if (N == 2) push_front_arr(arr, size_arr);
        if (N == 3) push_k_arr(arr, size_arr);
        if (N == 4) delete_back_arr(arr, size_arr);
        if (N == 5) delete_front_arr(arr, size_arr);
        if (N == 6) delete_k_arr(arr, size_arr);
        if (N == 7) push_value_arr(arr, size_arr);
        if (N == 8) delete_value_arr(arr, size_arr);




        cout << "\n";
        arr_print(arr, size_arr);
    } while (N != 0);




    arr_print(arr, size_arr);
    return 0;

}




void arr_ins(int n) {
    fstream f_out("arr.txt");
    for (int i = 0; i < n; i++) {
        f_out << rand() % max_rand << " ";
    }
    f_out.close();
}

void arr_read(int* arr, int n) {
    fstream f_in("arr.txt");
    if (f_in) {
        for (int i = 0; i < n; i++) {
            f_in >> arr[i];
        }
        f_in.close();
    }
}

void arr_print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout  << arr[i] << endl;
    }

}

void push_back_arr(int*& arr, int& n) {
    int k;
    cout << "Сколько элементов массива добавить в конец массива: ";
    cin >> k;
    int* newArray = new int[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i] = arr[i];
    }
    cout << "Введите добавляемые элементы, " << k << " штук: " << endl;
    for (int i = n; i < (n + k); i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}
void push_front_arr(int*& arr, int& n)
{
    int k;
    cout << "Сколько элементов массива добавить в начало массива: ";
    cin >> k;
    int* newArray = new int[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i + k] = arr[i];
    }
    cout << "Введите добавляемые элементы, " << k << " штук: " << endl;
    for (int i = 0; i < k; i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}

void delete_back_arr(int*& arr, int& n)
{
    int k;
    cout << "Сколько элементов массива удалить в конце массива: ";
    cin >> k;
    int* newArray = new int[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}


void delete_front_arr(int*& arr, int& n)
{
    int k;
    cout << "Количество элементов для удаления в начале массива: ";
    cin >> k;
    int* newArray = new int[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i + k];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}

void push_k_arr(int*& arr, int& n)
{
    int k;
    cout << "На какое место (всего мест " << n << ") массива добавить элемент: ";
    cin >> k;
    int* newArray = new int[n + 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    cout << "Введите элемент для добавления: ";
    cin >> newArray[k - 1];
    for (int i = k; i < (n + 1); i++)
    {
        newArray[i] = arr[i - 1];
    }
    delete[]arr;
    arr = newArray;
    n++;
}

void delete_k_arr(int*& arr, int& n)
{
    int k;
    cout << "Какой элемент (всего элементов " << n << " штук) массива удалить (введите номер от 1, до " << n << "): ";
    cin >> k;
    int* newArray = new int[n - 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    for (int i = (k - 1); i < (n - 1); i++)
    {
        newArray[i] = arr[i + 1];
    }
    delete[]arr;
    arr = newArray;
    n--;
}

void push_value_arr(int*& arr, int& n)
{
    int k, result = 0, buf;
    cout << "После какого какого встреченного в массиве значения добавить элемент: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k) { result = 1; buf = i; break; }
    }
    if (result == 1) {
        int* newArray = new int[n + 1];
        for (int i = 0; i < (buf + 1); i++)
        {
            newArray[i] = arr[i];
        }
        cout << "Введите добавляемый элемент: ";
        cin >> newArray[buf + 1];
        for (int i = buf + 2; i < (n + 1); i++)
        {
            newArray[i] = arr[i - 1];
        }
        delete[]arr;
        arr = newArray;
        n++;
    }
    else
    {
        cout << "Произошла ошибка (Элемент с таким значением не найден)" << endl;
    }

}

void delete_value_arr(int*& arr, int& n)
{
    int k, result = 0, buf = 0, buf2 = 0;
    cout << "Элементы с каким значением удалить: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k) { result = 1; buf++; }
    }
    if (result == 1)
    {
        int* newArray = new int[n - buf];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != k)
            {
                newArray[i - buf2] = arr[i];
            }
            else
            {
                buf2++;
                continue;
            }
        }
        delete[]arr;
        arr = newArray;
        n -= buf;
    }
    else
    {
        cout << "Произошла ошибка (Элемент с таким значением не найден)" << endl;
    }
}