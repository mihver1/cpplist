#include "list.h"

#define BOOST_TEST_MODULE
#include <boost/test/included/unit_test.hpp>
#include <boost/utility.hpp>

list<int> L;

BOOST_AUTO_TEST_CASE(test_push_mixed) {
    L.push_back(1);
    L.push_front(2);
    L.push_back(3);
    BOOST_CHECK_EQUAL((L.front()), 2);
    BOOST_CHECK_EQUAL(*(boost::next(L.begin(),1)), 1);
    BOOST_CHECK_EQUAL(*(boost::next(L.begin(),2)), 3);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_push_front) {
    L.push_front(1);
    BOOST_CHECK_EQUAL(L.front(), 1);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_push_back) {
    L.push_back(2);
    BOOST_CHECK_EQUAL(L.back(), 2);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_clear_size) {
    for(int i=0; i<100; ++i){
        L.push_front(i);
    }
    BOOST_CHECK_EQUAL(L.size(), 100);
    L.clear();
    BOOST_CHECK_EQUAL(L.size(), 0);
}

BOOST_AUTO_TEST_CASE(test_pop_back) {
    L.push_back(1);
    L.push_back(2);
    L.pop_back();
    BOOST_CHECK_EQUAL(L.back(), 1);
    BOOST_CHECK_EQUAL(L.size(), 1);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_pop_front) {
    L.push_back(1);
    L.push_front(2);
    L.pop_front();
    BOOST_CHECK_EQUAL(L.front(), 1);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_copy) {
    L.push_back(1);
    L.push_back(2);
    list<int> B(L);
    BOOST_CHECK_EQUAL(L.front(), 1);
    L.push_back(3);
    BOOST_CHECK_EQUAL(B.back(), 2);
    BOOST_CHECK_EQUAL(*(boost::prior(B.end(), 2)),1);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_assign) {
    L.push_back(1);
    L.push_back(2);
    list<int> B;
    B = L;
    BOOST_CHECK_EQUAL(L.front(), 1);
    L.push_back(3);
    BOOST_CHECK_EQUAL(B.back(), 2);
    BOOST_CHECK_EQUAL(*(boost::prior(B.end(), 2)),1);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_erase) {
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.erase(boost::next(L.begin()));
    BOOST_CHECK_EQUAL(L.front(), 1);
    BOOST_CHECK_EQUAL(L.back(), 3);
    BOOST_CHECK_EQUAL(L.size(), 2);
    L.clear();
}

BOOST_AUTO_TEST_CASE(test_insert) {
    L.push_back(1);
    L.push_back(2);
    L.insert(boost::next(L.begin()), 3);
    BOOST_CHECK_EQUAL(L.front(), 1);
    BOOST_CHECK_EQUAL(*(boost::next(L.begin())), 3);
    BOOST_CHECK_EQUAL(L.back(), 2);
    L.clear();
}