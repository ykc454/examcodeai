#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Chatbot: Hello! How can I help you?\n";

    while (true) {
        cout << "You: ";
        getline(cin, input);

        if (input == "hello" || input == "hi") {
            cout << "Chatbot: Hello! Nice to meet you.\n";
        }
        else if (input == "how are you") {
            cout << "Chatbot: I am fine. How are you?\n";
        }
        else if (input == "what is your name") {
            cout << "Chatbot: I am a simple chatbot.\n";
        }
        else if (input == "bye") {
            cout << "Chatbot: Goodbye! Have a nice day.\n";
            break;
        }
        else {
            cout << "Chatbot: Sorry, I don't understand.\n";
        }
    }
    return 0;
}