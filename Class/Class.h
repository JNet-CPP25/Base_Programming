#pragma once

class Counter //Создаем класс "Счетчик"
{
private:
    int counterResult = 0;

public:
    Counter(int initialValue);

    int getCounter();
    int counterPlus();
    int counterMinus();


};
