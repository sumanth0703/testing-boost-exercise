#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "Configuration.hpp"
#include "MatrixSolver.hpp"
#include "matrixIO.hpp"

using namespace Eigen;

struct matrixIOFixture {
  matrixIOFixture()
  {
    A = MatrixXd(3, 3);
    expectedA = MatrixXd(3, 3);
    expectedA << 2, 3, 4,
		 5, 6, 7,
		 8, 9, 1;
  }

  MatrixXd expectedA;
  MatrixXd A;
};

BOOST_FIXTURE_TEST_SUITE(matrixIOTests, matrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openData)
{
  A = matrixIO::openData("SampleData.csv", 3);

  for (int i = 0; i < 9; i++) 
  {
  BOOST_TEST(A(i) == expectedA(i));
  }
}

BOOST_AUTO_TEST_SUITE_END()
