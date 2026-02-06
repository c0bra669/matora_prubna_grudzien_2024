#include <iostream>
#include<fstream>
#include<vector>
#include<cmath>
 #include <array>
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
std::array<int, 4>split_num(int number){
    std::array<int, 4> num_arr{};
    num_arr[3] = number % 10;
    num_arr[2] = (number / 10) % 10;
    num_arr[1] = (number / 100) % 10;
    num_arr[0] = (number / 1000) % 10;
    return num_arr;
}
int marge_num(const std::array<int, 4>& num_arr)
{
    int marged_num{};
    marged_num += num_arr[0] * 1000;
    marged_num += num_arr[1] * 100;
    marged_num += num_arr[2] * 10;
    marged_num += num_arr[3];
    return marged_num;
}

void swap(int &A,int &B){
    int temp;
    temp=A;
    A=B;
    B=temp;
}
void sort_arr(std::array<int, 4> &num_arr,bool desc=false){
    for(int i{};i<4;i++){
        for(int j{};j<4;j++){
            if(desc){
                if(num_arr[i]>num_arr[j]){
                    swap(num_arr[i],num_arr[j]);
                    continue;
                }
            }
            if(num_arr[i]<num_arr[j]){
                    swap(num_arr[i],num_arr[j]);
            }
        }
    }
}
void zad3_3(std::vector<int> &numbers){
    int eq_count{};
    int gr_count{};
    int ls_count{};
    for(int number : numbers){
        std::array<int,4> num_arr_as =split_num(number);
        std::array<int,4> num_arr_desc =split_num(number);
        sort_arr(num_arr_as);
        sort_arr(num_arr_desc,true);
        int asc=marge_num(num_arr_as);
        int desc=marge_num(num_arr_desc);
        if(desc - asc==number){
            eq_count++;
            std::cout<<number<<std::endl;
            continue;
        }
        if(desc-asc>number)
        {
            gr_count++;
            continue;
        }
        else
        {
            ls_count++;
            continue;
        }
    }
    std::cout<<"różnica większa: "<<gr_count<<
        "\nróżnica równa: "<<eq_count<<
        "\nróżnica mniejsza: "<<ls_count<<std::endl;
}
int main()
{
    std::vector<int>numbers;
    get_data(numbers,"./files/liczby.txt");
    std::cout <<"zad 3.1\n";
    print_nat_powers(numbers);
    std::cout<<"zad 3.2 \n";
    print_numbers_primef(numbers);
    std::cout<<"zad 3.3 \n";
    zad3_3(numbers);


    return 0;
}
