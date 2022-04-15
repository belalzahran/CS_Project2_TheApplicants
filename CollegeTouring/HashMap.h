//
// Created by marti on 3/11/2022.
//

#ifndef HASHMAP_H
#define HASHMAP_H
#include <QDebug>
#include <vector>
using namespace std;

// Hash node class template
template <typename K, typename V>
class HashNode {
public:

    // key-value pair
    K key;
    V value;

    HashNode(const K &key, const V &value) :
    key(key), value(value){}

    K getKey() const {
        return key;
    }

    void setKey(const K& key){
        this->key = key;
    }

    V getValue() const {
        return value;
    }

    void setValue(const V& value) {
        this->value = value;
    }

};

// Hash map class template
template <typename K, typename V, typename Hash>
class HashMap {
private:
    static const int BUCKET_SIZE = 31;
    static const int SECOND_PRIME = 13;

    // an array for the values to be inserted into
    HashNode<K, V>* arr[BUCKET_SIZE];
    int count;
    Hash externalHashFunction; //Hash function specified by the type parameter

public:
    //class HashNode; // a (key, value) pair
    HashMap() {

        // construct zero initialized hash map of size 31
        count = 0;
        for(int index = 0; index < BUCKET_SIZE; index++)
        {
            arr[index] = nullptr;
        }
    }

    //copy constructor
    HashMap(const HashMap& otherMap)
    {
        for(int index = 0; index < BUCKET_SIZE; index++)
        {
            arr[index] = nullptr;
        }

        //Copies value of the other map to current map
        for(int index = 0; index < BUCKET_SIZE; index++)
        {
            if(otherMap.arr[index] != nullptr)
            {
                arr[index] = new HashNode<K, V>(otherMap.arr[index]->key, otherMap.arr[index]->value);
            }
        }
        count = otherMap.count;
    }

    //copy assignment
    HashMap& operator= (const HashMap& otherMap)
    {
        //Clears old contents of the map
        for(int index = 0; index < BUCKET_SIZE; index++)
        {
            if(arr[index] != nullptr)
            {
                delete arr[index];
                arr[index] = nullptr;
            }
        }

        //Copies value of the other map to current map
        for(int index = 0; index < BUCKET_SIZE; index++)
        {
            if(otherMap.arr[index] != nullptr)
            {
                arr[index] = new HashNode<K, V>(otherMap.arr[index]->key, otherMap.arr[index]->value);
            }
        }
        count = otherMap.count;

        return *this;
    }

    ~HashMap() {
        // deletes contents of the map
        for(int index = 0; index < BUCKET_SIZE; index++)
        {
            if(arr[index] != nullptr)
            {
                delete arr[index];
                arr[index] = nullptr;
            }
        }
    }

    /*!
     * Overloaded subscript operator
     * @param key
     * @return &arr[i]->value
     */
    V& operator[] (const K& key)
    {
        int hashValue = search(key);

        if(arr[hashValue] != nullptr && arr[hashValue]->key == key)
        {
            return arr[hashValue]->value;
        }
        else if(arr[hashValue] == nullptr)
        {
            arr[hashValue] = new HashNode<K, V>(key, V());
            return arr[hashValue]->value;
        }
        else
        {
            qDebug() << "Hash map is full.";
        }
    }

    /*!
     * Function to search the value for a given key
     * @param key
     * @return arr[i]->value
     */
    V get(const K &key) {

        int hashValue = search(key);

        // Returns the value if it is not nullptr and the key is the same
        if(arr[hashValue] != nullptr && arr[hashValue]->key == key)
        {
            return arr[hashValue]->value;
        }
        else
        {
            qDebug() << "Key Not Found.";
            return V();
        }
    }

    /*!
     * Keep probing until an empty slot is found.
     * Once an empty slot is found, insert k.
     *
     * @param key - element key
     * @param value - element value
     *
     */
    void put(const K &key, const V &value) {
        // Does not insert new value in a full container
        if(count >= BUCKET_SIZE)
        {
            qDebug() << "Hash map is full.";
            return;
        }

        // Hash index to insert given key
        int hashValue = search(key);

        // If the hash index IS null, then we can insert
        if (arr[hashValue] == nullptr) {
            arr[hashValue] = new HashNode<K, V>(key, value);;
            count++;
        }
        else if(arr[hashValue]->key == key)
        {
            // If we hash to a value with the same key, replace that value
            // with the new value
            remove(key);    // remove current node with the selected key
            arr[hashValue] = new HashNode<K, V>(key, value);;  // insert new node into idx
            count++;
        }

    }


    /*!
     * If we simply delete a key, then search may fail.
     * So slots of deleted keys are marked specially as “deleted” by
     * setting the slot to NULL
     *
     * @param key - element key
     */
    void remove(const K &key) {

        // Find the node
        int hashValue = search(key);

        // If key is found
        if (arr[hashValue] != nullptr && arr[hashValue]->key == key){
            delete arr[hashValue];
            arr[hashValue] = nullptr; // If found, set the idx to nullptr (available)
            count--;
        }
        else
        {
            qDebug() << "Key not found.";
        }
    }

    /*!
     * Function returns whether or not the map is empty
     * @return boolean
     */
    bool empty() const
    {
        return count == 0;
    }

    /*!
     * Function returns whether or not the map is full
     * @return boolean
     */
    bool full() const
    {
        return count == BUCKET_SIZE;
    }

    /*!
     * Function returns the number of elements inside of the map
     * @return integer - size
     */
    int size() const
    {
        return count;
    }

    // Type alias for iterator (Pointer to HashNode)
    using iterator = HashNode<K,V>*;

    iterator begin()
    {
        if(count == 0)
        {
            return nullptr;
        }
        return arr[0];
    }

    iterator end()
    {
        if(count == 0)
        {
            return nullptr;
        }
        return arr[BUCKET_SIZE];
    }

protected:

    // initial hashfunction h(x)
    virtual int hashFunc1(const K& key){
        return externalHashFunction(key) % BUCKET_SIZE;
    }

    // second (double) hashfunction h'(x)
    virtual int hashFunc2(const K& key){
        int idx = SECOND_PRIME - (externalHashFunction(key) % SECOND_PRIME);
        return idx;
    }

    //Probes and returns the hash value
    int search(const K& key)
    {
        int hashValue = hashFunc1(key);
        int j = 0;

        while (arr[hashValue] != nullptr && arr[hashValue]->key != key && j < BUCKET_SIZE) {
            // idx = (h(k) + j * h'(k)) mod N
            hashValue = (hashFunc1(key) + j * hashFunc2(key)) % BUCKET_SIZE;
            j++;
        }

        return hashValue;
    }

};

#endif //HASHMAP_H
