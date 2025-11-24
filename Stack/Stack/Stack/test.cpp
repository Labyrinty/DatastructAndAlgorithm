#include "RunProject.h" 
#include <exception> 

int main() {
    try {
		RunProject();
    }
    catch (const std::overflow_error& e) {
        std::cerr << "溢出异常：" << e.what() <<std::endl;
    }
    catch (const std::underflow_error& e) {
        std::cerr << "空栈异常：" << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "未知异常：" << e.what() << std::endl;
    }

    return 0;
}