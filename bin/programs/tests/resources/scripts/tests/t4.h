class TestT4
{
    public:
        static int constructor()
        {
            TEST
            
            Int4 v;
            
            REQUIRE(v.x == 0 and v.y == 0 and v.z == 0 and v.w == 0)
            
            v = Int4(5, 10, 15, 20);
            
            REQUIRE(v.x == 5 and v.y == 10 and v.z == 15 and v.w == 20)
            
            v = Int4(15);
            
            REQUIRE(v.x == 15 and v.y == 15 and v.z == 15 and v.w == 15)
            
            return -1;
        }
        
        static int add()
        {
            TEST
            
            REQUIRE(Int4(1, 2, 9, 10) + Int4(2, 1, 3, 5) == Int4(3, 3, 12, 15))
            
            REQUIRE(Int4(1, 2, 3, 4) + 5 == Int4(6, 7, 8, 9))
            
            Int4 i(1, 2, 3, 4);
            i += Int4(2, 1, 0, 7);
            
            REQUIRE(i == Int4(3, 3, 3, 11))
            
            i = Int4(1, 2, 3, 4);
            i += 5;
            
            REQUIRE(i == Int4(6, 7, 8, 9))
            
            return -1;
        };
        
        static int subtract()
        {
            TEST
            
            REQUIRE(Int4(4, 5, 10, 8) - Int4(2, 1, 3, 2) == Int4(2, 4, 7, 6))
            
            REQUIRE(Int4(6, 7, 8, 9) - 5 == Int4(1, 2, 3, 4))
            
            Int4 i(4, 5, 7, 10);
            i -= Int4(2, 1, 3, 7);
            
            REQUIRE(i == Int4(2, 4, 4, 3))
            
            i = Int4(6, 7, 8, 10);
            i -= 5;
            
            REQUIRE(i == Int4(1, 2, 3, 5))
            
            return -1;
        };
        
        static int multiply()
        {
            TEST
            
            REQUIRE(Int4(1, 2, 3, 4) * Int4(2, 3, 4, 5) == Int4(2, 6, 12, 20))
            
            REQUIRE(Int4(1, 2, 3, 4) * 5 == Int4(5, 10, 15, 20))
            
            Int4 i(1, 2, 3, 4);
            i *= Int4(2, 3, 4, 5);
            
            REQUIRE(i == Int4(2, 6, 12, 20));
            
            i = Int4(1, 2, 3, 4);
            i *= 5;
            
            REQUIRE(i == Int4(5, 10, 15, 20));
            
            return -1;
        };
        
        static int divide()
        {
            TEST
            
            REQUIRE(Int4(10, 20, 30, 40) / Int4(10, 2, 15, 5) == Int4(1, 10, 2, 8))
            
            REQUIRE(Int4(100, 200, 300, 400) / 5 == Int4(20, 40, 60, 80))
            
            Int4 i(10, 20, 30, 40);
            i /= Int4(10, 2, 15, 5);
            
            REQUIRE(i == Int4(1, 10, 2, 8))
            
            i = Int4(100, 200, 300, 400);
            i /= 5;
            
            REQUIRE(i == Int4(20, 40, 60, 80))
            
            return -1;
        };
        
        static int comparison()
        {
            TEST
            
            REQUIRE(Int4(5, 10, 6, 7) == Int4(5, 10, 6, 7));
            REQUIRE(Int4(10, 5, 6, 7) != Int4(10, 6, 5, 8));
            REQUIRE(Int4(5, 2, 1, 3) < Int4(10, 5, 2, 5));
            REQUIRE(not (Int4(5, 2, 1, 8) < Int4(10, 1, 0, 9)))
            REQUIRE(Int4(10, 15, 20, 25) > Int4(5, 10, 15, 20))
            REQUIRE(not (Int4(10, 5, 0, 15) > Int4(5, 15, 20, 10)))
            REQUIRE(Int4(5, 2, 6, 1) <= Int4(5, 3, 6, 1))
            REQUIRE(Int4(5, 2, 3, 5) >= Int4(1, 2, 0, 5))
            
            return -1;
        }
        
        static int misc()
        {
            TEST
            
            REQUIRE(-Int4(10, 15, 20, 25) == Int4(-10, -15, -20, -25))
            REQUIRE(Int4(5, 10, 15, 20).sum() == 50)
            REQUIRE(Int4(16, 32, 64, 128).length() == 147) //Rounds down
            REQUIRE(Int4(16, 32, 64, 128).lengthSquared() == 21760)
            REQUIRE(Int4(10, 12, 13, 14).dot(Int4(15, 16, 17, 18)) == 815)
            
            return -1;
        }
};

#define T4_TESTS RUN_TEST(TestT4::constructor)\
RUN_TEST(TestT4::add)\
RUN_TEST(TestT4::subtract)\
RUN_TEST(TestT4::multiply)\
RUN_TEST(TestT4::divide)\
RUN_TEST(TestT4::comparison)\
RUN_TEST(TestT4::misc)
