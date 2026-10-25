#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Document
{
public:
    string title;
    string content;

    Document(string t, string c)
    {
        title = t;
        content = c;
    }
};

class SearchEngine
{
private:
    vector<Document> documents;

    string toLowerCase(string text)
    {
        transform(text.begin(), text.end(), text.begin(),
                  [](unsigned char c)
                  {
                      return static_cast<char>(tolower(c));
                  });

        return text;
    }

public:
    void addDocument(string title, string content)
    {
        documents.push_back(Document(title, content));
        cout << "Document added successfully!\n";
    }

    void search(string keyword)
    {
        keyword = toLowerCase(keyword);

        bool found = false;

        cout << "\n===== SEARCH RESULTS =====\n";

        for (int i = 0; i < documents.size(); i++)
        {
            string title = toLowerCase(documents[i].title);
            string content = toLowerCase(documents[i].content);

            int score = 0;

            if (title.find(keyword) != string::npos)
                score += 2;

            if (content.find(keyword) != string::npos)
                score += 1;

            if (score > 0)
            {
                found = true;

                cout << "\nTitle: "
                     << documents[i].title << endl;

                cout << "Content: "
                     << documents[i].content << endl;

                cout << "Relevance Score: "
                     << score << endl;
            }
        }

        if (!found)
        {
            cout << "No matching documents found.\n";
        }
    }
};

int main()
{
    SearchEngine engine;

    // Sample documents
    engine.addDocument(
        "Introduction to C++",
        "C++ is a programming language used to develop software."
    );

    engine.addDocument(
        "Data Science",
        "Data Science uses Python, statistics, and machine learning."
    );

    engine.addDocument(
        "Artificial Intelligence",
        "Artificial Intelligence enables machines to perform intelligent tasks."
    );

    int choice;
    string title, content, keyword;

    do
    {
        cout << "\n===== MINI SEARCH ENGINE =====\n";
        cout << "1. Search Documents\n";
        cout << "2. Add Document\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
            cout << "Enter keyword to search: ";
            getline(cin, keyword);

            engine.search(keyword);
            break;

        case 2:
            cout << "Enter document title: ";
            getline(cin, title);

            cout << "Enter document content: ";
            getline(cin, content);

            engine.addDocument(title, content);
            break;

        case 3:
            cout << "Exiting Search Engine...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
