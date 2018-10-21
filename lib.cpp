#include "lib.h"
#include "version.h"

int version()
{
    return PROJECT_VERSION_PATCH;
}

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<std::vector<std::string>> ReadData()
{
    try
    {
        std::vector<std::vector<std::string>> ip_pool; // 2d vector: L1 index -> L2 ip address octets
        std::ifstream in_data ("ip_filter.tsv");       // Define an input file stream

        // Reading from the file line by line
        if (in_data.is_open())
        {
            for (std::string line; std::getline(in_data, line);)
            {
                // Parsing an input string from the file
                std::vector<std::string> v = split(line, '\t');
                ip_pool.push_back(split(v.at(0), '.'));
            }
            in_data.close();
            return ip_pool;
        }
        else
        {
            std::cout << "Unable to open the file";
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
