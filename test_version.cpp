#define BOOST_TEST_MODULE ip_filter_test_module

#include <boost/test/unit_test.hpp>

#include "lib.h"


BOOST_AUTO_TEST_SUITE(ip_filter_test_suite)

BOOST_AUTO_TEST_CASE(ip_filter_test_version)
{
  BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(ip_filter_test_sort)
{
  std::vector<std::vector<int>> case_1 =     {{1, 2, 3, 0},
                                              {1, 2, 3, 4}};
  std::vector<std::vector<int>> case_1_exp = {{1, 2, 3, 4},
                                              {1, 2, 3, 0}};
  std::vector<std::vector<int>> case_2 =     {{1, 2, 3, 4},
                                              {10, 25, 3, 4}};
  std::vector<std::vector<int>> case_2_exp = {{10, 25, 3, 4},
                                              {1, 2, 3, 4}};
  Sort(case_1);
  BOOST_CHECK(case_1 == case_1_exp);

  Sort(case_2);
  BOOST_CHECK(case_2 == case_2_exp);
}

BOOST_AUTO_TEST_CASE(ip_filter_test_filter_1)
{
  std::vector<std::vector<int>> case_1 =     {{1, 2, 3, 4},
                                              {10, 2, 3, 4},
                                              {100, 2, 3, 4}};
  std::vector<std::vector<int>> case_1_exp = {{1, 2, 3, 4}};

  auto case_1_res = filter_pack(case_1, 1);
  BOOST_CHECK(case_1_res == case_1_exp);
}

BOOST_AUTO_TEST_CASE(ip_filter_test_filter_2)
{
  std::vector<std::vector<int>> case_1 =     {{1, 2, 3, 4},
                                              {10, 2, 3, 4},
                                              {100, 2, 3, 4}};
  std::vector<std::vector<int>> case_1_exp = {{10, 2, 3, 4}};

  auto case_1_res = filter_pack(case_1, 10, 2, 3);
  BOOST_CHECK(case_1_res == case_1_exp);
}

BOOST_AUTO_TEST_CASE(ip_filter_test_filter_any)
{
  std::vector<std::vector<int>> case_1 =     {{1, 2, 3, 4},
                                              {10, 2, 3, 4},
                                              {100, 2, 3, 4}};
  std::vector<std::vector<int>> case_1_exp = {{100, 2, 3, 4}};

  auto case_1_res = filter_any(case_1, 100);
  BOOST_CHECK(case_1_res == case_1_exp);
}

BOOST_AUTO_TEST_SUITE_END()
