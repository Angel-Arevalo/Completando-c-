#include <iostream>

template <typename Type>
class List {

    private:
        Type* cList;
        int length;

        void freeMemory() {
            delete[] this->cList;
        }

        bool verifyIndex(Type index) {
            for (int i = 0; i < length; i++) {
                if (cList[i] == index) return false;
            }
            return true;
        }
    public:
        List(): cList(nullptr), length(0) {}

        List(Type* x, int length) {
            freeMemory();
            this->length = length;
            cList = x;
        }

        ~List() {this->freeMemory();}

        void add(Type newItem) {
            Type* helpArray = new Type[this->length + 1];

            if (length != 0 && verifyIndex(newItem)) {
                for (int i = 0; i < this->length; i++) {
                    helpArray[i] = cList[i];

                }
                helpArray[this->length] = newItem;
                this->length += 1;
                this->cList = helpArray;
                delete[] helpArray;
            }else if (length == 0){
                cList = new Type[0];
                length += 1;
                cList[0] = newItem;
            }

            delete[] helpArray;
        }

        void operator=(const Type& array) {
            this->freeMemory();
            this->length = array.length;
            this->cList = array.cList;
        }

        friend std::ostream& operator<<(std::ostream& os, const List& w) {
            if (w.length != 0) {
                os << '{';
                for (int i = 0; i < w.length; i++) {
                    os << w.cList[i];
                    if (i != w.length - 1) os << ", ";
                }
                os << '}';
            }else os << "{}";

            os << "\n";
            return os;
        }

};
