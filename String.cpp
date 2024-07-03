#include <iostream>
#include <stdexcept>

class String {

	private:
		char* cString;
		int length;

		//this method return the length of the string
		static int lenString(const char* cString){
			int i = 0;
			while (cString[i] != '\0') {
				++i;
			}
			return i;
		};

		String concatenate(String args) {
		    int length = this->length + args.getlength() + 1;
		    const char* argsString = args.getString();
		    char* StringCont = new char[length];
		    int i, k = 0;

		    for (i = 0; i < this->length; ++i) {
                StringCont[i] = this->cString[i];
		    }for (int j = 0; j < args.getlength(); ++j, ++i) {
                StringCont[i] = argsString[j];
            }
		    StringCont[length - 1] = '\0';
            String y(StringCont);
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
        }

        void setString(const char* args) {
            String argsObject(args);
            this->setString(argsObject);
        }

        static bool compareStrings(String argsS, String args) {
            if (argsS.getlength() == args.getlength()) {
                char* argsString = args.getString();
                char* cString = argsS.getString();
                for (int i = 0; i < argsS.getlength(); i++) {
                    if (cString[i] != argsString[i])
                        return false;
                }
            }else return false;
            return true;
        }

	public:
	    // the constructor of the class
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

        String(const char ch) {
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
            this->setString(this->concatenate(str));
        }
        void operator+= (char* args) {
            String str(args);
            this->setString(this->concatenate(str));
        }
        void operator+= (char args) {
            String str(args);
            this->setString(this->concatenate(str));
        }
        // override the operator +
        String operator+ (String args) {
            return this->concatenate(args);
        }
        String operator+ (const char* args) {
            String str(args);
            return this->concatenate(str);
        }

        friend String operator+(const char* args, String m) {
            String argsObject(args);
            return (argsObject + m);
        }
        friend String operator+(char chr, String args) {
            String ch(chr);
            return ch + args;
        }
        /*friend String operator+(char chr, const char* args) {
            String ch(chr);
            String arg(args);
            return ch + arg;
        }*/
        // override the operator ==
        friend bool operator== (String argsS, String args) {
            return compareStrings(argsS, args);
        }
        friend bool operator== (String argsS, const char* args) {
            String argsObject(args);
            return compareStrings(argsS, argsObject);
        }
        friend bool operator== (const char* args, String argsS) {
            String argsObject(args);
            return compareStrings(argsS, argsObject);
        }
        friend bool operator== (String argsS, char* args) {
            String argsObject(args);
            return compareStrings(argsS, argsObject);
        }
        friend bool operator== (char* args, String argsS) {
            String argsObject(args);
            return compareStrings(argsS, argsObject);
        }
        // this is the equalIgnoreCase
        friend bool operator/= (String argsS, String args) {
            String x = argsS.toLowerCase();
            String y = args.toLowerCase();
            return (x == y);
        }
        friend bool operator/= (String argsS, const char* args) {
            String x = argsS.toLowerCase();
            String y(args);
            return (x == y.toLowerCase());
        }
        friend bool operator/= (const char* args, String argsS) {
            String x = argsS.toLowerCase();
            String y(args);
            return (x == y.toLowerCase());
        }
        friend bool operator/= (String argsS, char* args) {
            String x = argsS.toLowerCase();
            String y(args);
            return (x == y.toLowerCase());
        }
        friend bool operator/= (char* args, String argsS) {
            String x = argsS.toLowerCase();
            String y(args);
            return (x == y.toLowerCase());
        }
        // the ignore case to the char
        friend bool operator/= (char args, String argsS) {
            String x = argsS.toLowerCase();
            String y(args);
            return (x == y.toLowerCase());
        }
        friend bool operator/= (String argsS, char args) {
            String x = argsS.toLowerCase();
            String y(args);
            return (x == y.toLowerCase());
        }
        // override the operator =
        String& operator=(String other) {
            if (!(this == &other)) {
                this->setString(other.cString);
            }
            return *this;
        }
        void operator= (const char* args) {
            this->setString(args);
        }

        // the method subString
        String operator() (int firstIndex, int secondIndex) {
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

        String operator() (int firstIndex) {
            return (*this)(firstIndex, this->length);
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
