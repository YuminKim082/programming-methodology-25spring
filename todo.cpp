#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i = 0; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i = 0; i < size; ++i) {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
    size = 0;
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
    
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';  // Null-terminate the destination string
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size >= MAX_TASKS) {
        throw std::runtime_error("Task list is full");
    }
    tasks[size] = new char[string_length(task) + 1];  // +1 for null terminator
    string_copy(tasks[size], task);
    ++size;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    delete[] tasks[index];
    for (int i = index; i < size - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }
    tasks[size - 1] = nullptr;  // Nullify the last task
    --size;
    if (size < 0) {
        size = 0;  // Ensure size doesn't go negative
    }
    if (size == 0) {
        tasks[0] = nullptr;  // Reset the first task pointer
    }
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    return const_cast<const char**>(tasks);
    // Note: const_cast is used to remove constness for the return type
    // but should be used with caution. In this case, it's safe because
    // we are not modifying the tasks in the caller's context.
    // If you want to avoid const_cast, you can return a copy of the tasks
    // or use a different approach to manage constness.
    // For example, you could return a vector of strings instead of a raw array.
    // However, that would require changing the function signature and
    return nullptr;
}