#include <cstdarg>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename Type>
class VectorRn  {
    private:
        int dimension = 0;
        Type* vector;

    public:
        VectorRn(int args, ...) {
            static_assert(std::is_same<Type, int>::value || std::is_same<Type, double>::value,
                      "Unsupported type: only use int or double");
            if(args <= 0) {
                throw std::out_of_range("index out of the range");
            }

            this->dimension = args;
            this->vector = new Type[this->dimension];
            va_list argsList;
            va_start(argsList, args);

            for (int i = 0; i < this->dimension; ++i) {
                this->vector[i] = va_arg(argsList, Type);
            }
            va_end(argsList);
        }

        VectorRn(const VectorRn<int>& w) {
            this->dimension = w.dimension;
            this->vector = new Type[this->dimension];

            for (int i = 0; i < this->dimension; i++) {
                this->vector[i] = w.vector[i];
            }
        }

        VectorRn(const VectorRn<double>& w) {
            this->dimension = w.dimension;
            this->vector = new Type[this->dimension];

            for (int i = 0; i < this->dimension; i++) {
                this->vector[i] = w.vector[i];
            }
        }

        VectorRn(Type* array, int dimension) {
            this->dimension = dimension;
            this->vector = new Type[dimension];

            for (int i = 0; i < dimension; i++) {
                this->vector[i] = array[i];
            }
        }

        int getDimension() {
            return this->dimension;
        }

        Type* getVector() {
            return this->vector;
        }

        template <typename U>
        VectorRn<double> operator+(VectorRn<U> w) {
            int q = w.getDimension();
            if (this->dimension == q) {
                U* vectorW = w.getVector();
                double* z = new double[q];
                for (int i = 0; i < q; i++) {
                    double indexV1 = this->vector[i];
                    double indexV2 = vectorW[i];
                    z[i] = indexV1 + indexV2;
                }
                VectorRn<double> toReturn(z, q);
                delete[] vectorW, z;
                return toReturn;
            }else {
                std::cout << "Unsupported dimensions";
                std::exit(1);
            }
        }

        // the product point
        template <typename U>
        double operator*(VectorRn<U> w) {
            int q = w.getDimension();
            if (this->dimension == q) {
                U* vectorW = w.getVector();
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

        friend VectorRn<double> operator*(double scalar, const VectorRn<Type>& v) {
            double* result = new double[v.dimension];
            for (int i = 0; i < v.dimension; ++i) {
                double w = v.vector[i];
                result[i] = scalar * w;
            }
            VectorRn<double> toReturn(result, v.dimension);
            delete[] result;
            return toReturn;
        }
        friend VectorRn<double> operator*(const VectorRn<Type>& v, double scalar) {
            double* result = new double[v.dimension];
            for (int i = 0; i < v.dimension; ++i) {
                double w = v.vector[i];
                result[i] = scalar * w;
            }
            VectorRn<double> toReturn(result, v.dimension);
            delete[] result;
            return toReturn;
        }

        friend VectorRn<double> operator%(const VectorRn<Type>& v, const VectorRn<Type>& w) {
            if (v.dimension == w.dimension && v.dimension == 3) {
                VectorRn i(3, 1, 0, 0);
                VectorRn j(3, 0, 1, 0);
                VectorRn z(3, 0, 0, 1);
                return i*(v.vector[1]*w.vector[2] - v.vector[2]*w.vector[1]) + -1*j*(v.vector[0]*w.vector[2] - v.vector[2]*w.vector[0]) + z*(v.vector[0]*w.vector[1] - v.vector[1]*w.vector[0]);
            }else {
                std::cout<< "Not match dimensions";
                std::exit(1);
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const VectorRn<Type>& vecto) {
            os << '(';

            for (int i = 0; i < vecto.dimension; ++i) {
            os << vecto.vector[i];
            if (i < vecto.dimension - 1) {
                os << ", ";
            }
        }
            os << ')';
            return os;
        }
};
