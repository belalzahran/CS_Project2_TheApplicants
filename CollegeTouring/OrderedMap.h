
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

    struct entry
    {
        entry() : key{KeyType()}, value{ValueType()} {}
        entry(const KeyType& key, const ValueType& value) : key{key}, value{value} {}

        KeyType key;
        ValueType value;
    };

    // Type alias for iterator as defined by entry*
    using iterator = entry*;


    OrderedMap() : array{std::vector<entry>()}, LessThan{LessThanComparator()}, count{0} {}

    //! Allows for access of a particular value
    /*!
        \param KeyType key
        \return Reference to the value with the corresponding key.
    */
    ValueType& operator[] (const KeyType& key)
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            return array[searchIndex].value;
        }
        else
        {
            iterator newEntry = insert(key, ValueType());
            return newEntry->value;
        }
    }

    //! Member function that returns a constant reference to a particular value
    /*!
        \param KeyType key
        \return Constant reference to the value with the corresponding key.
    */
    const ValueType& at(const KeyType& key) const
    {
        int searchIndex = search(key);

        if(searchIndex != -1)
        {
            return array[searchIndex].value;
        }
        else
        {
            qDebug() << "OrderedMap::at() Key does not exist";
            return ValueType();
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
            array[searchIndex].value = value;
            return &array[searchIndex];
        }
        else
        {
            //Insertion into correct key position (O(n) worse case)
            int traverseIndex = 0;
            while(traverseIndex < count && LessThan(array[traverseIndex].key, key))
            {
                traverseIndex++;
            }

            array.insert(array.begin() + traverseIndex, entry(key,value));
            count++;

            return &array[traverseIndex];
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
            array.erase(array.begin() + searchIndex);
            count--;
        }
        else
        {
            qDebug() << "OrderedMap::erase() Key does not exist.";
        }
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
            return &array[searchIndex];
        }
        else
        {
            return nullptr;
        }
    }

    //! A member function removes all of the values
    void clear()
    {
        array.clear();
        count = 0;
    }

    //! A member function that returns whether or not the map is empty
    /*!
        \return Boolean true/false
    */
    bool empty() const
    {
        return count == 0;
    }

    //! A member function that returns the size of the map
    /*!
        \return int size
    */
    int size() const
    {
        return count;
    }

    //Iterator that points to the beginning of the map
    iterator begin()
    {
        if(count == 0)
        {
            return nullptr;
        }
        else
        {
            return &array[0];
        }
    }

    //Iterator that points to the end of the map
    iterator end()
    {
        if(count == 0)
        {
            return nullptr;
        }
        else
        {
            return &array[count]; // One past last index
        }
    }

protected:

    //Performs binary search
    int search(const KeyType& key) const
    {
        int lowIndex = 0;
        int highIndex = count - 1;
        int midIndex;

        while(lowIndex <= highIndex && count != 0)
        {
            midIndex = (highIndex + lowIndex) / 2;
            if(array[midIndex].key == key) //Requires equality comparable key
            {
                return midIndex;
            }
            else if(LessThan(key, array[midIndex].key))
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
    std::vector<entry> array;
    LessThanComparator LessThan;
    int count;
};

#endif //ORDEREDMAP_H
