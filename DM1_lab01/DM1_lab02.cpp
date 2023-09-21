#include <iostream>
#include <vector>
#include <cstdarg>
#include <Windows.h>
#include <random>
#include <array>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <string>
#include <tuple>





//#1
void fillArr() {

    const int SIZE = 1000;

    std::array<int, SIZE> A;

    for (size_t i = 0; i < A.size(); i++) {
        A[i] = i;
    }

    std::cout << "Розмір масиву А: " << A.size();

}

//#2 
std::vector<int> CreateArray(int count = 0, ...) {

    std::vector<int> result;

    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        result.push_back(value);
    }
    va_end(args);

    return result;
}

template <typename T>
void PrintArray(std::vector<T> array) {

    for (T i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

//#3
void QuickSort(std::vector<int>& arr, int left, int right, bool asc) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j <= right - 1; j++) {
            if ((asc && arr[j] <= pivot) || (!asc && arr[j] >= pivot)) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);

        int pivotIndex = i + 1;

        QuickSort(arr, left, pivotIndex - 1, asc);
        QuickSort(arr, pivotIndex + 1, right, asc);
    }
}

void sortArray(std::vector<int>& arr, const std::string& method) {

    bool ascending = method == "asc";
    bool descending = method == "desc";

    if (ascending) 
        QuickSort(arr, 0, arr.size() - 1, true);  

    else if (descending) 
        QuickSort(arr, 0, arr.size() - 1, false);
    
}

//#4
std::vector<int> CombineArray(const std::vector<int>& arr1, const std::vector<int>& arr2) {

    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        result.push_back(arr1[i] < arr2[j] ? arr1[i++] : arr2[j++]);
    }

    while (i < arr1.size()) {
        result.push_back(arr1[i++]);
    }

    while (j < arr2.size()) {
        result.push_back(arr2[j++]);
    }

    return result;
}

void IncludeArray(std::vector<int>& arr1, const std::vector<int>& arr2) {
    size_t i = arr1.size(), j = arr2.size(), k = arr1.size() + arr2.size();
    arr1.resize(k);

    while (j > 0) {
        arr1[--k] = (i > 0 && arr1[i - 1] > arr2[j - 1]) ? arr1[--i] : arr2[--j];
    }
}

//#5
std::vector<int> RandomArray(int N) {

    std::vector<int> result(N);
    std::vector<int> UsedNum(N + 1, 0);

    for (int i = 0; i < N; i++) {
        int RandNum = rand() % N + 1;

        while (UsedNum[RandNum] == 1) {
            RandNum = rand() % N + 1;
        }

        result[i] = RandNum;
        UsedNum[RandNum] = 1;
    }

    return result;
}

//#6 + #7
void ArrToMatrix() {

    const int N = 100; 
    const int rows = 10;
    const int cols = 10;

    std::vector<double> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = i + 1.0;
    }

    std::vector<std::vector<double>> b(rows, std::vector<double>(cols));

    int k = 0; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            b[i][j] = a[k++];
            
        }
    }

    std::cout << "Матриця B: " << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(5) <<b[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::string MatrixString;

    for (const auto& row : b) {
        for (double num : row) {
            MatrixString += std::to_string((int)num) + " ";
        }
    }

    std::cout << std::endl;
    std::cout << MatrixString << std::endl;


}

//#8 -

//#9
void Arr123() {


    std::vector<int> NewArr = {  };

    for (size_t i = 0; i < 10; i++) {

        for (size_t j = 1; j <= 3; j++) {
            NewArr.push_back(j);
        }

    }
    
    PrintArray(NewArr);

}

//#10
void ZeroMatrix() {

    const int rows = 10;
    const int cols = 10;

    int arr[rows][cols];

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << std::setw(4) <<arr[i][j];
        }
        std::cout << std::endl;
    }

}

//#11 + //#12
void MinMaxMatrix(int a) {
    
    const int rows = 3;
    const int cols = 3;

    int arr[rows][cols] = {

        {1,2,3},
        {2,3,4},
        {3,7,10},

    };

    std::vector<int> minElements = { };
    std::vector<int> maxElements = { };

    for (int i = 0; i < rows; i++) {
        int minElement = arr[i][0];
        int maxElement = arr[i][0];

        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < minElement) {
                minElement = arr[i][j];
            }

            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
            }
        }

        minElements.push_back(minElement);
        maxElements.push_back(maxElement);
    }

    std::cout << "Найменші значення в рядках: ";
    for (int element : minElements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Найбільші значення в рядках: ";
    for (int element : maxElements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    //#12
    std::vector<int>ElementsArray = { };
    int count = 0;

    for (size_t i = 0; i < (minElements.size() + maxElements.size()) / 2; i++) {
        if (minElements[i] < a) {
            count++;
        }
        if (maxElements[i] < a) {
            count++;
        }
    }

    std::cout << "Кількість елементів не більше за " << a << ": " << count << std::endl;

}

//#13
void UniqeWords() {

    std::vector<std::string> list1 = { "C++", "OOP", "SOLID", "TEST" };
    std::vector<std::string> list2 = { "C++", "PYTHON", "SOLID", "JAVA" };
    std::vector<std::string> result;


    for (const std::string& word : list1) {
        if (std::find(list2.begin(), list2.end(), word) == list2.end()) {
            result.push_back(word);
        }
    }

    for (const std::string& word : list2) {
        if (std::find(list1.begin(), list1.end(), word) == list1.end()) {
            result.push_back(word);
        }
    }

    PrintArray(result);

}

//#14
void MonthTuple() {

    std::vector<std::string> winter = { "Грудень", "Січень", "Дютий" };
    std::vector<std::string> spring = { "Березень", "Квітень", "Травень" };
    std::vector<std::string> summer = { "Червень", "Липень", "Серпень" };
    std::vector<std::string> autumn = { "Вересень", "Жовтень", "Листопад" };

    std::tuple<std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, std::vector<std::string>> seasons(winter, spring, summer, autumn);

 
    std::vector<std::string> SummerMonth = std::get<2>(seasons);

    std::cout << "Місяці літа: ";
    for (const std::string& month : SummerMonth) {
        std::cout << month << " ";
    }

}

//#15
bool CompareDate(const std::string& date1, const std::string& date2) {
    return date1 < date2;
}

class Student {

public:
    std::string name;
    std::string birthdate;

};

void DateSortTuple(const std::tuple<std::vector<Student>>& StudentTuple) {

    std::vector<Student> studentList = std::get<0>(StudentTuple);
    sort(studentList.begin(), studentList.end(), [](const Student& s1, const Student& s2) {
        return CompareDate(s1.birthdate, s2.birthdate);
        });

    for (const Student& student : studentList) {
        std::cout << "ПІБ: " << student.name << ", Дата народження: " << student.birthdate << std::endl;
    }

}

//#16
using PriceList = std::vector<std::tuple<std::string, double, int>>;
using Order = std::vector<std::pair<std::string, int>>;

double calculateOrderCost(std::vector<std::tuple<std::string, double, int>>& priceList, const Order& order) {
    double totalCost = 0.0;

    for (auto& item : order) {
        std::string itemName = item.first;
        int quantity = item.second;

        bool itemFound = false;

        for (auto& price : priceList) {
            if (std::get<0>(price) == itemName) {
                if (quantity > std::get<2>(price)) {
                    return -1.0;
                }
                else {
                    totalCost += std::get<1>(price) * quantity;
                    std::get<2>(price) -= quantity;
                    itemFound = true;
                    break;
                }
            }
        }

        if (!itemFound) {
            return -2.0;
        }
    }

    return totalCost;
}

//#17
//main - 483 строка

//#18

class Employee {
private:
    std::string name;
    int age;
    std::string position;
    double salary;

public:
    Employee(std::string n, int a, std::string p, double sal) : name(n), age(a), position(p), salary (sal) {
    }

    void displayInfo() {
        std::cout << "Ім'я: " << name << ", Вік: " << age << ", Посада: " << position << ", Зарплата: " << salary << " грн" << std::endl;
    }

    void setPay(double newPay) {
        this->salary = newPay;
    }


};


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    std::cout.setf(std::ios_base::boolalpha);
    srand(time(0));

    //#1
    //fillArr();

    //#2
    //std::vector<int> arr = CreateArray(5, 1, 2, 3, 4, 5);
    //PrintArray(arr);

    //#3
    /*std::vector<int> arr = {5, 1, 9, 3, 7, 6, 8, 2, 4};
    sortArray(arr, "asc"); //asc or desc
    PrintArray(arr);*/
 
    //#4
    /*std::vector<int> arr1 = {1, 3, 5, 7, 9};
    std::vector<int> arr2 = { 2, 4, 6, 8, 10 };

    std::vector<int> combArr = CombineArray(arr1, arr2);
    PrintArray(combArr);

    IncludeArray(arr1, arr2);
    PrintArray(arr1);*/
    
    //#5
    //std::vector<int> randomArr = RandomArray(10);
    //PrintArray(randomArr);
    
    //#6 + //#7
    //ArrToMatrix();
    
    //#8 -

    //#9
    //Arr123();

    //#10
    //ZeroMatrix();

    //#11 + 12
    //MinMaxMatrix(123);

    //#13
    //UniqeWords();

    //#14
    //MonthTuple();

    //#15
    /*std::tuple<std::vector<Student>> students = {
        {{"Людина Людинівна Людовченко", "22.12.1498"}, 
        {"Програміст Петро Кирильченко", "02.04.2020"}, 
        {"Вася Вася Васильович", "19.07.2006"}}
    };
    DateSortTuple(students);*/

    //#16
    /*PriceList priceList = {{"ХЛІБ", 10.0, 10}, {"МОЛОКО", 3.0, 20}, {"ЯЙЦЯ", 1.5, 30}, {"ПЕЧИВО", 13.5, 50}};
    Order order = { {"ХЛІБ", 3}, {"МОЛОКО", 2}, {"ЯЙЦЯ1", 10} };

    double totalCost = calculateOrderCost(priceList, order);

    if (totalCost == -1.0) {
        std::cout << "Запитується більше товару, ніж доступно." << std::endl;
    }
    else if (totalCost == -2.0) {
        std::cout << "Товару немає в прейскуранті." << std::endl;
    }
    else {
        std::cout << "Загальна вартість замовлення: " << totalCost << " грн." << std::endl;
    }*/

    //#17
    /*
    class Student {
        int phone_number;
        std::string email_address;
        std::string degree;
    }*/

    //#18
    Employee employee("Вася Васильович", 70, "Прибиральник", 10000.0);
    employee.setPay(15000.0);
    employee.displayInfo();
    

}
