#include <iostream>

class Hello {
	
	private:
		Hello() {
			std::cout << "Hello world 7" << std::endl;
		}
	public:
		static Hello* getInstance() {
			if (instance == NULL) {
				instance = new Hello();
			}
		}	
		
		~Hello() {
			
			
		}
		void releaseInstance() {
			if (instance) {
				delete instance;
				instance = NULL;
				//std::cout << "Deleted" << std::endl;
			}
		}
	private:
		static Hello* instance;
};

Hello* Hello::instance = NULL;

int main() {
	Hello *objHello;
	
	objHello = Hello::getInstance();
	
	objHello->releaseInstance();
	
	return 0;
}
