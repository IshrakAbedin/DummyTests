#define COLORED_TESTS // For colored tests if Terminal Supports, otherwise leave this undefined
#include "DummyTests/DummyTests.h"
#include "TestClass/TestClass.h"

TESTS_BEGIN // Basically provides the staring of main function

// TEST_UNIT("A unique name for the test") is used to write test for a single functionality
TEST_UNIT("ClasssUnderTest :: Getters and Setters")
{
    ClassUnderTest cut{10, 20};

    int m1 = cut.m1();
    int m2 = cut.m2();

    cut.m1() = m1 * 2;
    cut.m2() = m2 * 2;

    // TEST_ASSERT(e) checks the statement 'e' inside and passes or fails the test based on the evaluation of the expression 
    TEST_ASSERT(cut.m1() == 20 && cut.m2() == 40);
}

TEST_UNIT("ClasssUnderTest :: Equality and Inequality") // Will fail
{
    // If a test is dependent on a previous one, this TEST_REQUIRES("Dependent test name") can be used to raise warning if necessary
    TEST_REQUIRES("ClasssUnderTest :: Getters and Setters");

    ClassUnderTest cut1{10, 20};
    ClassUnderTest cut2;
    cut2.m1() = 10;
    cut2.m2() = 20;
    ClassUnderTest cut3{30};

    // TEST_ASSERT(cut1 == cut2 && cut1 != cut3); // This test is correct
    
    TEST_ASSERT(cut1 == cut2 && cut1 == cut3); // Intentionally wrongly tested to fail and show requirement failure in the next test(s) 
}

TEST_UNIT("ClasssUnderTest :: Take Away From M1")
{
    TEST_REQUIRES("ClasssUnderTest :: Getters and Setters");

    ClassUnderTest cut1{10, 20}; 
    ClassUnderTest cut2{5, 20};

    cut1.TakeAwayFromM1(7); 
    cut2.TakeAwayFromM1(7);

    TEST_ASSERT(cut1.m1() == 3 && cut2.m1() == 5); 
}

// ... ... ... other tests ... ... ...

TEST_UNIT("ClasssUnderTest :: Increase Both")
{
    TEST_REQUIRES("ClasssUnderTest :: Equality and Inequality"); // Not required in reality, but used to show requirement failure

    ClassUnderTest cut1{5, 15};
    ClassUnderTest cut2{10, 20}; 

    cut1.IncreaseBoth(5);

    TEST_ASSERT(cut1 == cut2); 
}

TESTS_END // Prints the result and closes the main function

