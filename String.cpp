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

		// a getter to use in the methods
		int getlength() {
            return this->length;
		}

		const char* getString() {
            return this->cString;
		}

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
		    StringCont[length-1] = '\0';
            String y(StringCont);
		    return y;
		}

		String toLowerCase() {
		    int index;
		    char* StringLower = new char[this->length];
            for (int i = 0; i < this->length; i++) {
                index = this->cString[i];
                if (65 <= index && index < 91) {
                    char x = index + 32;
                    StringLower[i] = x;
                }else StringLower[i] = this->cString[i];
            }

            String lower(StringLower);
            return lower;
		}

		// imprimir un objeto es equivalente a imprimir la cadena
		friend std::ostream& operator<<(std::ostream& os, const String& str) {
            os << str.cString;
            return os;
        }
};
