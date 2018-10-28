#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <functional>


int version();


void Sort(std::vector<std::vector<int>> &ip_pool);


void Print(const std::vector<std::vector<int>> &ip_pool);


std::vector<std::vector<int>> filter_any(
  const std::vector<std::vector<int>> &ip_pool,
  const int &any_byte);


std::vector<std::string> split(const std::string &str, char d);
std::vector<int> strToInt(const std::vector<std::string> &ip);


// Filter by first N octets
template <typename ... Args>
std::vector<std::vector<int>> filter_pack(
  const std::vector<std::vector<int>> &ip_pool,
  Args const & ... args)
{
  std::vector<std::vector<int>> pool_filtered;
  std::vector<int> p {{args ...}};

  for (const auto &ip : ip_pool)
  {
    bool flag = true;
    for (auto i = 0; i < p.size(); ++i)
    {
      if (ip[i] != p[i])
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      pool_filtered.push_back(ip);
    }
  }

  return pool_filtered;
}
