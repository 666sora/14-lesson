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
    for (int i = 0; i < 144; i++) {
        int x, y;
        bool correct = true;
        do {
            do {
                std::cout << "Input x: ";
                std::cin >> x;
                correct = (x >= 0 && x < 12 ? true : false);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            do {
                std::cout << "Input y: ";
                std::cin >> y;
                correct = (y >= 0 && y < 12 ? true : false);
                if (!correct) std::cout << "Invalid input" << std::endl;
            } while (!correct);
            correct = (poopyrka[y][x] == true ? true : false);
            if (!correct) std::cout << "Invalid input" << std::endl;
        } while (!correct);
        poopyrka[y][x] = false;
        showPoopyrka(poopyrka);
        std::cout << "Pop!" << std::endl;
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