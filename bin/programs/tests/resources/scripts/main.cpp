#define FAIL_IF_TRUE(cond, problem) if (cond)\
{\
    return problem;\
}

#define FAIL_IF_FALSE(cond, problem) FAIL_IF_TRUE(not (cond), problem)

#define FAIL(problem) return problem;

#define RUN_TEST(name, test)\
{\
    const char *res = test();\
    \
    if (res == NULL)\
    {\
        ++succeeded;\
    } else\
    {\
        ++failed;\
        \
        log("Test \"%s\" failed: %s\n", name, res);\
    }\
}

class TestHashMap
{
    public:
        static const char *equal()
        {
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(5, 2);
                
                FAIL_IF_FALSE(data == data2, "Two identical hash maps is not the same.");
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(5, 2);
                data2.set(2, 5);

                FAIL_IF_TRUE(data == data2, "Two different hash maps containing"
                                            " the same keys are the same.");
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(5, 5);

                FAIL_IF_TRUE(data == data2, "Two different hash maps containing"
                                            " a different value are the same.");
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                HashMap<int, int> data2;
                data2.set(0, 2);

                FAIL_IF_TRUE(data == data2, "Two different hash maps containing"
                                            " a different key are the same.");    
            }
            
            return NULL;
        }
        
        static const char *getAndSet()
        {
            {
                HashMap<int, int> data;
                data.set(5, 2);

                FAIL_IF_FALSE(data.get(5) == 2, "HashMap::get did not work.");
            }
            
            {
                HashMap<int, int> data;
                data.set(5, 2);

                try
                {
                    data.get(10);

                    FAIL("Did not catch a LookupException in the get fail test.")
                } catch (LookupException)
                {
                }
            }
            
            return NULL;
        }
        
        static const char *append()
        {
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

            FAIL_IF_FALSE(data == required, "HashMap::append did not work.")
            
            return NULL;
        }
        
        static const char *remove()
        {
            HashMap<int, int> required;
            required.set(5, 2);
            required.set(15, 6);

            HashMap<int, int> data;
            data.set(5, 2);
            data.set(10, 4);
            data.set(15, 6);

            data.remove(10);

            FAIL_IF_FALSE(data == required, "HashMap::remove did not work.")
            
            return NULL;
        }
        
        static const char *clear()
        {
            HashMap<int, int> data;
            data.set(5, 2);
            data.set(10, 4);
            data.set(15, 6);

            data.clear();
            
            FAIL_IF_FALSE(data.getEntryCount() == 0, "Hash map was not cleared.")
            
            return NULL;
        }
};

class TestList
{
    public:
        static const char *assignment()
        {
            List<int> data;
            data.append(5);
            
            List<int> data2;
            data2.append(10);
            
            List<int> data3;
            data3.append(5);
            
            data2 = data;
            
            FAIL_IF_FALSE(data2 == data3, "List assignment did not work.");
            
            return NULL;
        }
        
        static const char *copy()
        {
            List<int> data;
            data.append(5);
            
            List<int> data2 = data.copy();
            data2.clear();
            
            FAIL_IF_TRUE(data2 == data, "List::copy did not work.")
            
            return NULL;
        }
        
        static const char *equal()
        {
            {
                List<int> data;
                data.append(5);
                
                List<int> data2;
                data2.append(5);
                
                FAIL_IF_FALSE(data == data2, "Two identical lists are not the same.")
            }
            
            {
                List<int> data;
                data.append(5);
                
                List<int> data2;
                data2.append(5);
                data2.append(10);
                
                FAIL_IF_TRUE(data == data2, "Two lists of different sizes are the same.")    
            }
            
            {
                List<int> data;
                data.append(5);
                
                List<int> data2;
                data2.append(10);
                
                FAIL_IF_TRUE(data == data2, "Two lists with diffent elements are the same.")
            }
        
            return NULL;
        }
        
        static const char *indexing()
        {
            {
                List<int> data;
                data.append(5);
                
                FAIL_IF_FALSE(data[0] == 5, "List indexing does not work.")
            }
            
            {
                List<int> data;
                
                try
                {
                    int i = data[0];
                    
                    FAIL("List indexing worked.")
                } catch (BoundsException) {}
            }
            
            return NULL;
        }
        
        static const char *append()
        {
            List<int> required;
            required.append(5);
            required.append(10);
            
            List<int> data;
            data.append(5);
            
            List<int> data2;
            data2.append(10);
            
            data.append(data2);
            
            FAIL_IF_FALSE(data == required, "List::append does not work.")
            
            return NULL;
        }
        
        static const char *insertFront()
        {
            List<int> required;
            required.append(5);
            required.append(10);
            
            List<int> data;
            data.append(10);
            
            List<int> data2;
            data2.append(5);
            
            data.insert(0, data2);
            
            FAIL_IF_FALSE(data == required, "List::insert does not work (front).")
            
            return NULL;
        }
        
        static const char *insertMiddle()
        {
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
            
            FAIL_IF_FALSE(data == required, "List::insert does not work (middle).")
            
            return NULL;
        }
        
        static const char *insertBack()
        {
            List<int> required;
            required.append(5);
            required.append(10);
            
            List<int> data;
            data.append(5);
            
            List<int> data2;
            data2.append(10);
            
            data.insert(1, data2);
            
            FAIL_IF_FALSE(data == required, "List::insert does not work (back).")
            
            return NULL;
        }
        
        static const char *remove()
        {
            List<int> required;
            required.append(5);
            required.append(15);
            
            List<int> data;
            data.append(5);
            data.append(10);
            data.append(15);
            
            data.remove(1);
            
            FAIL_IF_FALSE(data == required, "List::remove does not work.")
            
            return NULL;
        }
        
        static const char *clear()
        {
            List<int> data;
            data.append(5);
            data.append(10);
            
            data.clear();
            
            FAIL_IF_FALSE(data.getCount() == 0, "List::clear does not work.")
            
            return NULL;
        }
};

BEGIN_SCRIPT
    virtual void init()
    {
        size_t succeeded = 0;
        size_t failed = 0;
        
        RUN_TEST("Hash map equality", TestHashMap::equal)
        RUN_TEST("Hash map get and set", TestHashMap::getAndSet)
        RUN_TEST("Hash map append", TestHashMap::append)
        RUN_TEST("Hash map remove", TestHashMap::remove)
        RUN_TEST("Hash map clear", TestHashMap::clear)
        
        RUN_TEST("List assignment", TestList::assignment)
        RUN_TEST("List copy", TestList::copy)
        RUN_TEST("List equal", TestList::equal)
        RUN_TEST("List indexing", TestList::indexing)
        RUN_TEST("List append", TestList::append)
        RUN_TEST("List insert front", TestList::insertFront)
        RUN_TEST("List insert middle", TestList::insertMiddle)
        RUN_TEST("List insert back", TestList::insertBack)
        RUN_TEST("List remove", TestList::remove)
        RUN_TEST("List clear", TestList::clear)
        
        size_t numTests = succeeded + failed;
        
        log("%zu out of %zu tests failed (%f%c).\n",
            failed,
            numTests,
            float(failed)/float(numTests)*100.0f,
            '%');
        
        app->running = false;
    }
END_SCRIPT
