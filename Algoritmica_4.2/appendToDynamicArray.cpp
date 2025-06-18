#include "appendToDynamicArray.h"

enum class DynamicArrayMessage
{
    Exit
};

void appendToDynamicArray(int*& arr, int* arrActualSize, int* arrLogicalSize)
{
    int appendUserData = 0;
    bool stoppingActions = false;

    do
    {
        std::cout << "Ââåäèòå ýëåìåíò äëÿ äîáàâëåíèÿ(0 - âûõîä áåç äîáàâëåíèé):> ";
        std::cin >> appendUserData;

        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Âû ââåëè íåâåðíûå äàíííûå. Ìàññèâ äëÿ öåëî÷èñëåííûõ çíà÷åíèé.\n";
            std::cout << "Ââåäèòå ýëåìåíò äëÿ äîáàâëåíèÿ(0 - âûõîä áåç äîáàâëåíèé):> ";
            std::cin >> appendUserData;
        }
        if (appendUserData == static_cast<int> (DynamicArrayMessage::Exit))
        {
            bool stoppingActions = true;
            PrintDynamicArray(arr, *arrActualSize, *arrLogicalSize, stoppingActions);

            return;
        }

        //åñëè ìàññèâ çàïîëíåí
        if (*arrActualSize == *arrLogicalSize)
        {
            *arrActualSize *= 2; // óâåëè÷èâàåì ðàçìåð ìàññèâà âäâîå 
            int* arr2 = new int[*arrActualSize] {};

            // êîïèðîâàíèå ñòàðîãî ìàññèâà â íîâûé
            for (int i = 0; i < *arrLogicalSize; i++)
            {
                arr2[i] = arr[i];
            };

            arr = arr2; //ïðèñâàèâàåì àäðåñ íîâîãî ìàññèâà ñòàðîìó
            arr2 = nullptr; // îáíóëÿåì àäðåññ íîâîãî, óäàëèòñÿ îí ñàì.
        }
        arr[*arrLogicalSize] = appendUserData; // äîáàâëÿåì çíà÷åíèå â êîíåö ìàññèâà.
        ++*arrLogicalSize; //ïðèáàâëÿåì åäèíèöó ê ëîãè÷åñêîìó ðàçìåðó

        PrintDynamicArray(arr, *arrActualSize, *arrLogicalSize, stoppingActions);

    } while (true);
};