#include <iostream>

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

		void concatenate(String args) {
		    int length = this->length + args.getlength() + 1;
		    const char* argsString = args.getString();
		    char* StringCont = new char[length];
		    int i, k = 0;

		    for (i = 0; i < this->length; ++i) {
                StringCont[i] = this->cString[i];
		    }for (int j = 0; j < args.getlength(); ++j, ++i) {
                StringCont[i] = argsString[j];
            }
		    StringCont[length-1] = '\0';
            String y(StringCont);
		    setString(y);
		}

		String concatenateSum(String args) {
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

        bool compareStrings(String args) {
            if (this->length == args.getlength()) {
                const char* argsString = args.getString();
                for (int i = 0; i < this->length; i++) {
                    if (this->cString[i] != argsString[i])
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
        String& operator+= (String args) {
            this->concatenate(args);
            return *this;
        }
        String& operator+= (const char* args) {
            String str(args);
            this->concatenateSum(str);
            return *this;
        }
        // override the operator +
        String operator+ (String args) {
            return this->concatenateSum(args);
        }
        String operator+ (const char* args) {
            String str(args);
            return this->concatenateSum(str);
        }

        // override the operator == and ===
        bool operator== (String args) {
            return this->compareStrings(args);
        }
        bool operator== (const char* args) {
            String argsObject(args);
            return this->compareStrings(argsObject);
        }
        // this is the equalIgnoreCase
        bool operator/= (String& args) {
            String x = this->toLowerCase();
            String y = args.toLowerCase();
            return (x == y);
        }
        bool operator/= (const char* args) {
            String x = this->toLowerCase();
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

        //
        char& operator[] (int index) {
            index = index%this->length;
            return this->cString[index - 1];
        }
        // print a object is equal to print a string
		friend std::ostream& operator<<(std::ostream& os, const String& str) {
            os << str.cString;
            return os;
        }
};
