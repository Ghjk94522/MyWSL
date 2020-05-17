#include <stddef.h>

template <typename T, int L>
class Iter; //Iter前置声明以定义CacheQueue中的begin, end迭代器

//模板参数T是数据元素的类型，L是CacheQueue可以包含的元素的最大数量
template <typename T, int L>
class CacheQueue
{
public:
    //类型别名
    using iterator = Iter<T, L>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    //CacheQueue的默认构造函数
    CacheQueue()
    {
        max_num = L;
        for (int i = 0; i < 101; i++)
            s[i] = 0;
        current_num = 0;
    };

    //下标访问操作符的重载函数，返回元素的引用
    //下标的顺序由小到大，表示上次使用时间由远及近（即下标为0的元素是最长时间没有使用的元素）
    //例如，队列元素从最久未使用到最近使用的元素依次为2 7 3 4，那么2的偏移量就是0，7的偏移量就是1，依次类推
    reference operator[](size_type idx){return &a[i]};

    //使用值为val的元素，如果有多个元素具有相同的值，则本次使用的是最久未被使用过的元素
    void use(value_type val);

    //向CacheQueue添加元素
    //当CacheQueue已满时，先pop出最长时间没有使用的元素，再加入新的元素
    //返回true表示添加前队列未满，返回false表示添加前队列已满
    bool push(value_type val);

    //从CacheQueue取出元素
    //将最长时间没有使用到的元素pop出来
    //返回true表示取出成功，false表示队列调用pop前为空
    bool pop();

    //返回迭代器对象begin，即指向最长时间未使用的元素的位置
    iterator begin() {return a[0]};

    //返回迭代器对象end，按照C++标准，end返回的迭代器对象指向最后一个元素的下一个位置，所以容器数据范围实际上是[begin,end)
    iterator end();

    // swap the node for the function sort
    void swap_nodes(int i, int j);

    // sort the array with the timer
    void sort_nodes();

private:
    //...
    T a[101];
    int s[101];
    int max_num;
    int current_num;
};

template <typename T, int L>
void CacheQueue<T, L>::swap_nodes(int i, int j)
{
    // swap the timer
    int t = s[i];
    s[i] = s[j];
    s[j] = t;
    // swap the value
    T temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

template <typename T, int L>
void CacheQueue<T, L>::sort_nodes()
{
    for (int i = 0; i < current_num; i++)
    {
        for (int j = i + 1; j < current_num; j++)
        {
            if (s[i] < s[j])
                swap_nodes(i, j);
        }
    }
}

template <typename T, int L>
void CacheQueue<T, L>::use(value_type val)
{
    int tar = -1;
    int temp_life = -1;
    for (int i = 0; i < current_num; i++)
    {
        if (a[i] == val && s[i] > temp_life)
        {
            tar = i;
            temp_life = s[i];
        }
    }
    if (tar >= 0)
    {
        // update the lifetime of the elements
        for (int i = 0; i < current_num; i++)
            s[i]++;
        s[tar] = 1;
        sort_nodes();
    }
}

template <typename T, int L>
bool CacheQueue<T, L>::push(value_type val)
{
    if (current_num < num){
        // the container is not full yet
        for(int i = 0; i < current_num; i++){
            s[i]++;
        }
        a[current_num] = val;
        s[current_num++] = 1;
        sort_nodes();
        return true;
    }
    else{
        // the container is full already
        for(int i = 0; i < current_num; i++){
            s[i]++;
        }
        a[current_num-1] = val;
        s[current_num-1] = 1;
        sort_nodes();
        return false;
    }
}

template<typename T, int L>
bool CacheQueue<T, L>::pop(){
    if(current_num == 0) return false;
    for(int i = 0; i < current_num-1; i++){
        swap_nodes(i, i+1);
    }
    current_num--;
    for(int i = 0; i < current_num; i++) s[i]++;
}

