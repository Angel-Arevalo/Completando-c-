#include <iostream>
#include <stdexcept>
#include <cstdlib>

class VectorRn  {
    private:
        int dimension = 0;
        double* vector;
        bool start = false;

    public:
        VectorRn() = default;

        VectorRn(const VectorRn& w) {
            this->dimension = w.dimension;
            this->vector = new double[this->dimension];

            for (int i = 0; i < this->dimension; i++) {
                this->vector[i] = w.vector[i];
            }
        }

        VectorRn(double* array, int dimension) {
            if (!start) {
                this->dimension = dimension;
                this->vector = new double[dimension];

                for (int i = 0; i < dimension; i++) {
                    this->vector[i] = array[i];
                }
                this->start = true;
            }else {
                std::runtime_error("This object already has been declarated");
            }
        }

        VectorRn(int* array, int dimension) {
            this->dimension = dimension;
            this->vector = new double[dimension];

            for (int i = 0; i < dimension; i++) {
                double x = array[i];
                this->vector[i] = x;
            }
        }
        VectorRn(float* array, int dimension) {
            this->dimension = dimension;
            this->vector = new double[dimension];

            for (int i = 0; i < dimension; i++) {
                double x = array[i];
                this->vector[i] = x;
            }
        }

        void setVectorRn(const VectorRn& w) {
            this->dimension = w.dimension;
            this->vector = new double[this->dimension];

            for (int i = 0; i < this->dimension; i++) {
                this->vector[i] = w.vector[i];
            }
        }

        int getDimension() {
            return this->dimension;
        }

        double* getVector() {
            return this->vector;
        }

        VectorRn operator+(VectorRn w) {
            int q = w.getDimension();
            if (this->dimension == q) {
                double* vectorW = w.getVector();
                double* z = new double[q];
                for (int i = 0; i < q; i++) {
                    double indexV1 = this->vector[i];
                    double indexV2 = vectorW[i];
                    z[i] = indexV1 + indexV2;
                }
                VectorRn toReturn(z, q);
                delete[] vectorW, z;
                return toReturn;
            }else {
                std::cout << "Unsupported dimensions";
                std::exit(1);
            }
        }

        // the product point
        double operator*(VectorRn w) {
            int q = w.getDimension();
            if (this->dimension == q) {
                double* vectorW = w.getVector();
                double z = 0;
                for (int i = 0; i < q; i++) {
                    double indexV1 = this->vector[i];
                    double indexV2 = vectorW[i];
                    z += indexV1 * indexV2;
                }
                delete[] vectorW;
                return z;
            }else {
                std::cout << "Unsupported dimensions";
                std::exit(1);
            }
        }

        void operator=(const VectorRn& w) {
            this->setVectorRn(w);
        }

        friend VectorRn operator*(double scalar, const VectorRn& v) {
            double* result = new double[v.dimension];
            for (int i = 0; i < v.dimension; ++i) {
                double w = v.vector[i];
                result[i] = scalar * w;
            }
            VectorRn toReturn(result, v.dimension);
            delete[] result;
            return toReturn;
        }
        friend VectorRn operator*(const VectorRn& v, double scalar) {
            return scalar * v;
        }

        friend VectorRn operator%(const VectorRn& v, const VectorRn& w) {
            if (v.dimension == w.dimension && v.dimension == 3) {
                double result[3] = {
                    v.vector[1] * w.vector[2] - v.vector[2] * w.vector[1],
                    v.vector[2] * w.vector[0] - v.vector[0] * w.vector[2],
                    v.vector[0] * w.vector[1] - v.vector[1] * w.vector[0]
                };
                return VectorRn(result, 3);
            }else {
                std::cout<< "Not match dimensions";
                std::exit(1);
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const VectorRn& vecto) {
            os << '[';

            for (int i = 0; i < vecto.dimension; ++i) {
            os << vecto.vector[i];
            if (i < vecto.dimension - 1) {
                os << ' ';
            }
        }
            os << ']';
            os << "\n";
            return os;
        }
};
