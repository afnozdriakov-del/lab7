#include <iostream>
using namespace std;

// ===== КОНСТАНТИ =====
const int MIN_SIZE = 2;     // Мінімальний розмір матриці
const int MAX_SIZE = 20;    // Максимальний розмір матриці


// ===== ПРОТОТИПИ ФУНКЦІЙ =====
void task1();   // Завдання 1 (Matrix42)
void task2();   // Завдання 2 (Matrix60)

bool readSize(int &M, int &N);   // Зчитування розмірів матриці
void inputMatrix(int a[][MAX_SIZE], int M, int N);   // Введення матриці
void outputMatrix(const int a[][MAX_SIZE], int M, int N);   // Виведення матриці

int countIncreasingRows(const int a[][MAX_SIZE], int M, int N);  // Обчислення (Task1)
void mirrorMatrix(int a[][MAX_SIZE], int M, int N);              // Перетворення (Task2)


// ===== ГОЛОВНА ФУНКЦІЯ =====
int main() {
    int num;   // Номер завдання

    do {
        cout << "---------------------------------" << endl;
        cout << "1 - Task1 (Matrix42)" << endl;
        cout << "2 - Task2 (Matrix60)" << endl;
        cout << "0 - Exit" << endl;
        cout << "Task num -> ";
        cin >> num;

        switch(num) {
            case 0:
                cout << "Exit..." << endl;
                break;

            case 1:
                task1();
                break;

            case 2:
                task2();
                break;

            default:
                cout << "Wrong task num!" << endl;
        }

    } while(num != 0);

    return 0;
}


// ===== ЗАВДАННЯ 1 =====
// Кількість рядків, строго впорядкованих за зростанням
void task1() {
    int M, N;

    if (!readSize(M, N))
        return;

    int matrix[MAX_SIZE][MAX_SIZE];

    inputMatrix(matrix, M, N);

    int result = countIncreasingRows(matrix, M, N);

    cout << "Increasing rows count: " << result << endl;
}


// ===== ЗАВДАННЯ 2 =====
// Дзеркальне відображення відносно вертикальної осі
void task2() {
    int M, N;

    if (!readSize(M, N))
        return;

    int matrix[MAX_SIZE][MAX_SIZE];

    inputMatrix(matrix, M, N);

    mirrorMatrix(matrix, M, N);

    cout << "Mirrored matrix:" << endl;
    outputMatrix(matrix, M, N);
}


// ===== ЗЧИТУВАННЯ РОЗМІРУ =====
bool readSize(int &M, int &N) {
    cout << "Enter M and N: ";
    cin >> M >> N;

    if (M < MIN_SIZE || M > MAX_SIZE ||
        N < MIN_SIZE || N > MAX_SIZE) {
        cout << "Wrong size! Allowed range: "
             << MIN_SIZE << " - " << MAX_SIZE << endl;
        return false;
    }

    return true;
}


// ===== ВВЕДЕННЯ МАТРИЦІ =====
void inputMatrix(int a[][MAX_SIZE], int M, int N) {
    cout << "Enter matrix elements:" << endl;

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> a[i][j];
}


// ===== ВИВЕДЕННЯ МАТРИЦІ =====
void outputMatrix(const int a[][MAX_SIZE], int M, int N) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}


// ===== ОБЧИСЛЕННЯ ДЛЯ TASK1 =====
int countIncreasingRows(const int a[][MAX_SIZE], int M, int N) {
    int count = 0;

    for(int i = 0; i < M; i++) {
        bool increasing = true;

        for(int j = 0; j < N - 1; j++) {
            if(a[i][j] >= a[i][j + 1]) {
                increasing = false;
                break;
            }
        }

        if(increasing)
            count++;
    }

    return count;
}


// ===== ПЕРЕТВОРЕННЯ ДЛЯ TASK2 =====
void mirrorMatrix(int a[][MAX_SIZE], int M, int N) {
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N / 2; j++)
            swap(a[i][j], a[i][N - 1 - j]);
}
