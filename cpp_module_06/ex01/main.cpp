#include "Serializer.hpp"

int main(void)
{
    Data *data = new Data(1, 42);
    std::cout << "data->serialNumber: " << data->serialNumber << std::endl;
    std::cout << "data->value: " << data->value << std::endl;
    std::cout << std::endl;

    // Serialize data
    uintptr_t raw = Serializer::serialize(data);

    // Deserialize data
    Data *deserializeData = Serializer::deserialize(raw);

    // Compare data
    if (deserializeData == data)
    {
        std::cout << "Serialize and deserialize data are the same" << std::endl;
        std::cout << "deserializeData->serialNumber: " << deserializeData->serialNumber << std::endl;
        std::cout << "deserializeData->value: " << deserializeData->value << std::endl;
    }
    else
    {
        std::cout << "Serialize and deserialize data are not the same" << std::endl;
    }

    delete data;

    return 0;
}