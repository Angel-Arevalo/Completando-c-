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
            std::cout << this->cString << std::endl;
        }

        bool compareStrings(String args) {

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

		// print a object is equal to print a string
		friend std::ostream& operator<<(std::ostream& os, const String& str) {
            os << str.cString;
            return os;
        }

        // override the method of the operator +=
        String& operator+= (String args) {
            this->concatenate(args);
            return *this;
        }
        String& operator+= (const char* args) {
            String str(args);
            this->concatenate(str);
            return *this;
        }
};
