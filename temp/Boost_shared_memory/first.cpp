#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>

#include <thread>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <chrono>

using namespace boost::interprocess;
using namespace std;

int main(int argc, char *argv[])
{
    named_mutex::remove("fstream_named_mutex");
     named_mutex mutex(create_only, "fstream_named_mutex");

      //Create a shared memory object.
      shared_memory_object::remove("MySharedMemory"); 
      shared_memory_object::remove("MySharedMemory");
      shared_memory_object shm (create_only, "MySharedMemory", read_write);
      //Set size
      

      vector<uint8_t> vec = {10,2,2,4,5,6,3,2,4,6,7,8,55,3,6,7,7};
      shm.truncate(1000);
       
      //Map the whole shared memory in this process
      mapped_region region(shm, read_write);
      uint32_t i =0;

    while(1)
    {

        uint8_t *data;
        {
        scoped_lock<named_mutex> lock(mutex);
        data = reinterpret_cast<uint8_t*>(region.get_address());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        vec[9] = i %256;
        ++i;
        copy(vec.begin(), vec.end(), data);
    }
    
    named_mutex::remove("fstream_named_mutex");
    shared_memory_object::remove("MySharedMemory");
      return 0;
}
