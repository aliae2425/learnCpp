#include <iostream>
#include <conio.h> // Pour _getch()
#include <chrono>
#include <vector>
#include <windows.h>

void afficherTour(int numero, double temps) {
    std::cout << "Tour " << numero << " : " << temps << " secondes." << std::endl;
}

void afficherCodeTouche(int key, int key2 = -1) {
    std::cout << "Code touche : " << key;
    if (key2 != -1) std::cout << ", code spécial : " << key2;
    std::cout << std::endl;
}

void attendreRelachementShift() {
    // Attend que la touche Shift soit relâchée pour éviter plusieurs tours d'affilée
    while (GetAsyncKeyState(VK_SHIFT) & 0x8000) {}
}

int main() {
    std::cout << "Appuyez sur ESPACE pour démarrer le chronomètre..." << std::endl;
    while (_getch() != ' ') {}

    std::cout << "Chronomètre démarré !\nAppuyez sur SHIFT pour enregistrer un tour.\nAppuyez sur ESPACE pour arrêter." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto last_lap = start;
    std::vector<double> laps;
    int lap_count = 0;

    while (true) {
        // Arrêt avec espace
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            break;
        }
        // Compte tour avec Shift
        if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            auto now = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> lap = now - last_lap;
            laps.push_back(lap.count());
            last_lap = now;
            lap_count++;
            afficherTour(lap_count, lap.count());
            attendreRelachementShift();
        }
        Sleep(10); // Petite pause pour éviter de surcharger le CPU
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
