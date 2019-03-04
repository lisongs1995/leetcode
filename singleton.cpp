#include <cpthread>
class Singleton {
private:
    static Singleton* instance;
    pthread_mutex_t mutex;
    Singleton(const Singleton& v);
    Singleton& operator=(const Singleton& v);
public:
    void get_instance(){
        pthread_mutex_lock(&mutex);
        if (instance == nullptr)
            instance = new Singleton;
        pthread_mutex_unlock(&mutex);
        return *instance;
    }
};

pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton* Singleton::instance = nullptr;
