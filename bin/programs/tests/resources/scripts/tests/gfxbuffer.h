class TestGfxBuffer
{
    public:
        static int test(GfxApi *gfxApi)
        {
            TEST
            
            GfxBuffer *buffer = gfxApi->createBuffer();
            
            buffer->allocData(16, NULL, GfxBufferUsage::Static);
            
            REQUIRE(buffer->getSize() == 16)
            
            DELETE(buffer);
            
            buffer = gfxApi->createBuffer();
            
            buffer->allocData(5, "Heya!", GfxBufferUsage::Static);
            
            char data[4];
            buffer->getData(1, 4, data);
            REQUIRE(data[0] == 'e' and data[1] == 'y' and data[2] == 'a' and data[3] == '!')
            
            buffer->setData(1, 4, "abcd");
            
            char data2[5];
            buffer->getData(0, 5, data);
            REQUIRE(data[0] == 'H' and data[1] == 'a' and data[2] == 'b' and data[3] == 'c' and data[4] == 'd')
            
            DELETE(buffer);
            
            return -1;
        }
};

#define GFX_BUFFER_TESTS(gfxapi) RUN_TEST(TestGfxBuffer::test, gfxapi)
