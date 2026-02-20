#include <iostream>

using namespace std;

// ----- Константи -----
const int MIN_SIZE = 2;      // Мінімально допустимий розмір матриці
const int MAX_SIZE = 20;     // Максимально допустимий розмір матриці

// ----- Прототипи функцій -----
void showMenu();                                     // Виведення меню
bool readSize(int &M, int &N);                       // Зчитування розмірів матриці
void inputMatrix(int a[][MAX_SIZE], int M, int N);   // Введення матриці
void outputMatrix(const int a[][MAX_SIZE], int M, int N); // Виведення матриці

int countIncreasingRows(const int a[][MAX_SIZE], int M, int N); // Завдання 1
void mirrorMatrix(int a[][MAX_SIZE], int M, int N);              // Завдання 2

void executeTask(int choice);                       // Виконання обраного завдання


// ===== ГОЛОВНА ФУНКЦІЯ ПРОГРАМИ =====
int main()
{
    int choice;   // Змінна для вибору пункту меню

    do
    {
        showMenu();        // Виведення меню
        cin >> choice;     // Зчитування вибору користувача

        switch (choice)
        {
            case 1:
            case 2:
                executeTask(choice);   // Виконання відповідного завдання
                break;

            case 0:
                cout << "Програму завершено.\n";
                break;

            default:
                cout << "Помилка! Неправильний пункт меню.\n";
        }

    } while (choice != 0);

    return 0;   // Успішне завершення програми
}


// ===== ФУНКЦІЯ ВИВЕДЕННЯ МЕНЮ =====
void showMenu()
{
    cout << "\n========== МЕНЮ ==========\n";
    cout << "1 - Завдання 1 (Matrix42)\n";
    cout << "2 - Завдання 2 (Matrix60)\n";
    cout << "0 - Вихід\n";
    cout << "Ваш вибір: ";
}


// ===== ФУНКЦІЯ ЗЧИТУВАННЯ РОЗМІРУ МАТРИЦІ =====
bool readSize(int &M, int &N)
{
    cout << "Введіть кількість рядків M та стовпців N: ";
    cin >> M >> N;

    // Перевірка допустимості розмірів
    if (M < MIN_SIZE || M > MAX_SIZE ||
        N < MIN_SIZE || N > MAX_SIZE)
    {
        cout << "Помилка! Розміри повинні бути в межах ["
             << MIN_SIZE << "; " << MAX_SIZE << "].\n";
        return false;   // Повертаємо false у випадку помилки
    }

    return true;        // Розміри введені коректно
}


// ===== ФУНКЦІЯ ВВЕДЕННЯ МАТРИЦІ =====
void inputMatrix(int a[][MAX_SIZE], int M, int N)
{
    cout << "Введіть елементи матриці:\n";

    for (int i = 0; i < M; i++)         // Перебір рядків
    {
        for (int j = 0; j < N; j++)     // Перебір стовпців
        {
            cin >> a[i][j];             // Зчитування елемента
        }
    }
}


// ===== ФУНКЦІЯ ВИВЕДЕННЯ МАТРИЦІ =====
void outputMatrix(const int a[][MAX_SIZE], int M, int N)
{
    cout << "Матриця:\n";

    for (int i = 0; i < M; i++)         // Перебір рядків
    {
        for (int j = 0; j < N; j++)     // Перебір стовпців
        {
            cout << a[i][j] << "\t";    // Виведення елемента
        }
        cout << endl;                   // Перехід на новий рядок
    }
}


// ===== ЗАВДАННЯ 1 =====
// Обчислення кількості рядків, строго впорядкованих за зростанням
int countIncreasingRows(const int a[][MAX_SIZE], int M, int N)
{
    int count = 0;   // Лічильник впорядкованих рядків

    for (int i = 0; i < M; i++)     // Перебір рядків
    {
        bool isIncreasing = true;   // Припускаємо, що рядок впорядкований

        for (int j = 0; j < N - 1; j++)   // Перевірка сусідніх елементів
        {
            if (a[i][j] >= a[i][j + 1])
            {
                isIncreasing = false;     // Порушено порядок зростання
                break;
            }
        }

        if (isIncreasing)
            count++;   // Збільшуємо лічильник
    }

    return count;      // Повертаємо результат
}


// ===== ЗАВДАННЯ 2 =====
// Дзеркальне відображення матриці відносно вертикальної осі
void mirrorMatrix(int a[][MAX_SIZE], int M, int N)
{
    for (int i = 0; i < M; i++)         // Перебір рядків
    {
        for (int j = 0; j < N / 2; j++) // Обмін елементів
        {
            int temp = a[i][j];             // Тимчасове збереження
            a[i][j] = a[i][N - 1 - j];      // Переносимо симетричний елемент
            a[i][N - 1 - j] = temp;         // Записуємо збережене значення
        }
    }
}


// ===== ФУНКЦІЯ ВИКОНАННЯ ОБРАНОГО ЗАВДАННЯ =====
void executeTask(int choice)
{
    int M, N;   // Розміри матриці

    if (!readSize(M, N))   // Якщо введено некоректні розміри
        return;

    int matrix[MAX_SIZE][MAX_SIZE];  // Оголошення матриці

    inputMatrix(matrix, M, N);       // Введення матриці

    if (choice == 1)                 // Виконання першого завдання
    {
        int result = countIncreasingRows(matrix, M, N);

        cout << "Кількість рядків, впорядкованих за зростанням: "
             << result << endl;
    }
    else if (choice == 2)            // Виконання другого завдання
    {
        mirrorMatrix(matrix, M, N);

        cout << "Матриця після дзеркального відображення:\n";
        outputMatrix(matrix, M, N);
    }
}
