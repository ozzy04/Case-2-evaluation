#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Structure to represent each participant
struct Participant {
    std::string name;
    std::string language;
    std::string specialization;
};

// Structure to represent each country
struct Country {
    std::string name;
    std::string required_language;
    std::string required_specialization;
};

// Function to generate a random matching probability between 0 and 100
int match_probability(const Participant& p, const Country& c) {
    int probability = 0;
    // If both language and specialization match, the probability is high
    if (p.language == c.required_language && p.specialization == c.required_specialization) {
        probability = 90;
    }
    // If only one criterion matches, the probability is medium
    else if (p.language == c.required_language || p.specialization == c.required_specialization) {
        probability = 50;
    }
    // If neither matches, the probability is low
    else {
        probability = 10;
    }
    return probability;
}

// Function to display the match result
void display_match(const Participant& p, const Country& c, int probability) {
    std::cout << "Participant: " << p.name << std::endl;
    std::cout << "Specialization: " << p.specialization << " | Language: " << p.language << std::endl;
    std::cout << "Country: " << c.name << std::endl;
    std::cout << "Required Specialization: " << c.required_specialization << " | Required Language: " << c.required_language << std::endl;
    std::cout << "Matching Probability: " << probability << "%" << std::endl;
}

int main() {
    // List of participants
    std::vector<Participant> participants = {
        {"Dr. Smith", "English", "Surgery"},
        {"Dr. Johnson", "Spanish", "Pediatrics"},
        {"Dr. Lee", "French", "Cardiology"},
        {"Dr. Brown", "Arabic", "Neurology"},
        {"Dr. Wilson", "Russian", "Obstetrics"}
    };

    // List of countries
    std::vector<Country> countries = {
        {"Country A", "English", "Surgery"},
        {"Country B", "Spanish", "Pediatrics"},
        {"Country C", "French", "Cardiology"},
        {"Country D", "Arabic", "Neurology"},
        {"Country E", "Russian", "Obstetrics"}
    };

    // Randomize and display matches
    srand(time(0));
    for (auto& participant : participants) {
        // Select a random country for matching
        int country_index = rand() % countries.size();
        Country selected_country = countries[country_index];

        // Calculate matching probability
        int probability = match_probability(participant, selected_country);

        // Display match information
        display_match(participant, selected_country, probability);
        std::cout << "------------------------------\n";
    }

    return 0;
}
