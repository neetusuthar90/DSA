template <typename T>
class queue_Array
{
private:
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    queue_Array(T s)
    {
        data = new T[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }

    int getsize()
    {
        return size;
    }

    bool isempty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[2*capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++){
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            //cout << "Queue is full!" << endl;
            //return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex = -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    T front()
    {
        if (isempty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isempty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};
