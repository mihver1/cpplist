#include "list.h"
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MAIN

list L;

BOOST_AUTO_TEST_CASE( test1 ) {
    L.push_front(1);
    BOOST_CHECK(1 == 2);
}
