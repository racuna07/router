//
// Created by rodrigo on 10/11/17.
//

#include "ListenerThread.h"
#include <iostream>
#include <unistd.h>
#include "LegosInterface.h"
#include "Definitions.h"
#include "Socket.h"

using namespace std;


ListenerThread::ListenerThread(char* ip,int port) {
    this->legosUtils = new LegosUtils();
    this->ip = ip;
    this->port = port;
}

void ListenerThread::run() {
    cout<<"listening"<<endl;
    int childpid;
    char a[PHYSICAL_NETWORK_MSIZE];
    Socket s1('s',false), *s2;

    s1.Bind(this->ip,this->port);		// Port to access this mirror server

    s1.Listen( 5 );		// Set backlog queue to 5 conections


    for( ; ; ) {
        s2 = s1.Accept();	 	// Wait for a conection
        childpid = fork();	// Create a child to serve the request
        if ( childpid < 0 )
            perror("server: fork error");
        else if (0 == childpid) {  // child code
            s1.Close();	// Close original socket in child
            s2->Read( a, PHYSICAL_NETWORK_MSIZE ); // Read a string from client
            cout<<a<<endl;//aqui va logica
            this->processMessage(a);
            //s2->Write( a,PHYSICAL_NETWORK_MSIZE );	// Write it back to client
            exit( 0 );	// Exit
        }
        s2->Close();		// Close socket in parent
    }

}

void ListenerThread::processMessage(char *buffer) {
    PhysicalLayerMessage* message = legosUtils->unpackPhysicalMessage(buffer);
    messageQueueMutex.lock();
    messageQueue.push_back(message);
    messageQueueMutex.unlock();



}

PhysicalLayerMessage* ListenerThread::getMessage() {
    PhysicalLayerMessage* message;
    messageQueueMutex.lock();
    if(messageQueue.size()>0){
        list<PhysicalLayerMessage*>::iterator it = messageQueue.begin();
        message = messageQueue.front();
        messageQueue.pop_front();

    }else{
        message = nullptr;
    }
    messageQueueMutex.unlock();
    return message;
}
