#include "Counter.h"

Counter::Counter(int initialInitValue) //Êîíñòðóêòîð
{
    counterResult_ = initialInitValue;
};

int Counter::getCounter() //Ìåòîä ïðîñìîòðà çíà÷åíèÿ ýëåìåíòîâ äàííûõ
{
    return counterResult_;
};

int Counter::counterPlus() //Ìåòîä óâåëè÷åíèÿ çíà÷åíèÿ íà îäèí
{
    return ++counterResult_;
};

int Counter::counterMinus() //Ìåòîä óìåíüøåíèÿ çíà÷åíèÿ íà îäèí
{
    return --counterResult_;
};