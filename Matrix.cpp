#include "VectorRn.cpp"
#include <iostream>
#include <time.h>
#include <cstdlib>

class Matrix {

    private:
        VectorRn* cMatrix;
        int rows, columns;

    public:
        Matrix() : cMatrix(nullptr), rows(0), columns(0) {}

        Matrix(int rows) {
            this->rows = rows;
            this->columns = rows;

            cMatrix = new VectorRn[rows];
            for (int i = 0; i < this->rows; i++) {
                double* ColumnRow = new double[this->columns];
                for (int j = 0; j < this->columns; j++) {
                    if (j == i) ColumnRow[j] = 1;
                    else ColumnRow[j] = 0;
                }
                cMatrix[i] = VectorRn(ColumnRow, this->columns);
                delete[] ColumnRow;
            }
        }

        void setMatrixIdenty(int rows, double x) {
            this->rows = rows;
            this->columns = rows;

            cMatrix = new VectorRn[rows];
            for (int i = 0; i < this->rows; i++) {
                double* ColumnRow = new double[this->columns];
                for (int j = 0; j < this->columns; j++) {
                    if (j == i) ColumnRow[j] = x;
                    else ColumnRow[j] = 0;
                }
                cMatrix[i] = VectorRn(ColumnRow, this->columns);
                delete[] ColumnRow;
            }
        }

        void readEntriesCin(int rows, int columns) {
            this->rows = rows;
            this->columns = columns;

            cMatrix = new VectorRn[rows];
            for (int i = 0; i < this->rows; i++) {
                std::cout << "Enter the row " << i << std::endl;
                double* ColumnRow = new double[this->columns];
                for (int j = 0; j < this->columns; j++) {
                    std::cin >> ColumnRow[j];
                }
                cMatrix[i] = VectorRn(ColumnRow, this->columns);
                delete[] ColumnRow;
            }
        }

        void setRandmatrix(int rows, int columns) {
            srand(time(0));
            this->rows = rows;
            this->columns = columns;

            cMatrix = new VectorRn[rows];
            for (int i = 0; i < this->rows; i++) {
                double* ColumnRow = new double[this->columns];
                for (int j = 0; j < this->columns; j++) {
                    ColumnRow[j] = rand();
                }
                cMatrix[i] = VectorRn(ColumnRow, this->columns);
                delete[] ColumnRow;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
            for (int i = 0; i < matrix.rows; i++) {
                os << matrix.cMatrix[i];
            }
            os << "\n";
            return os;
        }
};
