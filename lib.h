#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>


int version();

std::vector<std::vector<std::string>> ReadData();

void Sort(std::vector<std::vector<std::string>> &ip_pool);

void Print(const std::vector<std::vector<std::string>> &ip_pool);

std::vector<std::string> split(const std::string &str, char d);

