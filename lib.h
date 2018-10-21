#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>


int version();

std::vector<std::vector<std::string>> ReadData();

std::vector<std::string> split(const std::string &str, char d);
