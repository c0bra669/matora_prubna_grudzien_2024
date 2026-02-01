#include <iostream>
#include<fstream>
#include<vector>
void get_data(std::vector<int> &numbers,std::string path){
    std::ifstream file(path);
    int num{};
    while(file>>num){
        numbers.push_back(num);
    }
}

int main()
{
    std::vector<int>numbers;
    get_data(numbers,"./files/liczby_przyklad.txt");
    for(int number : numbers){
        std::cout<<number<<std::endl;
    }
    return 0;
}
