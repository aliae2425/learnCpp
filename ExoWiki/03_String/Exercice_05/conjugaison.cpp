#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> PRONOUNS = {
    "je", "tu", "il / elle", "nous", "vous", "ils / elles"
};

std::string conjugateVerb(const std::string& verb, const std::string& pronoun) {
    std::string baseVerb = verb.substr(0, verb.find_last_of("er")-1); // Remove "er" ending
    if (pronoun == "je") {
        return baseVerb + "e";
    } else if (pronoun == "tu") {
        return baseVerb + "es";
    } else if (pronoun.find("il") != std::string::npos || pronoun.find("elle") != std::string::npos) {
        return baseVerb + "e";
    } else if (pronoun == "nous") {
        return baseVerb + "ons";
    } else if (pronoun == "vous") {
        return baseVerb + "ez";
    } else if (pronoun.find("ils") != std::string::npos || pronoun.find("elles") != std::string::npos){
        return baseVerb + "ent";
    }
    return verb; // Default case, no conjugation
}

void displayConjugation(const std::string& verb) {
    std::cout << "Conjugaison du verbe \"" << verb << "\":" << std::endl;
    for (const auto& pronoun : PRONOUNS) {
        std::cout << pronoun << " " <<  conjugateVerb(verb, pronoun) << std::endl;
    }
}

int main() {
    std::string verb, pronoun;
    std::cout << "Entrez le verbe à conjuguer : ";
    std::cin >> verb;

    displayConjugation(verb);

    return 0;
}