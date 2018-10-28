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


std::vector<int> strToInt(const std::vector<std::string> &ip)
{
  std::vector<int> out;
  for (auto octet : ip)
  {
    out.push_back(std::stoi(octet));
  }
  return out;
}


// Custom comparator
bool comp (const std::vector<std::string> &lhs,
           const std::vector<std::string> &rhs)
{
  // Check which octect is not equal for 2 ip-addresses
  auto octet = 0;
  for (octet; octet < lhs.size(); ++octet)
  {
    // In case if octets are not equal
    if (lhs[octet] != rhs[octet])
    {
      // String comparison (numerical):
      // - If length of the first string greater than second -> value of first string is greater
      // - If lengths of strings are equal -> compare values
      if ((lhs[octet].length() > rhs[octet].length()) ||
          (lhs[octet].length() == rhs[octet].length() && lhs[octet] > rhs[octet]))
      {
        // lhs is greater than rhs
        return true;
      }
      break;
    }
  }
  // rhs is greater than lhs
  return false;
}


void Sort(std::vector<std::vector<int>> &ip_pool)
{
  // Reverse lexicographically sort
  //std::sort(ip_pool.begin(), ip_pool.end(), comp);
  std::sort(ip_pool.begin(), ip_pool.end(), std::greater<>());
}


void Print(const std::vector<std::vector<int>> &ip_pool)
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


std::vector<std::vector<int>> filter_any(
  const std::vector<std::vector<int>> &ip_pool,
  const int &any_byte)
{
  std::vector<std::vector<int>> pool_filtered;

  for (const auto &ip : ip_pool)
  {
    // Use stl algorithm std::any_of() with lambda function
    if (std::any_of(ip.begin(),
                    ip.end(),
                    [&any_byte](const int & octet) {
                      return octet == any_byte;
                    }))
    {
      pool_filtered.push_back(ip);
    }
  }
  return pool_filtered;
}
