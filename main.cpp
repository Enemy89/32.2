#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <vector>

struct Film {
    std::string filmName;
    std::string country;
    std::string dateOfCreation;
    std::string studio;
    std::string director;
    std::string author;
    std::string producer;
    std::string characters;
};

nlohmann::json createJsonDocument(const Film& movie) {
    nlohmann::json dict;
    dict["country"] = movie.country;
    dict["dateOfCreation"] = movie.dateOfCreation;
    dict["studio"] = movie.studio;
    dict["director"] = movie.director;
    dict["author"] = movie.author;
    dict["producer"] = movie.producer;
    dict["characters"] = movie.characters;
    return dict;
}

int main() {
    std::vector<Film> movies = {
            {"How are you?", "Japan", "14.07.2023", "Ghibli", "Hayao Miyazaki", "Hayao Miyazaki", "Toshio Suzuki, Goro Miyazaki, Koji Hoshino", "Mahito Maki - Soma Santoki, Himi - Aimyon, Izumi - Keiko Takeshita"},
            {"The Taming of the Shrew", "Italy", "20.12.1980", "Capital film", "Franco Castellano, Giuseppe Moccia", "Franco Castellano, Giuseppe Moccia, William Shakespeare", "Mario Cecchi Gori, Vittorio Cecchi Gori", "Adriano Celentano - Elia Codogno, Ornella Muti - Lisa Silvestri, Edith Peters - Haushälterin Mamie"},
            {"The Last of Us", "Canada, USA", "15.01.2023", "Naughty Dog, Sony Computer Entertainment", "Craig Mazin, Ali Abbasi, Jeremy Webb", "Neil Drakmann, Craig Mazin", "Neil Drakmann, Jane Allison Hooper, Rose Lam", "Pedro Pascal - Joel Miller, Bella Ramsey - Ellie William"},
            {"Harry Potter and the Sorcerer's Stone", "Great Britain, USA", "04.11.2001", "Warner Bros", "Chris Columbus", "Stephen Cloves, J.K. Rowling", "Todd Arnow, Michael Barnathan, Chris Columbus", "Daniel Radcliffe - Harry Potter, Rupert Grint - Ron Weasley, Emma Watson - Hermione Granger"},
            {"The Silence of the Lambs", "USA", "30.01.1991", "Orion Pictures Corporation", "Jonathan Demme", "Ted Talley, Thomas Harris", "Ronald M. Bozeman, Grace Blake, Gary Getzman", "Jodie Foster - Clarice Starling, Anthony Hopkins - Dr. Hannibal Lecter"},
    };

    nlohmann::json database;
    for (int i = 0; i < movies.size(); ++i) {
        database[movies[i].filmName] = createJsonDocument(movies[i]);
    }

    std::ofstream file("../MovieDatabase.json");
    file << std::setw(4) << database;

    std::string actorName;
    std::cout<<"Enter name actor for find: "<<std::endl;
    std::cin>>actorName;
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i].characters.find(actorName) != std::string::npos) {
            std::cout << "Film: " << movies[i].filmName << ", Role: " << movies[i].characters << std::endl;
        }
    }
    file.close();
}