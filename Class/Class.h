#pragma once

class Counter //������� ����� "�������"
{
private:
    int counterResult = 0;

public:
    Counter(int initialValue);

    int getCounter();
    int counterPlus();
    int counterMinus();


};
