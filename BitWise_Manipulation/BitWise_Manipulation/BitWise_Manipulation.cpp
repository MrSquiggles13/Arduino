#include <string>
#include <iostream>

int main()
{
    bool iSaySo{true};

    while (iSaySo)
    {
        std::cout << "Hey test number: ";
        int x{ 0 };
        std::string binary{ "" };
        std::cin >> x;

        if (x >= 128)
        {
            x -= 128;
            binary += '1';
        }
        else
            binary += '0';

        if (x >= 64)
        {
            x -= 64;
            binary += '1';
        }
        else
            binary += '0';

        if (x >= 32)
        {
            x -= 32;
            binary += '1';
        }
        else
            binary += '0';

        if (x >= 16)
        {
            x -= 16;
            binary += '1';
        }
        else
            binary += '0';

        binary += ' ';

        if (x >= 8)
        {
            x -= 8;
            binary += '1';
        }
        else
            binary += '0';

        if (x >= 4)
        {
            x -= 4;
            binary += '1';
        }
        else
            binary += '0';

        if (x >= 2)
        {
            x -= 2;
            binary += '1';
        }
        else
            binary += '0';

        if (x >= 1)
        {
            x -= 1;
            binary += '1';
        }
        else
            binary += '0';

        std::cout << "\n\nIn Binary Bruh: " + binary;
        char select{ ' ' };
        std::cout << "\n\nNew One HomeSkill??[y|n]: ";
        std::cin >> select;
        if (select == 'y')
            iSaySo = true;
        else
            iSaySo = false;
    }

    return 0;
}
