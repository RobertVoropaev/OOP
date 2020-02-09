//
// Created by RobertVoropaev on 01.02.2016.
//


#include "Matrix.h"
#include "SquareMatrix.h"

using namespace std;

/*
 * Написать классы матрицы и квадратной матрицы.
 * Реализовать все часто используемые операции с матрицами: сложение матриц, умножение на число, перемножение матриц,
 * транспонирование, обращение к элементам матрицы по индексам, поиск детерминанта, операции ввода/вывода;
 * матрица размера 1х1 должна уметь преобразовываться в переменную типа элементов матрицы.
 *
 * Написать код, проверяющий корректность этих операций.
 * В парах вы реализовывали хранение матрицы в (ROWS+1) или в одном (двух) динамических массивах.
 * Помимо кода, демонстрирующего корректность ваших классов, каждый из вас пишет код, замеряющий время выполнения
 * множества операций создания/уничтожения и транспонирования матриц, и делает замеры времени выполнения на своей и
 * чужой реализации. Каждый присылает мне помимо написанного кода результаты сравнения скорости работы над двумя
 * реализациями матриц в виде нескольких таблиц 2х2, где по одному измерению - две реализации, по другому - два вида
 * тестируемых операций - создание/удаление и транспонирование, а в клетках таблицы - замеренное время.
 *
 * Создать несколько таких таблиц для различных порядков размера матрицы (10, 100, ...), чтобы понять,
 * на каких размерах в какой степени отличаются или не отличаются показания.
 */


int main() {
    cout << "Введите матрицу 2 на 3: " << endl;
    Matrix A(2, 3);
    cin >> A;

    A *= 3;
    cout << "Матрица умноженная на 3: " << endl << A;
    cout << "Транспонированная матрица: " << endl << transpose(A / 3);

    cout << "Введите квадратную матрицу 3 на 3: " << endl;
    SquareMatrix B(3);
    cin >> B;

    cout << "Определитель: " << det(B) << endl;

    bool noinverse;
    inverse(B, noinverse);
    if(noinverse) {
        cout << "Обратной матрицы не существует";
    } else {
        cout << "Обратная матрица: " << endl << inverse(B, noinverse);
    }
    return 0;
}