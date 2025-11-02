#include <iostream>
#include <string>

struct Song {
    std::string title;
    std::string artist;
    Song(const std::string& t = "", const std::string& a = "") : title(t), artist(a) {}
};

class Playlist {
private:
    struct Node {
        Song song;
        Node* prev;
        Node* next;
        Node(const Song& s) : song(s), prev(nullptr), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;

public:
    ~Playlist() {
        Node* p = head;
        while (p) {
            Node* nxt = p->next;
            delete p;
            p = nxt;
        }
    }

    // Adds a new song to the end of the list
    void addSong(std::string title, std::string artist) {
        Node* node = new Node(Song(title, artist));
        if (!head) {
            head = tail = node;
            current = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // Move to the next song
    void playNext() {
        if (!current) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        if (current->next) {
            current = current->next;
            std::cout << "Playing: " << current->song.title << " - " << current->song.artist << "\n";
        } else {
            std::cout << "Already at the end of the playlist.\n";
        }
    }

    // Move to the previous song
    void playPrevious() {
        if (!current) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        if (current->prev) {
            current = current->prev;
            std::cout << "Playing: " << current->song.title << " - " << current->song.artist << "\n";
        } else {
            std::cout << "Already at the beginning of the playlist.\n";
        }
    }

    // Display all songs and mark the current song
    void displayPlaylist() {
        if (!head) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        Node* p = head;
        int idx = 1;
        while (p) {
            std::cout << idx << ". " << p->song.title << " - " << p->song.artist;
            if (p == current) std::cout << "  <-- current";
            std::cout << "\n";
            p = p->next;
            ++idx;
        }
    }

    // Optional: play current song (prints it)
    void playCurrent() {
        if (!current) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        std::cout << "Playing: " << current->song.title << " - " << current->song.artist << "\n";
    }
};

int main() {
    Playlist pl;
    pl.addSong("Bohemian Rhapsody", "Queen");
    pl.addSong("Imagine", "John Lennon");
    pl.addSong("Hotel California", "Eagles");

    pl.displayPlaylist();
    pl.playCurrent();

    pl.playNext();
    pl.playNext();
    pl.playNext();      // attempts to go past the tail
    pl.playPrevious();
    pl.displayPlaylist();

    return 0;
}