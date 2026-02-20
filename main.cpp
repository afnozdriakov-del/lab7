#include <iostream>

using namespace std;

// ===== КОНСТАНТИ =====
const int MIN_SIZE = 2;
const int MAX_SIZE = 20;

// ===== ПРОТОТИПИ ФУНКЦІЙ =====
void showMenu();
bool readSize(int &M, int &N);
void inputMatrix(int a[][MAX_SIZE], int M, int N);
void outputMatrix(const int a[][MAX_SIZE], int M, int N);

int countIncreasingRows(const int a[][MAX_SIZE], int M, int N);
void mirrorMatrix(int a[][MAX_SIZE], int M, int N);

void executeTask(int choice);

// ===== ГОЛОВНА ФУНКЦІЯ =====
int main()
{
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        if (choice == 0)
        {
            cout << "Програму завершено.\n";
        }
        else if (choice == 1 || choice == 2)
        {
            executeTask(choice);
        }
        else
        {
            cout << "Помилка! Неправильний пункт меню.\n";
        }

    } while (choice != 0);

    return 0;
}

// ===== ВИВЕДЕННЯ МЕНЮ =====
void showMenu()
{
    cout << "\n========== МЕНЮ ==========\n";
    cout << "1 - Завдання 1 (Matrix42)\n";
    cout << "2 - Завдання 2 (Matrix60)\n";
    cout << "0 - Вихід\n";
    cout << "Ваш вибір: ";
}

// ===== ЗЧИТУВАННЯ РОЗМІРУ =====
bool readSize(int &M, int &N)
{
    cout << "Введіть кількість рядків M та стовпців N: ";
    cin >> M >> N;

    if (M < MIN_SIZE || M > MAX_SIZE ||
        N < MIN_SIZE || N > MAX_SIZE)
    {
        cout << "Помилка! Розміри повинні бути в межах ["
             << MIN_SIZE << "; " << MAX_SIZE << "].\n";
        return false;
    }

    return true;
}

// ===== ВВЕДЕННЯ МАТРИЦІ =====
void inputMatrix(int a[][MAX_SIZE], int M, int N)
{
    cout << "Введіть елементи матриці:\n";

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
}

// ===== ВИВЕДЕННЯ МАТРИЦІ =====
void outputMatrix(const int a[][MAX_SIZE], int M, int N)
{
    cout << "Матриця:\n";

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

// ===== ЗАВДАННЯ 1 =====
// Кількість рядків, строго впорядкованих за зростанням
int countIncreasingRows(const int a[][MAX_SIZE], int M, int N)
{
    int count = 0;

    for (int i = 0; i < M; i++)
    {
        bool isIncreasing = true;

        for (int j = 0; j < N - 1; j++)
        {
            if (a[i][j] >= a[i][j + 1])
            {
                isIncreasing = false;
                break;
            }
        }

        if (isIncreasing)
            count++;
    }

    return count;
}

// ===== ЗАВДАННЯ 2 =====
// Дзеркальне відображення відносно вертикальної осі
void mirrorMatrix(int a[][MAX_SIZE], int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[i][N - 1 - j];
            a[i][N - 1 - j] = temp;
        }
    }
}

// ===== ВИКОНАННЯ ОБРАНОГО ЗАВДАННЯ =====
void executeTask(int choice)
{
    int M, N;

    if (!readSize(M, N))
        return;

    int matrix[MAX_SIZE][MAX_SIZE];

    inputMatrix(matrix, M, N);

    if (choice == 1)
    {
        int result = countIncreasingRows(matrix, M, N);

        cout << "Кількість рядків, впорядкованих за зростанням: "
             << result << endl;
    }
    else if (choice == 2)
    {
        mirrorMatrix(matrix, M, N);

        cout << "Матриця після дзеркального відображення:\n";
        outputMatrix(matrix, M, N);
    }
}
