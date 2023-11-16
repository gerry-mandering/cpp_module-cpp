#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
    long serialNumber;
    int value;

    Data(long serialNumber, int value): serialNumber(serialNumber), value(value) {};
};

#endif