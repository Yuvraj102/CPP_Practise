#include<bits/stdc++.h>


class Command {
public:
    std::string name;
    int duration;

    
    Command(const std::string& _name, int _duration)
        : name(_name), duration(_duration) {}
};


class CommandNode {
public:
    Command cmd;
    CommandNode* next;

    
    CommandNode(Command* c) : cmd(*c), next(nullptr) {}

    
    ~CommandNode() {
        
    }
};


class CommandExecutor {
public:

    void run(Command& c) {
        std::cout << "Executing command: \"" << c.name << "\" for " << c.duration << "ms." << std::endl;
    }
};

// Global function to advance a pointer to a command node
// Takes a reference to a pointer, allowing the pointer to be changed
void advanceQueue(CommandNode*& current) {
    if (current) {
        current = current->next;
    }
}


void printQueue(CommandNode* head) {
    std::cout << "\n--- Command Queue Status ---" << std::endl;
    if (head == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    CommandNode* temp = head;
    while (temp) {
        std::cout << "Command: " << temp->cmd.name << " (Duration: " << temp->cmd.duration << "ms)" << std::endl;
        temp = temp->next;
    }
    std::cout << "----------------------------" << std::endl;
}


class CommandQueue {
private:
    CommandNode* head;
    CommandExecutor executor;

public:
    
    CommandQueue() : head(nullptr) {}

    
    void enqueue(Command* c) {
        CommandNode* newNode = new CommandNode(c);
        if (head == nullptr) {
            head = newNode;
        } else {
            CommandNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << "Enqueued command: " << c->name << std::endl;
        delete c; // Clean up 
    }

    
    void executeNext(CommandNode*& current) {
        if (current) {
            executor.run(current->cmd);
            
            advanceQueue(current);
        } else {
            std::cout << "End of queue reached." << std::endl;
        }
    }

    
    void executeAll() {
        CommandNode* current = head;
        while (current) {
            executeNext(current);
        }
        std::cout << "All commands executed." << std::endl;
    }

    
    void clear() {
        while (head) {
            CommandNode* temp = head;
            head = head->next;
            delete temp;
        }
        std::cout << "Queue cleared and memory deallocated." << std::endl;
    }

    
    CommandNode* getHead() const {
        return head;
    }

    
    ~CommandQueue() {
        clear();
    }
};

int main() {
    CommandQueue queue;

    
    std::cout << "--- Creating and Enqueuing Commands ---" << std::endl;
    queue.enqueue(new Command("Start Motor", 100));
    queue.enqueue(new Command("Open Valve", 50));
    queue.enqueue(new Command("Reset Position", 200));
    queue.enqueue(new Command("Close Valve", 60));
    queue.enqueue(new Command("Stop Motor", 80));

    
    printQueue(queue.getHead());

    // show execution via reference-to-pointer traversal
    std::cout << "\n--- Executing all commands in queue ---" << std::endl;
    queue.executeAll();

    
    printQueue(queue.getHead());

    return 0;
}
