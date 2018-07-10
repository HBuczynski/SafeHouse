#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>

#define MAX_SIZE 1000
#define MAX_NUMBER 1000
using namespace boost::interprocess;
using namespace std;
int main ()
{

    uint8_t tab[1000];


   try{

        //Erase previous message queue
        message_queue::remove("message_queue");

        //Create a message_queue.
        message_queue mq
           (create_only               //only create
           ,"message_queue"           //name
           ,MAX_NUMBER                       //max message number
           ,MAX_SIZE//sizeof(tab)               //max message size
           );

      unsigned int priority;
      message_queue::size_type recvd_size;


      //Receive 100 numbers
         int number;
         vector<uint8_t> lol;
         lol.resize(1000);
         mq.receive(lol.data(), lol.size(), recvd_size, priority);

         lol.resize(recvd_size);
         lol.shrink_to_fit();
         cout << "Size:  " << lol.size() << endl;
         for(int i = 0; i < recvd_size; ++i)
         {
         std::cout << "Received: " << static_cast<int>(lol[i]) << std::endl;
         }


   }
   catch(interprocess_exception &ex){
      message_queue::remove("message_queue");
      std::cout << ex.what() << std::endl;
      return 1;
   }
   message_queue::remove("message_queue");
   return 0;
}
