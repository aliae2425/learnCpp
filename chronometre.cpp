#include <iostream>
#include <conio.h> // Pour _getch()
#include <chrono>
#include <vector>

int main() {
    std::cout << "Appuyez sur ESPACE pour démarrer le chronomètre..." << std::endl;
    // Attendre la première pression sur espace
    while (_getch() != ' ') {}

    std::cout << "Chronomètre démarré !\nAppuyez sur SHIFT pour enregistrer un tour.\nAppuyez sur ESPACE pour arrêter." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto last_lap = start;
    std::vector<double> laps;
    int lap_count = 0;

    while (true) {
        int key = _getch();
        // SHIFT = touche spéciale, _getch() retourne 0 ou 224, puis le code touche
        if (key == ' ') {
            break;
        } else if (key == 0 || key == 224) {
            int key2 = _getch();
            // 42 = gauche, 54 = droite (SHIFT gauche/droite)
            if (key2 == 42 || key2 == 54) {
                auto now = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> lap = now - last_lap;
                laps.push_back(lap.count());
                last_lap = now;
                lap_count++;
                std::cout << "Tour " << lap_count << " : " << lap.count() << " secondes." << std::endl;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Temps total : " << elapsed.count() << " secondes." << std::endl;
    if (!laps.empty()) {
        std::cout << "Récapitulatif des tours :" << std::endl;
        for (size_t i = 0; i < laps.size(); ++i) {
            std::cout << "  Tour " << (i+1) << " : " << laps[i] << " s" << std::endl;
        }
    }
    return 0;
}
