#include <cstdarg>
#include <iostream>
#include <stdexcept>

template <typename Type>
class VectorRn  {
    private:
        int dimension = 0;
        Type* vector;

    public:
        VectorRn(int args, ...) {
            static_assert(std::is_same<Type, int>::value || std::is_same<Type, double>::value,
                      "Unsupported type: only use int or double");
            this->dimension = args;
            this->vector = new Type[this->dimension];
            va_list argsList;
            va_start(argsList, args);

            for (int i = 0; i < this->dimension; ++i) {
                this->vector[i] = va_arg(argsList, Type);
            }

            va_end(argsList);
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
