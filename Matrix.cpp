#include "VectorRn.cpp"
#include <time.h>
#include <cstdlib>
#include <stdexcept>

class Matrix {

    private:
        VectorRn* cMatrix;
        int rows, columns;

        void freeMemory() {
            delete[] cMatrix;
        }
    public:
        Matrix() : cMatrix(nullptr), rows(0), columns(0) {}

        void setMatrixIdenty(int rows) {
            this->setMatrixIdenty(rows, 1.0);
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
            freeMemory();
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
            freeMemory();
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
        void setRandmatrix(int rows) {
            this->setRandmatrix(rows, rows);
        }

        friend Matrix operator+(const Matrix& w, const Matrix& z) {
            if(w.rows == z.rows && w.columns == z.columns) {
                Matrix toReturn;
                toReturn.rows = w.rows;
                toReturn.columns = z.columns;
                toReturn.cMatrix = new VectorRn[w.rows];
                for (int i = 0; i < w.rows; i++) {
                    toReturn.cMatrix[i] = (w.cMatrix[i] + z.cMatrix[i]);
                }
                return toReturn;
            }else throw std::invalid_argument("Don't match the dimensions of the matrix");
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
            for (int i = 0; i < matrix.rows; i++) {
                os << matrix.cMatrix[i];
            }
            os << "\n";
            return os;
        }
};
