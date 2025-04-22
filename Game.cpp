#include<iostream>
#include "Game.h"
using namespace std;

Game::Game() {
    playGame();
}
void Game::printMatches(vector<int>playerPicks,vector<int>kenoNumbers) {
    m_matches.clear();
    int j = 0;
    for (int i = 0; i < 20;) {
        if(j == 11) {
            i=100;
        }
        else if (kenoNumbers[i] == playerPicks[j]) {
            m_matches.push_back(kenoNumbers[i]);
            i++;
            j++;
        }
        else if(kenoNumbers[i] > playerPicks[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    for (auto i:m_matches) {
        std::cout << i << " ";
    }
}
void Game::displayResults() {

}
void Game::playGame() {
    bool play = true;
    while(play) {
        m_matches.clear();
        m_player.inputPlayerNumbers();
        m_keno.generateNumbers();
        cout << endl << "----------------------------------Results----------------------------------" << endl;
        cout << "Keno Numbers: ";
        m_keno.printKenoNumbers();
        cout << "Player Picks: ";
        m_player.printPlayerNumbers();
        cout << "You matched: ";
        printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers());
        int prize = 0;
        if(m_matches.size()==5) {
            prize = 5;
        }
        else if(m_matches.size()==6) {
            prize = 10;
        }
        else if(m_matches.size()==7) {
            prize = 50;
        }
        else if(m_matches.size()==8) {
            prize = 250;
        }
        else if(m_matches.size()==9) {
            prize = 2500;
        }
        else if(m_matches.size()==10) {
            prize = 25000;
        }
        cout <<  endl << "Matching " << m_matches.size() << " of 20 numbers wins $" << prize;
        cout << endl << "Play again? (y/n): ";
        char playYN;
        cin >> playYN;
        if (playYN == 'n') {
            play = false;
        }
        else {
            play = true;
        }
    }
}