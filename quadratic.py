size = 10
client_list = [None] * size


def add_client():
    client_id = int(input("client id : "))
    name = input("client name : ")
    telephone = input("client telephone Number : ")
    client_details = [client_id, name, telephone]

    index = client_id % size
    # Inserting record using linear
    # probing in case of collision
    if client_list[index] == None:
           client_list[index] = client_details
           print("Client details added as : ", index, client_details)
    else:
           for j in range( 1, int((size-1)/2)) :
               t = (index + j * j) % size
               if client_list[t] == None:
                   client_list[t] = client_details
                   print("Client details added as : ", index, client_details)
                   break

    print("\n Client List :",client_list)

def search_client():
    client_id = int(input("Enter client id to be search : "))
    index = client_id % size
    cnt=0
    for i in range(size):
        
        if client_list[index] != None:
            cnt=cnt+1
            if client_list[index][0] == client_id:
                
                print("client is a found at index ", index, client_list[index])
                print("\n Number of comparisions required to search client id %d are %d."%(client_id,cnt)) 
                break
        index = (index + 1) % size
        
    else:
        print("element is not found")
    print("\n Number of comparisions required to search client id %d are %d."%(client_id,cnt)) 

#def quadratic_client():
	
'''def delete_client():
    client_id = int(input("client id"))
    index = client_id % size
    for i in range(size):
        if client_list[index] != None:
            if client_list[index][0] == client_id:
                client_list[index] = None
                print("cliet delted")
                break
        index = (index + 1) % size
    else:
        print("element is not found")'''



def Main() :
   Group_A = []
   Group_B = []
   Group_C = []
   
   while True :
       print ("\t1 : ADD Client")
       print ("\t2 : Serach Client")
       print ("\t3 : Quadratic Probing")
       print ("\t4: Exit")
       ch = int(input("Enter your choice : "))
       Group_R = []       
       if (ch == 3):
           print ("End of Program")
           break
       elif (ch==1):
             add_client()        
       elif (ch==2):
             search_client()
       else :
           print ("Wrong choice entered !! Try again")


Main()
quit()






