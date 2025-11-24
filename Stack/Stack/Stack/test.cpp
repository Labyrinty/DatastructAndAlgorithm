#include "RunProject.h" 
#include <exception> 

int main() {
    try {
		double result = RunProject();
        std::cout << "结果: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "无效参数异常：" << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
		std::cerr << "运行时异常：" << e.what() << std::endl;
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