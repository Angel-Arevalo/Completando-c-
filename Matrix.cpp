#include "VectorRn.cpp"
#include <time.h>
#include <cstdlib>
#include <stdexcept>

class Matrix {

    private:
        VectorRn* cMatrix;
        int rows, columns;
        double determinant;

        void freeMemory() {
            delete[] cMatrix;
        }
        // setters privates
        void setRows(int x) {
            this->rows = x;
        }

        void setColumns(int x) {
            this->columns = x;
        }

        static double abs(double x) {
            x = (x < 0)? -1*x: x;
            return x;
        }

        static double getDeterminant(const Matrix& w) {
            if (w.rows == w.columns && w.rows != 0) {
                if (w.rows == 1) {
                    return w.cMatrix[0][0];
                }if (w.rows == 2) {
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
            }else return 0;
        }

    public:
        Matrix() : cMatrix(nullptr), rows(0), columns(0) {}

        // setters and getters
        int getRows() {
            return this->rows;
        }

        int getColumns() {
            return this->columns;
        }

        double getdeterminant() {
            return this->determinant;
        }

        // fill the matrix with this static-methods

        void setMatrix(const Matrix& w) {
            *this = w;
        }

        static void setMatrixIdenty(Matrix& w, int rows) {
            Matrix::setMatrixIdenty(w, rows, 1.0);
        }

        static void setMatrixIdenty(Matrix& w, int rows, double x) {
            w.rows = rows;
            w.columns = rows;

            w.cMatrix = new VectorRn[rows];
            for (int i = 0; i < w.rows; i++) {
                double* ColumnRow = new double[w.columns];
                for (int j = 0; j < w.columns; j++) {
                    if (j == i) ColumnRow[j] = x;
                    else ColumnRow[j] = 0;
                }
                w.cMatrix[i] = VectorRn(ColumnRow, w.columns);
                delete[] ColumnRow;
            }
            w.determinant = Matrix::getDeterminant(w);
            std::cout << w;
        }

        static void readEntriesCin(Matrix& w, int rows, int columns) {
            w.freeMemory();
            w.rows = rows;
            w.columns = columns;

            w.cMatrix = new VectorRn[rows];
            for (int i = 0; i < rows; i++) {
                std::cout << "Enter the row " << i << std::endl;
                double* ColumnRow = new double[columns];
                for (int j = 0; j < columns; j++) {
                    std::cin >> ColumnRow[j];
                }
                w.cMatrix[i] = VectorRn(ColumnRow, columns);
                delete[] ColumnRow;
            }
            w.determinant = Matrix::getDeterminant(w);
        }

        static void readEntriesCin(Matrix& w, int rows) {
            Matrix::readEntriesCin(w, rows, rows);
        }

        static void readEntriesCin(Matrix& w) {
            int rows, columns;
            std::cout << "Enter the number of rows" << std::endl;
            std::cin >> rows;
            std::cout << "Enter the number of columns" << std::endl;
            std::cin >> columns;
            Matrix::readEntriesCin(w, rows, columns);
        }

        static void setRandmatrix(Matrix& w, int rows, int columns) {
            w.freeMemory();
            srand(time(0));
            w.rows = rows;
            w.columns = columns;

            w.cMatrix = new VectorRn[rows];
            for (int i = 0; i < rows; i++) {
                double* ColumnRow = new double[columns];
                for (int j = 0; j < columns; j++) {
                    ColumnRow[j] = rand() /(rand() + 1.0);
                }
                w.cMatrix[i] = VectorRn(ColumnRow, columns);
                delete[] ColumnRow;
            }
            w.determinant = Matrix::getDeterminant(w);
        }

        static void setRandmatrix(Matrix& w, int rows) {
            Matrix::setRandmatrix(w, rows, rows);
        }

            // this function create a array of integers numbers
        static void setRandmatrixInt(Matrix& w, int rows, int columns) {
            w.freeMemory();
            srand(time(0));
            w.rows = rows;
            w.columns = columns;

            w.cMatrix = new VectorRn[rows];
            for (int i = 0; i < rows; i++) {
                double* ColumnRow = new double[columns];
                for (int j = 0; j < columns; j++) {
                    ColumnRow[j] = rand();
                }
                w.cMatrix[i] = VectorRn(ColumnRow, columns);
                delete[] ColumnRow;
            }
            w.determinant = Matrix::getDeterminant(w);
        }

        static void setRandmatrixInt(Matrix& w, int rows) {
            Matrix::setRandmatrixInt(w, rows, rows);
        }

            // get the matrix on other way
        static Matrix getMatrixtranspose(const Matrix& q) {
            Matrix w;
            w.setColumns(q.rows);
            w.setRows(q.columns);
            w.cMatrix = new VectorRn[q.columns];
            w.determinant = q.determinant;
            for (int i = 0; i < q.columns; i++) {
                double* arrayHelper = new double[q.rows];
                for (int j = 0; j < q.rows; j++) {
                    arrayHelper[j] = q.cMatrix[j][i];
                }
                w.cMatrix[i] = VectorRn(arrayHelper, q.rows);
                delete[] arrayHelper;
            }
            return w;
        }

        // operations with matrix
        static Matrix getMatrixInv(const Matrix& w) {
            if (w.rows != w.columns || w.rows == 0 || w.determinant == 0) {
                throw std::invalid_argument("Invalid matrix.");
            }

            Matrix wInv;
            wInv.rows = w.rows;
            wInv.columns = w.rows;
            wInv.determinant = 1./w.determinant;
            wInv.cMatrix = new VectorRn[w.rows];

            if (w.rows == w.columns && w.rows == 1) {
                double row[] = {1./(w.cMatrix[0][0])};// this array is used to can create the VectorRn object
                wInv.cMatrix[0] = VectorRn(row, 1);
                return wInv;
            }

            for (int i = 0; i < w.rows; i++) {// to travel around the rows of the matrix
                double* cofactorRow = new double[w.rows];
                for (int j = 0; j < w.rows; j++) {
                    Matrix Minor;
                    Minor.rows = w.rows - 1;
                    Minor.columns = w.rows - 1;
                    Minor.cMatrix = new VectorRn[Minor.rows];
                    int dom = 0;
                    for (int k = 0; k < w.rows; k++) {
                        if (k != i) {
                            double* rowMinor = new double[Minor.rows];
                            int counter = 0;
                            for (int l = 0; l < w.rows; l++) {
                                if (l != j) {
                                    rowMinor[counter++] = w.cMatrix[k][l];
                                }
                            }
                            Minor.cMatrix[dom++] = VectorRn(rowMinor, Minor.rows);
                            delete[] rowMinor;
                        }
                    }
                    double s = ((i + j)% 2 == 0)? 1. : -1.;
                    cofactorRow[j] = s * Matrix::getDeterminant(Minor);
                }
                wInv.cMatrix[i] = VectorRn(cofactorRow, w.rows);
                delete[] cofactorRow;
            }
            return (1/(w.determinant) * Matrix::getMatrixtranspose(wInv));
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
                        double s = (Matrix::abs(result) < 0.002)? 0.: result;
                        row[k] = s;
                    }
                    toReturn.cMatrix[i] = VectorRn(row, z.columns);
                    delete[] row;
                }

                return toReturn;
            }else throw std::invalid_argument("Don't match the columns and the rows.");
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
            for (int i = 0; i < matrix.rows; i++) {
                os << matrix.cMatrix[i];
            }
            os << "\n";
            return os;
        }
        friend void operator>>(std::istream& is, Matrix& w) {
            Matrix::readEntriesCin(w);
        }
};
