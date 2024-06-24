#include <gtest/gtest.h>
#include "../src/matrix.h" 

TEST(MatrixTest, HandlesConstruction) {
    Matrix m(2, 3);
    EXPECT_EQ(m.getRows(), 2);
    EXPECT_EQ(m.getCols(), 3);
}

// Test the get method
TEST(MatrixTest, HandlesGet) {
    Matrix m(2, 2);
    // Assuming you have a method to set values for testing
    m.set(0, 0, 1.0);
    m.set(0, 1, 2.0);
    m.set(1, 0, 3.0);
    m.set(1, 1, 4.0);
    EXPECT_EQ(m.get(0, 0), 1.0);
    EXPECT_EQ(m.get(1, 1), 4.0);
}

// Test the Multiply method
TEST(MatrixTest, HandlesMultiply) {
    std::vector<std::vector<double> > data1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double> > data2 = {{5, 6}, {7, 8}};
    Matrix a(data1);
    Matrix b(data2);

    // Populate a and b with values...
    Matrix result = a.Multiply(a, b);
    std::vector<std::vector<double>> res = {{19, 22}, {43, 50}};
    Matrix expected(res);
    bool equal = a.equals(result, expected);
    EXPECT_TRUE(equal);
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
