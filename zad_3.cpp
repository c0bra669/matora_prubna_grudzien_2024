#include <iostream>
#include<fstream>
#include<vector>
#include<cmath>
void get_data(std::vector<int> &numbers,std::string path){
    std::ifstream file(path);
    int num{};
    while(file>>num){
        numbers.push_back(num);
    }
}
bool power_check(int number){
    if(sqrt(number)==floor(sqrt(number))){
        return true;
    }
    return false;
}

void print_nat_powers(std::vector<int> &numbers){
    bool first_printed{false};
    int count{};
    for(int number : numbers){
        if(power_check(number)){
            if(!first_printed){
                std::cout << number<<std::endl;
                first_printed=true;
            }
            count++;
        }
    }
    std::cout << count;
}
int main()
{
    std::vector<int>numbers;
    get_data(numbers,"./files/liczby_przyklad.txt");
    print_nat_powers(numbers);

    return 0;
}
