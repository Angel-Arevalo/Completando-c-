#include <cstdarg>
#include <iostream>

class VectorRn {
    private:
        int dimension = 0;
        int* vector;

    public:
        VectorRn(int args, ...) {
            this->dimension = args;
            this->vector = new int[this->dimension];
            va_list argsList;
            va_start(argsList, args);

            for (int i = 0; i < this->dimension; ++i) {
                this->vector[i] = va_arg(argsList, int);
                std::cout << this->vector[i] << std::endl;
            }

            va_end(argsList);
        }

        friend std::ostream& operator<<(std::ostream& os, const VectorRn& vecto) {
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
