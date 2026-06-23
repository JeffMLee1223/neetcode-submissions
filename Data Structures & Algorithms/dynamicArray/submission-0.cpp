class DynamicArray {
public:

    DynamicArray(int capacity) {
        _capacity  = capacity;
        length = 0;
        arr = new int[_capacity];

    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(length == _capacity){
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        if(length > 0){
            int value = arr[length -1];
            length--;
            return value;
        }
        return -1;
    }

    void resize() {
        _capacity *=2;
        int* newArr = new int[_capacity];
        for(int i = 0; i < length; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;

    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return _capacity;
    }
    ~DynamicArray(){
        delete[] arr;
    }
private:
    int length;
    int _capacity;
    int* arr;

};
