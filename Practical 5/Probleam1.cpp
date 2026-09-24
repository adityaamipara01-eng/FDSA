#include <iostream>
#include <string>
using namespace std;

struct SongNode
{
    string song;
    SongNode *previous;
    SongNode *next;

    SongNode(string name)
    {
        song = name;
        previous = nullptr;
        next = nullptr;
    }
};

class Playlist
{
private:
    SongNode *first;
    SongNode *last;
    int songCount;

public:
    Playlist()
    {
        first = nullptr;
        last = nullptr;
        songCount = 0;
    }

    void addAtBeginning(string name)
    {
        SongNode *newNode = new SongNode(name);

        if (first == nullptr)
        {
            first = last = newNode;
        }
        else
        {
            newNode->next = first;
            first->previous = newNode;
            first = newNode;
        }

        songCount++;
    }

    void addAtEnd(string name)
    {
        SongNode *newNode = new SongNode(name);

        if (last == nullptr)
        {
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            newNode->previous = last;
            last = newNode;
        }

        songCount++;
    }

    bool insertAfter(string oldSong, string newSong)
    {
        SongNode *current = first;

        while (current != nullptr && current->song != oldSong)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            return false;
        }

        SongNode *newNode = new SongNode(newSong);
        newNode->previous = current;
        newNode->next = current->next;

        if (current->next != nullptr)
        {
            current->next->previous = newNode;
        }
        else
        {
            last = newNode;
        }

        current->next = newNode;
        songCount++;
        return true;
    }

    bool removeFirst()
    {
        if (first == nullptr)
        {
            return false;
        }

        SongNode *oldFirst = first;
        first = first->next;

        if (first == nullptr)
        {
            last = nullptr;
        }
        else
        {
            
            first->previous = nullptr;
        }

        delete oldFirst;
        songCount--;
        return true;
    }

    void display()
    {
        cout << "Playlist: ";

        if (first == nullptr)
        {
            cout << "empty";
        }
        else
        {
            SongNode *current = first;
            while (current != nullptr)
            {
                cout << current->song;
                if (current->next != nullptr)
                {
                    cout << " -> ";
                }
                current = current->next;
            }
        }

        cout << "\nNumber of songs: " << songCount << "\n";
    }

    ~Playlist()
    {
        while (first != nullptr)
        {
            removeFirst();
        }
    }
};

int main()
{
    Playlist playlist;
    int choice;
    string song;
    string oldSong;
    string newSong;

    do
    {
        cout << "1. Add song at beginning\n";
        cout << "2. Add song at end\n";
        cout << "3. Insert song after a song\n";
        cout << "4. Remove first song\n";
        cout << "5. Count songs\n";
        cout << "6. Display playlist\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            getline(cin, song);
            playlist.addAtBeginning(song);
            playlist.display();
            break;

        case 2:
            cout << "Enter song name: ";
            getline(cin, song);
            playlist.addAtEnd(song);
            playlist.display();
            break;

        case 3:
            cout << "Insert after which song? ";
            getline(cin, oldSong);
            cout << "Enter new song name: ";
            getline(cin, newSong);

            if (playlist.insertAfter(oldSong, newSong))
            {
                cout << "Song inserted.\n";
            }
            else
            {
                cout << "Song not found. Nothing was inserted.\n";
            }
            playlist.display();
            break;

        case 4:
            if (playlist.removeFirst())
            {
                cout << "First song removed.\n";
            }
            else
            {
                cout << "Playlist is already empty.\n";
            }
            playlist.display();
            break;

        case 5:
            playlist.display();
            break;

        case 6:
            playlist.display();
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}