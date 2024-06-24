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
    Matrix a(2, 3);
    Matrix b(3, 2);
    // Populate a and b with values...
    Matrix result = a.Multiply(a, b);
    // Assuming you have a way to verify the contents of result...
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
