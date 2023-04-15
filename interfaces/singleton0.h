// http://cpp-reference.ru/patterns/creational-patterns/singleton/

// singleton0.h
class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(Singleton&);
public:
    static Singleton& getInstance() {
        static Singleton  instance;
        return instance;
    }
};
