template<typename t>
class smartarray{

private:
    t* array;
public:
    smartarray(int a){    array = new t[a];    }
    t& operator[](int a){    return array[a];    }
    ~smartarray(){    delete[] array;    }
};