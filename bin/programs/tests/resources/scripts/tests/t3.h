class TestT3
{
    public:
        static int constructor()
        {
            TEST
            
            Int3 v;
            
            REQUIRE(v.x == 0 and v.y == 0 and v.z == 0)
            
            v = Int3(5, 10, 15);
            
            REQUIRE(v.x == 5 and v.y == 10 and v.z == 15)
            
            v = Int3(15);
            
            REQUIRE(v.x == 15 and v.y == 15 and v.z == 15)
            
            return -1;
        }
        
        static int add()
        {
            TEST
            
            REQUIRE(Int3(1, 2, 9) + Int3(2, 1, 3) == Int3(3, 3, 12))
            
            REQUIRE(Int3(1, 2, 3) + 5 == Int3(6, 7, 8))
            
            Int3 i(1, 2, 3);
            i += Int3(2, 1, 0);
            
            REQUIRE(i == Int3(3, 3, 3))
            
            i = Int3(1, 2, 3);
            i += 5;
            
            REQUIRE(i == Int3(6, 7, 8))
            
            return -1;
        };
        
        static int subtract()
        {
            TEST
            
            REQUIRE(Int3(4, 5, 7) - Int3(2, 1, 3) == Int3(2, 4, 4))
            
            REQUIRE(Int3(6, 7, 8) - 5 == Int3(1, 2, 3))
            
            Int3 i(4, 5, 7);
            i -= Int3(2, 1, 3);
            
            REQUIRE(i == Int3(2, 4, 4))
            
            i = Int3(6, 7, 8);
            i -= 5;
            
            REQUIRE(i == Int3(1, 2, 3))
            
            return -1;
        };
        
        static int multiply()
        {
            TEST
            
            REQUIRE(Int3(1, 2, 3) * Int3(2, 3, 4) == Int3(2, 6, 12))
            
            REQUIRE(Int3(1, 2, 3) * 5 == Int3(5, 10, 15))
            
            Int3 i(1, 2, 3);
            i *= Int3(2, 3, 4);
            
            REQUIRE(i == Int3(2, 6, 12));
            
            i = Int3(1, 2, 3);
            i *= 5;
            
            REQUIRE(i == Int3(5, 10, 15));
            
            return -1;
        };
        
        static int divide()
        {
            TEST
            
            REQUIRE(Int3(10, 20, 30) / Int3(10, 2, 15) == Int3(1, 10, 2))
            
            REQUIRE(Int3(100, 200, 300) / 5 == Int3(20, 40, 60))
            
            Int3 i(10, 20, 30);
            i /= Int3(10, 2, 15);
            
            REQUIRE(i == Int3(1, 10, 2))
            
            i = Int3(100, 200, 300);
            i /= 5;
            
            REQUIRE(i == Int3(20, 40, 60))
            
            return -1;
        };
        
        static int comparison()
        {
            TEST
            
            REQUIRE(Int3(5, 10, 6) == Int3(5, 10, 6));
            REQUIRE(Int3(10, 5, 6) != Int3(10, 6, 5));
            REQUIRE(Int3(5, 2, 1) < Int3(10, 5, 2));
            REQUIRE(not (Int3(5, 2, 1) < Int3(10, 1, 0)))
            REQUIRE(Int3(10, 15, 20) > Int3(5, 10, 15))
            REQUIRE(not (Int3(10, 5, 0) > Int3(5, 15, 20)))
            REQUIRE(Int3(5, 2, 6) <= Int3(5, 3, 6))
            REQUIRE(Int3(5, 2, 3) >= Int3(1, 2, 0))
            
            return -1;
        }
        
        static int misc()
        {
            TEST
            
            REQUIRE(-Int3(10, 15, 20) == Int3(-10, -15, -20))
            REQUIRE(Int3(5, 10, 15).sum() == 30)
            REQUIRE(Int3(16, 32, 64).length() == 73) //Rounds down
            REQUIRE(Int3(16, 32, 64).lengthSquared() == 5376)
            REQUIRE(Int3(10, 12, 13).dot(Int3(15, 16, 17)) == 563)
            
            return -1;
        }
};

#define T3_TESTS RUN_TEST(TestT3::constructor)\
RUN_TEST(TestT3::add)\
RUN_TEST(TestT3::subtract)\
RUN_TEST(TestT3::multiply)\
RUN_TEST(TestT3::divide)\
RUN_TEST(TestT3::comparison)\
RUN_TEST(TestT3::misc)
