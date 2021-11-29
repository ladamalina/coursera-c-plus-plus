/*
 * Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение invalid_argument,
 * если знаменатель  равен нулю. Кроме того, переделайте реализацию оператора деления для класса Rational так,
 * чтобы он выбрасывал исключение domain_error, если делитель равен нулю.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

void CheckNonNegativeSizing(int num_rows, int num_cols) {
    if (num_rows < 0) {
        throw out_of_range("num_rows is out of range: " + to_string(num_rows));
    }
    if (num_cols < 0) {
        throw out_of_range("num_cols is out of range: " + to_string(num_cols));
    }
}

void CheckRangeSizing(int row, int col, int available_rows, int available_cols) {
    if (row > available_rows-1 or row < 0) {
        throw out_of_range("row is out of range: " + to_string(row) +
            ", available_rows: " + to_string(available_rows));
    }
    if (col > available_cols-1 or col < 0) {
        throw out_of_range("col is out of range: " + to_string(col) +
            ", available_cols: " + to_string(available_cols));
    }
}

class Matrix {
public:
    Matrix() {
        rows = 0;
        cols = 0;
    }

    Matrix(int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols) {
        CheckNonNegativeSizing(num_rows, num_cols);
        if (num_rows == 0 || num_cols == 0) {
            num_rows = num_cols = 0;
        }
        rows = num_rows;
        cols = num_cols;
        InitZeroes();
    }

    int& At(int row, int col) {
        CheckRangeSizing(row, col, rows, cols);
        return values[row][col];
    }

    int At(int row, int col) const {
        CheckRangeSizing(row, col, rows, cols);
        return values[row][col];
    }

    int GetNumRows() const {
        return rows;
    }

    int GetNumColumns() const {
        return cols;
    }

private:
    int rows;
    int cols;
    vector<vector<int>> values;

    void InitZeroes() {
        values = {};
        for (int r=0; r<rows; r++) {
            values.push_back({});
            for (int c=0; c<cols; c++) {
                if (c==0) {
                    values[r] = {};
                }
                values[r].push_back(0);
            }
        }
    }
};

bool operator==(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        return false;
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumColumns(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw invalid_argument("Mismatched number of columns");
    }

    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) + two.At(row, column);
        }
    }

    return result;
}

istream& operator>>(istream& in, Matrix& matrix) {
    int num_rows, num_columns;
    in >> num_rows >> num_columns;

    matrix.Reset(num_rows, num_columns);
    for (int row = 0; row < num_rows; ++row) {
        for (int column = 0; column < num_columns; ++column) {
            in >> matrix.At(row, column);
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << endl;
    }

    return out;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
