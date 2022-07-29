#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // Return the size of priority queue
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq.at(0);
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        int lastIndex = pq.size() - 1;
        pq[0] = pq[lastIndex];
        pq.pop_back();

        int PI = 0;
        int LCI = 2 * PI + 1;
        int RCI = 2 * PI + 2;

        while(LCI < pq.size())
        {
            int minIndex = PI;
            if (pq[minIndex] > pq[LCI])
            {
                minIndex = LCI;
            }
            if (RCI < pq.size() && pq[minIndex] > pq[RCI])
            {
                minIndex = RCI;
            }
            
            if(minIndex == PI){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[PI];
            pq[PI] = temp;

            PI = minIndex;
            LCI = 2 * PI + 1;
            RCI = 2 * PI + 2;
        }
        return ans;
    }
};
