#include "ZFunction.h"
#include "BruteForce.h"
#include "Gallai.h"
#include "BoyerMooreHorspool.h"


std::string* readTextFromTxt(const std::string& path)
{
    std::ifstream inputFile(path);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return nullptr;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();

    std::string* fileContent = new std::string(buffer.str());

    inputFile.close();
    return fileContent;
}

int main()
{
    system("chcp 65001");

    std::string* smallText = readTextFromTxt("1m.txt");
    std::string* mediumText = readTextFromTxt("10m.txt");
    std::string* largeText = readTextFromTxt("100m.txt");


    int choice;
    std::string choiceString = "1 - Z function search \n2 - Brute force search \n3 - Gallai search \n4 - Boyer-Moore-Horspool \n0 - Exit \n";
    std::string subString = "";
    std::vector<int> result;
    result.clear();
    sf::Clock clock;
    clock.restart();
    sf::Int64 temporary—osts = 0;

    do {
        std::cout << choiceString << std::endl;
        std::cout << "Enter: ";

        std::cin >> choice;
        if (!choice)
            break;

        std::cout << "Enter sub string: ";
        while(subString.empty())
            std::getline(std::cin, subString);

        clock.restart();
        switch (choice)
        {
        case 1:
            result = ZFunction::GetInstance()->findSubstring(*largeText, subString);
            break;

        case 2:
            result = BruteForce::GetInstance()->findSubstring(*largeText, subString);
            break;

        case 3:
            result = Gallai::GetInstance()->findSubstring(*largeText, subString);
            break;

        case 4:
            result = BoyerMooreHorspool::GetInstance()->findSubstring(*largeText, subString);
            break;

        default:
            std::cout << "Invalid value!\n";
            break;
        }
        temporary—osts = clock.getElapsedTime().asMicroseconds();

        if (result.empty())
        {
            std::cout << "The substring was not found in the text" << std::endl;
        }
        else
        {
            std::cout << "The substring is located at the positions: ";

            if(CONSOLE_OUT)
            {
                for (auto n : result)
                    std::cout << n << ", ";
                std::cout << "\b\b.\n";
            }

            std::cout << "Total occurrences: " << result.size() << std::endl;

            result.clear();
        }

        std::cout << "Temporary costs: " << temporary—osts << " microseconds or " << temporary—osts / 1000000. << " seconds" << std::endl;

        subString.clear();
    } while (choice != 0);



    return 0;
}