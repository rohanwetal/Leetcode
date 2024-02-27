#include <mutex>        // Include for std::mutex
#include <functional>   // Include for std::function

// Define an alias for std::mutex
using MyMutex = std::mutex;

class DiningPhilosophers {
    MyMutex mutex;   // Use the custom alias instead of std::mutex

public:
    void wantsToEat(int philosopher, std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork, std::function<void()> eat,
                    std::function<void()> putLeftFork, std::function<void()> putRightFork) {
        std::lock_guard<MyMutex> lock(mutex); // Use the custom alias in std::lock_guard
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};
