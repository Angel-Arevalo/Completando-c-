#include <iostream>
#include <stdexcept>

class String {

	private:
		char* cString;
		int length = 0;

		//this method return the length of the string
		static int lenString(const char* cString){
			int i = 0;
			while (cString[i] != '\0') {
				++i;
			}
			return i;
		};

		String concatenate(const String& args) {
		    int length = this->length + args.length + 1;
		    char* StringCont = new char[length];
		    int i, k = 0;

		    for (i = 0; i < this->length; ++i) {
                StringCont[i] = this->cString[i];
		    }for (int j = 0; j < args.length; ++j, ++i) {
                StringCont[i] = args.cString[j];
            }
		    StringCont[length - 1] = '\0';
            String y(StringCont);
            delete[] StringCont;
		    return y;
		}

		void setString(String args) {
            delete[] this->cString;
            // change the length
            this->length = args.getlength();
            char* argsString = args.getString();

            this->cString = new char[this->length + 1];

            for (int i = 0; i < this->length; i++) {
                this->cString[i] = argsString[i];
            }
            this->cString[this->length] = '\0';
            delete[] argsString;
        }

        void setString(const char* args) {
            String argsObject(args);
            this->setString(argsObject);
        }

        static bool compareStrings(const String& argsS, const String& args){
            if (argsS.length == args.length) {
                for (int i = 0; i < argsS.length; i++) {
                    if (argsS.cString[i] != args.cString[i]) {
                        return false;
                    }
                }
            }else {
                return false;
            }
            return true;
        }

        String subString(int firstIndex, int secondIndex) const {
            if (this->length < secondIndex || firstIndex < 0)
                throw std::runtime_error("index out of the range");
            if (firstIndex == secondIndex || secondIndex < firstIndex)
                throw std::runtime_error("second index in bat range");
            char* subString = new char[secondIndex - firstIndex + 1];
            int k = 0;

            for (int i = firstIndex; i < secondIndex; i++, k++) {
                subString[k] = this->cString[i];
            }
            subString[secondIndex - firstIndex] = '\0';
            String args(subString);
            return args;
        }

        int indexOf(const String& args) const {
            if (this->length >= args.length) {
                for (int i = 0; i < this->length - args.length; i++) {
                    String y = this->subString(i, i + args.length);
                    if (y == args) {
                        return i;
                    }
                }
            }
            return -1;
        }
	public:
	    // the constructor of the class
	    String() : cString(nullptr), length(0) {}
		String(const char* string) {
			this->length = String::lenString(string);
            this->cString = new char[this->length + 1];

            for (int i = 0; i < this->length; i++) {
                this->cString[i] = string[i];
            }

            this->cString[this->length] = '\0';
		};

		String(const char* string, int length) {
		    delete[] this->cString;
            this->length = length;
            this->cString = new char[length + 1];

            for (int i = 0; i< length; i++) {
                cString[i] = string[i];
            }
            cString[length] = '\0';
		}

        String(const String& string) {
            this->length = string.length;
            this->cString = new char[this->length + 1];

            for (int i = 0; i < this->length; i++) {
                this->cString[i] = string.cString[i];
            }

            this->cString[this->length] = '\0';
        }

        String(char ch) {
            this->length = 1;
            this->cString = new char[2];

            cString[0] = ch;
            cString[1] = '\0';
        }
		// a getter to use in the methods
		int getlength() {
            return this->length;
		}

		char* getString() {
            return this->cString;
		}

		String toLowerCase() {
		    int index;
		    char* StringLower = new char[this->length + 1];
            for (int i = 0; i < this->length; i++) {
                index = this->cString[i];
                if (65 <= index && index < 91) {
                    char x = index + 32;
                    StringLower[i] = x;
                }else if (this->cString[i] != '\0') {
                    StringLower[i] = this->cString[i];
                }
            }
            StringLower[this->length] = '\0';
            String lower(StringLower);
            return lower;
		}

		String toUpperCase() {
		    int index;
		    char* StringUpper = new char[this->length + 1];
            for (int i = 0; i < this->length; i++) {
                index = this->cString[i];
                if (97 <= index && index < 124) {
                    char x = index - 32;
                    StringUpper[i] = x;
                }else if (this->cString[i] != '\0') {
                    StringUpper[i] = this->cString[i];
                }
            }
            StringUpper[this->length] = '\0';
            String Upper(StringUpper);
            return Upper;
		}
        // override the method of the operator +=
        void operator+= (String args) {
            this->setString(this->concatenate(args));
        }
        void operator+= (const char* args) {
            String str(args);
            *this += str;
        }
        void operator+= (char* args) {
            String str(args);
            *this += str;
        }
        void operator+= (char args) {
            String str(args);
            *this += str;
        }
        // override the operator +
        String operator+ (String args) {
            return this->concatenate(args);
        }
        String operator+ (const char* args) {
            String str(args);
            return *this + str;
        }
        String operator+ (char* args) {
            String str(args);
            return *this + str;
        }
        String operator+ (char args) {
            String str(args);
            return *this + str;
        }
        friend String operator+(const char* args, String m) {
            String argsObject(args);
            return (argsObject + m);
        }
        friend String operator+(char* chr, String args) {
            String ch(chr);
            return ch + args;
        }
        friend String operator+(char chr, String args) {
            String ch(chr);
            return ch + args;
        }
        // override the operator ==
        friend bool operator== (String argsS, String args) {
            return String::compareStrings(argsS, args);
        }
        friend bool operator== (String argsS, const char* args) {
            String argsObject(args);
            return argsS == argsObject;
        }
        friend bool operator== (const char* args, String argsS) {
            String argsObject(args);
            return argsS == argsObject;
        }
        friend bool operator== (String argsS, char* args) {
            String argsObject(args);
            return argsS == argsObject;
        }
        friend bool operator== (char* args, String argsS) {
            String argsObject(args);
            return argsS == argsObject;
        }
        // this is the equalIgnoreCase
        friend bool operator/= (String argsS, String args) {
            String x = argsS.toLowerCase();
            String y = args.toLowerCase();
            return (x == y);
        }
        friend bool operator/= (String argsS, const char* args) {
            String y(args);
            return (argsS /= y);
        }
        friend bool operator/= (const char* args, String argsS) {
            String y(args);
            return (argsS /= y);
        }
        friend bool operator/= (String argsS, char* args) {
            String y(args);
            return (argsS /= y);
        }
        friend bool operator/= (char* args, String argsS) {
            String y(args);
            return (argsS /= y);
        }
        // the ignore case to the char
        friend bool operator/= (char args, String argsS) {
            String y(args);
            return (argsS /= y);
        }
        friend bool operator/= (String argsS, char args) {
            String y(args);
            return (argsS /= y);
        }
        // override the operator !=
        friend bool operator!=(String x, String y) {
            return !(x == y);
        }
        friend bool operator!=(String x, const char* y) {
            String args(y);
            return (x != args);
        }
        friend bool operator!=(const char* y, String x) {
            String args(y);
            return (x != args);
        }
        friend bool operator!=(String x, char* y) {
            String args(y);
            return (x != args);
        }
        friend bool operator!=(char* y, String x) {
            String args(y);
            return (x != args);
        }
        friend bool operator!=(String x, char y) {
            String args(y);
            return (x != args);
        }
        friend bool operator!=(char y, String x) {
            String args(y);
            return (x != args);
        }
        // override the operator =
        void operator=(String other) {
            if (this != &other) {
                this->setString(other.cString);
            }
        }
        void operator= (const char* args) {
            this->setString(args);
        }

        // the method subString
        String operator() (int firstIndex, int secondIndex) {
            return this->subString(firstIndex, secondIndex);
        }

        String operator() (int firstIndex) {
            return this->subString(firstIndex, this->length);
        }

        int operator[] (const String& w) const {
            return this->indexOf(w);
        }

        int operator[] (const char* x) {
            String w(x);
            return this->indexOf(w);
        }
        int operator[] (char* x) {
            String w(x);
            return this->indexOf(w);
        }
        int operator[] (char x) {
            String w(x);
            return this->indexOf(w);
        }

        // the method to get the chars
        char& operator[] (int index) {
            index = index%(this->length);
            return this->cString[index];
        }
        // print a object is equal to print a string
		friend std::ostream& operator<<(std::ostream& os, const String& str) {
            os << str.cString;
            return os;
        }
};

String toLowerCase(const char* args) {
    String x(args);
    return x.toLowerCase();
}

String toLowerCase(char* args) {
    String x(args);
    return x.toLowerCase();
}

String toLowerCase(char args) {
    String x(args);
    return x.toLowerCase();
}

String toUpperCase(const char* args) {
    String x(args);
    return x.toUpperCase();
}

String toUpperCase(char* args) {
    String x(args);
    return x.toUpperCase();
}

String toUpperCase(char args) {
    String x(args);
    return x.toUpperCase();
}
