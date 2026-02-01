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
    file.close();
}
bool power_check(int number){
    if(sqrt(number)==floor(sqrt(number))){
        return true;
    }
    return false;
}
bool is_prime(int number){
    if (number <=1){
        return false;
    }
    if(number == 2){
        return true;
    }
    for(int i{number-1};i>=2;i--){
        if(number%i==0){
            return false;
        }
    }
    return true;
}
void calc_prime_factors(int number,std::vector<int> &factors){

       for(int i{number};i>0;i--){
        if(number%i==0){
            if(is_prime(i)){
                factors.push_back(i);
            }
        }
    }
}
void print_numbers_primef(std::vector<int> &numbers){
    for(int number : numbers){
        std::vector<int> factors;
        calc_prime_factors(number,factors);
        if(factors.size()>=5){
            std::cout<<number<<std::endl;
        }

    }
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
    std::cout << count<<std::endl;
}
int main()
{
    std::vector<int>numbers;
    get_data(numbers,"./files/liczby_przyklad.txt");
    std::cout <<"zad 3.1\n";
    print_nat_powers(numbers);
    std::cout<<"zad 3.2 \n";
    print_numbers_primef(numbers);

    return 0;
}
