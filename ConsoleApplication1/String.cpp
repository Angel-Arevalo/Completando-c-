#include <iostream>

class String {

	private:
		const char* cString;
		int length;

		int getlength() const {
			int i = 0;
			while (this->cString[i] != '\0') {
				++i;
			}
			return i;
		};

	public:
		String(const char* string) {
			this->cString = string;

			this->length = this->getlength();

		};
};