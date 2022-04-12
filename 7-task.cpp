#include <iostream>
#include <vector>

bool initial(bool poopyrka[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            poopyrka[i][j] = true;
        }
    }
    return poopyrka;
}

void showPoopyrka(bool poopyrka[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << (poopyrka[i][j] == true ? "o" : "x") << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    bool poopyrka[12][12];
    initial(poopyrka);
    showPoopyrka(poopyrka);
    for (int i = 0; i < 144;) {
        int x1, y1, x2, y2;
        bool correct = true;
        do {
            do {
                std::cout << "Input x1: ";
                std::cin >> x1;
                correct = (x1 >= 0 && x1 < 12 ? true : false);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            do {
                std::cout << "Input y1: ";
                std::cin >> y1;
                correct = (y1 >= 0 && y1 < 12 ? true : false);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            correct = (poopyrka[y1][x1] == true ? true : false);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        do {
            do {
                std::cout << "Input x2: ";
                std::cin >> x2;
                correct = (x2 >= 0 && x2 < 12 ? true : false);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            do {
                std::cout << "Input y2: ";
                std::cin >> y2;
                correct = (y2 >= 0 && y2 < 12 ? true : false);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            correct = (poopyrka[y2][x2] == true ? true : false);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        for (int k = y1; k <= y2; k++) {
            for (int j = x1; j <= x2; j++) {
                poopyrka[k][j] = false;
                std::cout << "Pop!" << std::endl;
                i++;
            }
        }
        showPoopyrka(poopyrka);
    }
}

/*
После посылки из Китая осталась спец. плёнка для бережной перевозки груза — пупырка. 
Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька — это всегда либо 
он целый, либо нет, т.е. true или false (тип массива bool). Для начала, требуется реализовать 
отдельную функцию инициализации пупырки начальным состоянием — полностью целая пупырка, т.е. 
все элементы true. Но это только самое начало.
Программа заключается в последовательном лопанье целых регионов пузырьков. Перед каждым таким 
лопаньем надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый. 
Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопанье. Пользователь вводит две
координаты: координаты начала региона и конца прямоугольного региона. Сама процедура лопанья пузырей 
должна быть реализована с помощью отдельной функции, все аргументы должны проверяться на их валидность, 
что они в в рамках диапазона возможных значений — иначе должна быть выведена ошибка. После лопанья каждого 
пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.
Лопанье должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает 
выполнение. В принципе, вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, т.к. она выполняется после каждого лопанья.
*/