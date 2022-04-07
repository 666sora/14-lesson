#include <iostream>

void showField(int field[][10][10], int n) {
    std::cout << std::endl;
    std::cout << "  ";
    for (int i = 0; i < 10; i++) std::cout << " " << i;
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << "  ";
        for (int j = 0; j < 10; j++) {
            if (field[n][i][j] == 2) std::cout << "  ";
            else if (field[n][i][j] == -1) std::cout << "x ";
            else std::cout << field[n][i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int prepareField(int field[][10][10], int n) {
    bool correct = true;
    int i = 0;
    std::cout << "Player " << n + 1 << " is starting to prepare to fight his field!" << std::endl;
    do {
        int x1, y1;
        std::cout << "Choose where to put 1 square ship:" << std::endl;
        std::cout << "x: ";
        std::cin >> x1;
        std::cout << "y: ";
        std::cin >> y1;
        correct = ((x1 > 9 || y1 > 9 || x1 < 0 || y1 < 0)
            || (field[n][y1][x1] == 1) ? false : true);
        if (!correct) std::cout << "Invalid input" << std::endl;
        if (correct) {
            field[n][y1][x1] = 1;
            showField(field, n);
            i++;
        }
    } while (!correct || i < 4);
    i = 0;
    do {
        int x1, y1;
        int x2, y2;
        std::cout << "Choose where to put 2 square ship:" << std::endl;
        do {
            std::cout << "x1: ";
            std::cin >> x1;
            std::cout << "y1: ";
            std::cin >> y1;
            correct = ((x1 > 9 || y1 > 9 || x1 < 0 || y1 < 0)
                || (field[n][y1][x1] == 1) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y1][x1] = 1;
        }
        do {
            std::cout << "x2: ";
            std::cin >> x2;
            std::cout << "y2: ";
            std::cin >> y2;
            correct = ((x2 > 9 || y2 > 9 || x2 < 0 || y2 < 0)
                || (field[n][y2][x2] == 1) || (x2 != x1 && y2 != y1)
                || (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y2][x2] = 1;
            showField(field, n);
            i++;
        }
    } while (!correct || i < 3);
    bool horizontal;
    i = 0;
    do {
        int x1, y1;
        int x2, y2;
        std::cout << "Choose where to put 3 square ship:" << std::endl;
        do {
            std::cout << "x1: ";
            std::cin >> x1;
            std::cout << "y1: ";
            std::cin >> y1;
            correct = ((x1 > 9 || y1 > 9 || x1 < 0 || y1 < 0)
                || (field[n][y1][x1] == 1) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y1][x1] = 1;
        }
        do {
            std::cout << "x2: ";
            std::cin >> x2;
            std::cout << "y2: ";
            std::cin >> y2;
            correct = ((x2 > 9 || y2 > 9 || x2 < 0 || y2 < 0) || (field[n][y2][x2] == 1)
                || (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y2][x2] = 1;
        }
        horizontal = (x1 != x2 ? true : false);
        x1 = x2;
        y1 = y2;
        do {
            std::cout << "x3: ";
            std::cin >> x2;
            std::cout << "y3: ";
            std::cin >> y2;
            correct = ((x2 > 9 || y2 > 9 || x2 < 0 || y2 < 0) || (field[n][y2][x2] == 1)
                || (abs(x2 - x1) > 1 || abs(y2 - y1) > 1)
                || ((horizontal && x1 == x2) || (!horizontal && y1 == y2)) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y2][x2] = 1;
            showField(field, n);
            i++;
        }
    } while (!correct || i < 2);
    i = 0;
    do {
        int x1, y1;
        int x2, y2;
        std::cout << "Choose where to put 4 square ship:" << std::endl;
        do {
            std::cout << "x1: ";
            std::cin >> x1;
            std::cout << "y1: ";
            std::cin >> y1;
            correct = ((x1 > 9 || y1 > 9 || x1 < 0 || y1 < 0)
                || (field[n][y1][x1] == 1) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y1][x1] = 1;
        }
        do {
            std::cout << "x2: ";
            std::cin >> x2;
            std::cout << "y2: ";
            std::cin >> y2;
            correct = ((x2 > 9 || y2 > 9 || x2 < 0 || y2 < 0) || (field[n][y2][x2] == 1)
                || (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y2][x2] = 1;
        }
        horizontal = (x1 != x2 ? true : false);
        x1 = x2;
        y1 = y2;
        do {
            std::cout << "x3: ";
            std::cin >> x2;
            std::cout << "y3: ";
            std::cin >> y2;
            correct = ((x2 > 9 || y2 > 9 || x2 < 0 || y2 < 0) || (field[n][y2][x2] == 1)
                || (abs(x2 - x1) > 1 || abs(y2 - y1) > 1)
                || ((horizontal && x1 == x2) || (!horizontal && y1 == y2)) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y2][x2] = 1;
        }
        x1 = x2;
        y1 = y2;
        do {
            std::cout << "x4: ";
            std::cin >> x2;
            std::cout << "y4: ";
            std::cin >> y2;
            correct = ((x2 > 9 || y2 > 9 || x2 < 0 || y2 < 0) || (field[n][y2][x2] == 1)
                || (abs(x2 - x1) > 1 || abs(y2 - y1) > 1)
                || ((horizontal && x1 == x2) || (!horizontal && y1 == y2)) ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (correct) {
            field[n][y2][x2] = 1;
            showField(field, n);
            i++;
        }
    } while (!correct || i < 1);
    return field[n][10][10];
}

int main() {
    int field[2][10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field[0][i][j] = 0;
            field[1][i][j] = 0;
        }
    }
    showField(field, 0);
    prepareField(field, 0);
    showField(field, 1);
    prepareField(field, 1);
    std::cout << "Player 1:" << std::endl;
    showField(field, 0);
    std::cout << "Player 2:" << std::endl;
    showField(field, 1);
    int i = 0, j = 0;
    while (i < 20 && j < 20) {
        int x, y;
        std::cout << "Player 1 shooting:" << std::endl;
        bool correct = true;
        do {
            std::cout << "x: ";
            std::cin >> x;
            std::cout << "y: ";
            std::cin >> y;
            correct = (field[1][y][x] == 2 || field[1][y][x] == -1 ? false : true);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        if (field[1][y][x] == 1) {
            std::cout << "Hit!" << std::endl;
            field[1][y][x] = 2;
            i++;
            showField(field, 1);
        }
        else if (field[1][y][x] == 0) {
            std::cout << "Miss!" << std::endl;
            field[1][y][x] = -1;
            showField(field, 1);
        }
        if (i != 20) {
            std::cout << "Player 2 shooting:" << std::endl;
            do {
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "y: ";
                std::cin >> y;
                correct = (field[0][y][x] == 2 || field[0][y][x] == -1 ? false : true);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            if (field[0][y][x] == 1) {
                std::cout << "Hit!" << std::endl;
                field[0][y][x] = 2;
                j++;
                showField(field, 0);
            }
            else if (field[0][y][x] == 0) {
                std::cout << "Miss!" << std::endl;
                field[0][y][x] = -1;
                showField(field, 0);
            }
        }
    }
    if (i == 20) {
        std::cout << "Player 1 win!";
    }
    else if (j == 20) {
        std::cout << "Player 1 win!";
    }
}

/*
Требуется реализовать упрощённую игру в Морской бой. Игровое поле размером 10 на 10 клеток.
Участвует двое игроков. В арсенале каждого из них: 4 маленьких кораблика размером в одну клетку,
3 небольших корабля размером в две клетки, 2 средних корабля размером в три клетки и один большой
корабль размером в четыре клетки. Для простоты, клетки поля пронумерованы по вертикали от 0 до 9,
и по горизонтали также от 0 до 9. Мы не будем использовать классические наименования клеток, такие
как B4, C6, а просто два индекса. Вначале игроки по очереди расставляют корабли, начиная с самых
маленьких и заканчивая большими. Маленькие корабли в одну клетку расставляются с помощью указания
лишь одной клетки-точки на поле, к примеру 2,1. Корабли размерностью от двух клеток и выше, расставляются
с помощью координат их начала и конца, к примеру: 0,1 - 0,3. Корабли могут быть установлены только строго
вертикально, или горизонтально. Установка корабля по диагонали — недопустимо, в случае которого об этом тоже
надо сообщить пользователю. Если корабль не может быть размещён на заданных клетках из-за того, что он
столкнётся с другим кораблём (окажется на его клетках) или выйдет за пределы поля вообще, то игроку должно
быть сделано предупреждение, после которого он должен переставить корабль на новые валидные координаты.
Замечу, в нашем упрощённом варианте игры, мы не будем обсчитывать соприкосновения кораблей друг с другом,
а потому корабли вполне можно будет размещать друг к другу вплотную — борт к борту. После того как все корабли
были расставлены начинается игра. Игроки по очереди атакуют друг друга, называя координаты выстрела.
После выстрела, в консоль выводится информация о его результате: попал или мимо. Если выстрел успешен, клетка,
на которой был корабль (или его фрагмент) затирается и становится пустой. Игра заканчивается тогда, когда все
корабли одной из сторон будут полностью уничтожены. Как только это произойдёт в консоль выводится информация
с номером игрока, который победил.
*/