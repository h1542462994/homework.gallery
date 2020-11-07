// @environ=ubuntu18.04，c11

#include <iostream>
#include <semaphore.h>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <pthread.h>
#include <sstream>
#include <ctime>
#include <sys/time.h>

typedef void* thread_func(void*);

using namespace std;

class semaphore {
private:
    sem_t sem;
public:
    explicit semaphore(unsigned int value = 1, int pshared = 0){
        sem_init(&sem, pshared, value);
    }
    ~semaphore() {
        sem_destroy(&sem);
    }
    bool wait(){
        sem_wait(&sem);
        return true;
    }
    void post(){
        sem_post(&sem);
    }
    int value(){
        int v;
        sem_getvalue(&sem, &v);
        return v;
    }
};

#define BUFFER_SIZE 10
semaphore *lock;
semaphore *exist_count;
semaphore *remain_count;
int *buffer;
int index;
int running;
timeval producer_timeval{};
timeval customer_timeval{};
long producer_sleep;
long customer_sleep;

/* producer每步操作后的睡眠时间 */
int rand_time_producer(){
    return 1;
}

/* customer每步操作后的睡眠时间 */
int rand_time_customer() {
    return (int)(random() % 4);
}

/* 生产一个number */
int produce() {
    return (int)(random() % 50);
}

/* 工具函数，计算两者的时间差 ms */
long time_diff(const timeval& start_time,const timeval& end_time) {
    long second_diff = end_time.tv_sec - start_time.tv_sec;
    long microsecond_diff = end_time.tv_usec - start_time.tv_usec;
    long t_diff = second_diff * 1000 + microsecond_diff / 1000; // ms级别
    return t_diff;
}

/* 进行一次计时，并给出时间差 ms */
long record_time(timeval & record) {
    timeval current{};
    gettimeofday(&current, nullptr);
    long s;
    if(record.tv_sec == 0){
        s = 0;
    } else {
        s = time_diff(record, current);
    }
    record = current;
    return s;
}

/* 打印缓冲区的记录 */
void print_all(){
    cout << "[";
    for(int i = 0; i < index; ++i) {
        cout << buffer[i];
        if(i < index - 1){
            cout << ",";
        }
    }
    cout << "]";
}

/* 生产者进程 */
void * producer(void * args) {
    while (running) {
        int value = produce(); // 生产者生产了一个商品
        long last_sleep = producer_sleep; // 记录上一次睡眠的时间
        producer_sleep = rand_time_producer();
        remain_count->wait();  // 存储区满则等待
        lock->wait();  // 进入临界区
        buffer[index++] = value;
        long record = record_time(producer_timeval); // 获取记录的时间
        cout << "+" << record << "," << record - last_sleep * 1000; // 其中差值即为阻塞的时间
        print_all();
        cout << endl;
        lock->post();  // 退出临界区
        exist_count->post();

        sleep(producer_sleep);
    }
    return (void *)1;
}

/* 消费者进程 */
void * consumer(void * args) {
    while (running) {
        int value;
        long last_sleep = customer_sleep;
        customer_sleep = rand_time_customer();
        exist_count->wait();  // 存储区空则等待
        lock->wait();  // 进入临界区
        value = buffer[--index];
        long record = record_time(customer_timeval);
        cout << "-" << record << "," << record - last_sleep * 1000;
        print_all();
        cout << endl;
        lock->post();
        remain_count->post();

        sleep(customer_sleep);
    }

    return (void *)1;
}


int main() {
    lock = new semaphore(1);
    exist_count = new semaphore(0);
    remain_count = new semaphore(BUFFER_SIZE);
    buffer = new int[BUFFER_SIZE];
    index = 0;
    unsigned seed;
    seed = time(nullptr);
    srand(seed);
    running = 1;
    pthread_t tid_producer;
    pthread_t tid_consumer;
    pthread_create(&tid_producer, nullptr, producer, (void *)1);
    pthread_create(&tid_consumer, nullptr, consumer, (void *)1);

    string line;
    getline(cin, line);

    delete lock;
    delete exist_count;
    delete remain_count;
    delete buffer;
}
