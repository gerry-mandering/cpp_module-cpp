#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange = BitcoinExchange::Builder()
                                                .setDataFileName("data.csv")
                                                .setInputFileName(argv[1])
                                                .build();
    exchange.run();

    return 0;
}