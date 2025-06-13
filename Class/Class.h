#pragma once

class Counter //—оздаем класс "—четчик"
{
private:
    int counterResult = 0;

public:
    Counter(int initialValue);

    int getCounter();
    int counterPlus();
    int counterMinus();


};
