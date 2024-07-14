#include <iostream>

template <typename Type>
class List {

    private:
        Type* cList;
        int length;

        void freeMemory() {
            delete[] this->cList;
            this->length = 0;
        }

        List<int> verifyIndex(Type index) {
            for (int i = 0; i < length; i++) {
                if (cList[i] == index) {
                    List<int> x;
                    x.add(0);
                    x.add(i);
                    return x;
                }
            }
            List<int> x;
            x.add(1);
            return x;
        }

        void copyList(List<Type>& x) {
            freeMemory();
            this->length = x.length;
            cList = new Type[this->length];
            for (int i = 0; i < length; i++) {
                this->cList[i] = x[i];
            }
        }


    public:
        List(): cList(nullptr), length(0) {}

        List(Type* x, int length) {
            List<Type> w;
            w.cList = x;
            w.length = length;
            copyList(w);
            w.freeMemory();
        }

        List(const List<Type>& list): length(list.length), cList(list.cList) {}

        ~List() {this->freeMemory();}

        void add(Type newItem) {
            Type* helpArray = new Type[this->length + 1];

            if (length != 0 && verifyIndex(newItem)[0]) {
                for (int i = 0; i < this->length; i++) {
                    helpArray[i] = cList[i];
                }
                helpArray[this->length] = newItem;
                this->length += 1;
                this->cList = helpArray;
            }else if (length == 0){
                cList = new Type[0];
                length += 1;
                cList[0] = newItem;
            }

            delete[] helpArray;
        }

        void remove(int element) {
            if(-1*length <= element && element <= length) {
                element = (element + length)%length;
                List<Type> toHelpProcess;
                for (int i = 0; i < length; i++) {
                    if(i != element) toHelpProcess.add(cList[i]);
                }
                *this = toHelpProcess;
                toHelpProcess.freeMemory();
            }else throw std::invalid_argument("Index out of the range.");
        }

        List<Type> subList(int start, int end) {
            if (start < 0) throw std::invalid_argument("The start must be positive");
            if (end < start) throw std::invalid_argument("The start must be smaller than end");
        }

        void operator=(List<Type> array) {
            this->copyList(array);
        }

        Type& operator[](int x) {
            if (-1*length <= x && x <= length) {
                return this->cList[(x + length)%length];
            }else throw std::invalid_argument("Index out of the range");
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
