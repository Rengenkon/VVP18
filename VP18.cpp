#include <iostream>
/*
Задание 18

1. Даны массивы A и B одинакового размера N. Поменять местами их содержимое и вывести вначале элементы преобразованного массива A, а затем — элементы преобразованного массива B.
2. Дан массив A размера N. Сформировать новый массив B того же размера по следующему правилу: элемент BK равен среднему арифметическому элементов массива A с номерами от 1 до K.
3. Дан целочисленный массив размера N. Увеличить все нечетные числа, содержащиеся в массиве, на исходное значение последнего нечетного числа. Если нечетные числа в массиве отсутствуют, то оставить массив без изменений
4. Дан массив размера N. Обнулить элементы массива, расположенные между его минимальным и максимальным элементами (не включая минимальный и максимальный элементы).
5. Дан массив размера N, все элементы которого, кроме первого, упорядочены по возрастанию. Сделать массив упорядоченным, переместив первый элемент на новую позицию.

Каждая задача решена в отдельном классе
*/



class z1
{
private:
    int n;
    int* a;
    int* b;

public:

    z1(int size = 10) {
        n = size;
        a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
            b[i] = i + 1 + n;
        }
    }

    z1(int size, int* m) {
        n = size;
        a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
            b[i] = m[n - 1 - i];
        }
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";

        std::cout << "Массив 2:\n";
        for (int i = 0; i < n; i++) {
            std::cout << b[i] << ' ';
        }
        std::cout << "\n";
    }

    void svap() {
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = a[i];
            a[i] = b[i];
            b[i] = r;
        }
    }

    void test() {
        std::cout << "\n\nЗадача 1\n";
        print_arr();
        svap();
        print_arr();
    }
};

class z2
{
private:
    int n;
    int* a;
    double* b;

    int med(int l, int r) {
        int s = 0;
        for (int i = l; i < r + 1; i++) {
            s += a[i];
        }
        return s;
    }

public:

    z2(int size = 10) {
        n = size;
        a = new int[n];
        b = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }

    z2(int size, int* m) {
        n = size;
        a = new int[n];
        b = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
    }

    void print_arr_a() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void print_arr_b() {
        std::cout << "Массив 2:\n";
        for (int i = 0; i < n; i++) {
            std::cout << b[i] << ' ';
        }
        std::cout << "\n";
    }

    void mm() {
        for (int i = 0; i < n; i++) {
            b[i] = (double)med(0, i)/(i+1);
        }
    }

    void test() {
        std::cout << "\n\nЗадача 2\n";
        print_arr_a();
        mm();
        print_arr_b();
    }
};

class z3
{
private:
    int n;
    int* a;

public:

    z3(int size = 10) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }

    z3(int size, int* m) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void np() {
        int c = 0;
        for (int i = n - 1; i > -1; i--) {
            if (a[i] % 2 == 1) {
                if (c == 0) {
                    c = a[i];
                }
                a[i] = a[i] + c;
            }
        }
    }

    void test() {
        std::cout << "\n\nЗадача 3\n";
        print_arr();
        np();
        print_arr();
    }
};

class z4
{
private:
    int n;
    int* a;

public:

    z4(int size = 10) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }

    z4(int size, int* m) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void np() {
        int* max = NULL;
        int* min = NULL;
        for (int i = 0; i < n; i++) {
            if (max == NULL) {
                max = a + i;
            }
            if (min == NULL) {
                min = a + i;
            }
            if (*max < a[i]) {
                max = a + i;
            }
            if (*min > a[i]) {
                min = a + i;
            }
        }
        int l, r;
        if (max > min) {
            l = min - a + 1;
            r = max - a;
        }
        else {
            l = max - a + 1;
            r = min - a;
        }
        for (int i = l; i < r; i++) {
            a[i] = 0;
        }
    }

    void test() {
        std::cout << "\n\nЗадача 4\n";
        print_arr();
        np();
        print_arr();
    }
};

class z5
{
private:
    int n;
    int* a;

public:

    z5(int size = 10) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }

    z5(int size, int* m) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[i];
        }
    }

    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void np() {
        int i = 0;
        while (a[i] > a[i + 1]) {
            int t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
            i++;
        }
    }

    void test() {
        std::cout << "\n\nЗадача 5\n";
        print_arr();
        np();
        print_arr();
    }
};


int main()
{
    setlocale(LC_ALL, "rus");

    z1 first;
    z2 second;
    z3 third;
    z4 fourth;
    z5 fifth;

    first.test();
    second.test();
    third.test();
    fourth.test();
    fifth.test();

    return 0;
}
