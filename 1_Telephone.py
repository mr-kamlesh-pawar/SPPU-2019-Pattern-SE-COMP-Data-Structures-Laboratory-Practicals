# Consider telephone book database of N clients. Make use of a hash table
# implementation to quickly look up client’s telephone number. Make use of
# two collision handling techniques and compare them using number of
# comparisons required to find a set of telephone numbers

size = 3
client_list = [None] * size


def add_client():
    client_id = int(input("client id"))
    name = input("client name")
    telephone = input("client telephone")
    client_details = [client_id, name, telephone]

    index = client_id % size
    # Inserting record using linear
    # probing in case of collision
    for i in range(size):
        if client_list[index] == None:
            client_list[index] = client_details
            print("adding data", index, client_details)
            break
        else:
            index = (index + 1) % size


def search_client():
    client_id = int(input("client id"))
    index = client_id % size
    for i in range(size):
        if client_list[index] != None:
            if client_list[index][0] == client_id:
                print("client is a found at index ", index, client_list[index])
                break
        index = (index + 1) % size
    else:
        print("element is not found")


def delete_client():
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
        print("element is not found")


add_client()
add_client()
add_client()
print("serach client")
search_client()
print("deleted client")
delete_client()
print("search client")
search_client()

'''
#with two handling techniques

size = 3
client_list_linear = [None] * size
client_list_quadratic = [None] * size

def hash_function(client_id, probe_count, technique):
    if technique == "linear":
        return (client_id + probe_count) % size
    elif technique == "quadratic":
        return (client_id + probe_count**2) % size

def add_client_linear():
    client_id = int(input("client id"))
    name = input("client name")
    telephone = input("client telephone")
    client_details = [client_id, name, telephone]

    probe_count = 0
    index = hash_function(client_id, probe_count, "linear")
    
    while probe_count < size:
        if client_list_linear[index] is None:
            client_list_linear[index] = client_details
            print("adding data with linear probing at index", index, client_details)
            break
        else:
            probe_count += 1
            index = hash_function(client_id, probe_count, "linear")
    else:
        print("Hash table is full")

def add_client_quadratic():
    client_id = int(input("client id"))
    name = input("client name")
    telephone = input("client telephone")
    client_details = [client_id, name, telephone]

    probe_count = 0
    index = hash_function(client_id, probe_count, "quadratic")

    while probe_count < size:
        if client_list_quadratic[index] is None:
            client_list_quadratic[index] = client_details
            print("adding data with quadratic probing at index", index, client_details)
            break
        else:
            probe_count += 1
            index = hash_function(client_id, probe_count, "quadratic")
    else:
        print("Hash table is full")

# Example usage:
add_client_linear()
add_client_linear()
add_client_linear()

add_client_quadratic()
add_client_quadratic()
add_client_quadratic()



'''