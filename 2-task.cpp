#include <iostream>
#include <vector>

void showField(char field[][3]) {
    int k = 0;
    for (int i = 0; i < 5; i++) {
        std::cout << " ";
        for (int j = 0; j < 3; j++) {
            if (i % 2 == 0) {
                std::cout << " " << field[k][j] << " ";
                if (j < 2) {
                    std::cout << "|";
                }
            }
            else {
                std::cout << "---";
                if (j < 2) {
                    std::cout << "|";
                }
            }
        }
        if (i % 2 == 0) k++;
        std::cout << std::endl;
    }
}

bool findWinner(char field[][3], char symbol) {
    bool win = false;
    for (int i = 0; i < 3 && !win; i++) {
        int counterX = 0, counterY = 0;
        for (int j = 0; j < 3; j++) {
            if (field[i][j] == symbol) {
                counterX++;
            }
            if (field[j][i] == symbol) {
                counterY++;
            }
        }
        if (counterX == 3 || counterY == 3) {
            win = true;
        }
    }
    if (win) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char field[3][3] = { {' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '} };
    showField(field);
    bool win1 = false, win2 = false;
    for (int i = 0; i < 9 && (!win1 && !win2); i++) {
        bool correct = true;
        int x, y;
        std::cout << "Player1, making his move:" << std::endl;
        do {
            do {
                std::cout << "x: ";
                std::cin >> x;
                correct = (x >= 0 && x < 3 ? true : false);
            } while (!correct);
            do {
                std::cout << "y: ";
                std::cin >> y;
                correct = (y >= 0 && y < 3 ? true : false);
            } while (!correct);
            correct = ((field[y][x] == ' ') ? true : false);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        field[y][x] = 'X';
        showField(field);
        win1 = findWinner(field, 'X');
        i++;
        if (!win1 && i < 9) {
            std::cout << "Player2, making his move:" << std::endl;
            do {
                do {
                    std::cout << "x: ";
                    std::cin >> x;
                    correct = (x >= 0 && x < 3 ? true : false);
                } while (!correct);
                do {
                    std::cout << "y: ";
                    std::cin >> y;
                    correct = (y >= 0 && y < 3 ? true : false);
                } while (!correct);
                correct = ((field[y][x] == ' ') ? true : false);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            field[y][x] = 'O';
            showField(field);
            win2 = findWinner(field, 'O');
        }
    }
    if (win1) {
        std::cout << "Player 1 win!";
    }
    else if (win2) {
        std::cout << "Player 2 win!";
    }
    else {
        std::cout << "Nobody wins...";
    }
}

/*
Старинная-добрая игра на страницах всех школьных тетрадей.
Поле размером 3х3 представлено в виде двумерного массива с
типом элементов char. Помните тот символьный тип из предыдущего модуля?
Теперь он нам и пригодится. Участвуют два игрока, которые ходят по очереди
и ставят в указанные ими в стандартном вводе координаты свой символ - ‘X’ или ‘O’
(буквы латинского алфавита). Как только у одного из игроков будет установлено подряд
три крестика или три нолика - он побеждает. Если свободных клеток не осталось, а трёх
совпадающих элементов не найдено - объявляется ничья. Для простоты, мы не будем
рассматривать диагональные совпадения, а только строго вертикальные либо строго горизонтальные.

Изначально всё поле инициализируется символом пробела - ‘ ‘. Это можно сделать сразу при объявлении,
либо с помощью вложенного цикла. На каждом ходе, при занятой клетке или при неверных координатах этой
клетки должно быть выведено сообщение и игрок должен указать координаты клетки повторно. После каждого
хода надо выводить в консоль текущее состояние всего игрового поля, для наглядности.

Сделаю ещё одну небольшую подсказку. Проверку на победу игрока, которую надо осуществлять
после каждого хода, можно сделать с помощью вложенного цикла, сразу проверяя и вертикаль и
горизонталь а как именно - попробуйте догадаться сами.
*/  