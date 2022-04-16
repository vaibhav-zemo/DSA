#include <iostream>
#include <string>
using namespace std;

template <typename V>
class Mapnode
{
public:
    string key;
    V value;
    Mapnode<V> *next;

    Mapnode<V>(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Mapnode<V>()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    Mapnode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourmap<V>()
    {
        count = 0;
        numBuckets = 5;
        buckets = new Mapnode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap<V>()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V remove(string key)
    {
        int bucketIndex = getbucketIndex(key);
        Mapnode<V> *head = buckets[bucketIndex];
        Mapnode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }

                V ans = head->value;
                head->next = NULL;
                delete head;
                count--;
                return ans;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    V getvalue(string key)
    {
        int bucketIndex = getbucketIndex(key);
        Mapnode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getbucketIndex(string key)
    {
        int hashcode = 0;
        int coeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * coeff;
            hashcode = hashcode % numBuckets;
            coeff *= 37;
            coeff = coeff % numBuckets;
        }

        return hashcode % numBuckets;
    }

public:
    void rehasing()
    {
        Mapnode<V> **temp = buckets;
        buckets = new Mapnode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }

        int oldbuckets = numBuckets;
        numBuckets *= 2;
        count = 0;
        for (int i = 0; i < oldbuckets; i++)
        {
            Mapnode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldbuckets; i++)
        {
            Mapnode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getbucketIndex(key);
        Mapnode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }

            head = head->next;
        }
        head = buckets[bucketIndex];
        Mapnode<V> *node = new Mapnode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double load = (1.0 * count) / numBuckets;
        if (load > 0.7)
        {
            rehasing();
        }
    }
};

int main()
{
    ourmap<int> Map;
    for (int i = 0; i < 10; i++)
    {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        int value = i + 1;
        Map.insert(key, value);
    }
    cout << Map.size() << endl;

    Map.remove("abc4");
    Map.remove("abc8");
    cout << Map.size() << endl;

    for (int i = 0; i < 10; i++)
    {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        cout << key << " : " << Map.getvalue(key) << endl;
    }

    return 0;
}