#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>

using namespace boost::interprocess;
using namespace std;

int main ()
{
    vector<uint8_t> lol= {1,2,3,4,3,2,4,3,3,2,2,2,4,5,3,2,14,5,2,4,33,4,92,90};
   try{
        //Open a message queue.
        message_queue mq
           (open_only        //only create
           ,"message_queue"  //name
           );

      //Send 100 numbers
      //for(int i = 0; i < 100; ++i){
        // mq.send(&i, sizeof(i), 0);
      //}

        uint8_t tab[1000];
        //Receive 100 numbers
        for(int i = 0; i < 1000; ++i)
        {
            tab[i] = i;
        }

        mq.send(lol.data(), lol.size(), 0);

   }
   catch(interprocess_exception &ex){
      std::cout << ex.what() << std::endl;
      return 1;
   }

   return 0;
}
