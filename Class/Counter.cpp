#include "Class.h"



Counter::Counter(int initialValue)
{
    counterResult = initialValue;
};

int Counter::getCounter()
{
    return counterResult;
};

int Counter::counterPlus() //увеличиваем счетчик на  единицу
{
    return ++counterResult;
};

int Counter::counterMinus() //уменьшаем счетчик на  единицу
{
    return --counterResult;
};
