#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

int main() {
    std::setlocale(LC_ALL, "");
    system("chcp 1251");
    std::srand(std::time(nullptr));
    const std::string high_scores_filename = "high_scores.txt";
    const int max_value = 100;
    const int random_value = std::rand() % 100;
    int current_value = 0;
    bool not_win = true;  

    std::cout << "Здравствуйте, введите Ваше имя:" << std::endl;
    std::string user_name;
    std::cin >> user_name;
    int attempts_count = 0;
    std::cout << "Введите предполагаемое число:" << std::endl;

    do {
        std::cin >> current_value;

        if (current_value < random_value) {
            std::cout << "более чем " << current_value << std::endl;
            attempts_count++;
        }
        else if (current_value > random_value) {
            std::cout << "менее чем " << current_value << std::endl;
            attempts_count++;
        }
        else {
            std::cout << "Поздравляем с победой! Количество попыток: " << attempts_count << std::endl;

  
            std::ofstream out_file{ high_scores_filename, std::ios_base::app };
            if (out_file.is_open()) {
                out_file << user_name << ' ' << attempts_count << std::endl;
            }
            else {
                std::cout << "Не удалось открыть файл для записи!\n";
            }

            std::ifstream in_file{ high_scores_filename };
            if (in_file.is_open()) {
                std::cout << "\nТаблица рекордов:\n";
                std::string username;
                int high_score;
       
                while (true) {
                    in_file >> username;
                    in_file >> high_score;
                    in_file.ignore(); 
                    if (in_file.fail()) {
                        break;
                    }
                    std::cout << username << '\t' << high_score << std::endl;
                }
            }
            else {
                std::cout << "Не удалось открыть файл для чтения!\n";
            }
            break; 
        }
    } while (true);
    return 0;
}