//Klopov Aleksei demo project 2b

#include <iostream>
#include <string>
#include <sstream>

double solution(std::string rpn)
{
    double* arr = new double[100];
    double* top = arr;
    std::stringstream ss(rpn);
    std::string cell;
    
    while (ss >> cell)
    {   
    	if (cell == "+" || cell == "-" || cell == "*" || cell == "/")
    	{
            double b = *(--top);
            double a = *(--top);
            if (cell == "+") *top++ = a + b;
            else if (cell == "-") *top++ = a - b;
            else if (cell == "*") *top++ = a * b;
            else if (cell == "/") *top++ = a / b;
        }
        else 
        {
            *top++ = std::stod(cell);
        }
    }
    
    double result = *(top - 1);
    delete [] arr;
    return result;
}

int main()
{
    std::string rpn;
    std::cout << "Введите обратную польскую запись выражения: ";
    std::getline(std::cin, rpn);
    
    int result = solution(rpn);
    std::cout << "Ответ: " << result << std::endl;

    return 0;
}
