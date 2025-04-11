#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    for(int i=0;i<MAX_TASKS;i++){tasks[i]=nullptr;}
    size=0;
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i=0;i<MAX_TASKS;i++){delete[] tasks[i];}
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int count=0;
    while(true)
    {
        if(str[count]=='\0'){return count;}
        count++;
    }
    return 0;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i=0;
    while(src[i]!='\0')
    {
        dest[i]=src[i];
        i++;
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size<MAX_TASKS)
    {
        size+=1;
        int len=string_length(task);
        char *temp=new char[len+1];
        temp[len]='\0';
        for(int i=0;i<len;i++){temp[i]=task[i];}
        tasks[size-1]=temp;
    }
    else{throw std::out_of_range("List is already full");}
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    char* temp;
    int final=0;
    for(int i=0;i<MAX_TASKS;i++)
    {
        if(tasks[final]==nullptr){final=i-1;break;}
    }
    //if(final==-1){~~}
    for(int i=index;i<final;i++)
    {
        tasks[i]=tasks[i+1];
    }
    tasks[final]=nullptr;
    size-=1;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count=0;
    while(count<MAX_TASKS)
    {
        if(tasks[count]==nullptr){break;}
        count++;
    }
    if(count==0){return nullptr;}
    else
    {
        const char** result=new const char*[count];
        for(int i=0;i<size;i++){result[i]=tasks[i];}
        return result;
    }
}