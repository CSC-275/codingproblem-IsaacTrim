#include <iostream>
#include <algorithm>
#include "Player.h"

void Player::inputPlayerNumbers() {
    std::cout << "To play Keno, select 10 numbers in the range of 1-80.\n\n";
    bool error;
    int temp=0;

    for (int i=0;i<10;i++)
    {
        error = false;
        std::cout << "Enter your pick #" << i+1 <<": ";
        std::cin >> temp;
        if (std::cin.fail())
        {
            error = true;
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cout << "Invalid data input! Try again. ";
        }
        else if (temp > 80)
        {
            error = true;
            std::cout << temp << " is out of range! Try again. ";
        }
        else if (std::find(m_playerNumbers.begin(), m_playerNumbers.end(), temp) != m_playerNumbers.end()) {
            error = true;
            std::cout << temp << " was already picked! Try again. ";
        }
        if (error)
            i--;
        else
            m_playerNumbers.push_back(temp);
    }
}

std::vector<int> Player::getPlayerNumbers() {
    return m_playerNumbers;
}

void Player::printPlayerNumbers() {
    std::sort(m_playerNumbers.begin(), m_playerNumbers.end());
    for (auto i:m_playerNumbers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void Player::clearPlayerNumbers() {
    m_playerNumbers.clear();
}
