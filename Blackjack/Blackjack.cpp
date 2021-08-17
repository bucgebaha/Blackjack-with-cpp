#include "Card.h"
#include "Hand.h"
#include "Table.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    char wannaPlayAgain = 'y';
    char wannaDraw = 'n';
    bool didYouWin = false;

    while (wannaPlayAgain != 'n') {
        system("CLS");
        Table table;
        table.startTheGame();

        if (table.playerHand.getTotalValue() == 21) {
            std::cout << "\n---BLACKJACK!---\n\n";
            std::cout << "\n---LET'S SEE DEALER'S HAND---\n\n";
            table.printTableAllRevealed();
            table.dealerDraws();
            wannaDraw = 'n';
        }
        else {
            std::cout << "Do you want to draw? (y/n): ";
            std::cin >> wannaDraw;
            std::cout << "\n";
        }

        while (wannaDraw != 'n') {
            table.hit(table.playerHand);

            if (!table.playerHand.doesBurst()) {
                table.printTable();

                if (table.playerHand.getTotalValue() != 21) {
                    std::cout << "Do you want to draw? (y/n): ";
                    std::cin >> wannaDraw;
                    std::cout << "\n";
                }
                else break;
            }
            else {
                table.printTable();

                std::cout << "\n---YOU BURST!---\n\n";
                break;
            }
        }

        std::cout << "\n---LET'S SEE DEALER'S HAND---\n\n";
        table.printTableAllRevealed();
        table.dealerDraws();
        table.declareTheWinner();

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> wannaPlayAgain;
        std::cout << "\n";
    }

    return 0;
}