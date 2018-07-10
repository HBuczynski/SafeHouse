#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>

#include <chrono>
#include <thread>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>


using namespace boost::interprocess;
using namespace std;

int main(int argc, char *argv[])
{

    named_mutex mutex(open_only, "fstream_named_mutex");

    //Open already created shared memory object.
    shared_memory_object shm (open_only, "MySharedMemory", read_only);

    //Map the whole shared memory in this process
    mapped_region region(shm, read_only);

    vector<uint8_t> vec;
    vec.resize(region.get_size());

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        uint8_t *mem;
        {
            scoped_lock<named_mutex> lock(mutex);
            //Check that memory was initialized to 1
            mem = reinterpret_cast<uint8_t* >(region.get_address());
        }

        memcpy(vec.data(), mem, region.get_size());
        vec.resize(vec[0]);
        vec.shrink_to_fit();
        for(int i=0; i <vec.size(); ++i)
        {
            cout << static_cast<int>(vec[i]) << endl;
        }
    }

   
   return 0;
}
