#define BOOST_TEST_MODULE ServerTest

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "../PeriphManager.h"

BOOST_AUTO_TEST_SUITE( test_multiply )

BOOST_AUTO_TEST_CASE( test_int )
        {

                peripherials::PeriphManager::getInstance();
                

                BOOST_CHECK( 21 == 21);
        }

BOOST_AUTO_TEST_CASE( test_float )
        {
                BOOST_CHECK( 24.75 == 24.75);
        }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( test_computeInterest )

BOOST_AUTO_TEST_CASE( test_simple )
        {

        }

BOOST_AUTO_TEST_SUITE_END()

