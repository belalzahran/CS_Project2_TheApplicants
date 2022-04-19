
#ifndef ORDEREDMAP_H
#define ORDEREDMAP_H
#include <QDebug>
#include <vector>

//If the comparator isn't specified as a template argument, it uses the
//default, as defined here, instead. This also assumes that the key
//has the LessThan (<) relational operator overloaded.
template<typename KeyType>
struct DefaultLessThanComparator
{
    bool operator() (const KeyType& lkey, const KeyType& rkey) const
    {
        return lkey < rkey;
    }
};

//! Templated OrderedMap class
/*! Implemented using an ordered table. */
template<typename KeyType, typename ValueType, typename LessThanComparator = DefaultLessThanComparator<KeyType>>
class OrderedMap
{
public:

    struct Entry
    {
        Entry() : key{KeyType()}, value{ValueType()} {}
        Entry(const KeyType& key, const ValueType& value) : key{key}, value{value} {}

        KeyType key;
        ValueType value;
    };

    // Type alias for iterator and const_iterator
    using iterator = typename std::vector<Entry>::iterator;
    using const_iterator = typename std::vector<Entry>::const_iterator;


    OrderedMap() : array{std::vector<Entry>()}, LessThan{LessThanComparator()}, count{0} {}


    //! Allows for access of a particular value
    /*!
        \param KeyType key
        \return Reference to the value with the corresponding key.
    */
    ValueType& operator[](const KeyType& key)
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            return this->array[searchIndex].value;
        }
        else
        {
            iterator newEntry = insert(key, ValueType());
            return newEntry->value;
        }
    }

    //! Member function that returns a constant reference to a particular value
    /*! (Does not throw exception if key doesn't exist, returns a defaulted constructed value)
        \param KeyType key
        \return Constant reference to the value with the corresponding key.
    */
    const ValueType& at(const KeyType& key) const
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            return this->array[searchIndex].value;
        }
        else
        {
            qDebug() << "OrderedMap::at()const Key does not exist";
            return ValueType();
        }
    }

    //! Member function that returns a reference to a particular value
    /*! (Does not throw exception if key doesn't exist, manual check required)
        \param KeyType key
        \return Reference to the value with the corresponding key.
    */
    ValueType& at(const KeyType& key)
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            return this->array[searchIndex].value;
        }
        else
        {
            qDebug() << "OrderedMap::at() Key does not exist";
        }
    }

    //! A member function that inserts a particular value with an associated key
    /*!
        \param KeyType key
        \param ValueType value
        \return Reference an iterator to the newly inserted key|value pair
    */
    iterator insert(const KeyType& key, const ValueType& value)
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            //Change value at the index if the key already exists
            this->array[searchIndex].value = value;
            return this->array.begin() + searchIndex;
        }
        else
        {
            //Insertion into correct key position (O(n) worse case)
            int traverseIndex = 0;
            while(traverseIndex < this->count && this->LessThan(this->array[traverseIndex].key, key))
            {
                traverseIndex++;
            }

            this->array.insert(this->array.begin() + traverseIndex, Entry(key, value));
            this->count++;

            return this->array.begin() + traverseIndex;
        }
    }

    //! A member function that erases a value using an associated key
    /*! Removes a particular value.
        \param KeyType key
    */
    void erase(const KeyType& key)
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            this->array.erase(this->array.begin() + searchIndex);
            this->count--;
        }
        else
        {
            qDebug() << "OrderedMap::erase() Key does not exist.";
        }
    }


    //! A member function that checks the map and returns whether or not it contains the key
    /*!
        \param KeyType key
    */
    bool contains(const KeyType& key) const
    {
        return search(key) != -1;
    }

    //! A member function removes all of the values
    void clear()
    {
        this->array.clear();
        this->count = 0;
    }

    //! A member function that returns whether or not the map is empty
    /*!
        \return Boolean true/false
    */
    bool empty() const
    {
        return this->count == 0;
    }

    //! A member function that returns the size of the map
    /*!
        \return int size
    */
    int size() const
    {
        return this->count;
    }


    //! A member function that returns an iterator to the pair with an associated key
    /*!
        \param KeyType key
        \return iterator
    */
    iterator find(const KeyType& key)
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            return this->array.begin() + searchIndex;
        }
        else
        {
            return this->array.end();
        }
    }

    //! A member function that returns an iterator to the beginning Entry of the map
    /*!
        \return iterator
    */
    iterator begin()
    {
        return this->array.begin();
    }

    //! A member function that returns an iterator to the beginning Entry of the map
    /*!
        \return iterator
    */
    iterator end()
    {
       return this->array.end();
    }

    //! A member function that returns an const_iterator to the beginning Entry of the map
    /*!
        \return const_iterator
    */
    const_iterator cbegin() const
    {
        return this->array.cbegin();
    }

    //! A member function that returns an const_iterator to the beginning Entry of the map
    /*!
        \return const_iterator
    */
    const_iterator cend() const
    {
       return this->array.cend();
    }

protected:

    //Performs binary search (O(logn))
    int search(const KeyType& key) const
    {
        int lowIndex = 0;
        int highIndex = this->count - 1;
        int midIndex;

        while(lowIndex <= highIndex && this->count != 0)
        {
            midIndex = (highIndex + lowIndex) / 2;
            if(this->array[midIndex].key == key) //Requires equality comparable key
            {
                return midIndex;
            }
            else if(this->LessThan(key, this->array[midIndex].key))
            {
                highIndex = midIndex - 1;
            }
            else
            {
                lowIndex = midIndex + 1;
            }
        }

        return -1; // returns -1 if search did not find the key.
    }

private:
    std::vector<Entry> array;
    LessThanComparator LessThan;
    int count;
};

#endif //ORDEREDMAP_H
