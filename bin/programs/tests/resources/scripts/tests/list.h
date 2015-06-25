class TestList
{
    public:
        static int assignment()
        {
            TEST
            
            List<int> data;
            data.append(5);
            
            List<int> data2;
            data2.append(10);
            
            List<int> data3;
            data3.append(5);
            
            data2 = data;
            
            REQUIRE(data2 == data3);
            
            return -1;
        }
        
        static int copy()
        {
            TEST
            
            List<int> data;
            data.append(5);
            
            List<int> data2 = data.copy();
            data2.clear();
            
            REQUIRE(data2 != data)
            
            return -1;
        }
        
        static int equal()
        {
            TEST
            
            {
                List<int> data;
                data.append(5);
                
                List<int> data2;
                data2.append(5);
                
                REQUIRE(data == data2)
            }
            
            {
                List<int> data;
                data.append(5);
                
                List<int> data2;
                data2.append(5);
                data2.append(10);
                
                REQUIRE(data != data2)    
            }
            
            {
                List<int> data;
                data.append(5);
                
                List<int> data2;
                data2.append(10);
                
                REQUIRE(data != data2)
            }
        
            return -1;
        }
        
        static int indexing()
        {
            TEST
            
            {
                List<int> data;
                data.append(5);
                
                REQUIRE(data[0] == 5)
            }
            
            {
                List<int> data;
                
                try
                {
                    int i = data[0];
                    
                    FAIL()
                } catch (BoundsException) {}
            }
            
            return -1;
        }
        
        static int append()
        {
            TEST
            
            List<int> required;
            required.append(5);
            required.append(10);
            
            List<int> data;
            data.append(5);
            
            List<int> data2;
            data2.append(10);
            
            data.append(data2);
            
            REQUIRE(data == required)
            
            return -1;
        }
        
        static int insertFront()
        {
            TEST
            
            List<int> required;
            required.append(5);
            required.append(10);
            
            List<int> data;
            data.append(10);
            
            List<int> data2;
            data2.append(5);
            
            data.insert(0, data2);
            
            REQUIRE(data == required)
            
            return -1;
        }
        
        static int insertMiddle()
        {
            TEST
            
            List<int> required;
            required.append(5);
            required.append(10);
            required.append(15);
            
            List<int> data;
            data.append(5);
            data.append(15);
            
            List<int> data2;
            data2.append(10);
            
            data.insert(1, data2);
            
            REQUIRE(data == required)
            
            return -1;
        }
        
        static int insertBack()
        {
            TEST
            
            List<int> required;
            required.append(5);
            required.append(10);
            
            List<int> data;
            data.append(5);
            
            List<int> data2;
            data2.append(10);
            
            data.insert(1, data2);
            
            REQUIRE(data == required)
            
            return -1;
        }
        
        static int remove()
        {
            TEST
            
            List<int> required;
            required.append(5);
            required.append(15);
            
            List<int> data;
            data.append(5);
            data.append(10);
            data.append(15);
            
            data.remove(1);
            
            REQUIRE(data == required)
            
            return -1;
        }
        
        static int clear()
        {
            TEST
            
            List<int> data;
            data.append(5);
            data.append(10);
            
            data.clear();
            
            REQUIRE(data.getCount() == 0)
            
            return -1;
        }
};

#define LIST_TESTS RUN_TEST(TestList::assignment)\
RUN_TEST(TestList::copy)\
RUN_TEST(TestList::equal)\
RUN_TEST(TestList::indexing)\
RUN_TEST(TestList::append)\
RUN_TEST(TestList::insertFront)\
RUN_TEST(TestList::insertMiddle)\
RUN_TEST(TestList::insertBack)\
RUN_TEST(TestList::remove)\
RUN_TEST(TestList::clear)
