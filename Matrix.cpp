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

        static double getDeterminant(const Matrix& w) {
            if (w.rows == 1) {
                return w.cMatrix[0][0];
            }else if (w.rows == w.columns && w.rows != 0) {
                if (w.rows == 2) {
                    return w.cMatrix[0][0] * w.cMatrix[1][1] - w.cMatrix[0][1] * w.cMatrix[1][0];
                }else {
                    double toReturn = 0;
                     for (int k = 0; k < w.rows; k++) {
                        Matrix Minnor;
                        Minnor.rows = w.rows - 1;
                        Minnor.columns = w.columns - 1;
                        Minnor.cMatrix = new VectorRn[w.rows - 1];

                        for (int i = 1; i < w.rows; i++) {
                            double* rows = new double[w.rows - 1];
                            int counter = 0;
                            for (int j = 0; j < w.rows; j++) {
                                if( k != j) {
                                    rows[counter++] = w.cMatrix[i][j];
                                }
                            }
                            Minnor.cMatrix[i - 1] = VectorRn(rows, w.rows - 1);
                            delete[] rows;
                        }
                        double s = (k % 2 == 0)? 1 : -1;
                        toReturn += w.cMatrix[0][k] * s * Matrix::getDeterminant(Minnor);
                        Minnor.freeMemory();
                    }
                    return toReturn;
                }
            }else throw std::invalid_argument("Is't a square matrix");
        }

        void setMatrix(const Matrix& w) {
            *this = w;
        }

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
                    ColumnRow[j] = rand() /(rand() + 1.0);
                }
                cMatrix[i] = VectorRn(ColumnRow, this->columns);
                delete[] ColumnRow;
            }
        }
        void setRandmatrix(int rows) {
            this->setRandmatrix(rows, rows);
        }

        Matrix getMatrixtranspose() const {
            Matrix w;
            w.setColumns(this->rows);
            w.setRows(this->columns);
            w.cMatrix = new VectorRn[this->columns];
            for (int i = 0; i < this->columns; i++) {
                double* arrayHelper = new double[this->rows];
                for (int j = 0; j < this->rows; j++) {
                    arrayHelper[j] = this->cMatrix[j][i];
                }
                w.cMatrix[i] = VectorRn(arrayHelper, this->rows);
                delete[] arrayHelper;
            }
            return w;
        }

        // setters and getters
        int getRows() {
            return this->rows;
        }

        int getColumns() {
            return this->columns;
        }
        void setRows(int x) {
            this->rows = x;
        }

        void setColumns(int x) {
            this->columns = x;
        }
        // override the operators

        void operator=(const Matrix& w) {
            this->setMatrix(w);
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

        friend Matrix operator*(double x, const Matrix& w) {
            Matrix toReturn;
            toReturn.rows = w.rows;
            toReturn.columns = w.columns;
            toReturn.cMatrix = new VectorRn[w.rows];
            for (int i = 0; i < w.rows; i++) {
                toReturn.cMatrix[i] = x * (w.cMatrix[i]);
            }
            return toReturn;
        }
        friend Matrix operator*(const Matrix& w, double x) {
            return x * w;
        }
        friend Matrix operator*(const Matrix& w, int x) {
            double z = x;
            return z * w;
        }
        friend Matrix operator*(int x, const Matrix& w) {
            double z = x;
            return z * w;
        }
        friend Matrix operator*(const Matrix& w, float x) {
            double z = x;
            return z * w;
        }
        friend Matrix operator*(float x, const Matrix& w) {
            double z = x;
            return z * w;
        }

        friend Matrix operator*(const Matrix& w,const Matrix& z) {
            if (w.columns == z.rows) {
                Matrix toReturn;
                toReturn.rows = w.rows;
                toReturn.columns = z.columns;
                toReturn.cMatrix = new VectorRn[w.rows];

                for (int i = 0; i < w.rows; i++) {// this go around of the rows of the matrix w
                    double* row = new double[z.columns];
                    for (int k = 0; k < z.columns; k++) {// this go around of the columns of the matrix z
                        double result = 0;
                        for (int j = 0; j < z.rows; j++) {
                             result += w.cMatrix[i][j] * z.cMatrix[j][k];
                        }
                        row[k] = result;
                    }
                    toReturn.cMatrix[i] = VectorRn(row, z.columns);
                    delete[] row;
                }

                return toReturn;
            }else {throw std::invalid_argument("Don't match the columns and the rows.");}
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
            for (int i = 0; i < matrix.rows; i++) {
                os << matrix.cMatrix[i];
            }
            os << "\n";
            return os;
        }
};
