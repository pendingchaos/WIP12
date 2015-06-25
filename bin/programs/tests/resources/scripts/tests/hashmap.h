class TestHashMap
{
    public:
        static int equal()
        {
            TEST
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(5, 2);
                
                REQUIRE(data == data2);
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(5, 2);
                data2.set(2, 5);

                REQUIRE(data != data2);
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(5, 5);

                REQUIRE(data != data2);
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(0, 2);

                REQUIRE(data != data2);    
            }
            
            return -1;
        }
        
        static int getAndSet()
        {
            TEST
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                REQUIRE(data.get(5) == 2);
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                try
                {
                    data.get(10);

                    FAIL()
                } catch (LookupException)
                {
                }
            }
            
            return -1;
        }
        
        static int append()
        {
            TEST
            
            HashMap<int, int> required;
            required.set(5, 2);
            required.set(10, 4);
            required.set(15, 6);

            HashMap<int, int> data;
            data.set(5, 2);
            data.set(15, 6);

            HashMap<int, int> data2;
            data.set(10, 4);
            data.set(15, 6);

            data.append(data2);

            REQUIRE(data == required)
            
            return -1;
        }
        
        static int remove()
        {
            TEST
            
            HashMap<int, int> required;
            required.set(5, 2);
            required.set(15, 6);

            HashMap<int, int> data;
            data.set(5, 2);
            data.set(10, 4);
            data.set(15, 6);

            data.remove(10);

            REQUIRE(data == required)
            
            return -1;
        }
        
        static int clear()
        {
            TEST
            
            HashMap<int, int> data;
            data.set(5, 2);
            data.set(10, 4);
            data.set(15, 6);

            data.clear();
            
            REQUIRE(data.getEntryCount() == 0)
            
            return -1;
        }
};

#define HASHMAP_TESTS RUN_TEST(TestHashMap::equal)\
RUN_TEST(TestHashMap::getAndSet)\
RUN_TEST(TestHashMap::append)\
RUN_TEST(TestHashMap::remove)\
RUN_TEST(TestHashMap::clear)
