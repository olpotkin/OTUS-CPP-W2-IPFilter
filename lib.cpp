#include "version.h"
#include "lib.h"

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


void Sort(std::vector<std::vector<std::string>> &ip_pool)
{
  // Reverse lexicographically sort
  for (auto i = 1; i < ip_pool.size(); ++i)
  {
    for (auto j = 0; j < ip_pool.size() - i; ++j)
    {
      // Check which octect is not equal for 2 ip-addresses
      auto octet = 0;
      for (octet; octet < ip_pool[0].size(); ++octet)
      {
        if (std::stoi(ip_pool[j][octet]) != std::stoi(ip_pool[j + 1][octet]))
        {
          if (std::stoi(ip_pool[j][octet]) < std::stoi(ip_pool[j + 1][octet]))
          {
            std::swap(ip_pool[j], ip_pool[j + 1]);
          }
          break;
        }
      }
    }
  }
}


void Print(const std::vector<std::vector<std::string>> &ip_pool)
{
  for (const auto &ip : ip_pool)
  {
    for (auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
    {
      if (ip_part != ip.cbegin())
      {
        std::cout << ".";
      }
      std::cout << *ip_part;
    }
    std::cout << std::endl;
  }
}


// Filter by first byte
std::vector<std::vector<std::string>> filter(
  const std::vector<std::vector<std::string>> &ip_pool,
  const uint &first_byte)
{
  std::vector<std::vector<std::string>> pool_filtered;

  for (const auto &ip : ip_pool)
  {
    if (std::stoi(ip[0]) == first_byte)
    {
      pool_filtered.push_back(ip);
    }
  }
  return pool_filtered;
}


// Filter by first and second bytes
std::vector<std::vector<std::string>> filter(
  const std::vector<std::vector<std::string>> &ip_pool,
  const uint &first_byte,
  const uint &second_byte)
{
  std::vector<std::vector<std::string>> pool_filtered;

  for (const auto &ip : ip_pool)
  {
    if (std::stoi(ip[0]) == first_byte
        && std::stoi(ip[1]) == second_byte)
    {
      pool_filtered.push_back(ip);
    }
  }
  return pool_filtered;
}


std::vector<std::vector<std::string>> filter_any(
  const std::vector<std::vector<std::string>> &ip_pool,
  const uint &any_byte)
{
  std::vector<std::vector<std::string>> pool_filtered;

  for (const auto &ip : ip_pool)
  {
    for (const auto &ip_part : ip)
    {
      if (std::stoi(ip_part) == any_byte)
      {
        pool_filtered.push_back(ip);
        break; // exit from this loop
      }
    }
  }
  return pool_filtered;
}
