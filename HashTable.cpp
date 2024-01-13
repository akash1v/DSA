class HashTable
{
private:
    int* array;
    int size;

    int hash(int);
    int _hash(int);
public:
    HashTable(int);
    void insert(int);
    bool search(int);
    int remove(int);
    ~HashTable();
};

int HashTable::hash(int data){
    return data%10;
}

int HashTable::_hash(int data){
    return data%11;
}

HashTable::HashTable(int a){
    array = new int[a]{};
    size = a;
}

void HashTable::insert(int data){

    int index{},i{};
    while(i < size){
        if(array[index] == 0){
            array[index] = data;
            return;
        }
        index = (hash(data) + i* _hash(data))%size;
        i++;
    }
}

bool HashTable::search(int data){

    int index{},i{};
    while(i < size ){
        if(array[index] == data){    return true;    }
        index = (hash(data) + i* _hash(data))%size;
        i++;
    }
    return false;
}

int HashTable::remove(int data){
    
    int index{},i{};
    while(index < size ){
        if(array[index] == data){
            int val = array[index];
            array[index] = 0;
            return val;
        }
        index = (hash(data) + i* _hash(data))%size;
        i++;
    };
    return 0;
}
HashTable::~HashTable()
{
    delete[] array;
}
