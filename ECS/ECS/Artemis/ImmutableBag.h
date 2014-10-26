#ifndef _IMMUTBAG_H
#define _IMMUTBAG_H

#include <cstddef>

namespace artemis
{
    template<typename E>
    class ImmutableBag
    {
    public:
        virtual E get(int index) = 0;
        virtual int getCapacity() = 0;
        virtual int getCount() = 0;
        virtual bool isEmpty() = 0;
        virtual ~ImmutableBag(){};
    };
    
    /* 容器，动态数组，将类实体打包 */
    template<typename E>
    class Bag : public ImmutableBag<E>
    {
    public:
        Bag()
        {
            init(20);
        };
        
        Bag(int capacity)
        {
            init(capacity);
        };
        
        /**
         * 有可能这个包中有空隙，所以需要去除空隙
         */
        Bag<E> * getGapless()
        {
            Bag<E> * bag = new Bag<E>(this->count);
            for(int i=0; i < this->size; i++)
            {
                if(this->data[i] != NULL)
                {
                    bag->add(data[i]);
                }
            }
            return bag;
        }
        
        /**
         * 添加实体对象到包中
         * 不要混用add和set，有可能会让包产生空隙
         * 
         * 当空间不够的时候，包会自动扩大空间。
         */
        void add(E o)
        {
            if(size == count)grow();
            
            data[count++] = o;
        };
        
        void addAll(Bag<E> & bag)
        {
            for(int i=0; i < bag.size ; i++)
            {
                add(bag.data[i]);
            }
        };
        
        /**
         * 将所有集合置空，并不释放内存
         */
        void clear()
        {
            for(int i=0; i<size; i++)
            {
                data[i] = NULL;
            }
            count = 0;
        };
        
        bool contains(E o)
        {
            for(int i=0; i<count; i++)
                if(o == data[i])
                    return true;
            
            return false;
        };
        
        virtual E get(int index)
        {
            if (index >= size) return NULL;
            return (E)data[index];
        };
        
        virtual int getCapacity() {return size;};
        virtual bool isEmpty() {return count == 0;};
        virtual int getCount() {return count;};
        
        bool remove(E o)
        {
            for(int i=0; i<count; i++)
            {
                if(o == data[i])
                {
                    remove(i);
                    return true;
                }
            }
            return false;
        };
        
        E remove(int index)
        {
            if(count == 0) return NULL;
            
            E object = data[index];
            data[index] = data[count-1];
            data[count-1] = NULL;
            count--;
            return (E) object;
        };
        
        bool removeAll(Bag<E> bag)
        {
            bool mod = false;
            
            for(int i=0; i<bag.count; i++)
                for(int j= 0; j< count ; j++)
                    if(bag.data[i] == data[j])
                    {
                        remove(j);
                        j--; // ?
                        mod = true;
                        break;
                    }
            return mod;
        };
        
        E removeLast()
        {
            if(!isEmpty())
            {
                E object = data[count-1];
                data[count-1] = NULL;
                --count;
                return (E) object;
            }
            
            return NULL;
        };
        
        bool set(int index, E o)
        {
            if(index >= size) grow(index*2);
            
            if(o == NULL && data[index] != NULL)
            {
                count--;
            }
            else if(o != NULL && data[index] == NULL)
            {
                count++;
            };
            
            data[index] = o;
            return true;
        };
        
        void operator += (Bag<E> &bag)
        {
            addAll(bag);
        };
        
        void deleteData()
        {
            for(int i=0; i<size; i++)
            {
                delete data[i];
                data[i] = NULL;
            }
            count = 0;
        }
        
        virtual ~Bag<E>()
        {
            delete[] data;
        };
        
    private:
        void grow()
        {
            int newCapacity =(size * 3.0f) * 0.5f + 1.0f;
            grow(newCapacity);
        };
        
        /* 申请增加的空间 */
        void grow(int newCapacity)
        {
            E* newData = new E[newCapacity];
            
            for (int i = 0; i < size; i++)
                newData[i] = data[i];
            for (int i = size; i < newCapacity; i++)
                newData[i] = NULL;
            
            delete[] data;
            
            size = newCapacity;
            data = newData;
        };
        
        void init(int capacity)
        {
            size = capacity;
            count = 0;
            data = new E[capacity];
            clear();
        }
        
    private:
        int count;
        int size;
        E *data;
    };
};

#endif // $(Guard token)
