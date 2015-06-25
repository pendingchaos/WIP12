class TestT2
{
    public:
        static int constructor()
        {
            TEST
            
            Int2 v;
            
            REQUIRE(v.x == 0 and v.y == 0)
            
            v = Int2(5, 10);
            
            REQUIRE(v.x == 5 and v.y == 10)
            
            v = Int2(15);
            
            REQUIRE(v.x == 15 and v.y == 15)
            
            return -1;
        }
        
        static int add()
        {
            TEST
            
            REQUIRE(Int2(1, 2) + Int2(2, 1) == Int2(3, 3))
            
            REQUIRE(Int2(1, 2) + 5 == Int2(6, 7))
            
            Int2 i(1, 2);
            i += Int2(2, 1);
            
            REQUIRE(i == Int2(3, 3))
            
            i = Int2(1, 2);
            i += 5;
            
            REQUIRE(i == Int2(6, 7))
            
            return -1;
        };
        
        static int subtract()
        {
            TEST
            
            REQUIRE(Int2(4, 5) - Int2(2, 1) == Int2(2, 4))
            
            REQUIRE(Int2(6, 7) - 5 == Int2(1, 2))
            
            Int2 i(4, 5);
            i -= Int2(2, 1);
            
            REQUIRE(i == Int2(2, 4))
            
            i = Int2(6, 7);
            i -= 5;
            
            REQUIRE(i == Int2(1, 2))
            
            return -1;
        };
        
        static int multiply()
        {
            TEST
            
            REQUIRE(Int2(1, 2) * Int2(2, 3) == Int2(2, 6))
            
            REQUIRE(Int2(1, 2) * 5 == Int2(5, 10))
            
            Int2 i(1, 2);
            i *= Int2(2, 3);
            
            REQUIRE(i == Int2(2, 6));
            
            i = Int2(1, 2);
            i *= 5;
            
            REQUIRE(i == Int2(5, 10));
            
            return -1;
        };
        
        static int divide()
        {
            TEST
            
            REQUIRE(Int2(10, 20) / Int2(10, 2) == Int2(1, 10))
            
            REQUIRE(Int2(100, 200) / 5 == Int2(20, 40))
            
            Int2 i(10, 20);
            i /= Int2(10, 2);
            
            REQUIRE(i == Int2(1, 10))
            
            i = Int2(100, 200);
            i /= 5;
            
            REQUIRE(i == Int2(20, 40))
            
            return -1;
        };
        
        static int comparison()
        {
            TEST
            
            REQUIRE(Int2(5, 10) == Int2(5, 10));
            REQUIRE(Int2(10, 5) != Int2(10, 6));
            REQUIRE(Int2(10, 5) != Int2(11, 5));
            REQUIRE(Int2(5, 2) < Int2(10, 5));
            REQUIRE(not (Int2(5, 2) < Int2(10, 1)))
            REQUIRE(Int2(10, 15) > Int2(5, 10))
            REQUIRE(not (Int2(10, 5) > Int2(5, 15)))
            REQUIRE(Int2(5, 2) <= Int2(5, 3))
            REQUIRE(Int2(5, 2) >= Int2(1, 2))
            
            return -1;
        }
        
        static int misc()
        {
            TEST
            
            REQUIRE(-Int2(10, 15) == Int2(-10, -15))
            REQUIRE(Int2(5, 10).sum() == 15)
            REQUIRE(Int2(16, 32).length() == 35) //Rounds down
            REQUIRE(Int2(16, 32).lengthSquared() == 1280)
            REQUIRE(Int2(10, 12).dot(Int2(15, 16)) == 342)
            
            return -1;
        }
};

#define T2_TESTS RUN_TEST(TestT2::constructor)\
RUN_TEST(TestT2::add)\
RUN_TEST(TestT2::subtract)\
RUN_TEST(TestT2::multiply)\
RUN_TEST(TestT2::divide)\
RUN_TEST(TestT2::comparison)\
RUN_TEST(TestT2::misc)
